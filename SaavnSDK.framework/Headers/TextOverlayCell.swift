//
//  TextOverlayCell.swift
//  Saavn
//
//  Created by Kautsya Kanu on 15/08/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

final class TextOverlayCell: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var titleLabel: UILabel!
    @IBOutlet var imageView: UIImageView!
    
    override func updateUIMode() {
        super.updateUIMode()
        titleLabel.textColor = .white
        imageView.backgroundColor = Styles_n.subtleColor()
    }
    override func setupFonts() {
        titleLabel.font = Font_n.simpleHeaderTitle()
    }
    override func setupLayers() {
        curveRect()
        imageView.curveRect()
    }
    override var imageForCTA: UIImage? {
        return imageView.image
    }
    override func refreshView() {
        titleLabel.text = data?.title
        Util_n.loadImage(data?.imageLink, in: imageView)
    }
}
