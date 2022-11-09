//
//  SaavnSDKDoorway.h
//  SaavnSDK
//
//  Created by Rishabh Tiwari on 30/09/21.
//  Copyright © 2021 Saavn. All rights reserved.
//

#ifndef SaavnSDKDoorway_h
#define SaavnSDKDoorway_h
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JioSaavnDelegate.h"
#import "Settings.h"


typedef enum {
    LOGIN_SOURCE_TYPE_JIO  = 0,
    LOGIN_SOURCE_TYPE_NON_JIO = 1,
} JIOSAAVN_SDK_LOGIN_SOURCE;

typedef NS_ENUM(int, JioSaavnViewType) {
    kJioSaavnViewHome,
    kJioSaavnViewSearch,
    kJioSaavnViewBrowse,
    kJioSaavnViewMyMusic,
    kJioSaavnViewJioTunes,
};
@protocol JioSaavnScrollDelegate
@optional
- (void)homeScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)homeScrollViewDidEndDecelerating:(UIScrollView *)scrollView;
- (void)homeScrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;
 
@end
@interface SaavnSDKDoorway : NSObject{
    
}




@property (nonatomic, weak) id <JioSaavnDelegate> delegate;
@property (nonatomic, weak) id <JioSaavnScrollDelegate> scrolldelegate;

+ (SaavnSDKDoorway *) doorway;

//The host app must use this method to manually initialize SDK.
- (void) initializeSDK;

//The host app must use this method to manually initialize SDK along with Theme
// true for dark them and false for light theme
- (void) initializeSDKWithTheme:(BOOL)dark;


/// The host app can call this method when logging out of JioSaavn is required.
/// Notification observer setup is required for this.
- (void) logOutFromJioSaavn;

/// The host app can call this method to get the root controller from the SDK.
///
/// - returns: Home controller of type `UIViewController`
- (UIViewController *) getHomeController;

/// The host app can call this method to get the player view from the SDK.
///
/// - returns: Player view of type `UIView`
- (UIView *) getPlayerView;

- (void) setCurrentNC:(UINavigationController *)navC;

///The host app can call this method to get ViewController instance for tab bar items.
/// - parameter viewId: The viewId corresponding to the ViewController required.
///
/// - returns: The viewController based on the specified `viewId`.
- (UIViewController *) getJioSaavnViewController:(int)viewId;

/// The host app can call this method to get navigation viewController instance for tab bar items.
/// It can be used only to get the Browse, Search and MyLibrary navigationController.
/// - parameter viewId: The viewId corresponding to the NavigationController required.
///
/// - returns: The navigationController based on the specified `viewId`.
- (UINavigationController *) getJioSaavnNavigationViewController:(int)viewId;

/// The host app can call this method to login into JioSaavn with specified `userdata` and `source`.
///
/// - parameter userdata: The NSDictionary.
/// - parameter source: The JIOSAAVN_SDK_LOGIN_SOURCE.
- (void) performZLA:(NSDictionary *)userdata source:(JIOSAAVN_SDK_LOGIN_SOURCE)source;

// The host app can call this method to change the playback state of the player.
- (void) changePlayerPlaybackState:(bool) play;

///The host app can call this method to check the current status of player.
///
/// - returns: BOOL value YES if the player is currently playing else NO.
- (BOOL) isSaavnPlaying;

/// The host app can call this method to pass the current JioTune data.
/// The `data` dictionary must contain following keys:
///  imageUrl, title, subtitle, vcode, digitalServiceId, isActive.
///
/// - parameter data: The NSDictionary.
- (void) handleCurrentJioTuneData: (NSDictionary *)data;

/// The host app can call the deactivate api and pass the response in the parameters.
///
/// - parameter isSuccess: The BOOL value specifying success or failure.
/// - parameter errorMsg: The NSString stating the errorMsg in case of failure.
- (void) deactiveJioTuneResponse:(BOOL)isSuccess errorMsg:(NSString *)errorMsg;

/// The host app can call this method when deeplinking needs to take place based on the `url`.
///
/// - parameter url: The URL.
- (void) handleDeepLinkUrl:(NSURL *) url;

/// The host app can call the setDarkMode method and pass a bool to put app in dark mode
///
/// - parameter set: YES for dark mode and NO for light mode

- (void) setDarkMode:(BOOL) set ;

/// The host app can call the isDarkMode method and check if the SDK is in dark mode
///
///
- (BOOL) isDarkMode;

- (BOOL) isSDKLoggedIn ;

@end
#endif /* SaavnSDKDoorway_h */

