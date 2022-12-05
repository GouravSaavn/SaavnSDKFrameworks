//
//  UIButton.swift
//  Saavn
//
//  Created by Kautsya Kanu on 01/09/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

extension UIButton {
    func popAnimate() {
        transform = CGAffineTransform(scaleX: 0.5, y: 0.5)
        UIView.animate(withDuration: 1.0, delay: 0, usingSpringWithDamping: 0.25,
                       initialSpringVelocity: 5.0, options: .allowUserInteraction, animations: {
                        [weak self] in
                        self?.transform = .identity
        }, completion: nil)
    }
}
