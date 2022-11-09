//
//  Util.h
//  New Saavn
//
//  Created by Clint Balcom on 8/21/17.
//  Copyright © 2017 Saavn. All rights reserved.
//



// Classes
#ifndef  __SvnSenSDK
#import "AppDelegate.h"
#import "UserData.h"
#import "DeviceIDManager.h"
#import "JioUserManager.h"
#import "SSOZLAUtil.h"
#else
#import "SaavnSDKDelegate.h"
#endif


// Parent Controllers
#import "SaavnVC_n.h"

@interface Util_n : NSObject

#pragma mark - Getters
#ifndef __SvnSenSDK
+ (AppDelegate *) appDel;
#else
+ (SaavnSDKDelegate *) appDel;
#endif
+ (UIApplicationState ) appState;
+ (SaavnVC_n *) currentVC;
+ (SaavnVC_n *) currentNonPlayerVC;
+ (SaavnVC_n *) currentPresentedVC;
+ (UIViewController *) topMostController;
+ (NSUInteger) getCurrentTab;

#pragma mark - Setters
+ (void) setCurrentTab:(MainTabs)tab;

#pragma mark - Nil Checks
+ (BOOL) isNonEmptyString:(NSString *)string;
+ (BOOL) isNonEmptyArray:(id)array;
+ (BOOL) isNonEmptyDictionary:(id)dict;
+ (BOOL) isNonEmptyNumber:(id)number;

#pragma mark - Colors
+ (UIColor *) colorFromHex:(NSString *)hex;
+ (UIColor *) colorFromHex:(NSString *)hex withAlpha:(float)alpha;
+ (NSInteger) hexIntFromColor:(UIColor *)color;

#pragma mark - Images
// Image Loading
+ (void) loadImage:(NSString *)image in:(UIImageView *)imageView;
+ (void) loadImage:(NSString *)image in:(UIImageView *)imageView withResolution:(BOOL)same;
+ (void) loadImage:(NSString *)image withSize:(CGSize)size in:(UIImageView *)imageView;
//+ (void) loadImage:(NSString *)image in:(UIImageView *)imageView withSize:(CGSize)size forVideo:(BOOL)isVideo;
+ (void) loadImage:(NSString *)image in:(UIImageView *)imageView withSize:(CGSize)size forVideo:(BOOL)isVideo withCompletion:(void(^)(void))completion;
+ (void) loadImage:(NSString *)image in:(UIImageView *)imageView withCompletion:(void(^)(void))completion;
+ (void) loadImage:(NSString *)image in:(UIImageView *)imageView atSize:(CGFloat)size withCompletion:(void(^)(void))completion;
+ (void) loadImage:(NSString *)image in:(UIImageView *)imageView atSize:(CGFloat)size withCompletion:(void(^)(void))completion withFailure:(void(^)(void))failure;
+ (void) loadImageWithoutThreading:(NSString *)image in:(UIImageView *)imageView withCompletion:(void(^)(void))completion;
+ (void) loadImageWithoutThreading:(NSString *)image in:(UIImageView *)imageView atSize:(CGFloat)size withCompletion:(void(^)(void))completion;
// Preloaded Image Checks
+ (UIImage *) imageFromTableCell:(UITableViewCell *)cell;
+ (UIImage *) imageFromCollectionViewCell:(UICollectionViewCell *)cell;
// Image Extras
+ (UIImage *) imageFromColor:(UIColor *)color;
+ (UIImage *) imageFromColor:(UIColor *)color atSize:(CGRect)rect;
+ (NSString *) getImageSize:(NSUInteger)size from:(NSString *)imageUrl;
+ (UIImage *) resizeImage:(UIImage *)image toSize:(CGSize)newSize;
+ (UIImage *) pixellateImage:(UIImage*)fromImage withScale:(double)scale;

#pragma mark - String Handlers
// Cleaning Strings
+ (NSString *) cleanString:(NSString *)str;
+ (NSString *) trimWhitespace:(NSString *)str;
+ (NSString *) trimWhitespace:(NSString *)str andLineBreaks:(BOOL)trimBreaks;
// String Creators
+ (NSString *) addCommas:(int)num;
+ (NSString *) pluralize:(NSString *)string with:(NSUInteger)count;
+ (NSString *) condenseNumber:(long)number;
// NSString
+ (float) stringWidth:(NSString *)string font:(UIFont *)font;
+ (float) stringHeight:(NSString *)string font:(UIFont *)font;
+ (float) multilineStringHeight:(NSString *)string font:(UIFont *)font inWidth:(float)maxWidth;
// NSAttributedString
+ (float) attributedStringWidth:(NSAttributedString *)string;
+ (float) multilineAttributedStringHeight:(NSAttributedString *)string withWidth:(float)width;

#pragma mark - Dates
+ (NSString *) formatReleaseDate:(NSString *)releaseDate;
+ (NSString *) formatReleaseDate:(NSString *)releaseDate withFormat:(NSString *)dateFormat dateStyle:(NSDateFormatterStyle)dateStyle andTimeStyle:(NSDateFormatterStyle)timeStyle;
// Simple Display Strings
+ (NSString *) getTimeOfDayString;

#pragma mark - Numbers & Math
+ (NSInteger) intFrom:(id)value;
+ (NSInteger) randBetween:(NSInteger)min andMax:(NSInteger)max;
+ (NSInteger) randBetween:(NSInteger)min andMax:(NSInteger)max excluding:(NSArray *)excludes;
+ (CGFloat) degreesToRadians:(CGFloat)degrees;

#pragma mark - Interface
+ (void) haptic:(UIImpactFeedbackStyle)style;

#pragma mark - Pagination
+ (BOOL) reachedBottom:(UIScrollView *)scrollView withOffset:(CGFloat)offset;
+ (NSUInteger) getItemsPerFetchForList;
+ (NSUInteger) getItemsPerFetchForGrid;
+ (NSUInteger) getItemsPerFetchForHomeList;

#pragma mark - TabBar Badges
#ifndef __SvnSenSDK

+ (void) showLabelBadge:(NSString *)label onTab:(MainTabs)tab;
+ (void) showDotBadgeOnTab:(MainTabs)tab;
+ (void) hideBadgesOnTab:(MainTabs)tab;
+ (void) clearAllBadges;
+ (void) showTabBarLike;
#endif

#pragma mark - Miscellaneous
+ (NSDictionary *) convertStringToDict:(NSString *)str;


#pragma mark - Event tracking
#ifdef __SvnSenSDK
+ (void) sendBackToRootEvent:(SaavnVC_n *)parentVC;
+ (void) sendBackButtonEvent:(SaavnVC_n *)parentVC;
+ (void) sendDismissToRootEvent:(SaavnVC_n *)parentVC;
#endif
+ (NSString*) getLoginTypeString:(LOGIN_TYPE)loginType;
+ (NSMutableDictionary *) getAppLaunchParams;
+ (NSString*) getViewTypeStr:(ViewType)type;
+ (NSString *) getScreenName:(SaavnVC_n *) vc;
+ (void) trackPageView:(NSString *)pageView trackingDict:(NSDictionary *)dict;
+ (NSString *) createOptionId:(NSString *) title;
+ (NSMutableDictionary *) extractStreamingDictFromBottomSrc:(id) dict;
+ (NSMutableDictionary *) appendTopSourceToDict:(NSDictionary *)trackingDict fromSection:(NSDictionary *)sectionDetails andEntity:(NSDictionary *)entityDetails viaParent:(SaavnVC_n *)parentVC;
+ (NSMutableDictionary *) appendBottomSourceToDict:(NSDictionary *)trackingDict fromSection:(NSDictionary *)sectionDetails andEntity:(NSDictionary *)entityDetails viaParent:(SaavnVC_n *)parentVC;
+ (NSMutableDictionary *) appendStreamingInfoToDict:(NSDictionary *)dict fromItem:(NSDictionary *) item;
+ (NSMutableDictionary *) removeStreamingInfoFromBottomSrc:(NSDictionary *) trackingDict;
+ (NSString *) getAccessLabelForCell:(id)cell atIndex:(NSInteger) sectionIndex;
+ (NSString *) getAccessValueForCell:(id)cell;
+ (NSMutableDictionary *) appendTrackingKeysToOject:(NSDictionary *)mediaObject fromTrackingDict:(NSDictionary *) trackingDict;
+ (NSMutableArray *) prepareSongs:(NSArray *) songList withTrackingDict:(NSDictionary *)trackingDict;
+(NSMutableDictionary *) appendStreaminginfoToDict:(NSDictionary *)dict fromRadio:(NSDictionary *) radioObj;
+(NSMutableDictionary *) appendIdToTopSource:(NSDictionary *) trackingDict fromEntity:(NSDictionary *) entity;
+ (NSMutableDictionary *) appendBrandBarToTopSrc:(NSDictionary *) trackingDict;
+ (BOOL) isBrandChannelContent:(NSDictionary *) trackingDict;
+ (NSString *) getScreenId:(NSDictionary *)trackingDict;
+ (BOOL) runSanityOnJioTuneParams:(NSDictionary *)dict;
+ (NSMutableDictionary *) runSanityOnTrackingParams:(NSDictionary *) trackingDict;
+ (NSMutableArray *) getABTestArray;
+ (NSString *) getmediaTypeForTracking:(NSDictionary *)entityData;
+ (BOOL) isJIOMarkerPresent : (NSDictionary *) eventParams;
+ (NSMutableDictionary *) modifyParamsForJIOAnalytics: (NSDictionary *)paramDict;
+ (NSString *) getEntityIDFromEntityName:(NSString*)name;

// File System
+ (NSString *) getDocumentsFolderPath;

+ (NSArray *) getColorsFor:(UIImage *)image;
+ (NSString*) hexStringFromColor:(UIColor*)color;


+ (NSMutableDictionary *) appendMidSourceToDict:(NSDictionary *)trackingDict fromSection:(NSDictionary *)sectionDetails andEntity:(NSDictionary *)entityDetails viaParent:(SaavnVC_n *)parentVC;
+ (NSMutableDictionary *) appendBottomSourceToDict:(NSDictionary *)trackingDict fromSection:(NSDictionary *)sectionDetails andEntity:(NSDictionary *)entityDetails viaParent:(SaavnVC_n *)parentVC andScreen:(NSString*) screenName;
+ (void) writeAdSystemToLogFile:(NSString*)content;
+ (void) writeCrashSystemToLogFile:(NSString*)content;
#pragma mark - Dolby
+ (BOOL)isDolbySupported;


+ (NSMutableDictionary *) fillSectionInfo:(NSDictionary *) sectionData;
+ (NSMutableDictionary *) fillEntityInfo:(NSDictionary *) entityData;
@end

