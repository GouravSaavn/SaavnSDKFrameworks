//
//  MultipleItemCell.swift
//  Saavn
//
//  Created by Kautsya Kanu on 15/08/20.
//  Copyright © 2020 Saavn. All rights reserved.
//
import UIKit
//import SaavnSDK
class MultipleItemCell: BaseModuleCell {
    enum ContentType { case basic, advanced }
    //MARK:- Properties
    var parentVC: SaavnVC_n!
    var contentType: ContentType = .basic
    //MARK:- Elements
    @IBOutlet private var baseContentView: UIView!
    @IBOutlet private var baseStackView: UIStackView!
    @IBOutlet private var infoBackgroundView: UIView!
    @IBOutlet private var imageView: UIImageView!
    @IBOutlet private var bookmarkView: BadgeView!
    @IBOutlet private var titleLabel: UILabel!
    @IBOutlet private var subTitleBadgeView: BadgeView!
    @IBOutlet private var descriptionLabel: UILabel!
    @IBOutlet private var secondOptionButton: UIButton!
    @IBOutlet private var moreOptionsButton: UIButton!
    @IBOutlet private var rightsTagLabel: UILabel!
    //MARK:- Constants
    private let subTitleFont = Font_n.itemMeta()!
    private let settings = Settings.singleton()!
    private let library = MyLibraryManager.shared()!
    
    override func updateUIMode() {
        super.updateUIMode()
        setupColors()
    }
    override func setupFonts() {
        titleLabel.font = Font_n.itemTitle()
        descriptionLabel.font = subTitleFont
        rightsTagLabel.font = subTitleFont
    }
    override func setupLayers() {
        curveRect()
        imageView.curveRect()
    }
    override func setupUI() {
        super.setupUI()
        setupStackView()
        hideAll()
    }
    override var imageForCTA: UIImage? {
        return imageView.image
    }
    // Refreshing according to Data
    override func refreshView() {
        titleLabel.text = data?.title
        descriptionLabel.attributedText = data?.attributedSubTitle(for: subTitleFont)
        Util_n.loadImageSwift(from: (data?.moreInfo?.squareImageLink ?? data?.imageLink), in: imageView)
        setupOptions()
        setupBookmark()
        setupPlayingState()
        setupAvailability()
    }
}

//MARK:- IBActions
extension MultipleItemCell {
    @IBAction func SecondMoreOptionsTapped() {
        guard let data = data else { return }
        switch settings.cellSecondOption {
        case CSO_Download:
            UserData.cacheSongs([data.originalJSON], via: parentVC)
            if !data.cachable { return }
            subTitleBadgeView.badgeType = .download(.pending)
            secondOptionButton.isHidden = true
        default: break
        }
    }
    @IBAction func MoreOptionsTapped() {
        ModalUtil.showOptions(data?.originalJSON, with: imageView.image)
    }
}

//MARK:- Helpers
extension MultipleItemCell {
    private func setupOptions() {
        guard let data = data, contentType != .basic else { hideAll(); return }
        moreOptionsButton.isHidden = false
        moreOptionsButton.setImage(#imageLiteral(resourceName: "Empty More").withRenderingMode(.alwaysTemplate), for: .normal)
        let objcSongStatus = SongUtil.checkLocalCacheState(data.originalJSON)
        let currentSongStatus = BadgeView.DownloadStatus(rawValue: Int(objcSongStatus)) ?? .none
        subTitleBadgeView.badgeType = .download(currentSongStatus)
        
        let option = Settings.singleton()!.cellSecondOption
        switch option {
        case CSO_Download:
            //Hiding secondOptionButton Of Downlaod if Song is in Pending, Downloading or Completed
            secondOptionButton.setImage(#imageLiteral(resourceName: "Icon Download").withRenderingMode(.alwaysTemplate), for: .normal)
            secondOptionButton.isHidden = currentSongStatus != .none
        default:
            secondOptionButton.isHidden = true
        }
    }
    private func setupBookmark() {
        guard let data = data, contentType != .basic else { return }
        bookmarkView.badgeType = .playState(data.playingState)
    }
    private func setupPlayingState() {
        guard let data = data, contentType != .basic else { return }
        titleLabel.textColor = data.isPlaying ? Styles_n.highlightColor() : Styles_n.itemTitleColor()
    }
    private func setupAvailability() {
        guard let data = data, contentType != .basic else { return }
        switch data.availability {
        case .unavailable, .expilictOff, .proOnly:
            hideAll()
            imageView.isHidden = data.availability != .expilictOff
            rightsTagLabel.isHidden = false
            titleLabel.textColor = Styles_n.unavailableColor()
            descriptionLabel.textColor = Styles_n.unavailableColor()
            rightsTagLabel.textColor = data.availability == .proOnly ?
                Styles_n.highlightColor() : Styles_n.unavailableColor()
            rightsTagLabel.text = data.availability.sideMessage
        default:
            imageView.isHidden = false
            rightsTagLabel.isHidden = true
            titleLabel.textColor = Styles_n.itemTitleColor()
            descriptionLabel.textColor = Styles_n.itemMetaColor()
            //Required Because Title color updated and setupPlayingState was called before
            //in refreshView, Cannot Setup Playing State afterwards because UnAvailability
            //should overwrite playing state(highlight color)
            setupPlayingState()
        }
    }
    //Other Setup
    private func hideAll() {
        bookmarkView.badgeType = .none
        subTitleBadgeView.badgeType = .none
        secondOptionButton.isHidden = true
        moreOptionsButton.isHidden = true
        rightsTagLabel.isHidden = true
    }
    private func setupColors() {
        baseContentView.backgroundColor = Styles_n.bgColor()
        infoBackgroundView.backgroundColor = Styles_n.bgColor()
        imageView.backgroundColor = Styles_n.subtleColor()
        titleLabel.textColor = Styles_n.itemTitleColor()
        titleLabel.backgroundColor = Styles_n.bgColor()
        descriptionLabel.textColor = Styles_n.itemMetaColor()
        descriptionLabel.backgroundColor = Styles_n.bgColor()
        secondOptionButton.backgroundColor = Styles_n.bgColor()
        secondOptionButton.tintColor = Styles_n.itemMetaColor()
        moreOptionsButton.backgroundColor = Styles_n.bgColor()
        moreOptionsButton.tintColor = Styles_n.itemMetaColor()
        rightsTagLabel.backgroundColor = Styles_n.bgColor()
        rightsTagLabel.textColor = Styles_n.itemMetaColor()
    }
    private func setupStackView() {
        if #available(iOS 11.0, *) {
            baseStackView.setCustomSpacing(10, after: imageView)
        } else {
            // Fallback on earlier versions
        }
    }
}
