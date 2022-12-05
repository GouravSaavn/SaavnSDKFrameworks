//
//  JioTuneArtistCell.swift
//  Saavn
//
//  Created by Nitin Yadav on 24/5/2021.
//  Copyright © 2021 Saavn. All rights reserved.
//

final class JioTuneArtistCell: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var imageView: UIImageView!
    @IBOutlet private var titleLabel: UILabel!
    
    override func updateUIMode() {
        backgroundColor = Styles_n.bgColor()
        titleLabel.textColor = Styles_n.itemTitleColor()
    }
    override var imageForCTA: UIImage? {
        return imageView.image
    }
    override func refreshView() {
        titleLabel.text = data?.title
        Util_n.loadImage(data?.imageLink, in: imageView)
        updateUIMode()
    }
    override func setupFonts() {
        titleLabel.font = Font_n.itemTitle()
    }
    override func setupLayers() {
        imageView.circular()
    }
}
