//
//  CustomTextOverlayCell.swift
//  Saavn
//
//  Created by Nitin Yadav on 22/9/2021.
//  Copyright © 2021 Saavn. All rights reserved.
//

final class CustomTextOverlayCell: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var titleLabel: UILabel!
    @IBOutlet private var imageContainerView: UIView!
    @IBOutlet private var imageView: UIImageView!
    
    override func updateUIMode() {
        super.updateUIMode()
        titleLabel.textColor = .white
        imageContainerView.backgroundColor = .clear
//        imageView.backgroundColor = Styles_n.subtleColor()
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
        setupImageView()
    }
}

//MARK:- Helpers
extension CustomTextOverlayCell {
    private func setupImageView() {
        Util_n.loadImageSwift(from: data?.imageLink, in: imageView) {
            self.setupBackgroundColor()
        }
        imageView.transform = imageView.transform.rotated(by: -1*(.pi/18))
    }
    private func setupBackgroundColor() {
        let colors = Util_n.getColorsFor(imageView.image)
        self.contentView.backgroundColor = (colors?.first as? UIColor)?.withAlphaComponent(0.5)
    }
}
