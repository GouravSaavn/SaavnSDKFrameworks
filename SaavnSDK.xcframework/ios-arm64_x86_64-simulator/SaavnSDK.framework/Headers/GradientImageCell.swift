//
//  GradientImageCell.swift
//  Saavn
//
//  Created by Kautsya Kanu on 22/09/20.
//  Copyright © 2020 Saavn. All rights reserved.
//
import UIKit
import SDWebImage
class GradientImageCell: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var outerView: UIView!
    @IBOutlet private var midView: UIView!
    @IBOutlet private var imageView: UIImageView!
    @IBOutlet private var titleLabel: UILabel!
    
    override func updateUIMode() {
        super.updateUIMode()
        titleLabel.textColor = Styles_n.itemTitleColor()
    }
    override func setupFonts() {
        titleLabel.font = Font_n.itemTitle()
    }
    override func setupLayers() {
        outerView.circular()
        midView.circular()
        imageView.circular()
    }
    override var imageForCTA: UIImage? {
        return imageView.image
    }
    override func refreshView() {
        outerView.addGradiant(of: [.white, .black], from: .pos(.top, .left), to: .pos(.bottom, .right))
        midView.addGradiant(of: [.white, .black], from: .pos(.bottom, .right), to: .pos(.top, .left))
        imageView.sd_setImage(with: URL(string: data?.imageLink ?? ""), completed: nil)
        titleLabel.text = data?.title
        
    }
}
