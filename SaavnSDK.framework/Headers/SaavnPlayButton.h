//
//  SaavnPlayButton.h
//  New Saavn
//
//  Created by Clint Balcom on 1/25/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SaavnPlayButton : UIView


@property (nonatomic, strong) UIButton *button;


#pragma mark - Setters
// Size
- (void) useSmallSize;
// Style
- (void) setBtnColor:(UIColor *)color;
- (void) setBtnTapColor:(UIColor *)color;
- (void) setIconColor:(UIColor *)color;


@end

