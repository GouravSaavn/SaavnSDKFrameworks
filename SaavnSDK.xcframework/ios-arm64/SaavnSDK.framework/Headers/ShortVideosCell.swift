//
//  ShortVideosCell.swift
//  Saavn
//
//  Created by Kautsya Kanu on 15/09/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

class ShortVideosCell: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var mainImageView: UIImageView!
    @IBOutlet private var centreImageContainer: UIView!
    @IBOutlet private var centreImageView: UIImageView!
    @IBOutlet private var blurView: UIVisualEffectView!
    @IBOutlet private var censorEye: UIImageView!
    @IBOutlet private var userImageView: UIImageView!
    @IBOutlet private var userNameLabel: UILabel!
    @IBOutlet private var onPartnerButton: UIButton!
    @IBOutlet private var arrowImageView: UIImageView!
    @IBOutlet private var partnerWatermarkImageView: UIImageView!
    
    //MARK:- Properties
    override var moduleSectionData: Module? {
        didSet { refreshData() }
    }
    
    override func updateUIMode() {
        super.updateUIMode()
        mainImageView.backgroundColor = Styles_n.subtleColor()
        centreImageContainer.backgroundColor = .clear
        centreImageContainer.layer.borderColor = UIColor.white.cgColor
        userImageView.backgroundColor = Styles_n.subtleColor()
        userNameLabel.textColor = Styles_n.itemTitleColor()
        userNameLabel.backgroundColor = Styles_n.bgColor()
        onPartnerButton.backgroundColor = Styles_n.bgColor()
        onPartnerButton.setTitleColor(UIColor(rgbHex: moduleSectionData?.extraData?.bgColor), for: .normal)
        arrowImageView.tintColor = UIColor(rgbHex: moduleSectionData?.extraData?.bgColor)
    }
    override func setupFonts() {
        userNameLabel.font = Font_n.itemTitle()
		onPartnerButton.titleLabel?.font = Font_n.itemMeta()
    }
    override func setupLayers() {
        curveRect(to: 4)
        mainImageView.curveRect()
        centreImageContainer.circular()
        centreImageContainer.layer.borderWidth = 2
        centreImageView.circular()
        userImageView.circular()
        let color = Styles_n.getCustomColor(COLOR_NAAVY)!
        mainImageView.addGradiant(of: [color.withAlphaComponent(0), color],
                                  from: .pos(.top, .mid), to: .pos(.bottom, .mid), shouldRasterize: false)
    }
    override var imageForCTA: UIImage? {
        return mainImageView.image
    }
    override func refreshView() {
        if let name = data?.moreInfo?.shortVideos?.name, !name.isEmpty {
            userNameLabel.text = name
        } else {
            userNameLabel.text = data?.title
        }
        if data?.isExplicit == false {
            blurView.isHidden = true
            censorEye.isHidden = true
        }
        Util_n.loadImageSwift(from: data?.moreInfo?.shortVideos?.image, in: mainImageView)
        Util_n.loadImageSwift(from: data?.imageLink, in: centreImageView)
        Util_n.loadImageSwift(from: data?.moreInfo?.shortVideos?.userImage, in: userImageView)
        userImageView.isHidden = data?.moreInfo?.shortVideos?.userImage.isEmpty ?? true
    }
    private func refreshData() {
        onPartnerButton.setTitle(moduleSectionData?.extraData?.logoSubtext, for: .normal)
        onPartnerButton.setTitleColor(UIColor(rgbHex: moduleSectionData?.extraData?.bgColor), for: .normal)
        arrowImageView.image = UIImage(named: "small_arrow")?.withRenderingMode(.alwaysTemplate)
        arrowImageView.tintColor = UIColor(rgbHex: moduleSectionData?.extraData?.bgColor)
        
        Util_n.loadImageSwift(from: moduleSectionData?.extraData?.logoUrl, in: partnerWatermarkImageView) {
            self.partnerWatermarkImageView.image = self.partnerWatermarkImageView.image?.withRenderingMode(.alwaysTemplate)
            self.partnerWatermarkImageView.tintColor = .white
        }
        partnerWatermarkImageView.alpha = 0.5
    }
}

extension ShortVideosCell {
	@IBAction private func onPartner() {
        let appUrl = URL(string: moduleSectionData?.extraData?.appLink ?? "")!
        if UIApplication.shared.canOpenURL(appUrl) {
            UIApplication.shared.open(appUrl, options: [:], completionHandler: nil)
        }
		if let indexPath = indexPath { eventHandler?.clickedInsideCell?(at: indexPath) }
	}
}
