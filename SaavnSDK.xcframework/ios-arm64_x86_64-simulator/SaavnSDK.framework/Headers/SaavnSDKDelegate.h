//
//  SaavnSDKDelegate.h
//  SaavnSDK
//
//  Created by Rishabh Tiwari on 18/10/21.
//  Copyright © 2021 Saavn. All rights reserved.
//


#import <Foundation/Foundation.h>
// Libraries
//#import "JSReachability.h"

// Parent Controllers
#import "SaavnNC.h"
#ifndef __SvnSenSDK
#import "SaavnTC.h"
#import "SaavnTabBar.h"
#endif
#import "MiniPlayer.h"

#import "SaavnVC_n.h"

// View Controllers
#import "HomeVC.h"
#import "SearchVC.h"
#import "VideoPlayerVC.h"
#import "BrowseVC.h"
#import "MyLibraryVC.h"

// iPad
#import "iPadContainer.h"

extern NSString *sApiServerHostName;
extern NSString *sSocketServerHostName;
typedef enum {
    LOGIN_TYPE_NONE  = 0,
    LOGIN_TYPE_EMAIL = 1,
    LOGIN_TYPE_PHONE = 2,
    LOGIN_TYPE_FB    = 3,
    LOGIN_TYPE_JIO    = 4,
    LOGIN_TYPE_APPLE = 5
} LOGIN_TYPE;

typedef NS_ENUM(NSUInteger, apiCallbackState){
    IN_PROGRESS, CALL_SUCCESS, CALL_FAILURE
};

typedef enum {
    Tab_Home,
    Tab_Search,
    Tab_Player,
    Tab_Browse,
    Tab_MyLibrary,
    Tab_JioTune
} MainTabs;

NS_ASSUME_NONNULL_BEGIN
typedef enum _errorType {
    ERROR_NONE, ERROR_NOCONNECTIVITY, ERROR_HOMEDATA, ERROR_LAUNCHDATA
} errorType;


// iOS9 Default Quick Actions
static NSString *quickSearch = @"shortcutSearch";
static NSString *quickTop15 = @"shotcutTop15";
static NSString *quickHistory = @"shortcutHistory";
static NSString *quickKeepListening = @"shortcutKeepListening";

@interface SaavnSDKDelegate : NSObject{
    BOOL loggedIn, fbLogin, pendingForegroundEvent;
    
    // MERGED from 2.x ... to be cleaned up, fully integrated, or removed.
    NSString *_loggedInUsername;
    NSString *displayName;
    NSString *geo;
    BOOL firstTimeTrialOrPro;
    float notificationTimeout;
    __block UIBackgroundTaskIdentifier backgroundTaskId;
    
    BOOL overrideRegisterPushNotification;
    NSDictionary *payload;          // when a push notification is received while the app is not running
    NSURL *openUrl;                 // when the app is launched from a externelurl
    
    // These variables are only used for testing various carrier and dataplan combinations using dfp easter eggs
    NSString *carrier, *dataPlan;
    NSArray *fb_permissions;
    NSString *deeplinkType;
    NSString *utmParams;
    NSString *deeplinkTopSrc,*deeplinkTopSrcId,*deeplinkTopSrcType;
    
    // Flag to present enhanced deep link modals: settings & go pro
    NSString *enhancedDeepLinkModalType;    // when settings or go pro modal needs to be presented on app launch
    UIImageView *MPContainer;
}

+ (SaavnSDKDelegate *) doorway;


#pragma mark - Properties

@property (strong, nonatomic) UIWindow *window;
#ifndef __SvnSenSDK
@property (strong, nonatomic) SaavnTC *tabBarController;
#endif
@property (nonatomic) BOOL playerOpen;

#pragma mark - Launch Screen
- (void) dismissLaunchScreen;

#pragma mark - Setters
- (void) setParentAppNC: (UINavigationController *)nc;
- (void) setParentAppNCAsCurrentNC;
- (void) setCurrentNC: (UINavigationController*)nc;

// JioTune
- (void) handleCurrentJioTuneData: (NSDictionary *)data;
- (void) deactiveJioTuneResponse:(BOOL)isSuccess errorMsg:(NSString *)errorMsg;

#pragma mark - Getters
- (SaavnVC_n *) getRootVC:(MainTabs)tab;
- (SaavnNC *) getRootNC:(MainTabs)tab;
//for upgrade
- (VideoPlayerVC *) getPlayerVC;
- (UINavigationController *) getCurrentNC;
- (MiniPlayer *) getMiniPlayer;


#pragma mark -
#pragma mark - PRE 6.0 ↓
#pragma mark -

//for upgrade
//@property (strong, nonatomic) JSReachability *internetReach;

@property (nonatomic) float notificationTimeout;
@property (nonatomic) int proBenefitFrequencyPerDay;
@property (nonatomic, assign) BOOL overrideRegisterPushNotification, pendingForegroundEvent, blockRefresh, forceWatchUpdate,showProBenefitPromptForNewUser,showProBenefitPrompt;
@property (nonatomic, assign) volatile BOOL appEnteredForegroundAtleastOnce; // Dont schedule downloads if this flase
@property (nonatomic, strong) NSURL *openUrl;
@property (nonatomic, strong) NSDictionary *payload;
@property (nonatomic, retain) NSString *carrier;
@property (nonatomic, retain) NSString *dataPlan;
@property (nonatomic, retain) NSString *geo;
//@property (nonatomic, strong) NSString *enhancedDeepLinkModalType;
@property (nonatomic, strong) UIImageView *MPContainer;

// iPad
@property (strong, nonatomic) iPadContainer *iPadView;
@property (strong, nonatomic) UIView *iPadStatusFill, *iPadPlayerContainerBevel;

// ProRow Setup
@property (nonatomic, strong) NSString *splashGroup, *proGroup, *loginWallType;
// Orientation Support for iPhone
@property (nonatomic, assign) BOOL allowRotation;


#pragma mark - Getters for root viewControllers
//for upgrade
//- (PlayerVC *) getPlayerViewController;
- (HomeVC *) getHomeViewController;
- (SearchVC *) getSearchViewController;
- (MyLibraryVC *) getMyMusicViewController;
- (BrowseVC *) getBrowseViewController;
- (UIViewController *)getJioTunesController;

#pragma mark - Getters for root navigationControllers
- (SaavnNC *) getHomeNavigationController;
- (SaavnNC *) getSearchNavigationController;
- (SaavnNC *) getBrowseNavigationController;
- (SaavnNC *) getLibraryNavigationController;
- (SaavnNC *) getPlayerNavigationController;
// - (void) setCurrentTab:(NSInteger) tabIndex;

#pragma mark - Network Status
- (void) throwConnectionError:(errorType)error;
- (void) clearConnectionAlert;
- (void) retryDefaultConfigOnError:(id)sender;

#pragma mark - Handling Deep Link
- (BOOL) convertPermaUrlToDeepLink:(NSString *)targetURLString;
- (BOOL) handleDeepLinkUrl:(NSURL *)url;
- (NSDictionary *)parseURLParams:(NSString *)query;
- (BOOL) handlePermaUrl: (NSURL *)url;
- (BOOL) OpenExternalURL:(NSURL *)url;
- (void) checkForiPADdeepLink;
- (BOOL) isIpadDeepLinkPending;

#pragma mark - Others
- (void) proBookkeepingOnLaunch;
- (BOOL) consumePendingForegroundEvent;
- (void) debugLogLaunchTime;
- (void) processPendingCallbacks;
- (void) processPendingSearchCallbacks;
- (BOOL) didAppEnteredForegroundAtleastOnce;
- (void) prepareForWatchApp;


- (void) sendWeeklyTop15Info:(NSString *) playlistID;
- (void) updateWeeklyTop15Info:(NSDictionary *) playlistInfo;
- (void) sendRadioInfo;
- (void) setMPDetails:(NSDictionary *)theSongData withArt:(BOOL)reloadArt;

- (void) repaintPlayerQueueOnUpdate;
- (void) updateDBOnUpdate;

/*
 - (void) checkForProExpiryModals:(UIViewController *) viewController;
 - (void) launchWebView:(NSString *) url;
 - (NSInteger) countDownloadedSongs;
 - (NSInteger) countDownloadedSongsinPlaylist:(NSArray *)contents;
 */

- (void) initializeDelegate:(BOOL) dark;
- (void) endBGTaskIFAny;
- (BOOL) isDeeplinkHandlerActive;

- (void) initializeDelegate;
- (void) logOutFromJioSaavn;
- (void) trackEventFor:(int) viewId;

- (void) setCurrentTab: (MainTabs)selectedTab;
- (MainTabs) getCurrentTab;
- (BOOL) isPlaying;
@end

NS_ASSUME_NONNULL_END
