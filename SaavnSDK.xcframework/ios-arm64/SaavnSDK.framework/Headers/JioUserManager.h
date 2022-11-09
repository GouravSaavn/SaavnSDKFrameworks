//
//  JioUserManager.h
//  Saavn
//
//  Created by Shatrughan Singh on 7/23/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>
//#ifndef __SvnSenSDK

//JMSSO Library

//#endif
#define JIO_SAAVN_APP_NAME                  @"JioSaavn"//@"jiomags"
#define JIO_SAAVN_IDAM_APP_NAME             @"RJIL_JioSaavn"//@"RJIL_JioMags"
#define JIO_SAAVN_API_KEY                   @"l7xx77e611b130e44bdd91e5193986704c32"//@"l7xxdc844b1a61fc44e780ad4a8b3f3f79b4"//@"l7xx6859e86d88d5476d84565f5af03a022c"

#define JIO_SAAVN_MEDIA_ANALYTICS_REG_KEY   @"109155008"
#define JIO_SAAVN_MEDIA_ANALYTICS_MEDIA_URL   @"https://collect.media.jio.com/postdata"

#ifdef __SvnSenSDK
#import "SaavnSDKDoorway.h"
#else
#import "JMSSOController.h"
#import "JMSSOUIController.h"
#import "JMSSOResultListener.h"
#import "JIOMediaAnalytics.h"
#import "JMSSOUserInfo.h"
#endif


typedef void (^LoginHandler)(BOOL success, NSDictionary *user);
typedef void (^ZLALoginHandler)(NSDictionary *zlaData);


@interface JioUserManager : NSObject

+ (instancetype) sharedManager;
@property (assign) BOOL isJioLoggedIn;
@property(nonatomic,strong) NSDictionary *savedZLAUserData;
@property(nonatomic,strong) NSDictionary *currentZLAUserData;
@property(nonatomic,assign) BOOL    analyticsInitialized;
@property(nonatomic,assign) BOOL      performAutoLogin;

@property (nonatomic, copy) LoginHandler handler;
@property (nonatomic, copy) ZLALoginHandler zlaLoginhandler;
- (void)setSSORefreshBody:(NSDictionary *)dict;

#pragma mark - ZLA User Getter
- (NSString*) getJToken;
- (NSString*) getLBCookie;
- (NSString*) getSSOToken;
- (NSString*) getSubscriberID;
- (NSString*) getUserID;
- (NSString*) getUniqueID;
- (NSString*) getPhoneNumber;
- (NSString*) getEncryptedPhoneNumber;

#pragma mark - SSO Login
- (void) registerJioMediaSSO;
- (BOOL) isZLAAvailable;
- (BOOL) isJioUserAvailable;
- (BOOL) isJioFullDataAvailable;
- (BOOL) isJioUserDifferent;
- (void) performZLAAndAutoLogin:(void (^)(NSDictionary *zlaData))completion;

#pragma mark - Jio Analytics
- (void) registerJioMediaAnalytics;
- (void) startAnalyticsSession;
- (void) trackJioEvent:(NSString*)event withProperties:(NSDictionary*)dict;

#pragma mark - JIOSaavn Login
- (void) requestJioLogin;
- (void) requestJioLogout;
- (void) requestJioLoginWithCompletion:(void (^)(BOOL success, NSDictionary *user))completion withRefreshToken:(BOOL)isRefreshed;
#ifdef __SvnSenSDK
- (void) requestJioLogin:(NSDictionary *)newZLAUserData source:(JIOSAAVN_SDK_LOGIN_SOURCE) source;
#endif
- (void) updateJioInfo:(BOOL)isRefreshed;
- (void) requiredUpdateJioInfoWithCompletion:(void (^)(BOOL success, NSDictionary *user))completion withRefresh:(BOOL)isRefreshed;
- (void) checkAndSaveCurrentZLAUser:(NSDictionary*)moreInfo;

#pragma mark - Jio Tune
- (void) setJioTune:(NSDictionary*)song isRefresh:(BOOL)refreshing withVcode:(NSString*)vcode withTrackingDict:(NSDictionary*)trackingDict;

#pragma mark - Prompt screen
- (void) viewedAllPromptScreen;
+ (void) viewedJioBannerPromptScreen;

#pragma mark - network check lib
- (void)checkJioNetwork;

- (void) clearSSOData;


- (void) deleteMobileFromZLAUserInfo;
@end
