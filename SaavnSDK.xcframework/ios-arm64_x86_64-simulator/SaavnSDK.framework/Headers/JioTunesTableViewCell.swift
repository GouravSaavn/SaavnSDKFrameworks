//
//  JioTunesTableViewCell.swift
//  Saavn
//
//  Created by Nitin Yadav on 25/4/2021.
//  Copyright © 2021 Saavn. All rights reserved.
//

protocol JTTableViewCellProtocol: JTStandardCellProtocol {}

@objc class JioTunesTableViewCell: BaseTableViewCell {
    //MARK:- Elements
    @IBOutlet var collectionView: UICollectionView!
    lazy private var longPressGesture = UILongPressGestureRecognizer(target: self, action: #selector(cellLongPressed(_:)))
    //MARK:- Properties
    var module: JioTuneModule? { didSet {
		self.updateUI()
    }}
    var contentOffset: CGPoint = .zero
    var parentVC: SaavnVC_n!
    var eventHandler: JioTuneEventHandler?
    var query = ""
    var cellStandardDelegate: JTTableViewCellProtocol?
    //MARK:- Constants
    private var insets = UIEdgeInsets(top: 0, left: LayoutConstants.sideMargin,
                                      bottom: 0, right: LayoutConstants.sideMargin)
    private var verticalItemSpacing: CGFloat = 0
    private var horizontalItemSpacing: CGFloat = 0
    private var cellSize: CGSize = .zero
    private var viewAllSize: CGSize = .zero
    private var cellId: String = ""
    
    override func awakeFromNib() {
        super.awakeFromNib()
        setupUI()
    }
    override func prepareForReuse() {
        module = nil
    }
    override func updateUIMode() {
        super.updateUIMode()
        collectionView.backgroundColor = Styles_n.bgColor()
    }
	override func layoutSubviews() {
		//TODO: Find a better way to set collectionView width
		
		super.layoutSubviews()
		collectionView.bounds.size.width = parentVC.view.bounds.width
		updateConstants()
	}
    
    
}

//MARK: UICollectionView
extension JioTunesTableViewCell: UICollectionViewDataSource {
    //Items
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        guard let module = module else { return 0 }
        let hasViewMoreCell = module.viewMore == nil ? 0 : 1
        return module.cellsData.count + hasViewMoreCell
    }
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        guard let module = module
        else {
            return UICollectionViewCell()
        }
        
        if isViewMoreCell(at: indexPath) {
            if module.scrollType.scrollDirection == .vertical {
                let viewAllCellId = CellType.viewAllVertical.reuseId
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: viewAllCellId, for: indexPath) as! ViewAllCellVertical
                return cell
            } else {
                let viewAllCellId = CellType.viewAll.reuseId
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: viewAllCellId, for: indexPath) as! ViewAllCell
//                switch module.scrollType {
//                case .multipleItem:
//                    cell.alignment = .horizontalLeading
//                default:
//                    let collectionViewWidth = collectionView.bounds.size.width
//                    let centerOffset = module.scrollType.viewAllYPadding(for: collectionView.contentInset,
//                                                                         of: collectionViewWidth)
//                    cell.alignment = .verticalCenterOffset(centerOffset)
//                }
				cell.collectionView = collectionView
				cell.jioTuneData = module
                return cell
            }
        }
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: cellId, for: indexPath) as! BaseModuleCell
        if let cellStandard = cell as? JioTuneCellStandard {
            cellStandard.delegate = self
            cellStandard.data = module.cellsData[indexPath.item]
            cellStandard.indexPath = indexPath
            cellStandard.eventHandler = self
            cellStandard.parentVC = parentVC
            return cellStandard
        }
        cell.data = module.cellsData[indexPath.item]
        cell.indexPath = indexPath
        cell.eventHandler = self
        return cell
    }
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        guard let module = module else { return }
        if isViewMoreCell(at: indexPath), let data = module.viewMore as? [AnyHashable: Any] {
            JioTuneUtil.loadView(of: .more, from: data, in: module, via: parentVC, with: nil, with: query)
            return
        }
        eventHandler?.didSelectRow?(at: indexPath.item, in: module)
        let data = module.cellsData[indexPath.row]
        let image = cellImage(at: indexPath)
        if data.subtype == .artist {
            guard let feed = JioTuneFeed(with: "jiotunepage.getArtistCallerTune", searchApi: "jiotunepage.getArtistCallerTuneFacet", data: data) else { return }
            let nextVC = JioTunesMenuVC(feed)
            nextVC.topSrcData = Util_n.currentVC().topSrcData
            parentVC.navigationController?.pushViewController(nextVC, animated: true)
        } else if data.subtype == .artistTune || data.subtype == .nameTune || data.subtype == .songTune{
            return
        } else {
            JioTuneUtil.loadView(of: data.type, from: data.originalJSON as [AnyHashable : Any],
                                 in: module, at: indexPath.item, via: parentVC, with: image)
        }
    }
    @objc private func cellLongPressed(_ gestureRecognizer: UILongPressGestureRecognizer) {
        guard let module = module else { return }
        let touchPoint = gestureRecognizer.location(in: collectionView)
        guard gestureRecognizer.state == .began,
            let indexPath = collectionView.indexPathForItem(at: touchPoint),
            !isViewMoreCell(at: indexPath) else { return }
        
        let data = module.cellsData[indexPath.item]
        if data.type == .menu || data.type == .category { return }
        if data.subtype == .artist || data.subtype == .artistTune || data.subtype == .nameTune { return }
        let image = cellImage(at: indexPath)
        ModalUtil.showOptions(forView: nil, withData: data.originalJSON, andTracking: nil, andImage: image)
        eventHandler?.longPress?(at: indexPath.item, in: module)
    }
}

extension JioTunesTableViewCell: UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        if isViewMoreCell(at: indexPath) { return viewAllSize }
        return cellSize
    }
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumLineSpacingForSectionAt section: Int) -> CGFloat {
        return viewMoreReverse() ? verticalItemSpacing : horizontalItemSpacing
    }
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumInteritemSpacingForSectionAt section: Int) -> CGFloat {
        return viewMoreReverse() ? horizontalItemSpacing : verticalItemSpacing
    }
    //FIXME: Somehow UICollectionViewFlowLayout Reversing behaviour of minimumLineSpacing and
    //minimumInteritemSpacing If cell size for ViewAll is different than Normal Cell
    //If you find reason for same, May remove this patch then..
    private func viewMoreReverse() -> Bool {
        if module?.scrollType.scrollDirection == UICollectionView.ScrollDirection.vertical { return true }
        if module?.viewMore == nil { return false }
        switch module?.scrollType {
        case .basic(.double), .condensed(.double), .wideScreen(.double), .carouselDescription, .myJioTune, .cellStandard: return true
        default: return false
        }
    }
}

//MARK:- EventHandler
extension JioTunesTableViewCell: EventHandler {
    func clickedInsideCell(at indexPath: IndexPath) {
        guard let module = module else { return }
        eventHandler?.didTapOnShortVideo?(at: indexPath.item, in: module)
    }
}

//MARK:- JioTuneCellStandard Protocol
extension JioTunesTableViewCell: JTStandardCellProtocol {
    var sectionDetails: [String : Any] {
        var sectionDetails = cellStandardDelegate?.sectionDetails ?? [:]
        sectionDetails["sec_title"] = module?.header?.title
        sectionDetails["type"] = module?.originalJSON["scroll_type"]
        sectionDetails["sec_pos"] = module?.position
        return sectionDetails
    }
    
    var bottomSource: [String : Any] {
        let bottomSource = cellStandardDelegate?.bottomSource ?? [:]
        return bottomSource
    }
    
    var eventParams: [String : Any] {
        let playerEventDict = cellStandardDelegate?.eventParams ?? [:]
        return playerEventDict
    }
}

//MARK:- Helpers
extension JioTunesTableViewCell {
    private func setupUI() {
        self.updateUIMode()
        self.collectionView.contentInset = insets
        setupGestures()
        
    }
    
    private func updateUI() {
        setupCollectionView()
        updateConstants()
        collectionView.reloadData()
        collectionView.contentOffset = self.contentOffset
        longPressGesture.isEnabled = self.module?.scrollType.isLongPressEnable ?? false
    }
    
    private func setupGestures() {
        longPressGesture.requiresExclusiveTouchType = true
        collectionView.addGestureRecognizer(longPressGesture)
    }
    
    private func setupCollectionView() {
        guard let module = module else { return }
        let layout = UICollectionViewFlowLayout()
        layout.scrollDirection = module.scrollType.scrollDirection
        if (module.scrollType.scrollDirection == .vertical) { collectionView.isScrollEnabled = false }
        collectionView.collectionViewLayout = layout
        cellId = module.scrollType.cellType.reuseId
//        module.scrollType.registerNib(for: collectionView)
		let mainCellType = module.scrollType.cellType
		module.scrollType.registerNibs(in: collectionView, from: [mainCellType, .viewAll, .viewAllVertical])
        let bundle = Bundle.init(for: JioTuneCellStandard.self)
        if let _ = module.viewMore {
            if module.scrollType.scrollDirection == .vertical {
                let nib = UINib(nibName: "\(ViewAllCellVertical.self)", bundle: bundle)
                collectionView.register(nib, forCellWithReuseIdentifier: CellType.viewAllVertical.reuseId)
            } else {
                let nib = UINib(nibName: "\(ViewAllCell.self)", bundle: bundle)
                collectionView.register(nib, forCellWithReuseIdentifier: CellType.viewAll.reuseId)
            }
        }
        let nib = UINib(nibName: "\(JioTuneCellStandard.self)", bundle: bundle)
        self.collectionView.register(nib, forCellWithReuseIdentifier: CellType.cellStandard.reuseId)
        let nibBasicCell = UINib(nibName: "\(BasicCell.self)", bundle: bundle)
        self.collectionView.register(nibBasicCell, forCellWithReuseIdentifier: CellType.basic(.title).reuseId)
        self.collectionView.register(nibBasicCell, forCellWithReuseIdentifier: CellType.condensed(.title).reuseId)
        self.collectionView.register(nibBasicCell, forCellWithReuseIdentifier: CellType.wideScreen(.title).reuseId)
        let nibCustomTextOverlayCell  = UINib(nibName: "\(CustomTextOverlayCell.self)", bundle: bundle)
        self.collectionView.register(nibCustomTextOverlayCell, forCellWithReuseIdentifier: CellType.customTextOverlay.reuseId)
        let nibMultipleItemCell  = UINib(nibName: "\(MultipleItemCell.self)", bundle: bundle)
        self.collectionView.register(nibMultipleItemCell, forCellWithReuseIdentifier: CellType.standard.reuseId)        
        let nibArtistCell  = UINib(nibName: "\(JioTuneArtistCell.self)", bundle: bundle)
        self.collectionView.register(nibArtistCell, forCellWithReuseIdentifier: CellType.jioTuneArtist.reuseId)
        let nibMyJiotuneCell  = UINib(nibName: "\(MyJioTuneCell.self)", bundle: bundle)
        self.collectionView.register(nibMyJiotuneCell, forCellWithReuseIdentifier: CellType.myJioTune.reuseId)
        
        let nibTextOverlayCell  = UINib(nibName: "\(TextOverlayCell.self)", bundle: bundle)
        self.collectionView.register(nibTextOverlayCell, forCellWithReuseIdentifier: CellType.textOverlay.reuseId)
        
    }
    
    private func updateConstants() {
        guard let module = module else { resetConstants(); return }
        verticalItemSpacing = module.scrollType.verticalItemSpacing
        horizontalItemSpacing = module.scrollType.horizontalItemSpacing
        let collectionViewWidth = collectionView.bounds.size.width
        cellSize = module.scrollType.cellSize(for: collectionView.contentInset, of: collectionViewWidth)
        viewAllSize = module.scrollType.viewAllSize(for: collectionView.contentInset, of: collectionViewWidth)
    }
    
    private func resetConstants() {
        verticalItemSpacing = 0
        horizontalItemSpacing = 0
        cellSize = .zero
        viewAllSize = .zero
    }
    
    private func isViewMoreCell(at indexPath: IndexPath) -> Bool {
        guard let module = module else { return false }
        return indexPath.item == module.cellsData.count && module.viewMore != nil
    }
    
    private func cellImage(at indexPath: IndexPath) -> UIImage? {
        let cell = collectionView.cellForItem(at: indexPath) as! BaseModuleCell
        return cell.imageForCTA
    }
}
