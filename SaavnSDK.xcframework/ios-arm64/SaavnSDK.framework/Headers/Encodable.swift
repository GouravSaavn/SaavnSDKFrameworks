//
//  Encodable.swift
//  Saavn
//
//  Created by Kautsya Kanu on 29/11/20.
//  Copyright © 2020 Saavn. All rights reserved.
//
import Foundation
extension Encodable {
    var dict: [AnyHashable: Any]? {
        do { let data = try JSONEncoder().encode(self)
            let jsonObject = try JSONSerialization.jsonObject(with: data, options: .allowFragments)
            if let jsonDict = jsonObject as? [AnyHashable: Any] {
                return jsonDict }
            else {
                NSLog("Encoding Fails")
                return nil }
        } catch let error {
            NSLog(error.localizedDescription)
            return nil
        }
    }
}
