//
//  FauxNav.h
//  New Saavn
//
//  Created by Clint Balcom on 1/10/18.
//  Copyright © 2018 Saavn. All rights reserved.
//


// Parent Controllers
@class SaavnVC_n;

// Subclasses
#import "SaavnPlayButton.h"


@interface FauxNav : UIView {
@protected
    // Standard UI Elements
    UIView *fill, *shadow, *bevel;
    UIButton *title;
    UIImageView *icon;
    CGFloat statusBarH, navBarH;
}

// Nav Bar Buttons
@property (nonatomic, strong) NSArray *leftBarButtonItems, *rightBarButtonItems;
@property (nonatomic, strong) SaavnVC_n *currentOwner;

// Detail View UI elements
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) SaavnPlayButton *playBtn;

@property (nonatomic) BOOL hasViewTabs;


#pragma mark - Init
- (instancetype) initInView:(SaavnVC_n *)parent;
- (instancetype) initInView:(SaavnVC_n *)parent forMedia:(BOOL)hasPinnedItems;
- (void) initUI;
- (void) bringExtrasToFront;
- (void) useCircleArt;
- (void) refreshButtons;

#pragma mark - iPad Layout
- (void) iPadRefreshLayout;

#pragma mark - Setters
- (void) setTitle:(NSString *)titleStr;
- (void) setTitle:(NSString *)titleStr andMeta:(NSString *)metaStr;
- (void) setTitle:(NSString *)titleStr andMeta:(NSString *)metaStr withMetaOnTop:(BOOL)metaOnTop;
- (void) setTintColor:(UIColor *)tintColor asCustom:(BOOL)isCustom;
- (void) setBarButtonBgOpacity:(CGFloat)opacity;
- (void) resetCustomTint;
- (void) fadeTitle:(CGFloat)pct;
- (void) fadeFillAndBevel:(CGFloat)pct;
- (void) fadeOnlyFill:(CGFloat)pct;
- (void) fadeOnlyBevel:(CGFloat)pct;
- (void) setLabelStyles;
- (void) alignLeft;
- (void) alignCenter;
- (void) showPinnedItems:(BOOL)shouldShowPinned;

#pragma mark - Getters
- (CGFloat) alignedButtonWidth;
- (UIButton *) getTitleButton;

#pragma mark - Standard Buttons
- (UIButton *) getBackButton;
- (UIButton *) getBackButtonWithLabel:(NSString *)label;
- (UIButton *) getCloseButton;
- (UIButton *) getOptionsButton:(BOOL)tinted;
#ifndef __SvnSenSDK
#else
- (UIButton *) getDeleteButton;
#endif
@end

