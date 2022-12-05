//
//  NSDate.swift
//  Saavn
//
//  Created by Kautsya Kanu on 27/01/21.
//  Copyright © 2021 Saavn. All rights reserved.
//

extension Date {
    func inFormat(_ format: String) -> String? {
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = format
        return dateFormatter.string(from: self as Date)
    }
}
