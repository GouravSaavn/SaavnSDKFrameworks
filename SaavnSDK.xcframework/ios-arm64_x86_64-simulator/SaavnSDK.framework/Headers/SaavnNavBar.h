//
//  SaavnNavBar.h
//  New Saavn
//
//  Created by Clint Balcom on 8/21/17.
//  Copyright © 2017 Saavn. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SaavnNavBar : UINavigationBar <UIGestureRecognizerDelegate>


#pragma mark - UI Options
- (void) setShadowAlpha:(CGFloat)alpha;
- (void) forceDarkBar;
- (void) showStatusBarFill:(UIViewController *)targetVC;

#pragma mark - Scroll Effects
- (void) setFade:(CGFloat)alpha;

#pragma mark - Getters
- (CGFloat) getStatusBarHeight;
- (CGFloat) getDefaultStatusBarHeight;
- (CGFloat) getShadowAlpha;

@end

