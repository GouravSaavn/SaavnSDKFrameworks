//
//  AppAlert.h
//  Saavn
//
//  Created by Clint Balcom on 11/8/13.
//  Copyright (c) 2013 Saavn. All rights reserved.
//
#import <UIKit/UIKit.h>

typedef enum {
    STANDARD = 1,
    SUCCESS = 2,
    ERROR = 3,
    LIGHT = 4
} ALERT_TYPE;

@interface AppAlert : UIView

@property (nonatomic, strong) UIViewController *parentVC;
@property (nonatomic) NSTimeInterval timer;
@property (nonatomic, strong) UIView *simpleAlert, *playerBadge, *cacheBar;
@property (nonatomic, strong) UILabel *simpleAlertLabel, *playerBadgeLabel, *cacheBarLabel;
@property (nonatomic) BOOL simpleAlertShowing, simpleAlertAnimating, playerBadgeShowing, playerBadgeAnimating;

#pragma mark - Class Methods
+ (AppAlert *) getSingleton;

#pragma mark - Helper
- (void) setTimer:(NSTimeInterval)newTimer;

#pragma mark - Simple Alerts
- (void) simpleAlert:(NSString *)title ofType:(ALERT_TYPE)type inVC:(UIViewController *)vc;
- (void) simpleAlert:(NSString *)title ofType:(ALERT_TYPE)type;
- (void) dismissAlert;

#pragma mark - Action Alerts
- (void) actionAlert:(NSString *)title withSubtitle:(NSString *)subtitle andButtons:(NSArray *)buttons ofType:(ALERT_TYPE)type;
- (void) dismissActionAlert;

#pragma mark - Player Badge
- (void) showPlayerBadge:(int)count;

#pragma mark - Cache Bar
- (void) blockCacheDisplay:(BOOL)shouldBlock;
- (BOOL) isCacheBlocked;
- (void) showCacheBar;
- (void) hideCacheBar;
- (void) updateCacheBar:(int)songsLeft;

@end
