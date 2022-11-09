//
//  Layout.h
//  New Saavn
//
//  Created by Clint Balcom on 8/20/17.
//  Copyright © 2017 Saavn. All rights reserved.
//


// Parent Controllers
#import "SaavnVC_n.h"

// NOTE: Try to keep this list limited.
//       Things should be added here only when they're needed in multiple views or classes
//       which do not have direct access to one another.
//
//       If there's a chance we may want a variable value, we should not use a constanst.
//       Set up a LayoutIndex below, and define and store it once in the Layout class.

// Core Layout Sizes
#define LAYOUT_MARGIN 27.f
#define LAYOUT_GUTTER 20.f
#define LAYOUT_GUTTER_CONDENSED 3.f
#define ITEM_BOTTOM_MARGIN 17.f
#define SECTION_BOTTOM_MARGIN 15.f

// Section Headers
#define HEADER_TOP_MARGIN 17.f
#define HEADER_BOTTOM_MARGIN 17.f
#define HEADER_SUBTITLE_TOP_MARGIN 5.f
#define SIMPLE_HEADER_TOP_MARGIN 15.f
#define SIMPLE_HEADER_BOTTOM_MARGIN 6.f
#define EMPTY_HEADER_SPACER 21.f

#define HEADER_TITLE_TOP_MARGIN 17.f
#define HEADER_META_TOP_MARGIN 14.f
#define HEADER_DETAILS_TOP_MARGIN 11.f

// Standard Type Displays
#define TITLE_TOP_MARGIN 8.f
#define META_TOP_MARGIN 2.f
#define LABEL_PADDING 10.f
#define CONDENSED_LABEL_PADDING 3.f

// Transitions & Animations
#define TRANSITION 0.26f
#define TRANSITION_FAST 0.21f
#define TRANSITION_SLOW 0.39f

// Badges
#define BADGE_BOTTOM_MARGIN 10.f

// Buttons
#define BTN_SIZE 48.f
#define ACCESSORY_SIZE 52.f
#define SECOND_ACCESSORY_SIZE 44.f
//#define HEADER_PLAY_BTN_SIZE 57.f
#define HEADER_PLAY_BTN_SIZE 49.f
#define SECONDARY_BTN_SIZE 28.f

// Icons
#define ICON_SIZE 42.f

// Misc
#define PLUS_WIDTH 414.f
#define LAYOUT_ZERO 0.001f
#define LAYOUT_IOS_VIEW_MARGIN 8.f
#define LAYOUT_IOS_NAVBAR_MARGIN 15.f
#define LAYOUT_MENU_FOOTER 19.f
#define WIDESCREEN_ADJUST 0.5625f
#define BEVEL 0.5f
#define PLAYER_ART_TOP_GUTTER 15.f
#define PULL_TO_REFRESH_HEIGHT 75.f

#ifdef __SvnSenSDK
#define MINI_PLAYER_HEIGHT 48.f
#endif

// Search Bars & Segment Tabs
#define CONTROL_HEIGHT 36.f
#define CONTROL_PADDING 10.f

// Modals
#define MODAL_ART_SIZE 150.f
#define MODAL_DIVIDER 10.f

// iPad
#define iPAD_PLAYER_WIDTH 300.f


// For mixed use tables, like most top level views.
typedef NS_ENUM(NSInteger, SectionType) {
    Section_Unknown = 0,
    Section_Custom = 1,
    Section_AdBanner = 2,
    Section_Hero = 3,
    Section_Brand_Bar = 4,
    
    // Menus
    Menu_Basic = 10,
    
    // Standard Cells
    Cells_Standard = 100,
    Cells_Large = 101,          // Slightly larger than standard.
    Cells_EditorsNote = 102,    // Editor's Note & Editor's Pick
    
    // Actions
    Cells_Download = 110,       // Download all cell, at top of detail views.
    Cells_More = 111,           // Plain "More ___" cells. Load longer lists in detail views.
    
    // Settings
    Cells_Settings = 120,       // Slightly smaller than standard.
    
    // Custom
    Cells_Text = 200,           // Basic text cells, like bios, descriptions, and lyrics.
    Cells_Inbox = 210,          // Inbox notifications.
    
    // Channel Grid Cells (Table mimicking UICollectionView)
    // This is specifically for the browse view's grid of channels. It's unlikely we'll use this
    // anywhere else, nor should we need to support it from the back-end in other views.
    Channel_Grid = 300,
#ifdef __SvnSenSDK
    // Library Playlist Cell
    Library_Grid = 310,
#endif
    
    // Grid Cells (CollectionViews)
    Grid_Basic = 400,
    Grid_Condensed = 410,
    Grid_Widescreen = 420,
    
    // Side Scrollers ---------------------
    // NOTE: Don't include anything after this point which is not a scroller (ie. a UICollectionView inside a UITableViewCell).
    //       We're using SS_Basic (1000) as the min value to check if section is scroller type.
    //       The layout types above are all static cells like grids, ads, or containers for custom layouts.
    
    // NOTE: Also, the "flush" variants here are simply used to determine the correct layout margins, depending on the view type.
    //       Main views (home tabs) have a wider margin than detail views. This is to make the layouts clean and offer the best UX
    //       in terms of spacing, peaking the next section, etc. The "flush" versions are the same as the regular versions except
    //       they adjust some sizing to match the margins of standard table view cells, as is used in DetailVC, so that scroller
    //       sections can align nicely with basica table view rows.
    
    // Big Squares
    SS_Basic = 1000, SS_Basic_Flush = 1010,
    SS_Basic_Double = 1100, SS_Basic_Double_Flush = 1110,
    
    // Condensed Squares
    SS_Condensed = 2000,
    SS_Condensed_Double = 2100,
    
    // Widescreen
    SS_Widescreen = 3000, SS_Widescreen_Flush = 3010,
    SS_Widescreen_Double = 3100, SS_Widescreen_Double_Flush = 3110,
    SS_Carousel = 3200, SS_Carousel_Flush = 3210,
    SS_Description = 3300,
    
    // Multiple Items (ie. groups of songs)
    SS_MultipleItems = 4000,
    
    // Video
    SS_Video = 5000,
	SS_Short_Videos = 5001,
	SS_Video_Landscape = 5010,
    Video_Station = 5011
};

typedef enum {
    // Section Headers -- NSStrings
    Type_HeaderTitle,
    Type_HeaderSubtitle,
    Type_SimpleHeaderTitle,
    
    // Scroller Item Labels -- NSAttributedStrings
    Type_ScrollerLabel,
    Type_ScrollerLabelWithMeta,
    Type_ScrollerCondensedLabel,
    Type_ScrollerCondensedLabelWithMeta,
    Type_ScrollerFeatureMetaTopMargin,
    
    // Misc Cells
    Type_MenuCell,
    Type_LargeCell,
    Type_HeroCell,
    Type_ShareCell,
    
    // Misc Items
    Type_HeaderAngle,
    Type_HeaderArt,
    Type_ViewFooter,
    Type_PlayerRadioFooter,
    Type_SettingsHeader
} LayoutIndex;


@interface Layout : NSObject


// Properties are only used to store things that shouldn't be changing once we set them up.
// This way, we can simply access values or assets rather than recalculating / rebuilding them
// in various views and methods. Saves cycles, and improves performance, especially in tables.
@property (nonatomic, strong) NSMutableArray *sizes;

// Keyboard notification handling. These properties help us keep track of changes to the keyboard's
// height, as well as the animation speed and style it's using to show/hide, so that we can update our
// views accordingly whenever the height changes.
@property (nonatomic) UIViewAnimationOptions kbAnimationCurve;
@property (nonatomic) double kbAnimationDuration;
@property (nonatomic) CGFloat kbHeight;


#pragma mark - Init
+ (Layout *) singleton;
- (void) setLayoutSizes;

#pragma mark - Basic Getters
+ (SectionType) typeFor:(NSDictionary *)data;
+ (BOOL) isScroller:(SectionType)type;
+ (CGFloat) heightFor:(LayoutIndex)layout;
+ (BOOL) sectionShowsMeta:(NSDictionary *)sectionData;

#pragma mark - Grid (UICollectionView) Sizing
+ (CGSize) gridItemSizeForView:(UIView *)parent withInsets:(UIEdgeInsets)sectionInset inSectionType:(SectionType)type withMeta:(BOOL)hasMeta;
+ (CGFloat) gridItemSpacingForSectionType:(SectionType)type;

#pragma mark - Scroller Sizing
// Item Widths
+ (CGFloat) scrollerItemWidth:(UIView *)view;
+ (CGFloat) scrollerCondensedItemWidth:(UIView *)view forWidescreen:(BOOL)isWidescreen;
+ (CGFloat) scrollerItemWidth:(UIView *)view asCondensed:(BOOL)isCondensed forWidescreen:(BOOL)isWidescreen;
+ (CGFloat) scrollerFlushItemWidth:(UIView *)view forWidescreen:(BOOL)isWidescreen;
+ (CGFloat) scrollerCarouselItemWidth:(UIView *)view flushToMargins:(BOOL)isFlush;
+ (CGFloat) scrollerDescriptionItemWidth:(UIView *)view;
// Row Heights
+ (CGFloat) scrollerRowHeight:(UIView *)view
                  asCondensed:(BOOL)isCondensed
                forWidescreen:(BOOL)isWidescreen
                     withMeta:(BOOL)hasMeta
                     asDouble:(BOOL)isDouble
               flushToMargins:(BOOL)isFlush;
+ (CGFloat) scrollerCarouselHeightFor:(UIView *)view flushToMargins:(BOOL)isFlush;
+ (CGFloat) scrollerDescriptionHeightFor:(UIView *)view;
+ (CGFloat) scrollerVideoRowHeight:(UIView *)view withMeta:(BOOL)hasMeta;
// Multi-Item Scrollers
+ (CGFloat) multiItemCellHeight;
+ (CGFloat) multiItemCellMargin;

#pragma mark - Grid Sizing
+ (CGFloat) gridRowHeightFor:(UIView *)view asWidescreen:(BOOL)isWidescreen withTitle:(BOOL)hasTitle andMeta:(BOOL)hasMeta;
+ (CGFloat) gridRowHeightFor:(UIView *)view withFlushMargins:(BOOL)flushMargins asWidescreen:(BOOL)isWidescreen withTitle:(BOOL)hasTitle andMeta:(BOOL)hasMeta;

#pragma mark - Table Cells
// Some direct access methods for things we might need outside of a cached heights array.
// Should generally try to avoid accessing these, we want to abstract it as much as possible, but sometimes it's needed.
+ (CGFloat) rowHeight;
+ (CGFloat) rowHeightShort;
+ (CGFloat) rowImageSize;
+ (CGFloat) rowImageSizeShort;
+ (CGFloat) customRowImageSize:(CGFloat)rowHeight;
+ (CGFloat) rowIconWidth;
// Standardized (and tintaable) Disclosure Indicator
+ (UIImageView *) disclosure;
+ (UIImageView *) modalDisclosure;
// Standard Accessory Views
+ (UIButton *) optionsAccessory;
+ (UIButton *) downloadAccessory;
+ (UIButton *) likeAccessory;
+ (UIButton *) jioTuneAccessory;
+ (UIButton *) removeAccessory;
#ifdef __SvnSenSDK
+ (UIButton *) currentJioTuneAccessory;
#endif

#pragma mark - Table Section Headers
+ (CGFloat) headerHeightWithSubtitle:(BOOL)hasSubtitle;
+ (CGFloat) simpleHeaderHeight;
+ (CGFloat) artistAlbumHeaderHeight;
+ (BOOL) isSimpleHeader:(NSDictionary *)sectionData;
+ (BOOL) hideHeader:(NSDictionary *)sectionData;

#pragma mark - Table Section Footer
+ (BOOL) hasBasicFooter:(NSDictionary *)sectionData;
+ (CGFloat) bottomClearance;

#pragma mark - Parse & Table Section & Row Heights
+ (void) cacheHeights:(NSArray *)data forVC:(SaavnVC_n *)parentVC;
+ (void) cacheHeights:(NSArray *)data forVC:(SaavnVC_n *)parentVC inScrollView:(UIScrollView *)scroller forHeaders:(NSMutableArray *)sectionHeaderHeights andRows:(NSMutableArray *)rowHeights;

#pragma mark - Saavn Angled Headers
+ (void) setAngleMaskOn:(UIView *)target;           // Mask bottom of container, to bottom right.
+ (void) setBase:(UIView *)target;					// Mask bottom of DetailHeader.
+ (void) setFlippedAngleMaskOn:(UIView *)target;    // Mask bottom of container, to bottom left.
+ (void) setAngleLineMask:(UIView *)target;         // Mask only a line, instead of whole element.
+ (void) setFlippedAngleLineMask:(UIView *)target;  // Mask only a line, but matching flipped mask.
+ (void) setReverseAngleMaskOn:(UIView *)target;    // Mask the top of the container.

#pragma mark - Positioning Helpers
+ (void) setAnchorPoint:(CGPoint)anchorPoint forView:(UIView *)view;
+ (UITableViewCell *) alignCellToStandardMargin:(UITableViewCell *)cell;
+ (UITableViewCell *) alignCell:(UITableViewCell *)cell toMargin:(CGFloat)leftMargin;

#pragma mark - Keyboard Helpers
+ (CGFloat) keyboardSafeMaxHeight;

#pragma mark - Overlays & Effects
+ (UIView *) createOverlay:(CGRect)frame withRadius:(float)radius;
+ (void) addSoftShadowTo:(UIView *)view;
+ (void) addSoftShadowTo:(UIView *)view withOpacity:(CGFloat)opacity offset:(CGSize)offset andRadius:(CGFloat)radius;


@end

