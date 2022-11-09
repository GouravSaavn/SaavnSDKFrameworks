//
//  UIImage.swift
//  Saavn
//
//  Created by Kautsya Kanu on 14/12/20.
//  Copyright © 2020 Saavn. All rights reserved.
//
import UIKit
extension UIImage {
    func resize(to size: CGSize) -> UIImage {
        let imageRenderer = UIGraphicsImageRenderer(size: size, format: imageRendererFormat)
        let reducedImage = imageRenderer.image { _ in
            draw(in: CGRect(origin: .zero, size: size))
        }
        return reducedImage
    }
    /// Given a required width, returns a (rasterised) copy
    /// of the image, aspect-fitted to that width.
    func aspectFittedTo(_ newWidth: CGFloat) -> UIImage {
        let scale = newWidth / self.size.width
        let newHeight = self.size.height * scale
        let newSize = CGSize(width: newWidth, height: newHeight)
        let renderer = UIGraphicsImageRenderer(size: newSize)
        
        return renderer.image { _ in
            self.draw(in: CGRect(origin: .zero, size: newSize))
        }
    }
    func copy(alpha: CGFloat) -> UIImage? {
        UIGraphicsBeginImageContextWithOptions(size, false, scale)
        draw(at: CGPoint.zero, blendMode: .normal, alpha: alpha)
        let newImage = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return newImage
    }
    func addImagePadding(x: CGFloat, y: CGFloat) -> UIImage? {
        let width: CGFloat = size.width + x
        let height: CGFloat = size.height + y
        UIGraphicsBeginImageContextWithOptions(CGSize(width: width, height: height), false, 0)
        let origin: CGPoint = CGPoint(x: (width - size.width) / 2, y: (height - size.height) / 2)
        draw(at: origin)
        let imageWithPadding = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return imageWithPadding
    }
}
