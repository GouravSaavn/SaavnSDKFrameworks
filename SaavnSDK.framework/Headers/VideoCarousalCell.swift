//
//  VideoCarousalCell.swift
//  Saavn
//
//  Created by Kautsya Kanu on 15/09/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

class VideoCarousalCell: BaseModuleCell, VideoRateCapStateProtocol {
    //MARK:- Elements
    //parental control blur
    @IBOutlet private var blurView: UIVisualEffectView!
    @IBOutlet private var videoThumbnailImageView: UIImageView!
    @IBOutlet private var eyeView: UIImageView!
    //Bottom Left StackView
    @IBOutlet private var songArtContainerView: UIView!
    @IBOutlet private var songArtImageView: UIImageView!
    @IBOutlet private var lockImageView: UIImageView!
    @IBOutlet private var titleLabel: UILabel!
    @IBOutlet private var contentRating: UIImageView!
    @IBOutlet private var contentRatingWidth: NSLayoutConstraint!
    @IBOutlet private var descriptionLabel: UILabel!
    //Bottom Right StackView
    @IBOutlet private var firstPrimaryArtistImageView: UIImageView!
    @IBOutlet private var moreArtistCountLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        registerForVideoRateCapReachedNotification()
    }
    override func updateUIMode() {
        super.updateUIMode()
        videoThumbnailImageView.backgroundColor = Styles_n.subtleColor()
    }
    override func setupLayers() {
        curveRect()
        videoThumbnailImageView.curveRect()
        
        songArtContainerView.circular()
        songArtContainerView.layer.borderWidth = 2
        songArtContainerView.layer.borderColor = UIColor.white.cgColor
        songArtImageView.circular()
        
        firstPrimaryArtistImageView.circular()
        videoThumbnailImageView.addGradiant(of: [UIColor.black.withAlphaComponent(0), .black],
                                            from: .pos(.mid, .mid), to: .pos(.bottom, .mid),
                                            shouldRasterize: true)
    }
    override var imageForCTA: UIImage? {
        return videoThumbnailImageView.image
    }
    override func refreshView() {
        Util_n.loadImageSwift(from: data?.moreInfo?.thumbnailUrl, in: videoThumbnailImageView)
        setParentalControl()
        //Bottom Left StackView
        songArtContainerView.isHidden = data?.imageLink == nil
        Util_n.loadImageSwift(from: data?.imageLink, in: songArtImageView)
        setProBadge()
        titleLabel.text = data?.title
        descriptionLabel.text = MediaUtil_n.meta(for: data?.originalJSON, in: MetaStyle_ROW_PLAYER)
        //Bottom Right StackView
        let primaryArtists = data?.moreInfo?.artistMap?.primaryArtists ?? []
        firstPrimaryArtistImageView.isHidden = primaryArtists.count == 0
        Util_n.loadImageSwift(from: primaryArtists.first?.image, in: firstPrimaryArtistImageView, withCompletion:{
            self.moreArtistCountLabel.isHidden = primaryArtists.count < 2
            self.moreArtistCountLabel.text = "+\(primaryArtists.count - 1)"
        })
    }
    func videoRateCapReached() {
        setProBadge()
    }
    deinit {
        deRegisterForVideoRateCapReachedNotification()
    }
}

//MARK:- Helpers
extension VideoCarousalCell {
    private func setProBadge() {
        if UserData.isUserFullPro() {
            lockImageView.isHidden = true
        } else if UserData.getSingleton()!.isFreeLimitReached() {
            lockImageView.isHidden = false
        } else{
            if let rights = data?.moreInfo?.rights {
                let code = rights.code
                if code == 0 {//Not Pro Only
                    if let videoRateCap = data?.moreInfo?.videoRateCap, videoRateCap != 0{
                        lockImageView.isHidden = true//Do not Tag Pro
                    }else{
                        lockImageView.isHidden = false//Tag Pro
                    }
                } else {//Pro Only
                    lockImageView.isHidden = false
                }
            } else{// Default
                lockImageView.isHidden = true
            }
        }
    }
    
    private func setParentalControl() {
        if (data?.isExplicit == true && Settings.singleton().disableExplicit) {
            eyeView.isHidden = false
            blurView.isHidden = false
        } else {
            blurView.isHidden = true
            eyeView.isHidden = true
        }
        // content rating
        if (data?.moreInfo?.contentCategory == "U") {
            contentRating.image = UIImage(named: "Tag U")
            contentRatingWidth.constant = 15
        } else if (data?.moreInfo?.contentCategory == "U/A 7+") {
            contentRating.image = UIImage(named: "Tag U:A 7+")
            contentRatingWidth.constant = 38
        } else if (data?.moreInfo?.contentCategory == "U/A 13+") {
            contentRating.image = UIImage(named: "Tag U:A 13+")
            contentRatingWidth.constant = 44
        } else if (data?.moreInfo?.contentCategory == "U/A 16+") {
            contentRating.image = UIImage(named: "Tag U:A 16+")
            contentRatingWidth.constant = 44
        } else if (data?.moreInfo?.contentCategory == "A") {
            contentRating.image = UIImage(named: "Tag A")
            contentRatingWidth.constant = 15
        } else {
            if (data?.isExplicit == true) {
                contentRating.image = UIImage(named: "Tag A")
                contentRatingWidth.constant = 15
            } else {
                contentRating.image = UIImage(named: "Tag U")
                contentRatingWidth.constant = 15
            }
        }
    }
    
}


