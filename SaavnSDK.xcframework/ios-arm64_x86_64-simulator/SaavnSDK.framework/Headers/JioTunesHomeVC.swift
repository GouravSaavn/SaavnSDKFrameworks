//
//  JioTunesHomeVC.swift
//  Saavn
//
//  Created by Nitin Yadav on 26/4/2021.
//  Copyright © 2021 Saavn. All rights reserved.
//

//import Starscream
import Foundation

@objc public class JioTunesHomeVC: SaavnVC_n, LocalDataProtocol {
    //MARK:- Elements
    private var refreshControl = UIRefreshControl()
    @IBOutlet private var bottomConstraint: NSLayoutConstraint!
    @IBOutlet private var tableView: UITableView!
    
    //MARK:- Properties
    private var feed: JioTuneHomeFeed
    private var contentOffsets: [CGPoint] = []
    private var cookiesUpdated: Bool = false
    private var jioTunePlayer = JioTunePlayer.shared
    private var headerView: JioTuneHomeHeaderView!
    private var emptyStateView: SearchEmptyStateView?
    private var footerStackView: UIStackView!
    private var jioTuneQuickActionView: JioTuneQuickActionView!
    private var searchMoreJioTuneView: SearchMoreJioTuneView!
    var currentlySearching = false
    var isRequestJioTuneVC = false
    var currentJioTuneData: [String: Any] = [:]
    //MARK:- Constants
    let contentInset = UIEdgeInsets(top: LayoutConstants.sideMargin, left: 0,
                                    bottom: LayoutConstants.sideMargin - LayoutConstants.sectionBottomMargin,
                                    right: 0)
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?) {
        feed = JioTuneHomeFeed()
        let bundle = Bundle.init(for: JioTunesHomeVC.self)
        super.init(nibName: "\(JioTunesHomeVC.self)", bundle: bundle)
        feed.delegate = self
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    public override func viewDidLoad() {
        oldCodePreLoadSetup()
        super.viewDidLoad()
        feed.isRequestJioTuneVC = isRequestJioTuneVC
        setupUI()
        registerForLocalDataUpdate()
        updateData(withLoader: true)
        if !isRequestJioTuneVC {
            feed.setDefaultSocket(searchApi: "jiotunepage.get")
        } else {
            self.title = "Search JioTunes"
            feed.setDefaultSocket(searchApi: "jiotunepage.getSongFacet")
        }
        let bundle = Bundle.init(for: JioTuneAvailableVC.self)
        let nib = UINib(nibName: "\(JioTunesTableViewCell.self)", bundle: bundle)
        tableView.register(nib, forCellReuseIdentifier: "\(JioTunesTableViewCell.self)")
        
        
        
        NotificationCenter.default.addObserver(self, selector: #selector(currentJioTuneUpdated), name: NSNotification.Name(rawValue: "com.saavnSDK.currentJioTune"), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(removeCurrentJioTuneClicked), name: NSNotification.Name(rawValue: "com.saavnSDK.remoteCurrentJioTuneTap"), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(handleDeactiveResponse), name: NSNotification.Name(rawValue: "com.saavnSDK.deactivateResponse"), object: nil)
        
        SaavnSDKDoorway().delegate.getCurrentJioTuneData()
    }
    public override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        if (!isRequestJioTuneVC) { resetNav() }
        if cookiesUpdated { updateData(withLoader: true) }
        handleEvent(for: .viewWillAppear)
        headerView.setPlaceHolderText(text: "Search JioTunes")
        NotificationCenter.default.post(name: Notification.Name("com.sensibol.saavn.hideTab"), object: nil)
        setupNavigationBar()
        
    }
    @objc func dismissVC() {
        //        self.dismiss(animated: true, completion: nil)
        SaavnSDKDoorway().delegate.dismiss(fromJioSaavn: self, isClose: false)
        
        
    }
    public override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        headerView.hideKeyboard()
        jioTunePlayer.flushPlayerData()
        self.postScreenViewTimeEvents()
    }
    public override func updateUIMode() {
        super.updateUIMode()
        Util_n.appDel()?.getHomeViewController().updateUIMode()
        tableView.backgroundColor = Styles_n.bgColor()
        refreshControl.tintColor = Styles_n.fillColor()
    }
    func languageUpdated() {
        cookiesUpdated = true
    }
}

//MARK: UITableView
extension JioTunesHomeVC {
    public override func numberOfSections(in tableView: UITableView) -> Int {
        return feed.modules.count
    }
    public override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 1
    }
    //Header
    public override func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        guard section < feed.modules.count , let header = feed.modules[section].header else { return .leastNonzeroMagnitude }
        if header.isEmpty { return LayoutConstants.emptyHeaderSpacer }
        return JTModuleHeaderView.calculateHeaderViewHeight(header: header)
    }
    public override func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        guard section < feed.modules.count ,  let header = feed.modules[section].header,
              let sectionHeaderView = tableView.dequeueReusableHeaderFooterView(withIdentifier: "\(JTModuleHeaderView.self)") as? JTModuleHeaderView else { return nil }
        sectionHeaderView.header = header
        return sectionHeaderView
    }
    //Rows as CollectionView
    public override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        let cell = tableView.dequeueReusableCell(withIdentifier: "\(JioTunesTableViewCell.self)") as! JioTunesTableViewCell
        if feed.modules.count > indexPath.section {
        let module = feed.modules[indexPath.section]
        let hasViewMoreCell = module.viewMore == nil ? 0 : 1
        let cellCount = module.cellsData.count + hasViewMoreCell
        let height = module.scrollType.scrollHeight(for: cell.collectionView.contentInset,
                                                             of: tableView.bounds.size.width, with: cellCount)
            return height
            
        }
        return 0 //default value to avoid crash
        
    }
    public override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "\(JioTunesTableViewCell.self)") as! JioTunesTableViewCell
        cell.cellStandardDelegate = self
        cell.parentVC = self
        cell.eventHandler = self
        if (currentlySearching) { cell.query = headerView.getSearchBarText() }
        if feed.modules.count > indexPath.section , contentOffsets.count > indexPath.section{
            cell.contentOffset = contentOffsets[indexPath.section]
            cell.module = feed.modules[indexPath.section]
        }
        return cell
    }
    public override func tableView(_ tableView: UITableView, willDisplay cell: UITableViewCell, forRowAt indexPath: IndexPath) {
        self.view.layoutIfNeeded()
    }
    public override func tableView(_ tableView: UITableView, didEndDisplaying cell: UITableViewCell, forRowAt indexPath: IndexPath) {
        let cell = tableView.dequeueReusableCell(withIdentifier: "\(JioTunesTableViewCell.self)") as! JioTunesTableViewCell
        if indexPath.section < contentOffsets.count {
            contentOffsets[indexPath.section] = cell.collectionView.contentOffset
        }
    }
    //Footer
    public override func tableView(_ tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        guard feed.modules[section].footer != nil
        else { return LayoutConstants.sectionBottomMargin }
        return LayoutConstants.standardGutter
    }
}

//MARK:- ScrollView
extension JioTunesHomeVC {
    public override func scrollViewDidScroll(_ scrollView: UIScrollView) {
        setupNavDivider()
    }
    public override func scrollViewWillBeginDragging(_ scrollView: UIScrollView) {
        headerView.hideKeyboard()
    }
}

//MARK:- HeaderSearchViewProtocol
extension JioTunesHomeVC: HeaderSearchViewProtocol {
    func textDidChange(text: String) {
        if !text.isEmpty {
            currentlySearching = true
            feed.connectionType = .webSocket
            feed.defaultSocket?.startRequest(with: text, artistId: nil)
            feed.fetchData(for: .first)
            let contentInset = CGPoint(x: -LayoutConstants.sideMargin, y: 0)
            contentOffsets = Array(repeating: contentInset, count: feed.modules.count)
            self.tableView.reloadData()
            loader.startAnimating()
            headerView?.setLoading(isLoading: true)
            tableView.tableFooterView = nil
            jioTunePlayer.flushPlayerData()
            handleEvent(for: .searchFor(text))
        } else {
            currentlySearching = false
            feed.connectionType = .standard
            hideEmptyState()
            self.updateData(withLoader: true)
        }
    }
}

//MARK:- JioTuneTableViewCell Protocol
extension JioTunesHomeVC: JTTableViewCellProtocol {
    var sectionDetails: [String : Any] {
        return [:]
    }
    
    var bottomSource: [String : Any] {
        var bottomSource: [String: Any] = [:]
        bottomSource["screen_name"] = self.getScreenName
        return bottomSource
    }
    
    var eventParams: [String : Any] {
        let playerEventDict: [String: Any] = [:]
        return playerEventDict
    }
}

//MARK:- ApiProtocol
extension JioTunesHomeVC: ApiProtocol {
    func didFetchSuccessfully(for params: [String : Any]) {
        let contentInset = CGPoint(x: -LayoutConstants.sideMargin, y: 0)
        contentOffsets = Array(repeating: contentInset, count: feed.modules.count)
        loader.stopAnimating()
        refreshControl.endRefreshing()
        headerView.setLoading(isLoading: false)
        if !isRequestJioTuneVC && feed.connectionType == .standard { tableView.tableFooterView = footerStackView }
        tableView.tableHeaderView = headerView
        if feed.modules.count == 0 && feed.connectionType == .webSocket {
            showNoSearchResultsView()
        } else {
            addCurrentJiotune()
            tableView.reloadData()
        }
        handleEvent(for: .apiSuccess)
    }
    func didFail(with error: SaavnError, for params: [String: Any]) {
        loader.stopAnimating()
        refreshControl.endRefreshing()
        tableView.tableFooterView = nil
        tableView.tableHeaderView = nil
        addErrorState(for: error, buttonText: "Refresh")
        handleEvent(for: .apiFail)
    }
}
//MARK:- Error Handling
extension JioTunesHomeVC {
    private func addErrorState(for error: SaavnError, buttonText: String) {
        errorState = EmptyErrorState(inVC: self, withTitle: error.title, message: error.message, buttonLabel: buttonText, andAction: {
            self.errorState.isHidden = true
            self.updateData(withLoader: true)
        })
        errorState.isHidden = false
    }
    func showNoSearchResultsView(){
        if emptyStateView == nil {
            emptyStateView = SearchEmptyStateView(frame: CGRect(x: 0, y: 0, width: self.mainTable.frame.width, height: 250))
            emptyStateView!.setQueryString(headerView.getSearchBarText())
        }
        emptyStateView!.setQueryString(headerView.getSearchBarText())
        tableView.tableFooterView = emptyStateView
    }
    private func hideEmptyState() {
        guard let _ = errorState
        else { return }
        self.errorState.isHidden = true
    }
}

//MARK:- JioTuneEventHandler Protocol
extension JioTunesHomeVC: JioTuneEventHandler {
    func didSelectRow(at index: Int, in module: JioTuneModule) {
        if !isRequestJioTuneVC { addTopSource(for: index, in: module) }
        handleEvent(for: .cellClickedAt(index, inModule: module))
    }
    func longPress(at index: Int, in module: JioTuneModule) {
        handleEvent(for: .longPressAt(index, inModule: module))
    }
}

extension JioTunesHomeVC: JioTuneQuickActionViewDelegate {
    func jioTuneQuickActionTapped() {
        let entityDict = ["entity_name":"Quick Action",
                          "entity_type":"button",
                          "entity_id":"quick_action",
                          "entity_pos": "\(feed.modules.count)"
        ]
        let botSrc = Util_n.appendBottomSource(toDict: nil, fromSection: nil, andEntity: entityDict, viaParent: self)
        Util_n.trackPageView(ENTITY_CLICK, trackingDict: botSrc as? [AnyHashable : Any])
        
        let settingsVC = SettingsVC()
        settingsVC.topSrcData = [
            "entity_name":"Quick Action",
            "entity_type":"button",
            "entity_id":"quick_action",
            "entity_pos": "\(feed.modules.count)",
            "screen_name": "home_screen_jiotunes"
        ]
        settingsVC.showCellSecondaryOptions(self.navigationController)
    }
}

extension JioTunesHomeVC: SerachMoreJioTuneViewDelegate {
    func searchMoreJioTuneButtonAction() {
        let entityDict = ["entity_name":"Request JioTune",
                          "entity_type":"button",
                          "entity_id":"request_jiotune",
                          "entity_pos": "\(feed.modules.count+1)"]
        let botSrc = Util_n.appendBottomSource(toDict: nil, fromSection: nil, andEntity: entityDict, viaParent: self)
        Util_n.trackPageView(ENTITY_CLICK, trackingDict: botSrc as? [AnyHashable : Any])
        
        let jiotuneSearchVC = JioTunesHomeVC()
        jiotuneSearchVC.topSrcData = [
            "entity_name":"Request JioTune",
            "entity_type":"button",
            "entity_id":"request_jiotune",
            "entity_pos": "\(feed.modules.count+1)",
            "screen_name": "home_screen_jiotunes"
        ]
        jiotuneSearchVC.isRequestJioTuneVC = true
        self.navigationController?.pushViewController(jiotuneSearchVC, animated: true)
    }
}

//MARK:- Helpers
extension JioTunesHomeVC {
    private func oldCodePreLoadSetup() {
        viewType = ViewType_JIOTUNE
        trackingPrefix = ""
        if !isRequestJioTuneVC { hidesNavBar = true }
        //        navigationController?.navigationBar.isHidden = true
    }
    private func setupUI() {
        mainTable = tableView
        updateUIMode()
        setupTableView()
        setupRefreshControl()
        if(!isRequestJioTuneVC) { setupNavigationBar() }
        setupHeaderView()
        handleProUsers()
        initFooterStackView()
    }
    private func setupTableView() {
        tableView.contentInset = contentInset
        let bundle = Bundle.init(for: JioTunesHomeVC.self)
        var nib = UINib(nibName: "\(JioTunesTableViewCell.self)", bundle: bundle)
        tableView.register(nib, forCellReuseIdentifier: "\(JioTunesTableViewCell.self)")
        nib = UINib(nibName: "\(JTModuleHeaderView.self)", bundle: bundle)
        tableView.register(nib, forHeaderFooterViewReuseIdentifier: "\(JTModuleHeaderView.self)")
    }
    private func setupRefreshControl() {
        refreshControl.addTarget(self, action: #selector(updateData), for: .valueChanged)
        tableView.refreshControl = refreshControl
    }
    private func setupNavigationBar() {
        fauxNav = Util_n.appDel()?.getHomeViewController().fauxNav
        // Adjust tableView insets, since we hid the standard nav bar.
        //        let fauxNavH = fauxNav.bounds.size.height - navBar.getDefaultStatusBarHeight()
//        let fauxNavH = 10
//        var insets = tableView.contentInset
//        insets.top =  insets.top
////        insets.top = 0
//        tableView.contentInset = insets
        
        Util_n.appDel()?.setCurrentTab(Tab_JioTune)
        self.navigationController?.setNavigationBarHidden(false, animated: false)
        self.navigationController?.navigationBar.isHidden = false
        
        self.parent?.navigationController?.setNavigationBarHidden(false, animated: false)
        self.parent?.navigationController?.navigationBar.isHidden = false
        self.initNavBarItems()
        
        if let navBar = self.parent?.navigationController {
            Util_n.appDel()?.setParentAppNC(navBar)
            Util_n.appDel()?.setParentAppNCAsCurrentNC()
        }
        
        self.navigationController?.navigationBar.tintColor = Styles_n.fillColor()
        self.parent?.navigationController?.navigationBar.tintColor = Styles_n.fillColor()
        
        self.navigationController?.navigationBar.backgroundColor = Styles_n.bgColor()
        self.parent?.navigationController?.navigationBar.backgroundColor = Styles_n.bgColor()
        
        guard self.navBar != nil else { return }
        
        if #available(iOS 13, *) {
            self.navigationController?.navigationBar.standardAppearance = self.navBar.standardAppearance
            self.navigationController?.navigationBar.compactAppearance = self.navBar.compactAppearance
            self.navigationController?.navigationBar.scrollEdgeAppearance = self.navBar.scrollEdgeAppearance
            
            self.parent?.navigationController?.navigationBar.standardAppearance = self.navBar.standardAppearance
            self.parent?.navigationController?.navigationBar.compactAppearance = self.navBar.compactAppearance
            self.parent?.navigationController?.navigationBar.scrollEdgeAppearance = self.navBar.scrollEdgeAppearance
        }
    }
    public func initNavBarItems() {
        let label = UILabel()
        label.text = "JioTunes"
        label.font = UIFont.boldSystemFont(ofSize: 16)
        label.textAlignment = NSTextAlignment.left
        if(Settings.singleton().isDarkMode)
        {
            label.textColor = UIColor.white
        }
        else{
            label.textColor = UIColor.black
        }
        
        let imageBundle = Bundle(for: JioTunesHomeVC.self)
        let image = UIImage.init(named: "Icon Back Button", in: imageBundle, compatibleWith: nil)
        
        let backButton: UIBarButtonItem = UIBarButtonItem.init(image: image, style: .plain, target: self, action: #selector(dismissVC))
        let item = UIBarButtonItem(customView: label)
        self.parent?.navigationItem.leftBarButtonItems = [backButton,item]
    }
    private func resetNav() {
        //        fauxNav.currentOwner = self
        //        view.addSubview(fauxNav)
        if Util.isiPad() { fauxNav.iPadRefreshLayout() }
        //        navigationController?.setNavigationBarHidden(true, animated: true)
        setupNavDivider()
    }
    private func setupNavDivider() {
        if fauxNav == nil { return }
        let scrollPos = tableView.contentOffset.y + fauxNav.bounds.size.height
        switch scrollPos {
        case let pos where pos<0: fauxNav.fadeOnlyBevel(0)
        case 0..<12: fauxNav.fadeOnlyBevel(scrollPos/12.0)
        default: fauxNav.fadeOnlyBevel(1)
        }
    }
    private func handleProUsers() {
#if !__SvnSenSDK
        bottomConstraint.constant = UserData.shouldShowMiniPlayer() ? MiniPlayer.height() : 0
#else
        bottomConstraint.constant = 0
#endif
    }
    @objc private func updateData(withLoader: Bool = false) {
        if withLoader { loader.startAnimating() }
        currentlySearching = false
        tableView.tableFooterView = nil
        tableView.tableHeaderView = nil
        feed.connectionType = .standard
        feed.fetchData(for: .first)
        headerView.setLoading(isLoading: false)
        headerView.setSearchBarText(text: "")
        headerView.hideKeyboard()
        jioTunePlayer.flushPlayerData()
        let contentInset = CGPoint(x: -LayoutConstants.sideMargin, y: 0)
        contentOffsets = Array(repeating: contentInset, count: feed.modules.count)
        tableView.reloadData()
        DispatchQueue.main.async {
            self.cookiesUpdated = false
        }
    }
    private func initFooterStackView() {
        footerStackView = UIStackView(frame: CGRect(x: 0, y: 0, width: tableView.frame.width, height: 450))
        footerStackView.backgroundColor = .clear
        footerStackView.axis = .vertical
        footerStackView.alignment = .firstBaseline
        footerStackView.distribution = .fill
        footerStackView.spacing = 40
        
        searchMoreJioTuneView = SearchMoreJioTuneView()
        searchMoreJioTuneView.heightAnchor.constraint(equalToConstant: 200).isActive = true
        searchMoreJioTuneView.widthAnchor.constraint(equalToConstant: tableView.frame.width).isActive = true
        searchMoreJioTuneView.delegate = self
        
        jioTuneQuickActionView = JioTuneQuickActionView()
        updateQuickAction()
        jioTuneQuickActionView.heightAnchor.constraint(equalToConstant: 190).isActive = true
        jioTuneQuickActionView.widthAnchor.constraint(equalToConstant: tableView.frame.width).isActive = true
        jioTuneQuickActionView.delegate = self
        
        footerStackView.addArrangedSubview(jioTuneQuickActionView)
        footerStackView.addArrangedSubview(searchMoreJioTuneView)
        NotificationCenter.default.addObserver(self, selector: #selector(updateQuickAction), name: NSNotification.Name(rawValue: "UI.forceRefresh"), object: nil)
    }
    @objc func updateQuickAction(){
        let currentQuickAction = Settings.getCellSecondOptionString(fromType: Settings.singleton().cellSecondOption)
        if let _ = currentQuickAction{
            jioTuneQuickActionView.setUpData(currentQuickAction: currentQuickAction!)
        }
    }
    private func setupHeaderView() {
        headerView = JioTuneHomeHeaderView(frame: CGRect(x: 0, y: 0, width: tableView.frame.width, height: 60), topConstraint: 0)
        if !isRequestJioTuneVC {
            headerView.searchApi = "jiotunepage.get"
        } else {
            headerView.searchApi = "jiotunepage.getSongFacet"
        }
        headerView.headerSearchDelegate = self
    }
}
//MARK:- Events
extension JioTunesHomeVC {
    enum Event {
        case viewWillAppear
        case cellClickedAt(_ index: Int, inModule: JioTuneModule)
        case longPressAt(_ index: Int, inModule: JioTuneModule)
        case searchFor(_ query: String)
        case apiSuccess
        case apiFail
    }
    
    ///Set the topsource so that it can be passed down to child views, if need be.
    func addTopSource(for index: Int, in module: JioTuneModule) {
        if !Util_n.isNonEmptyDictionary(getDeeplinkTopSourceDict()) {
            let header = module.header?.originalJSON
            let entityDict = module.cellsData[index].originalJSON
            topSrcData = Util_n.appendTopSource(toDict:nil, fromSection: header,
                                                andEntity: entityDict, viaParent: self)
        } else {
            topSrcData = getDeeplinkTopSourceDict()
        }
    }
    
    func handleEvent(for event: Event) {
        var header: [AnyHashable: Any]?
        var extraInfo: [AnyHashable: Any] = [:]
        var entityDict: [AnyHashable: Any] = [:]
        var action: String
        switch event {
        case .viewWillAppear:
            action = ENTITY_VIEW
        case .cellClickedAt(let index, let module):
            if !headerView.getSearchBarText().isEmpty { extraInfo["query"] = headerView.getSearchBarText() }
            header = module.header?.originalJSON
            entityDict = module.cellsData[index].originalJSON
            action = ENTITY_CLICK
        case .longPressAt(let index, let module):
            if !headerView.getSearchBarText().isEmpty { extraInfo["query"] = headerView.getSearchBarText() }
            header = module.header?.originalJSON
            entityDict = module.cellsData[index].originalJSON
            action = ENTITY_LONGPRESS
        case .apiSuccess:
            if feed.connectionType == .standard {
                entityDict["context"] = feed.apiEndPoint().components(separatedBy: ".").first ?? ""
                entityDict["contextId"] = feed.apiEndPoint()
            } else {
                entityDict["context"] = feed.searchApi.components(separatedBy: ".").first
                entityDict["contextId"] = feed.searchApi
            }
            action = IPHONE_SUCCESS
        case .apiFail:
            if feed.connectionType == .standard {
                entityDict["context"] = feed.apiEndPoint().components(separatedBy: ".").first ?? ""
                entityDict["contextId"] = feed.apiEndPoint()
            } else {
                entityDict["context"] = feed.searchApi.components(separatedBy: ".").first
                entityDict["contextId"] = feed.searchApi
            }
            action = IPHONE_FAILURE
        case .searchFor(_):
            extraInfo["query"] = headerView.getSearchBarText()
            action = IPHONE_SEARCH
        }
        let botSrc = Util_n.appendBottomSource(toDict: extraInfo, fromSection: header,
                                               andEntity: entityDict, viaParent: self)
        Util_n.trackPageView(action, trackingDict: botSrc as? [AnyHashable : Any])
    }
    
    public override func getScreenName() -> String! {
        if isRequestJioTuneVC {
            return "request_jiotune_page_screen"
        } else {
            return "home_screen_jiotunes"
        }
    }
}


//MARK: CurrentJiotuneMethods for SDK
extension JioTunesHomeVC{
    func addCurrentJioTuneCell() {
        //        guard !isRequestMoreSearchVC, !currentJioTuneData.isEmpty,!currentlySearching else { return }
        
        if !feed.modules.isEmpty,
           let firstObj = feed.modules.first,
           firstObj.name  == "current_jiotune" {
            feed.modules.remove(at: 0)
        }
        
        
        var title: String = ""
        if let dataTitle = currentJioTuneData["title"] as? String, dataTitle != "" {
            title = dataTitle
        }
        
        var subtitle: String = currentJioTuneData["subtitle"] as? String ?? " "
        var imgUrl: String = currentJioTuneData["image_url"] as? String ?? ""
        let vCode: String = currentJioTuneData["vcode"] as? String ?? ""
        
        //        let digitalServiceId: String = currentJioTuneData["digitalServiceId"] as? String ?? ""
        //        let isActive: Bool = currentJioTuneData["isActive"] as? Bool ?? true
        if vCode == "" {return}
        //        if title == "" , vCode != ""{
        //            getJiotuneData(vcode: vCode)
        //        }
        
        
        let contents: [[String: Any]] = [[
            "id": "jio_tune_current",
            "title": title,
            "subtitle": subtitle,
            "type": "song",
            "subtype": "SONGTUNE",
            "image": imgUrl,
            "perma_url": imgUrl,
            "explicit_content": "0",
            "mini_obj": true,
            "isCurrentJioTune": true,
            "more_info": [
                "album": "",
                "ctr": 100,
                "vcode": vCode
            ]
        ]]
        
        var dict: [String: Any] = [
            "title": "Active JioTune",
            "subtitle": "",
            "position": 0,
            "source": contents,
            //            "scroll_type": "CELLS_STANDARD"
            "scroll_type": "MYJIOTUNE"
        ]
        dict["contents"] = contents
        dict["sec_id"] = "jio_tune"
        dict["type"] = 100
        let currentJiotuneModule = JioTuneModule(key: "current_jiotune", value: dict)
        currentJiotuneModule.setCellsData(contents)
        var numModules = feed.modules.count
        numModules = 0
        let offset = CGPoint(x: -27, y: 0)
        contentOffsets.insert(offset, at: numModules)
        feed.modules.insert(currentJiotuneModule, at: numModules)
        tableView.reloadData()
    }
    func addCurrentJiotune(){
        if !self.currentJioTuneData.isEmpty , !isRequestJioTuneVC ,!currentlySearching{
            if let vCode = currentJioTuneData["vcode"] as? String
            { getJiotuneData(vcode: vCode) }
            
//            if let dataTitle = currentJioTuneData["title"] as? String {
//                addCurrentJioTuneCell()
//            }
//            else {
//                getJiotuneData(vcode: vCode)
//            }
        }
    }
    
    @objc public func currentJioTuneUpdated(notification: Notification) {
        guard let userInfo = notification.userInfo as? [String: Any] else { return }
        
        // If currentJioTuneData exist, means it is only updating currentJioTune
        // In that case index increment is not needed
        //        if currentJioTuneData.isEmpty, requestedJioTuneIndex != nil {
        //            requestedJioTuneIndex! += 1
        //        }
        
        self.currentJioTuneData = userInfo
//
        addCurrentJiotune()
        if feed.modules.count > 1 {
            //                    refreshData()
            self.tableView.reloadData()
            //add more refresh methods

        }
    }
    @objc public func removeCurrentJioTuneClicked() {
        guard !currentJioTuneData.isEmpty else {
            // Throw some error?
            return
        }
        
        let vCode: String = currentJioTuneData["vcode"] as? String ?? ""
        let digitalServiceId: String = currentJioTuneData["digitalServiceId"] as? String ?? ""
        loader.startAnimating()
        SaavnSDKDoorway().delegate.deactivateJioTune(vCode, digitalServiceId: digitalServiceId)
    }
    @objc public func handleDeactiveResponse(notification: Notification) {
        loader.stopAnimating()
        
        guard let userInfo = notification.userInfo as? [String: Any] else { return }
        if userInfo["success"] as! Bool == true {
            sendSuccessEvent()
            
            // Remove current jio tune
            currentJioTuneData = [:]
            if
                !feed.modules.isEmpty,
                let firstObj = feed.modules.first,
                firstObj.name == "current_jiotune" {
                
                feed.modules.remove(at: 0)
                self.tableView.reloadData()
                //                if requestedJioTuneIndex != nil, requestedJioTuneIndex! > 1 {
                //                    requestedJioTuneIndex! -= 1
                //                }
                //TODO: refresh data adding
                //                refreshData()
            }
        } else {
            let errorMsg = userInfo["error"] as? String
            sendFailureEvent(errorMsg: errorMsg)
            // Show alert view ?
        }
    }
    
    func sendSuccessEvent() {
        guard let vcode = currentJioTuneData["vcode"] as? String else { return }
        
        var botSrc: [String: Any] = [
            BOTTOM_SRC_KEY: [
                "context": "remove_jiotune",
                "contextId": vcode,
            ],
            "vcode": vcode
        ]
        botSrc[JIO_EVENT_MARKER] = true
        Util_n.trackPageView(IPHONE_SUCCESS, trackingDict: botSrc)
    }
    
    func sendFailureEvent(errorMsg: String?) {
        guard let vcode = currentJioTuneData["vcode"] as? String else { return }
        
        var botSrc: [String: Any] = [
            BOTTOM_SRC_KEY: [
                "context": "remove_jiotune",
                "contextId": vcode,
                "error_msg": errorMsg ?? ""
            ],
            "vcode": vcode
        ]
        botSrc[JIO_EVENT_MARKER] = true
        Util_n.trackPageView(IPHONE_FAILURE, trackingDict: botSrc)
    }
    func getJiotuneData(vcode : String)
    {
        //        let dummyvcode = "010912291623196"
        let param = ["vcode":"\(vcode)",
                     "ctx":"\(API_CONTEXT)"]
        
        API.get("jiotune.jiotuneDatafromVCode", withParams: param, saavnCookie: false, success: {(successResponse) in
            if successResponse != nil {
                let array = successResponse as? NSArray
                let dictionary = array?.firstObject as? NSDictionary
                dictionary?.forEach{(key,value) in self.currentJioTuneData[key as! String] = value}
                self.addCurrentJioTuneCell()
            }
            
        }, andFailure: { error in
            print(error)
        })
        
        
    }
    
}
