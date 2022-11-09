//
//  UIColor.swift
//  Saavn
//
//  Created by Kautsya Kanu on 15/08/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

extension UIColor {
    @objc public convenience init?(rgbHex: String?) {
        guard let rgbHex = rgbHex, rgbHex.hasPrefix("#") else { return nil }
        let r, g, b: CGFloat
        
        let start = rgbHex.index(rgbHex.startIndex, offsetBy: 1)
        let hexColor = String(rgbHex[start...])
        let scanner = Scanner(string: hexColor)
        var hexNumber: UInt64 = 0
        if !scanner.scanHexInt64(&hexNumber) { return nil }
        
        r = CGFloat((hexNumber & 0xff0000) >> 16) / 255
        g = CGFloat((hexNumber & 0x00ff00) >> 8) / 255
        b = CGFloat(hexNumber & 0x0000ff) / 255
        self.init(red: r, green: g, blue: b, alpha: 1)
        return
    }
    
    ///Return a color in-between two colors at particular distance
    ///where ratio should lie between 0-1 inclusive.
    @objc func toColor(_ color: UIColor, at ratio: CGFloat) -> UIColor {
        switch ratio {
        case 0: return self
        case 1: return color
        default:
            var (r1, g1, b1, a1): (CGFloat, CGFloat, CGFloat, CGFloat) = (0, 0, 0, 0)
            var (r2, g2, b2, a2): (CGFloat, CGFloat, CGFloat, CGFloat) = (0, 0, 0, 0)
            guard self.getRed(&r1, green: &g1, blue: &b1, alpha: &a1) else { return self }
            guard color.getRed(&r2, green: &g2, blue: &b2, alpha: &a2) else { return self }

            return UIColor(red: CGFloat(r1 + (r2 - r1) * ratio),
                           green: CGFloat(g1 + (g2 - g1) * ratio),
                           blue: CGFloat(b1 + (b2 - b1) * ratio),
                           alpha: CGFloat(a1 + (a2 - a1) * ratio))
        }
    }
}
