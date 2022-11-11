//
//  String.swift
//  Saavn
//
//  Created by Kautsya Kanu on 31/08/20.
//  Copyright © 2020 Saavn. All rights reserved.
//


import Foundation
import UIKit

extension String {
    var boolValue: Bool {
        return (self as NSString).boolValue
    }
    var hexColor: UIColor? {
        return UIColor(rgbHex: self)
    }
    var snakeCased: String {
        let pattern = "([a-z])([0-9A-Z])"
        let regex = try? NSRegularExpression(pattern: pattern, options: [])
        let range = NSRange(location: 0, length: count)
        return regex?.stringByReplacingMatches(in: self, options: [], range: range, withTemplate: "$1_$2")
            .lowercased() ?? self
    }
    var htmlDecoded: String {
        let options: [NSAttributedString.DocumentReadingOptionKey: Any] = [
            .documentType: NSAttributedString.DocumentType.html,
            .characterEncoding: String.Encoding.utf8.rawValue
        ]
        if (self.isEmpty) { return self }
        guard let data = data(using: .utf8), let attributedString = try? NSAttributedString(data: data, options: options, documentAttributes: nil)
        else { return self }
        return attributedString.string
    }
    var attributedString: NSAttributedString {
        return NSAttributedString(string: self)
    }
    func htmlMutableAttributedString() -> NSMutableAttributedString {
        guard let data = self.data(using: .utf8)
        else { return NSMutableAttributedString(string: self) }
        guard let attributedString = try? NSMutableAttributedString(
            data: data,
            options: [.documentType: NSMutableAttributedString.DocumentType.html],
            documentAttributes: nil
        ) else {
            return NSMutableAttributedString(string: self)
        }
        return attributedString
    }
    func imageWithString(textColor: UIColor, backgroundColor: UIColor, imageFrame: CGRect) -> UIImage? {
         let frame = imageFrame
         let nameLabel = UILabel(frame: frame)
         nameLabel.textAlignment = .center
         nameLabel.backgroundColor = backgroundColor
         nameLabel.textColor = textColor
         nameLabel.font = UIFont.boldSystemFont(ofSize: frame.height*0.5)
         nameLabel.text = self
         UIGraphicsBeginImageContext(frame.size)
          if let currentContext = UIGraphicsGetCurrentContext() {
             nameLabel.layer.render(in: currentContext)
             let nameImage = UIGraphicsGetImageFromCurrentImageContext()
             return nameImage
          }
          return nil
    }
    subscript(i: Int) -> String {
        return String(self[index(startIndex, offsetBy: i)])
    }
}

extension Optional where Wrapped == String {
    var boolValue: Bool {
        return self?.boolValue ?? false
    }
    ///It can be nil but would not be empty..
    ///so that even empty case can be handled using nil coalescing
    var nonEmpty: String? {
        return self?.isEmpty ?? true ? nil:self
    }
}

extension NSString {
	@objc public var nsHtmlDecoded: NSString {
		let string: String = self as String
		return string.htmlDecoded as NSString
	}
    @objc func stringByAddingPercentEncodingForRFC3986() -> String? {
        let unreserved = "-._~/?"
        let allowed = NSMutableCharacterSet.alphanumeric()
        allowed.addCharacters(in: unreserved)
        return addingPercentEncoding(withAllowedCharacters: allowed as CharacterSet)
    }
}
