//
//  Styles_n.h
//  New Saavn
//
//  Created by Clint Balcom on 8/20/17.
//  Copyright © 2017 Saavn. All rights reserved.
//


// Core Colors

#ifndef __SvnSenSDK
#define COLOR_BG_WHITE 0xf6f6f6
#else
#define COLOR_BG_WHITE 0xEFEFEF
#endif
#define COLOR_SUBTLE_WHITE 0xe6e6e6
#define COLOR_GREY 0x3e3e3e
#define COLOR_GREY_LIGHT 0xa9a9a9
#define COLOR_GREEN 0x2bc5b4
#define COLOR_JIO_HIGHLIGHT 0xadfaf1
#define COLOR_NAAVY 0x2a2d36
#define COLOR_NAAVY_HIGHLIGHT 0x8b9dbf
#define COLOR_SUBTLE_NAAVY 0x353841
#define COLOR_ALERT 0xf3464a

// Legacy
#define COLOR_LEGACY_GREEN 0x30b55a

// Partner Colors
#define COLOR_WHATSAPP 0x25d366
#define COLOR_TWITTER 0x1ea1f3
#define COLOR_FACEBOOK 0x3b5998

// Image Styles
#define CORNER_RADIUS 3.f
#define HEADER_IMAGE_CORNER_RADIUS 8.f
#define SHADOW_SIZE 1.5f

#import "SaavnVC_n.h"

@interface Styles_n : NSObject


#pragma mark - Colors
// Core
+ (UIColor *) bgColor;
+ (UIColor *) transitionBGColor;
+ (UIColor *) navColor;
+ (UIColor *) navColorInvert;
+ (UIColor *) navBtnColor;
+ (UIColor *) navBtnTapColor;
+ (UIColor *) subtleColor;
+ (UIColor *) fillColor;
+ (UIColor *) highlightColor;
+ (UIColor *) extraHighlightColor;
+ (UIColor *) alertColor;
+ (UIColor *) bevelColor;
+ (UIColor *) artBevelColor;
+ (UIColor *) headerFillColor;
+ (UIColor *) unavailableColor;
+ (UIColor *) newColor;
+ (UIColor *) getTheAppColor;

// Sections Headers
+ (UIColor *) headerTitleColor;
+ (UIColor *) headerSubtitleColor;

// Scroller & Grid Items
+ (UIColor *) itemTitleColor;
+ (UIColor *) itemMetaColor;

// Menus
+ (UIColor *) menuBGColor;
+ (UIColor *) menuGraphColor;
+ (UIColor *) menuTitleColor;
+ (UIColor *) menuActionColor;
+ (UIColor *) menuCellSelected;

// Forms & Fields
+ (UIColor *) inputFieldTextColor;
+ (UIColor *) inputFieldPlaceholderColor;
+ (UIColor *) switchBorders;

#pragma mark - Color Helpers
+ (UIColor *) tapColor:(UIColor *)color;
+ (UIColor *) disabledColor:(UIColor *)color;
+ (BOOL) isDarkColor:(UIColor *)color;
+ (UIColor *) getCustomColor:(int)defColor;
+ (UIColor *) getCustomColor:(int)defColor withAlpha:(CGFloat)alpha;
+ (UIColor *) getPrimaryColor:(UIImage *)image;

#pragma mark - Attributed Labels
// Standard
+ (NSDictionary *) getLabelTitleStylesAsCondensed:(BOOL)asCondensed;
+ (NSDictionary *) getLabelTitleStylesAsCondensed:(BOOL)asCondensed withTruncation:(BOOL)shouldTruncate;
+ (NSDictionary *) getLabelTitleStylesAsCondensed:(BOOL)asCondensed withTruncation:(BOOL)shouldTruncate andAlignment:(NSTextAlignment)alignment;
+ (NSDictionary *) getLabelMetaStylesAsCondensed:(BOOL)asCondensed;
// Scroller Features
+ (NSDictionary *) getLabelFeatureMetaStyles;
+ (NSDictionary *) getLabelFeatureMetaStylesWithTopMargin:(CGFloat)topMargin;
// Carousel Details
+ (NSDictionary *) getCarouselTitleStyles;
+ (NSDictionary *) getCarouselMetaStyles;
+ (NSDictionary *) getCarouselDescriptionStyles;
// Description
+ (NSDictionary *) getDescriptionTitleStyles;
+ (NSDictionary *) getDescriptionMetaStyles;
+ (NSDictionary *) getDescriptionDescriptionStyles;
// Player Nav Bar
+ (NSDictionary *) getPlayerTitleStyles;
+ (NSDictionary *) getPlayerTitleStylesCentered:(BOOL)isCentered;
+ (NSDictionary *) getPlayerMetaStyles;
// Section Footers
+ (NSDictionary *) getFooterStringStyles;
+ (NSDictionary *) getCondensedFooterStringStyles;

#pragma mark - Shadows
+ (UIColor *) crispShadowColor;
+ (UIColor *) softShadowColor;
+ (CGSize) softShadowOffset;
+ (CGFloat) softShadowRadius;
+ (CGFloat) softShadowOpacity;

#pragma mark - Buttons
+ (UIButton *) newStandardButton;
+ (UIButton *) newHighlightButton;
+ (UIButton *) newAlertButton;
+ (UIButton *) newSubtleButton;

#pragma mark - Nav Items
+ (UIButton *) newStandardRightNavItem:(NSString *)label inVC:(SaavnVC_n *)parentVC;
+ (UIButton *) newHighlightedRightNavItem:(NSString *)label inVC:(SaavnVC_n *)parentVC;

#pragma mark - Global Appearance & UI Mode
+ (void) toggleUIMode;
+ (void) updateUIMode;
+ (NSString *) backButtonLabel;


@end

