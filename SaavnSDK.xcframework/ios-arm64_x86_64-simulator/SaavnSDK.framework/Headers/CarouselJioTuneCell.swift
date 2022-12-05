//
//  CarouselJioTuneCell.swift
//  Saavn
//
//  Created by Nitin Yadav on 24/5/2021.
//  Copyright © 2021 Saavn. All rights reserved.
//

import UIKit

class CarouselJioTuneCell: BaseModuleCell {
    //MARK:- Elements
    @IBOutlet private var imageView: UIImageView!
    
    override func updateUIMode() {
        backgroundColor = Styles_n.bgColor()
    }
    override func setupLayers() {
        layer.cornerRadius = 16
    }
    override func refreshView() {
        Util_n.loadImage(data?.imageLink, in: imageView)
        updateUIMode()
    }
}
