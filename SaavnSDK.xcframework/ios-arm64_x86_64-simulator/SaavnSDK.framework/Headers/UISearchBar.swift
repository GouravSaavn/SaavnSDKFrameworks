//
//  UISearchBar.swift
//  Saavn
//
//  Created by Kautsya Kanu on 08/09/20.
//  Copyright © 2020 Saavn. All rights reserved.
//
import UIKit
extension UISearchBar {
    func setIcon(color: UIColor) {
        let iconView = textField?.leftView as? UIImageView
        iconView?.image = iconView?.image?.withRenderingMode(.alwaysTemplate)
        iconView?.tintColor = color
    }
}
