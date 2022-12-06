//
//  NSData+AES256.h
//  Saavn
//
//  Created by Sriranjan on 7/25/11.
//  Copyright 2011 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSMutableData (NSMutableData_AES256)

- (BOOL) encryptWithKey: (NSString *) key keyPtrFlag: (BOOL) flag;
- (BOOL) decryptWithKey: (NSString *) key keyPtrFlag: (BOOL) flag;
- (BOOL) encrypt256WithKey: (NSString *) key;
- (BOOL) decrypt256WithKey: (NSString *) key;

@end
