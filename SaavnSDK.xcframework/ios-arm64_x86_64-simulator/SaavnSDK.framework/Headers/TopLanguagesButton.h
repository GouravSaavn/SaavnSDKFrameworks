//
//  TopLanguagesButton.h
//  Saavn
//
//  Created by Clint Balcom on 5/27/18.
//  Copyright © 2018 Saavn. All rights reserved.
//


typedef enum {
    // Default (Small Buttons)
    LangButton_Default = 0,
    
    // Large Button Options
    LangButton_Left = 1,
    LangButton_Right = 2,
    LangButton_Center = 3,
} LanguageButtonLayout;


@interface TopLanguagesButton : UIButton


@property (nonatomic) BOOL isLarge;
@property (nonatomic) NSUInteger column;
@property (nonatomic, strong) UIImageView *btnImage;
@property (nonatomic, strong) UILabel *btnLabel;


#pragma mark - Init
- (void) buildLayout:(LanguageButtonLayout)layout;


@end

