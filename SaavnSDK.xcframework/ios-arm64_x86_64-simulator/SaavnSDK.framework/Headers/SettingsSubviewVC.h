//
//  SettingsSubviewVC.h
//  New Saavn
//
//  Created by Clint Balcom on 2/8/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import "SaavnVC_n.h"


typedef enum {
    FETCH_NONE = 0,
    //
    FETCH_NOTIFICATIONS_MOBILE = 1,
    FETCH_NOTIFICATIONS_EMAIL = 2,
    FETCH_PROFILE_DATA = 3,
    FETCH_DEVICES = 4
} FetchType;

typedef enum {
    DATA_OTHER = 0,
    DATA_LANGUAGE = 1
} DataType;

@interface SettingsSubviewVC : SaavnVC_n


@property (nonatomic, strong) NSMutableArray *settingOptions;
@property (nonatomic, strong) NSArray *lastSelections;
@property (nonatomic) BOOL allowMultipleSelections, isDirectModal, isLanguageSelector;

// Settings with remote fields/data to fetch.
@property (nonatomic) FetchType fetchType;
@property (nonatomic) DataType dataType;

// A callback method to execute on *every* row tap.
// This is for simple settings subviews where we're just updating settings in realtime.
@property (nonatomic, copy) void(^selectionCheck)(void);

// A callback method to fire on dismissal, if we want to trigger a save, or check for valid data selection.
@property (nonatomic, copy) void(^dismissalCheck)(void);


#pragma mark - Data Handling
- (void) initData;
- (void) fetchSuccess:(NSString *)JSON;
- (void) errorAndDismiss;
- (void) needsSave;

#pragma mark - Data Updates
- (void) updateSelectedItems:(NSIndexPath *)indexPath;
- (void) updateSelectedItems:(NSIndexPath *)indexPath andState:(BOOL) selected;

#pragma mark - Nav Actions
- (void) addSaveButtonToNav;
- (void) saveSettings;
- (void) saveError;
- (void) cancelSettings;
#pragma mark Save Status Display
- (void) beginSaving;
- (void) endSaving:(BOOL)success;


@end

