//
//  NSLayoutConstraint.swift
//  Saavn
//
//  Created by Kautsya Kanu on 25/08/20.
//  Copyright © 2020 Saavn. All rights reserved.
//
import UIKit
extension NSLayoutConstraint {
    func setMultiplier(_ multiplier:CGFloat) -> NSLayoutConstraint {
        NSLayoutConstraint.deactivate([self])
        let newConstraint = NSLayoutConstraint(
            item: firstItem as Any,
            attribute: firstAttribute,
            relatedBy: relation,
            toItem: secondItem,
            attribute: secondAttribute,
            multiplier: multiplier,
            constant: constant)

        newConstraint.priority = priority
        newConstraint.shouldBeArchived = shouldBeArchived
        newConstraint.identifier = identifier

        NSLayoutConstraint.activate([newConstraint])
        return newConstraint
    }
}
