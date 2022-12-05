//
//  Settings.h
//  New Saavn
//
//  Created by Clint Balcom on 10/2/17.
//  Copyright © 2017 Saavn. All rights reserved.
//
@import UIKit;


typedef enum {
    SK_isDarkMode          = 0,
    SK_isAutoDarkMode      = 1,
    SK_showTabLabels       = 2,
    SK_isExplicitDisabled  = 3,
    SK_cellSecondOption    = 4,
    SK_isAutoPlay          = 5,
    SK_isLyricsEnabled     = 6,
    SK_isAnnotationEnabled = 7,
    SK_isDeviceSettingsEnabled = 8,
    SK_isVideoEnabled      = 9
} SettingsKeys;

typedef enum {
    CSO_None      = 0,
    CSO_Download  = 1,
    CSO_Like      = 2,
    CSO_JioTune   = 3
} CellSecondOptions;


@interface Settings : NSObject


@property (strong, nonatomic) NSUbiquitousKeyValueStore *keyStore;
// Display Options
@property (nonatomic) BOOL isDarkMode, isAutoDarkMode, disableExplicit, isAutoPlay, isLyricsEnabled, isAnnotationEnabled, isDeviceSettingsEnabled, isVideoEnabled;
@property (nonatomic) CellSecondOptions cellSecondOption;
// Homepage Greeting
@property (strong, nonatomic) NSString *homeGreeting;
@property (nonatomic, assign) BOOL dolbySupported;


#pragma mark - Init
+ (Settings *) singleton;

#pragma mark - Auto Dark Mode
+ (void) toggleAutoDarkMode;
- (void) startAutoModeTimer;
- (void) stopAutoModeTimer;
- (void) toggleUseDeviceSettings;

#pragma mark - Explicit Content
+ (void) toggleExplicitContent;

#pragma mark - Video
+ (void) toggleVideo;

#pragma mark - Offline Mode
+ (void) toggleOfflineMode;

#pragma mark - Audio
+ (void) toggleAutoPlay;

#pragma mark - Secondary Row Options
+ (void) setCellSecondOption:(CellSecondOptions)option;
+ (NSString *) getCellSecondOptionStringFromType:(CellSecondOptions)option;
- (CellSecondOptions) getCellSecondOptionTypeFromString:(NSString *)optionStr;

#pragma mark - Key Getters
- (BOOL) getBoolForKey:(SettingsKeys)setting;
- (NSString *) getStringForKey:(SettingsKeys)setting;
- (BOOL) isKeyPresentAtCloud:(SettingsKeys)setting;

#pragma mark - Key Setters
- (void) storeBool:(BOOL)value forKey:(SettingsKeys)setting;
- (void) storeString:(NSString *)value forKey:(SettingsKeys)setting;

#pragma mark - iCloud NSUbiquitousKeyStore
#pragma mark Notifications
- (void) keyStoreChanged:(NSNotification *)notification;
#pragma mark Keys
+ (NSString *) keyFor:(SettingsKeys)setting;

#pragma mark - Helpers
+ (BOOL) isNightTime;
+ (NSString *) nightModeStartTimeString;
+ (NSString *) nightModeEndTimeString;

#pragma mark - Lyrics
+ (void) toggleLyricsMode;
+ (void) toggleAnnotationLyricsMode;


@end

