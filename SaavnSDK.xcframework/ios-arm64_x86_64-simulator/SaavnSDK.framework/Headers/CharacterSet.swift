//
//  CharacterSet.swift
//  Saavn
//
//  Created by Kautsya Kanu on 15/01/21.
//  Copyright © 2021 Saavn. All rights reserved.
//

extension CharacterSet {
    static let saavnurlQueryAllowed: CharacterSet = {
        var allowedCharSet = CharacterSet.urlQueryAllowed
        allowedCharSet.remove(charactersIn: "?&=+")
        return allowedCharSet
    }()
}
