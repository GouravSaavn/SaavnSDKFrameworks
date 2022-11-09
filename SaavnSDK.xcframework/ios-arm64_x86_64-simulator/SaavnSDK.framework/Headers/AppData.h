//
//  AppData.h
//  Saavn
//
//  Created by Clint Balcom on 9/28/13.
//  Copyright (c) 2013 Saavn. All rights reserved.
//

#ifndef __SvnSenSDK
#import "Reachability.h"
#else
#import "JSReachability.h"
#endif
@import UIKit;

//#ifdef __SvnSenSDK
typedef NS_ENUM(NSInteger, AFReachabilityStatus);
typedef NS_ENUM(NSUInteger, apiCallbackState);

//
//#endif




#ifndef __SvnSenSDK
extern NSString *sApiServerHostName;
extern NSString *sSocketServerHostName;
#endif

extern const NSString *kCrossFadeEnable;
extern const NSString *kCrossFadeDuration;
extern const NSString *kCrossFadeGainChange;
extern const NSString *kCrossFadeDefault;
@interface AppData : NSObject {
    apiCallbackState dataReady;

    JSReachability *internetReach;
    BOOL reachabilityReady, isOnlineTimerRunning, isOfflineTimerRunning, appLaunched,isAutoPlayOn,isCrossFadeOn;
    volatile BOOL explicitOfflineMode, implicitOfflineMode, radioMode;
    NSTimer *onlineTimer;
    NSTimer *offlineTimer;
    NSString *trackingServer;
    BOOL af_enabled;
    
    BOOL isDownloading;
    BOOL isIpadContainerLoaded;
    int songsLeft;
    int requestedSongs;
    NSTimeInterval last_registerdevice_time;
    
    BOOL jio_analytics_enabled, cleverTap_enabled, jioUserAvailable;
    BOOL device_mgmt_enabled;
    BOOL qrCode_enabled;
    BOOL dolby_enabled;
    BOOL force_https;

    BOOL homepod_enabled;
#ifndef __SvnSenSDK

    GoProCTAItem   *pro_cta_item;
#endif

}


// TODO: Remove this, once we fully remove PlayerVC.
// It still has a bunch of references, and it's not worth commenting them all out.
@property (strong, nonatomic) NSMutableDictionary *nowPlaying;

@property (assign, nonatomic) UIApplicationState saavnAppState;
#ifndef __SvnSenSDK

@property (strong, nonatomic) AppDelegate *saavnAppDelegate;
#endif
@property (nonatomic, assign) apiCallbackState dataReady;
@property (nonatomic) BOOL reachabilityReady, isDownloading, appLaunched, carriersAvailable, crossFadeEnabledFromBE;
@property (assign, nonatomic) BOOL explicitOfflineMode, implicitOfflineMode, radioMode;
@property (strong, nonatomic) JSReachability *internetReach;
@property (strong, nonatomic) NSString *trackingServer, *shareModalVariant , *shareTriggerVariant;
@property(nonatomic) BOOL af_enabled, eventLogEnabled,homepod_enabled;

//TODO:SS - Remove this line for code before going live
@property(nonatomic) BOOL deletemsisdn, hackcrbt, hackssolib;


@property (nonatomic) int songsLeft;
@property (nonatomic) int requestedSongs;
//@property (strong, nonatomic) NSMutableArray *topSearchesData;
@property (nonatomic, assign) NSTimeInterval last_registerdevice_time;

@property(nonatomic) BOOL jio_analytics_enabled, cleverTap_enabled,device_mgmt_enabled,force_https,dolby_enabled;

@property(nonatomic,assign) BOOL isAppUpgrade;
@property(nonatomic,assign) BOOL isJioUpdateRequireOnAppUpgrade;
#ifndef __SvnSenSDK

@property(nonatomic,strong) GoProCTAItem   *pro_cta_item;
#endif

#pragma mark - Class Methods
+ (AppData *) getSingleton;
- (void) explicitInit;

#pragma mark - Data Methods
- (void) fetchInitData;
//- (void) fetchHomepageData;
//- (void) parseHomepageData:(NSString *)JSON;
//- (NSDictionary *) getHomePageData;
//- (NSMutableArray *) getTopSearchesData;
//- (NSArray *) getSupportedLanguages;
//- (NSDictionary *) getAppLaunchData;
//- (void) setGlobalConfig:(NSDictionary *)dict;
//- (NSString *) getGlobalConfigVal:(NSString *)key;
//- (NSObject *) getGlobalConfigObject:(NSString *)key;
//- (void) replaceProStatus: (NSDictionary *) prostatus;
- (void) parseTrackingServer:(NSDictionary*)dict;
- (void) parseSDKFlagInfo:(NSDictionary *) globalConfig;

#pragma mark - Public Methods
+ (NSString *) getAppVersion;
#ifdef __SvnSenSDK
+ (NSString *) getPartnerAppVersion;
+ (NSString *) getReadableAppVersion;
#endif
+ (NSString *) getBuildNumber;
+ (NSString *) getCountryName;
+ (NSString *) getBitrate;
+ (NSString *) getFreeDiskSpaceString;
+ (NSString *) getCarrierNameForNetwork;
+ (BOOL) shouldShowBanner;

// Users Languages – Getters & Setters
+ (void) setLanguage:(NSString *)lang;
+ (void) setLanguages:(NSArray *)langs;
+ (NSString *) getLanguage;
+ (NSArray *) getLanguagesArray;
+ (NSString *) getLanguagesStringWithFormatting:(BOOL)formatted;

// User Settings.
+ (NSArray *) getDownloadQualityOptions;

// Radio language support.
+ (BOOL) isRadioSupported;
+ (BOOL) isRadioSupportedFor:(NSString *)language;
+ (NSString *) getSupportedRadioLanguagesList;

// Surprise Me Handling
+ (NSArray *) getSurpriseMeIDsArray;
+ (BOOL) isAnySurpriseMe:(NSString *)listId;

// Top 15
+ (NSDictionary *) getTop15s;
+ (NSArray *) getTop15IDsArray;
+ (BOOL) isAnyTop15:(NSString *)listId;
+ (NSString *) getLangugageOfTop15ID:(NSString *)listId;

// Ipad Video Support
+ (BOOL) isVideoSupported;

#pragma mark - Cache Status Bar Display
- (void) showCacheStatus:(int)songsRemaining;
- (void) hideCacheStatus;
- (BOOL) isCacheing;

+ (NSString*) getCurrentNetworkType;
+ (NSString*) getCountryCode;
+ (NSString*) getCurrentNetworkString;

- (void) initOfflineMode;
- (BOOL) isRadioMode;
- (BOOL) isIpadContainerLoaded;
- (void) setIpadContainerLoaded;
- (NSString*) getTrackingServer;

#pragma mark - Crossfade

- (void) setCrossFade: (BOOL) show;
- (void) setCrossFadeDuration: (int) duration;
- (void) setCrossFadeGainChange: (int) gain;

- (BOOL) crossFadeEnabled;
- (int) getCrossFadeDuration;
- (int) getCrossFadeGainChange;

#pragma mark - Allow Generate Crash
- (void) allowCrashForDebugging: (BOOL) allowCrash;
- (BOOL) getCrashStateForDebugging;

#pragma mark - Appsflyer
- (BOOL) isAppsflyerEnable;

- (BOOL) isJioAnalyticsEnabled;
- (BOOL) isCleverTapEnabled;
- (BOOL) isJioTuneEnabled;
- (BOOL) isDeviceMgmtEnabled;
- (BOOL) isdDolby_enabled;

#pragma mark - Network Status
- (BOOL) isInOfflineMode;
- (BOOL) isSoftOfflineMode;
- (BOOL) isHardOfflineMode;
- (void) unsetImplicitOffline;
- (void) goOfflineModal;
- (void) goOnlineModal;
- (void) goOfflineDirect;
- (void) updateTabsForOffline:(BOOL)isOffline;
- (void) setImplicitOffline;
- (void) setImplicitOfflineImmediate;
- (void) unsetHardOffline;
- (void) setHardOffline;
- (void) stopOnlineTimerExpiry;
- (void) stopOfflineTimerExpiry;
#ifdef __SvnSenSDK
- (void) processReachability: (AFReachabilityStatus) status forceHandle:(BOOL)mustHandle;
#else
- (void) processReachability: (AFNetworkReachabilityStatus) status forceHandle:(BOOL)mustHandle;
#endif
- (void) monitorReachability;
- (BOOL) canMakeNetworkRequest;
+ (BOOL) isConnected;
#ifdef __SvnSenSDK
+ (AFReachabilityStatus) getNetworkStatus;
#else
+ (AFNetworkReachabilityStatus) getNetworkStatus;
#endif

#pragma mark - Upgrade
- (BOOL) needToShowUpgradeScreen:(NSDictionary*) update_config;
- (BOOL) isUpgradeNeeded:(NSDictionary*)dict;

#pragma mark - A/B testing data parsing
- (void) setupABTestingBuckets: (NSDictionary *) backendResponse;

- (void) parseProCTA:(NSDictionary *) dict;

- (BOOL) isJioUpdateRequired;
- (void) setJioUpdateRequired:(BOOL)value;
- (void) initAfterSetup;
@end
