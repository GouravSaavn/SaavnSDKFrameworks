//
//  SearchEggs.h
//  Saavn
//
//  Created by Clint Balcom on 5/12/18.
//  Copyright © 2018 Saavn. All rights reserved.
//
@import UIKit;


@interface SearchEggs : NSObject


@property (nonatomic, strong) NSArray *eggs;


#pragma mark - Init
+ (SearchEggs *) singleton;

#pragma mark - System Eggs
+ (void) executeSystemCommand:(NSString *)commandStr;
+ (BOOL) isEasterEgg:(NSString *)commandStr;


@end

