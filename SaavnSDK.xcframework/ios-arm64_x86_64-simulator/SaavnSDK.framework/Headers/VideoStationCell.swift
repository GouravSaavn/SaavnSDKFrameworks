//
//  VideoStationCell.swift
//  Saavn
//
//  Created by Kunal Arora on 03/03/21.
//  Copyright © 2021 Saavn. All rights reserved.
//

class VideoStationCell: BaseModuleCell, VideoRateCapStateProtocol {
    //MARK:- Elements
    @IBOutlet private var stationLabel: UILabel!
    @IBOutlet private var titleLabel: UILabel!
    @IBOutlet private var proBadgeImageView: UIImageView!
    @IBOutlet private var stationArtBackgroundView: UIView!
    @IBOutlet private var stationArtImageView: UIImageView!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        dropStaticShadows()
        registerForVideoRateCapReachedNotification()
    }
    override func updateUIMode() {
        backgroundColor = data?.moreInfo?.backgroundColor?.hexColor ?? Styles_n.subtleColor()
    }
    override func setupLayers() {
        curveRect(to: 4)
        stationArtImageView.curveRect(to: 4)
        stationArtBackgroundView.curveRect(to: 4)
    }
    override func refreshView() {
        stationLabel.text = data?.subTitle.uppercased()
        titleLabel.text = data?.title
        setProBadge()
        
        Util_n.loadImageSwift(from: data?.imageLink, in: stationArtImageView)
        addGradiant(of: data?.moreInfo?.gradientColorsArray ?? [.clear],
                    from: .pos(.top, .left), to: .pos(.bottom, .right))
    }
    func videoRateCapReached() {
        setProBadge()
    }
    deinit {
        deRegisterForVideoRateCapReachedNotification()
    }
}

//MARK:- Helpers
extension VideoStationCell {
    private func dropStaticShadows() {
        dropShadow(to: stationLabel)
        dropShadow(to: titleLabel)
    }
    private func dropShadow(to label: UILabel) {
        label.layer.shadowColor = #colorLiteral(red: 0, green: 0, blue: 0, alpha: 0.29)
        label.layer.shadowOffset = CGSize(width: 0, height: 2)
        label.layer.shadowRadius = 4
        label.layer.shadowOpacity = 0.7
    }
    
    private func setProBadge() {
        if UserData.isUserFullPro() {
            proBadgeImageView.isHidden = true
        } else if UserData.getSingleton()!.isFreeLimitReached() {
            proBadgeImageView.isHidden = false
        } else if let proOnly = data?.moreInfo?.proOnly, proOnly {
            proBadgeImageView.isHidden = false
        } else {
            proBadgeImageView.isHidden = true
        }
    }
}
