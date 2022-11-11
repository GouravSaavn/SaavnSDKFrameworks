//
//  TopLanguagesCell.h
//  Saavn
//
//  Created by Clint Balcom on 5/27/18.
//  Copyright © 2018 Saavn. All rights reserved.
//


@class LanguageVC;


@interface TopLanguagesCell : UITableViewCell


#pragma mark - Init
- (instancetype) initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
                          inVC:(LanguageVC *)parentVC withLanguages:(NSArray *)languages andPreselections:(NSArray *)preselectedItems;

#pragma mark - Getters
+ (CGFloat) rowHeightFor:(NSArray *)langs;


@end

