//
//  JioTuneCellStandard.swift
//  Saavn
//
//  Created by Nitin Yadav on 28/5/2021.
//  Copyright © 2021 Saavn. All rights reserved.
//
import UIKit
//import SaavnSDK

protocol JTStandardCellProtocol: JTPlayerEventRespondable {}

class JioTuneCellStandard: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var imageView: UIImageView!
    @IBOutlet private var titleLabel: UILabel!
    @IBOutlet private var subtitleLabel: UILabel!
    @IBOutlet private var buttonContainerView: UIView!
    @IBOutlet private var playButton: LoaderButton!
    @IBOutlet private var pauseButton: UIButton!
    @IBOutlet private var setButton: UIButton!
    @IBOutlet private var jtIconContainerView: UIView!
    @IBOutlet private var showJTPromptButton: UIButton!
    //MARK:- Properties
    var delegate: JTStandardCellProtocol?
    var parentVC: SaavnVC_n?
    private var entityName = ""
    private var isPreviewed = 0
    override func updateUIMode() {
        super.updateUIMode()
        backgroundColor = Styles_n.bgColor()
        setupColors()
        setupImages()
    }
    override func setupFonts() {
        titleLabel.font = Font_n.itemTitle()
        subtitleLabel.font = Font_n.itemMeta()
        setButton.titleLabel?.font = Font_n.size(11, atWeight: Font_Bold)
    }
    override func setupLayers() {
        playButton.circular()
        pauseButton.circular()
        setButton.curveRect(to: 14)
        curveRect()
        imageView.curveRect()
    }
    override func setupUI() {
        super.setupUI()
        buttonContainerView.isHidden = true
        playButton.isHidden = true
        pauseButton.isHidden = true
        jtIconContainerView.isHidden = true
    }
    override var imageForCTA: UIImage? {
        return imageView.image
    }
    // Refreshing according to Data
    override func refreshView() {
        titleLabel.text = data?.title
        subtitleLabel.text = data?.subTitle
        playButton.currentStatus = .normal
        Util_n.loadImageSwift(from: data?.imageLink, in: imageView)
        setupOptions()
        setupJioTuneIcon()
    }
    deinit {
        removeObservers()
    }
}

//MARK:- IBActions
extension JioTuneCellStandard {
    @IBAction func playButtonTapped() {
        playButton.currentStatus = .loading
        addObservers()
        entityName = "play_icon"
        isPreviewed = 1
        JioTunePlayer.shared.setNewTune((self.data as? JioTuneModuleCell)?.vlink ?? "")
        JioTunePlayer.shared.play(with: self, continuePlayback: true)
    }
    
    @objc private func startPlayingUI(notification: Notification) {
        guard let jioTune = notification.userInfo,
              let vlink = jioTune["vlink"] as? String,
              vlink == (self.data as? JioTuneModuleCell)?.vlink ?? ""
        else { return }
        playButton.currentStatus = .normal
        playButton.isHidden = true
        pauseButton.isHidden = false
    }
    
    @objc private func reloadIfOldCell(notification: Notification) {
        guard let oldJioTune = notification.userInfo,
              let oldVlink = oldJioTune["oldVlink"] as? String,
              oldVlink == (self.data as? JioTuneModuleCell)?.vlink ?? ""
        else { return }
        playButton.currentStatus = .normal
        playButton.isHidden = false
        pauseButton.isHidden = true
        removeObservers()
    }
    
    @objc private func updatePauseUI(notification: Notification) {
        guard let currentPlayingJioTune = notification.userInfo,
              let vlink = currentPlayingJioTune["vlink"] as? String,
              vlink == (self.data as? JioTuneModuleCell)?.vlink ?? ""
        else { return }
        pauseButtonTapped()
    }
    
    @IBAction func pauseButtonTapped() {
        removeObservers()
        playButton.currentStatus = .normal
        playButton.isHidden = false
        pauseButton.isHidden = true
        entityName = "pause_icon"
        JioTunePlayer.shared.pause(with: self)
    }
    @IBAction func setButtonTapped() {
        var eventParams: [AnyHashable: Any] = [:]
        var bottomSource: [AnyHashable: Any] = [:]
        var sectionDetails: [AnyHashable: Any] = [:]
        if delegate != nil {
            eventParams = delegate?.eventParams ?? [:]
            bottomSource = delegate?.bottomSource ?? [:]
            sectionDetails = delegate?.sectionDetails ?? [:]
            if let cellData = self.data as? JioTuneModuleCell {
                eventParams["vcode"] = cellData.vcode
                eventParams["jiotune_id"] = cellData.id
                eventParams["type"] = cellData.type
                eventParams["subtype"] = cellData.subtype
                eventParams["previewed"] = isPreviewed
            }
            bottomSource["entity_name"] = "Set"
            bottomSource["entity_type"] = "button"
        }
        let extraInfo = ["event_params": eventParams]
        let entityDict = bottomSource
        let screenName = (entityDict["screen_name"] as? String) ?? "JioTuneMenuVC"
        let trackingDict = Util_n.appendBottomSource(toDict: extraInfo, fromSection: sectionDetails,
                                               andEntity: entityDict, viaParent: parentVC, andScreen: screenName)
        trackingDict?.addEntries(from: Util_n.currentVC().topSrcData as? [AnyHashable : Any] ?? [:])
        JioUserManager.shared()?.setJioTune(data?.originalJSON,
                                            isRefresh: false,
                                            withVcode: (self.data as? JioTuneModuleCell)?.vcode, withTrackingDict: trackingDict as? [AnyHashable: Any])
    }
    @IBAction func showJioTunePrompt() {
        guard let data = self.data?.originalJSON
        else { return }
        ModalUtil.showJioTunesPrompt(data, inSection: sectionDetails, andImage: self.imageView.image)
    }
}

extension JioTuneCellStandard: JTPlayerEventRespondable {
    var sectionDetails: [String : Any] {
        return delegate?.sectionDetails ?? [:]
    }
    
    var bottomSource: [String : Any] {
        var bottomSource = delegate?.bottomSource ?? [:]
        bottomSource["entity_name"] = entityName
        bottomSource["entity_type"] = "button"
        return bottomSource
    }
    
    var eventParams: [String : Any] {
        var playerEventDict = delegate?.eventParams ?? [:]
        if let cellData = self.data as? JioTuneModuleCell {
            playerEventDict["vcode"] = cellData.vcode
            playerEventDict["jiotune_id"] = cellData.id
            playerEventDict["type"] = cellData.type
            playerEventDict["subtype"] = cellData.subtype
        }
        return playerEventDict
    }
}

//MARK:- Helpers
extension JioTuneCellStandard {
    private func setupOptions() {
        guard let data = data as? JioTuneModuleCell,
              let type = data.subtype
        else {
            buttonContainerView.isHidden = true
            jtIconContainerView.isHidden = true
            return
        }
        
        if let _ = self.data?.originalJSON as? [String: Any],
           (data.type == .song || data.type == .video),
           AppData.getSingleton().isJioTuneEnabled() {
            jtIconContainerView.isHidden = false
            return
        }
        if data.type != .jiotune {
            buttonContainerView.isHidden = true
            return
        }
        switch type {
        case .artist:
            buttonContainerView.isHidden = true
        case .nameTune, .artistTune:
            imageView.isHidden = true
            buttonContainerView.isHidden = false
            playButton.isHidden = false
            pauseButton.isHidden = true
            setButton.isHidden = false
            
            switch JioTunePlayer.shared.playerState {
            case .playerPlaying:
                if (JioTunePlayer.shared.currentVink == (self.data as? JioTuneModuleCell)?.vlink ?? "") {
                    playButton.currentStatus = .normal
                    playButton.isHidden = true
                    pauseButton.isHidden = false
                    addObservers()
                }
            case .playerBuffering:
                if (JioTunePlayer.shared.currentVink == (self.data as? JioTuneModuleCell)?.vlink ?? "") {
                    playButton.currentStatus = .loading
                    addObservers()
                }
            case .playerPaused, .playerDisposed:
                playButton.currentStatus = .normal
                playButton.isHidden = false
                pauseButton.isHidden = true
                removeObservers()
            }
        case .unknown, .songTune:
            buttonContainerView.isHidden = true
        }
    }
    private func setupColors() {
        imageView.backgroundColor = Styles_n.subtleColor()
        titleLabel.textColor = Styles_n.itemTitleColor()
        subtitleLabel.textColor = Styles_n.itemMetaColor()
        playButton.imageView?.tintColor = .white
        pauseButton.imageView?.tintColor = .white
        playButton.backgroundColor = Styles_n.highlightColor()
        pauseButton.backgroundColor = Styles_n.highlightColor()
        setButton.backgroundColor = Settings.singleton().isDarkMode ? UIColor(rgb: 0x30343d) : UIColor(rgb: 0xE9E9E9)
        setButton.setTitleColor(Styles_n.highlightColor(), for: .normal)
    }
    private func setupImages() {
        playButton.setImage(UIImage(named: "Mini Player Play",in:  Bundle(for: type(of:self)),
                                    compatibleWith: nil)!.withRenderingMode(.alwaysTemplate), for: .normal)
        pauseButton.setImage(UIImage(named: "Mini Player Pause",in:  Bundle(for: type(of:self)),
                                     compatibleWith: nil)!.withRenderingMode(.alwaysTemplate), for: .normal)
    }
    private func setupJioTuneIcon() {
        guard let data = self.data?.originalJSON as? [String: Any]
        else { return }
        if(SongUtil.isJioTuneAvailable(data)) {
            showJTPromptButton.setImage(UIImage(named: "Icon JioTune Available",in:  Bundle(for: type(of:self)),compatibleWith: nil)!.withRenderingMode(.alwaysTemplate), for: .normal)
            showJTPromptButton.imageView?.tintColor = Styles_n.highlightColor()
        } else {
            showJTPromptButton.setImage(UIImage(named: "Icon JioTune Unavailable",in:  Bundle(for: type(of:self)),compatibleWith: nil)!.withRenderingMode(.alwaysTemplate), for: .normal)
            showJTPromptButton.imageView?.tintColor = Styles_n.itemMetaColor()
        }
    }
    private func addObservers() {
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(startPlayingUI(notification: )),
                                               name: NSNotification.Name("JioTuneWillPlay"),
                                               object: nil)
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(reloadIfOldCell(notification: )),
                                               name: NSNotification.Name("JioTuneSet"),
                                               object: nil)
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(updatePauseUI(notification: )),
                                               name: NSNotification.Name("JioTunePaused"),
                                               object: nil)
    }
    private func removeObservers() {
        NotificationCenter.default.removeObserver(self, name: NSNotification.Name("JioTuneWillPlay"), object: nil)
        NotificationCenter.default.removeObserver(self, name: NSNotification.Name("JioTuneSet"), object: nil)
        NotificationCenter.default.removeObserver(self, name: NSNotification.Name("JioTunePaused"), object: nil)
    }
}
