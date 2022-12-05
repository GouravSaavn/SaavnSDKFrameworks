//
//  Dictionary.swift
//  Saavn
//
//  Created by Kautsya Kanu on 19/08/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

extension Dictionary where Key==String, Value==String {
    func urlString() -> String {
        var output = "{"
        for (key,value) in self {
            output += "\"\(key)\":\"\(value)\""     // {"Key":"Value"}
        }
        output += "}"
        return output
    }
}
