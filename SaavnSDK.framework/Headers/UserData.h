//
//  UserData.h
//  Saavn
//
//  Created by Clint Balcom on 10/3/13.
//  Copyright (c) 2013 Saavn. All rights reserved.
//

#define CONTEXTUAL_PLAY_LENGTH 50

#ifndef __SvnSenSDK
#import <AccountKit/AccountKit.h>
#import "AppDelegate.h"
#else
#import "SaavnSDKDelegate.h"
#endif
//#import "SaavnVC.h"
#ifdef __SvnSenSDK
//
typedef NS_ENUM(NSInteger, Trigger) {

    TriggerNone = 0,
    TriggerDownload = 1,
    TriggerNoads = 2,
    TriggerJtune = 3 ,
    TriggerFullPro = 4 ,
    TriggerUnlimitedSkip = 5 ,
    TriggerProOnlyVideo = 6 ,
    TriggerVideoPlayback = 7,
    TriggerAddVideo = 8
};
#endif

typedef enum {
    ONBOARD_Save = 0,
    ONBOARD_Follow = 1,
    ONBOARD_Friends = 2,
    ONBOARD_Pro = 3,
    ONBOARD_PageCount
} ONBOARD_PAGES;
#ifndef __SvnSenSDK

typedef enum {
    LOGIN_TYPE_NONE  = 0,
    LOGIN_TYPE_EMAIL = 1,
    LOGIN_TYPE_PHONE = 2,
    LOGIN_TYPE_FB    = 3,
    LOGIN_TYPE_JIO    = 4,
    LOGIN_TYPE_APPLE    = 5
} LOGIN_TYPE;
#endif

#define TUTORIAL_STORE @"tutorials"

@interface UserData : NSObject {
    NSMutableDictionary *userData;
    BOOL loggedIn, isPro, fbLogin, isFBConnect, isJioUser,isShowingClearDownloadPrompt;
    apiCallbackState userReady;
    
    NSString *_loggedInUsername;
    NSString *displayName;
    NSString *song_version;
    
    @public
    NSObject *playerLock;
    NSObject *libraryLock;
    NSObject *fileLock;
}

@property (strong, atomic) NSMutableDictionary *userData;
@property (assign, nonatomic) apiCallbackState userReady;
@property (assign, nonatomic) LOGIN_TYPE loginType ;
@property (nonatomic) BOOL loggedIn, isPro, isFreemium, fbLogin, isFBConnect, isJioUser,qrCode_enabled, isJioTuneAvailable, isJioTuneLimitFromBackend;
@property (nonatomic, assign) BOOL fetchingPlaylistSongsInUI, fetchingPlaylistSongsInBackground;
@property (weak, nonatomic) NSObject *loginCallbackObject, *loginErrorObject;
@property (copy, nonatomic) NSString *loginCallbackSelector, *loginErrorSelector;
@property (strong, nonatomic) NSString *song_version;
@property (strong, nonatomic, getter=getUserRegisteredPhone) NSString *userRegisteredPhone;
@property (strong, nonatomic, getter=getHeaderEnrichedPhone) NSString *headerEnrichedPhone;
@property (assign, nonatomic) BOOL isShowingClearDownloadPrompt;
@property (nonatomic) NSInteger jioTunesLeft, totalAllotJioTune, videosRemaining, maxVideoLimit;
@property (assign, nonatomic) BOOL rateCapApplicable;


#pragma mark - Class Methods
+ (UserData *) getSingleton;

#pragma mark - Log In / Out
- (void) logIn:(NSString *)email andPassword:(NSString *)password;
- (void) loginResponse:(NSDictionary *)responseDic withLoginType:(LOGIN_TYPE) loginType;
- (void) loginResponse:(NSDictionary *)responseDic withLoginType:(LOGIN_TYPE) loginType skipOtpVerification: (BOOL) skipOtpVerification;
- (void) logOut;
- (void) logoutResponse:(NSString *)responseString;

#pragma mark - Sign Up
- (void) signUp:(NSString *)email andPassword:(NSString *)password andConfirmation:(NSString *)confirm;

#pragma mark - Facebook Handling
- (void) FBLogIn;
- (void) FBLoginSuccessful:(NSDictionary *)fbData;
- (void) unSyncFB;
- (void) FBLogOut;
- (BOOL) isFacebookLoggedIn;
- (void) FBTokenChangeAndSendtoBackend;
- (void) FBTokenExtended;

#pragma mark - Facebook SDK Methods
- (void) openSession:(NSArray *)perm;

- (void) openSession: (NSArray *) perm fromViewController: (UIViewController *) viewController;

#pragma mark - User Details
+ (NSString *) getUserImage:(NSUInteger)size;

#pragma mark - User Status
- (void) setProStatus:(BOOL)isUserPro;
- (void) setFreemiumStatus:(BOOL)isUserPro;
+ (void) showProROWPaywallModalIn:(UIViewController *)targetVC;
- (BOOL) isValidPro;

#pragma mark - Tutorial View States
+ (BOOL) didViewTutorial:(NSString *)key;
+ (void) setTutorialViewed:(NSString *)key;

#pragma mark - Playlist Handling
- (int) songsInLibrary;
- (void) deletePlaylist:(NSString *)listId;

#pragma mark - Song Handling
+ (int) numCachedSongs;
+ (int) numCachedSongsQueued;
+ (void) cacheSongs:(NSArray *)songs via:(UIViewController *)targetVC;
+ (void) cacheSongs:(NSArray *)songs via:(UIViewController *)targetVC withContext:(NSDictionary*)context;
+ (BOOL) readyToDownloadSongs: (NSArray *) songs via: (UIViewController *) targetVC withContext:(NSDictionary*)context;
+ (BOOL) readyToDownloadSongs:(UIViewController *)targetVC;
+ (BOOL) isUserPausedDownloading;
+ (void) setPauseStateOfDownloading:(BOOL) value;

#pragma mark - Public Methods (Getters and Setters for User Settings)
+ (void) setUserSelectedBitrate:(NSInteger)rate;
+ (NSInteger) getUserSelectedBitrate;
+ (void) setAutoBitrate:(BOOL)value;
+ (BOOL) getAutoBitrate;
+ (NSString *) getUserStreamingRateString;
+ (NSInteger) getUserCacheQuality;
+ (NSString *) getUserCacheQualityString;
+ (NSInteger) defaultNetworkBitrate;
+ (void) shouldCacheOverCellular:(BOOL)flag;
+ (BOOL) canCacheOverCellular;
+ (void) shouldStreamToFacebook:(BOOL)flag;
+ (BOOL) isStreamToFacebookEnabled;
+ (NSString *) getAppVersion;
+ (void) setAppVersion;
+ (BOOL) languagesSet;
+ (void) languagesSetter:(BOOL)value;

+ (void) setDeviceToken:(NSString *)token;
+ (NSString *) getDeviceToken;
+ (void) setPendingSongsWhenPaused:(int) pendingCount;
+ (int) getPendingSongsWhenPaused;
+ (BOOL) connectionOkayForCache;
+ (NSArray *) getOnboardPages;
+ (NSString *) getUserDevices;
+ (NSInteger) getUserDevicesCount;


#pragma mark - audio bitrate mapping
+ (NSInteger) mappedAudioQualityFromAACToMP3:(NSInteger)value;
+ (NSInteger) mappedAudioQualityFromMP3ToAAC:(NSInteger)value;

- (void) clearUserSelectedBitrate;

+ (BOOL) readyToDownloadSongs: (NSArray *) array via: (UIViewController *) via;

#pragma mark - 2.x METHODS TO BE INTEGRATED, UPDATED, OR REMOVED

- (NSString *) getLoggedInUserName;
- (void) setPaywallLoggedInState: (NSDictionary *) dict;
- (void) setLoggedInState:(NSDictionary*) dict;
- (void) setGlobalData:(NSDictionary *) dict;
- (NSString*) getUsersLoggedInState;
- (NSString*) getUsersProModeWithLoginMode:(NSString *)login_mode;
- (NSString *) getUsersConnectionState;

- (NSArray *) getAvailablePhoneNumbers;
+ (void) finishInitialLibrarySyncing:(BOOL) value;
+ (BOOL) isInitialLibrarySyncCompleted;

#pragma mark - LIBRARY methods
- (void) saveLibraryPlayerState: (id) currentLibrarySong;
- (void) removeLibraryPlayerState;
// This API is used to refresh an existing library mode around the currently playing song
- (void) refreshMyLibraryQueueFromSongID: (NSString *) songIdToPlay downloadsOnly: (BOOL) downloadsOnly;

#pragma mark - misc
- (void) clearAllCookies;
- (void) deleteDuplicateCookies;
- (void) setGarbageCookie;
- (BOOL) skipLimitReached:(NSInteger) playedCount;

#pragma mark - iCloud Keychain password autofill
- (NSMutableArray *) getSavedCredentialsFromKeyChain;
- (void) writeCredentialsToKeychain:(NSString *)username andPassword : (NSString *)password;

#pragma mark - JIO Data
- (NSDictionary*) getJioUserData;
- (BOOL) getJioTrialInfo;
- (void) updateJioTuneAvailable;
- (BOOL) isJioTuneLimitReached;
- (void) fetchJioTuneAvailability;


- (BOOL) isHandlingNeedForClearDownloads:(NSDictionary*) userData;
- (void) handleClearDownloads:(NSDictionary *)userData;
- (void) handleClearDownloadsThroughApi:(NSDictionary *)userData;

- (void) checkAppleSignIn;


#pragma mark - Tiered pro

+ (NSInteger) getTriggerType:(NSString*)type;
+ (BOOL) isUserHasAccess:(NSInteger)trigger;
+ (BOOL) isUserFullPro;
+ (BOOL) isUserPlusPro;
+ (BOOL) isUserHasPlusAccess;
+ (BOOL) isUserHasProAccess;
+ (BOOL) isProPurchased;
+ (BOOL) shouldShowMiniPlayer;
+ (BOOL) shouldShowAds;
+ (BOOL) canDownload;
+ (BOOL) canSetJioTune;
+ (BOOL) canSkipMedia;
+ (BOOL) isDeviceAuthorised;

- (void) updateUserdata:(NSDictionary *) dict;

#pragma mark - Videos
- (void) updateFreeVideoAvailable;
- (BOOL) isFreeLimitReached;
- (BOOL) isLastFreeVideo;
@end








