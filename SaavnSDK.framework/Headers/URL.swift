//
//  URL.swift
//  NewsApp
//
//  Created by Kautsya Kanu on 03/01/20.
//  Copyright © 2020 Kautsya Kanu. All rights reserved.
//

extension URL {
    init?(string: String?) {
        guard let string = string else { return nil }
        self.init(string: string)
    }
    func isSafe() -> Bool {
        return self.absoluteString.starts(with: "https://")
    }
}
