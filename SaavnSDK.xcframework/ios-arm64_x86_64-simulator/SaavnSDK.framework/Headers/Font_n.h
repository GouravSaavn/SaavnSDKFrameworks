//
//  Font.h
//  New Saavn
//
//  Created by Clint Balcom on 8/20/17.
//  Copyright © 2017 Saavn. All rights reserved.
//

#include <UIKit/UIKit.h>

// Core Font Sizes
// Standard Cells
#define FONT_HEADER_TITLE               18.0
#define FONT_HEADER_N_TITLE				24.0
#define FONT_HEADER_SUBTITLE            10.0
#define FONT_HEADER_META				13.f
#define FONT_HEADER_DETAILS				12.f
#define FONT_TITLE                      14.0
#define FONT_META                       12.0
#define FONT_CONDENSED_TITLE            13.0
#define FONT_CONDENSED_META             11.0

// Other Cells
#define FONT_MENU_CELL                  17.0
#define FONT_CHANNEL_TITLE              15.0
// Nav Bar
#ifndef  __SvnSenSDK
#define FONT_NAV_TITLE                  15.0
#else
#define FONT_NAV_TITLE                  20.0
#endif
#define FONT_NAV_BUTTON                 14.0
#define FONT_NAV_SEARCH_FIELD           16.0
#define FONT_NAV_PLAYER_TITLE           12.0    // These two double as mini player values.
#define FONT_NAV_PLAYER_META            11.0
// Tab Bar
#define FONT_TABBAR_BUTTON               9.5
// Headers
#define FONT_VIEW_HEADER_TITLE          21.0
// Custom Uses
#define FONT_VIEW_LYRICS_TEXT           18.0
#define FONT_TABVIEW_CURRENT            23.0
#define FONT_TABVIEW_DEFAULT            18.0


typedef enum {
    Font_Light      = 0,
    Font_Normal     = 1,
    Font_Semibold   = 2,
    Font_Bold       = 3,
    Font_Heavy      = 4,
    Font_Black      = 5
} FontWeights;


@interface Font_n : NSObject


#pragma mark - Manual Fonts
+ (UIFont *) size:(CGFloat)size;
+ (UIFont *) size:(CGFloat)size atWeight:(FontWeights)weight;
+ (UIFont *) size:(CGFloat)size atWeight:(FontWeights)weight asItalic:(BOOL)italic;

#pragma mark - Core Fonts
// Section Headers
+ (UIFont *) headerTitle;
+ (UIFont *) headerSubtitle;
+ (UIFont *) simpleHeaderTitle;
// Scroller & Grid Items
+ (UIFont *) itemTitle;
+ (UIFont *) itemMeta;
+ (UIFont *) condensedItemTitle;
+ (UIFont *) condensedItemMeta;
+ (UIFont *) scrollerFeatureMeta;
+ (UIFont *) itemBadge;
+ (UIFont *) bigBadge;
// Detail View Headers
+ (UIFont *) detailHeaderTitle;
+ (UIFont *) detailHeaderMeta;
+ (UIFont *) detailHeaderDetails;
// Detail View Footers
+ (UIFont *) footerStandard;
// Menus
+ (UIFont *) menuCellTitle;
+ (UIFont *) menuActionTitle;
// Channels
+ (UIFont *) channelTitle;
// System Elements
+ (UIFont *) navBarTitle;
+ (UIFont *) navBarButton;
+ (UIFont *) searchButton;
+ (UIFont *) searchField;
+ (UIFont *) emptySearchTitle;
+ (UIFont *) tabBarTitle;
+ (UIFont *) playerNavTitle;
+ (UIFont *) playerNavMeta;
// View Headers
+ (UIFont *) viewHeaderTitle;
+ (void) installFont:(NSString *) fontName;

@end

