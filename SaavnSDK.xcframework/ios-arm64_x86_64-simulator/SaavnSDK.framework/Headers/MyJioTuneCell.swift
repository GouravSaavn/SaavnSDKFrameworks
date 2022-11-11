//
//  MyJioTuneCell.swift
//  Saavn
//
//  Created by Nitin Yadav on 11/5/2021.
//  Copyright © 2021 Saavn. All rights reserved.
//

final class MyJioTuneCell: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var titleLabel: UILabel!
    @IBOutlet private var subtitleLabel: UILabel!
    @IBOutlet private var imageView: UIImageView!
    @IBOutlet private var customButton: LoaderButton!
    
    override func updateUIMode() {
        super.updateUIMode()
        backgroundColor = Styles_n.bgColor()
        setupColors()
        imageView.backgroundColor = Styles_n.subtleColor()
    }
    override func setupFonts() {
        titleLabel.font = Font_n.size(14, atWeight: Font_Semibold)
        subtitleLabel.font = Font_n.size(13, atWeight: Font_Normal)
        customButton.titleLabel?.font = Font_n.size(11, atWeight: Font_Bold)
    }
    override var imageForCTA: UIImage? {
        return imageView.image
    }
    override func refreshView() {
        titleLabel.text = data?.title
        subtitleLabel.text = data?.subTitle
        setupImages()
        updateUIMode()
    }
    override func setupLayers() {
        curveRect()
        imageView.curveRect()
        customButton.curveRect(to: 14)
    }
    private func setupColors() {
        imageView.backgroundColor = Styles_n.subtleColor()
        titleLabel.textColor = Styles_n.itemTitleColor()
        subtitleLabel.textColor = Styles_n.itemMetaColor()
//        customButton.backgroundColor = Settings.singleton().isDarkMode ? UIColor(rgb: 0x30343d) : UIColor(rgb: 0xE9E9E9)
//        customButton.setTitleColor(Styles_n.highlightColor(), for: .normal)
        customButton.backgroundColor = Styles_n.highlightColor()
        
        customButton.setTitleColor(UIColor(rgb: 0xE9E9E9), for: .normal)

        customButton.addTarget(self, action: #selector(removeJiotune), for: .touchUpInside)
    }
    private func setupImages() {
        guard let data = data as? JioTuneModuleCell,
              let type = data.subtype
        else { return }
        switch type {
        case .artistTune:
            imageView.circular()
            Util_n.loadImage(data.imageLink, in: imageView)
        case .nameTune:
            imageView.circular()
            let nameImage = data.title[0].imageWithString(textColor: .white, backgroundColor: Styles_n.highlightColor(), imageFrame: imageView.frame)
            imageView.image = nameImage
        case .songTune:
            Util_n.loadImage(data.imageLink, in: imageView)
        default:
            imageView.isHidden = true
        }
    }
    @objc private func removeJiotune(){
        
        NotificationCenter.default.post(name: NSNotification.Name(rawValue: "com.saavnSDK.remoteCurrentJioTuneTap"), object: nil)

    }
}
