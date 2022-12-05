//
//  Util.h
//  Saavn
//
//  Created by Clint Balcom on 9/18/13.
//  Copyright (c) 2013 Saavn. All rights reserved.
//

#import "TableSectionHeader.h"
//#import "SaavnProActionController.h"
#import "Util_n.h"
typedef enum {
    MODAL_ERROR = 1,
    MODAL_FORCED_UPDATE = 2
} MODAL_TYPE;

typedef enum {
    LC_DEFAULT = 0,
    LC_CACHE = 1,
    LC_MY_MUSIC = 2,
    LC_PLAYLIST = 3,
    LC_STAR = 4,
    LC_RADIO = 5,
    LC_PRO_CHAIN = 6
} LOGIN_CONTEXT;

typedef enum {
    FEEDBACK_BASIC = 0,
    FEEDBACK_HELP = 1,
    FEEDBACK_BUG = 2
} FEEDBACK_TYPES;

typedef enum {
    Unknown_CELL,
    Album_CELL,
    Artist_CELL,
    Channel_CELL,
    Chart_CELL,
    MyMusic_CELL,
    Playlist_CELL,
    Radio_CELL,
    Show_CELL,
    Song_CELL,
    Episode_CELL,
    Surprise_CELL,
    MixPlaylist_CELL
} HOME_CELL_TYPE;

typedef enum {
    QualityTypeHigh   = 1,
    QualityTypeMedium = 2,
    QualityTypeLow    = 4
} QualityType;

// TODO: Unclear if we still need this?
typedef enum {
    SONG_STATION            = 0,
    SEARCH_STATION          = 1,
    GENRE_STATION           = 2,
    ScratchStationTypes     = 3,  // Marker to easily check for scratch types (type < ScratchStationTypes = SCRATCH).
    
    FEATURED_STATION        = 4,
    FEATURED_ARTIST_STATION = 5,
    ARTIST_STATION          = 6,
    USER_STATION            = 7,
    CHANNEL_STATION         = 8,
    PLAYLIST_STATION        = 9,
    ALBUM_STATION           = 10,
    LIBRARY_STATION         = 11,
    USER_PROFILE_STATION    = 12,
    SCRATCH_STATION         = 999
} StationTypes;

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

static float tableHeaderStringAdjust = 6;
@class SaavnSDKDelegate;
@interface Util : NSObject {
    //
}

+ (NSObject *) fileLock;

#pragma mark - Variable Tab Handling
#ifndef __SvnSenSDK
+ (BOOL) tabOkayForOffline:(MainTabs)tab;

+ (SaavnTC *) getTabBarController;
#endif

#pragma mark - Convenience
#ifndef __SvnSenSDK
+ (AppDelegate *) appDel;
#else
+ (SaavnSDKDelegate *) appDel;
#endif
+ (UIApplicationState ) appState;
+ (NSString *) getHardware:(BOOL)withOS;
+ (NSString *) getSubStateString;
+ (NSString *) getFeedbackDiagnostics;
+ (UIColor *) colorFromHex:(NSString *)hex;
+ (UIColor *) colorFromHex:(NSString *)hex withAlpha:(float)alpha;
+ (NSInteger) hexIntFromColor:(UIColor *)color;

#pragma mark - API Requests

+ (NSString *) getStationType: (StationTypes) type;
+ (NSString *) constructApiRequest:(NSString *)method withParams:(NSDictionary *)params;
+ (NSString *) constructApiWebSocketRequest:(NSString *)method withParams:(NSDictionary *)params;
+ (NSString *) convertDictToString:(NSDictionary *)dict;

#pragma mark - Screen Size
// Width of app frame...
// Depending on view and iOS version, this may or may not exclude the status bar.
+ (int) getAppWidth;
// Width of screen.
+ (int) getScreenWidth;
// Height of entire screen (doesn't include status bar).
+ (int) getAppHeight;
// Height of screen (includes status bar).
+ (int) getScreenHeight;
// Quick way to set a variable based on screen sizes.
+ (float) setValue:(float)base iPhone5:(float)iPhone5 iPhone4:(float)iPhone4;

#pragma mark - View Titles
+ (UIView *) newTitleView:(NSString *)title withSubtitle:(NSString *)subtitle;
+ (UIView *) newTitleView:(NSString *)title withSubtitle:(NSString *)subtitle atSize:(CGSize)size;
+ (UIView *) newTitleView:(NSString *)title titleColor:(UIColor *)titleColor withSubtitle:(NSString *)subtitle subtitleColor:(UIColor *)subtitleColor atSize:(CGSize)size;
+ (UIView *) newShadowTitleView:(NSString *)title withSubtitle:(NSString *)subtitle;

#pragma mark - UI Shortcuts
+ (UIView *) createCard;
+ (UIView *) createOverlay:(CGRect)frame withRadius:(float)radius;

#ifndef __SvnSenSDK
+ (BOOL) accessProActionModalFromVC: (UIViewController *) parentVC proActionType: (ProActionType) type;
#endif
+ (void) accessContentFromVC: (UIViewController *) parentVC showLoginUI: (BOOL) showLoginUI asModal:(BOOL) asModal viaProAction:(BOOL) viaPro withContext: (NSDictionary *) context dismissHandler: (void (^)(BOOL success)) completion;
//+ (void) showLoginIn: (UIViewController *) vc fromSource: (NSString *) source viaProAction: (BOOL) viaPro dismissHandler: (void (^)()) completionBlock;
+ (void) showGoProIn:(UIViewController *)vc asModal:(BOOL)isModal dismissHandler:(void (^)(void))block;
+ (void) showProReminder:(UIViewController*)targetVC withDormancy:(BOOL)expired;

#pragma mark - Layout Helpers
+ (void) addShadowToView:(UIView *)view withColor:(UIColor *)color andOffset:(CGSize)offset andRadius:(int)radius;
+ (float) bannerHeight;
+ (CGSize) gridSizeFor:(float)width atRatio:(float)aspectRatio withTitle:(BOOL)hasTitle withMetaLines:(NSUInteger)lines andExtraLines:(NSUInteger)extraLines;
+ (CGSize) gridSizeForTableGrid:(float)width atRatio:(float)aspectRatio withTitle:(BOOL)hasTitle withMetaLines:(NSUInteger)lines andExtraLines:(NSUInteger)extraLines;
+ (CGSize) gridSizeFor:(float)width atRatio:(float)aspectRatio inCols:(int)cols withTitle:(BOOL)hasTitle withMetaLines:(NSUInteger)lines andExtraLines:(NSUInteger)extraLines;
+ (void) setAnchorPoint:(CGPoint)anchorPoint forView:(UIView *)view;

#pragma mark - Math Stuff
+ (float) greaterOf:(float)num1 and:(float)num2;
+ (CGFloat) degreesToRadians:(CGFloat)degrees;
+ (int) randFrom:(int)min to:(int)max;

#pragma mark - Image Handling
+ (UIImage *) imageFromColor:(UIColor *)color;
+ (UIImage *) downsizeImage: (UIImage *) image qualityType:(QualityType) type;
+ (UIImage *) resizeImage:(UIImage *)image toSize:(CGSize)newSize;
+ (UIImage *) imageWithImage: (UIImage *) image scaledToSize: (CGSize) newSize;
+ (UIImage *) blur:(UIImage *)image;
+ (UIImage *) blur:(UIImage *)image toRadius:(float)radius;
+ (UIImage *) getOfflineImage:(NSDictionary *)song atSize:(CGSize)size;
+ (UIImage *) createQuadArtFrom:(NSArray *)images;
+ (UIColor *) getColorFromImage:(UIImage *)image;
+ (UIColor *) getColorFromImage:(UIImage *)image avoidColor:(UIColor *)avoid;
+ (NSString *) getImageSize:(NSUInteger)size from:(NSString *)imageUrl;
+ (BOOL) needsHiRes;
// Get the launch image for use in app code.
+ (UIImage *) defaultImage;
+ (UIImage *) defaultImageForOrientation:(UIInterfaceOrientation)orient;

#pragma mark - Labels & Strings
+ (UILabel *) newLabel:(NSString *)string color:(UIColor *)color font:(UIFont *)font;
+ (NSString *) convertHTMLEntities:(NSString *)str;
+ (BOOL) isNonEmptyString:(NSString *) string;
+ (BOOL) isNonEmptyArray: (id) array;
+ (BOOL) isNonEmptyDictionary: (id) dict;
+ (BOOL) isNonEmptyNumber:(id) number;
+ (NSString *) checkAndReturnString:(NSString*) string;
+ (NSString *) getUniqueHistoryIdFromSongs:(NSArray*) songs;
// Standard Strings
+ (float) stringWidth:(NSString *)string font:(UIFont *)font;
+ (float) stringHeight:(NSString *)string font:(UIFont *)font;
+ (float) multilineStringHeight:(NSString *)string font:(UIFont *)font inWidth:(float)maxWidth;
// Attributed String
+ (float) attributedStringWidth:(NSAttributedString *)string;
+ (float) multilineAttributedStringHeight:(NSAttributedString *)string withWidth:(float)width;
+ (NSMutableAttributedString *) newFooterAttributedString:(NSString *)string;
+ (NSString *) addCommas:(int)num;
+ (NSString *) pluralize:(NSString *)string with:(NSUInteger)count;
+ (NSString *) trimWhitespace:(NSString *)string;
+ (NSString *) getUsernameFrom:(NSDictionary *)userData withLastName:(BOOL)showLast;
+ (BOOL) isUserLoggedInViaEmail:(NSDictionary *)userData;
+ (NSString *) getEncryptedUidFrom:(NSDictionary*)userData;
+ (BOOL) isPhoneNumber:(NSString *)string;
+ (NSString *) getJsonStringFromDict:(NSDictionary *)song;
+ (NSDictionary *) getDictFromJsonString:(NSString *)songString;
+ (NSString *) formatReleaseDate:(NSString *)releaseDate;
+ (NSString *) formatReleaseDate:(NSString *)releaseDate withFormat:(NSString *)dateFormat dateStyle:(NSDateFormatterStyle)dateStyle andTimeStyle:(NSDateFormatterStyle)timeStyle;
+ (NSInteger) numberOfDaysSince:(NSDate *)startDate;
+ (NSInteger) numberOfHoursSince:(NSDate *)startDate;
// Explicit Tags
+ (void) showExplicitLabel:(UILabel *)label;
+ (void) showExplicitLabel:(UILabel *)label withFullLabel:(BOOL)isFullExplicitLabel;


#pragma mark - Text Fields
+ (UIView *) styleInput:(UITextField *)field inFrame:(CGRect)frame withPadding:(CGSize)padding;

#pragma mark - Buttons
+ (UIButton *) newFlatButton:(NSString *)string withFrame:(CGRect)frame
                     bgColor:(UIColor *)background tapColor:(UIColor *)tapBackground
                   textColor:(UIColor *)color tapTextColor:(UIColor *)tapColor
                        font:(UIFont *)font;
+ (UIButton *) newOutlineButton:(NSString *)string withFrame:(CGRect)frame
                    borderColor:(UIColor *)border tapColor:(UIColor *)tapBackground
                      textColor:(UIColor *)color tapTextColor:(UIColor *)tapColor
                           font:(UIFont *)font;
+ (UIButton *) modalBackButton:(NSString *)label;
+ (UIButton *) modalBackButton:(NSString *)label withTint:(UIColor *)tintColor;
+ (UIButton *) modalMoreButton;
+ (UIButton *) settingsNavButton;
+ (UIButton *) knockoutTitle:(UIButton *)btn;
+ (UIButton *) knockoutAttributedTitle:(UIButton *)btn;

#pragma mark - Scroll View Autosize Content Handling
// Returns CGSize value for contents of a scroll view, accounting for overlaps, etc.
+ (CGSize) scrollContentSize:(UIScrollView *)sv;
+ (CGSize) scrollContentSize:(UIScrollView *)sv withPadRight:(float)padRight;
+ (CGSize) scrollContentSize:(UIScrollView *)sv withPadBottom:(float)padBottom;
+ (CGSize) scrollContentSize:(UIScrollView *)sv withPadRight:(float)padRight withPadBottom:(float)padBottom;

#pragma mark - Table View Convenience Methods
+ (UIView *) getTableViewHeader:(NSString *)theLabel inTable:(UITableView *)table withAlignment:(NSTextAlignment)align;

#pragma mark - Playlist Convenience Methods
+ (int) numSongsIn:(NSString *)playlist;
+ (int) numOfflineSongsIn:(NSString *)playlist;
+ (int) getNumOfflineSongsIn:(NSDictionary *)playlist;
+ (BOOL) isOfflineSongsAvailableInPlaylist:(NSString *)playlist;
+ (BOOL) isOfflineSongsInPlaylist:(NSDictionary *)playlist;
+ (NSArray *) arrayFromSongList:(NSString *)songs;
+ (NSString *) getContentsStringFromSongArray:(NSArray *)songs;
+ (NSString *) getPlaylistString:(NSArray *)playlist;
+ (NSString *) getPlaylistStringFromString:(NSString *)songs;
+ (BOOL) isFollowing:(NSDictionary *)playlist;
+ (NSMutableArray *) createMiniSongObjArray :(NSArray *) songs;

#pragma mark - Playability Checks
+ (NSArray *) getPlayableSongs: (NSArray *) songs;
+ (NSDictionary *) getPlayableTracksInfo: (NSArray *) songs startingIndex:(NSUInteger) startIndex;
+ (void) showUnavailableModalIn:(UIViewController *)parent withURL:(NSString *)url;
+ (void) showRadioAlert;
+ (void) showRadioLanguageAlert:(NSString *)songLanguage;
+ (NSString *) getSongLangFromPermaURL:(NSString *)songURL;

#pragma mark - Simple Animations
+ (void) fadeOut:(UIView *)item;
+ (void) fadeIn:(UIView *)item;

#pragma mark - Facebook API Stuff
+ (NSString *) md5HexDigest:(NSString *)input;

#pragma mark - Tracking Methods
+ (UIViewController*) getCurrentViewController;
+ (NSString *) hashedISU;
+ (void) reportAppOpenToAdMob;
+ (void) trackPageView:(NSString *)pageView songId:(NSString *)songId;
+ (void) logStat:(NSString *)event songId:(NSString *)songId loginmode:(NSString *)l_mode promode:(NSString *)p_mode connection_state:(NSString *)c_state;
+ (NSString *) getDateString:(double) timeStamp;

#pragma mark - iPad Helpers
+ (BOOL) isiPad;
+ (BOOL) isLandscape;
+ (CGRect) detailFrame;
+ (float) getRotationDegrees;
+ (UIButton *) iPadNavSearchButton;
+ (void) pushiPadSearch;
+ (void) pushiPadSearchWithQuery:(NSString *)query inScope:(NSString *)scope;

#pragma mark - App Versions
+ (BOOL) isiOSGT:(float)version;
+ (BOOL) isiOSGTE:(float)version;
+ (BOOL) isiOSLT:(float)version;
+ (BOOL) isiOSLTE:(float)version;
+ (BOOL) isiOSEqualTo:(float)version;

#pragma mark - Application Shortcuts
+ (void) setApplicationShortcutItems;

#pragma mark - Local Storage
+ (NSString *) pathForDataFile:(NSString*)dataFileName;
+ (void) saveDataToDisk:(NSString*)name key:(NSString*)key data:(NSObject*)data;
+ (NSObject *) loadDataFromDisk:(NSString*)name key:(NSString*)key;
+ (void) saveDataToDiskLRU:(NSString *)name key:(NSString *)key data:(NSDictionary *)data;
+ (void) removeLRUObject:(NSMutableDictionary *) dict;
+ (NSObject *) loadAllDataFromDisk:(NSString *)name;
+ (BOOL) isValidMediaUrl:(NSString*)url;
+ (BOOL) isValidMP3Url:(NSString *)url;
+ (BOOL) isValidSongObject:(NSDictionary*)songDict;
+ (NSString *) decryptMediaUrl:(NSString*)url;
+ (NSString *) decryptPhoneNumber:(NSString *)phone;
+ (void) storeLastSelectedTAB: (NSInteger) selectedIndex;
#ifndef __SvnSenSDK
+ (MainTabs) fetchLastSelectedTAB;
#endif
+ (void) clearCacheData;

+ (void) dismissNotification;
+ (NSString*) getSHA1Hash:(NSString*) input;
+ (void) checkForPersistentServer;
+ (void) checkForPersistentSocketServer;
+ (void) checkDuplicateCookies;


+ (HOME_CELL_TYPE) getCellType: (NSString *) typeStr;
+ (void) registerFBDeferredDeeplinkToSaavnCloud: (NSURL*) url;

#pragma mark - View Hierarchy helper methods
// Recursive routine that prints out the view hierarchy with proper indentation
+ (void) displayHierarchyForView: (UIView *) view;
// Recursive routine that checks for a view of a particular class/subclass type in a view hierarchy
+ (id) searchForclassType: (Class) classType inViewHierarchy: (UIView *) view isSubclass:(BOOL) subclass;

+ (void)showHardUpgrade:(NSDictionary*)dict isHardUpgrade:(BOOL)hard;


#pragma mark - Email Validation
+ (BOOL) isValidEmail:(NSString *)email;


+ (void) accessContentFromVC: (UIViewController *) parentVC showLoginUI: (BOOL) showLoginUI asModal: (BOOL) asModal viaProAction: (BOOL) viaPro andTrigger:(NSInteger)triggerType  withContext: (NSDictionary *) context dismissHandler: (void (^)(BOOL)) completionBlock;

// Call this method only when you need to show subscription view irrespective of whether user is on pro or not
+ (void) showProModal: (UIViewController *) parentVC showLoginUI: (BOOL) showLoginUI asModal: (BOOL) asModal viaProAction: (BOOL) viaPro andTrigger:(NSInteger)triggerType  withContext: (NSDictionary *) context;
+ (void) showGoProIn: (UIViewController *) targetVC asModal: (BOOL) isModal andTrigger:(NSInteger)triggerType performTrigger:(BOOL)triggerAction  context:(NSDictionary*)context dismissHandler: (void (^)(void)) block;
@end


