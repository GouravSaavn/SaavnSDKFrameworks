//
//  CarousalDescriptionCell.swift
//  Saavn
//
//  Created by Kautsya Kanu on 15/08/20.
//  Copyright © 2020 Saavn. All rights reserved.
//
import UIKit

final class CarousalDescriptionCell: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var titleLabel: UILabel!
    @IBOutlet private var descriptionLabel: UILabel!
    @IBOutlet var imageView: UIImageView!
    
    override func updateUIMode() {
        let bgColor = data?.moreInfo?.backgroundColor?.hexColor ?? Styles_n.subtleColor()
        backgroundColor = bgColor
        titleLabel.textColor = .white
        titleLabel.backgroundColor = bgColor
        descriptionLabel.textColor = .white
        descriptionLabel.backgroundColor = bgColor
        imageView.backgroundColor = bgColor
    }
    override func setupFonts() {
        titleLabel.font = Font_n.headerTitle()
        descriptionLabel.font = Font_n.detailHeaderMeta()
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
        descriptionLabel.text = data?.moreInfo?.description
        Util_n.loadImage(data?.moreInfo?.squareImageLink, in: imageView)
        updateUIMode()
    }
}
