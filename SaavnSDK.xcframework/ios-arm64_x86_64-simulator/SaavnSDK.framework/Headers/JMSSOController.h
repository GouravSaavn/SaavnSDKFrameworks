//
//  JMSSOController.h
//  JMSSOController
//
//  Created by Rishab Bokaria on 11/03/16.
//  Copyright © 2016 Reliance Jio Infocomm Ltd. All rights reserved.
//

//version 2.4

#import <Foundation/Foundation.h>
#import "JMSSOResultListener.h"
#import "JMSSOResponseListener.h"
#import "JMSSOModeType.h"

extern NSString *const JMSSOControllerErrorDomain;

@interface JMSSOController : NSObject

+ (NSString *)libVersion;
+ (void)initializeSSOControllerWithAppName:(NSString *)appName IDAMAppName:(NSString *)idamAppName APIKey:(NSString *)kAPIKey mode:(JMSSOModeType )aMode listener:(id<JMSSOResultListener>)aListener;
+ (instancetype)getInstance;

- (instancetype)init NS_UNAVAILABLE __attribute__((unavailable("Must call getInstance instead.")));
+ (instancetype)new NS_UNAVAILABLE __attribute__((unavailable("Must call getInstance instead.")));

- (BOOL)isNetworkAvailable:(NSError **)error;
- (BOOL)isConnectedToWiFi;

- (void)enableZLAOverWiFi:(BOOL)enable;
- (BOOL)isZLAEnabledOverWiFi;

- (BOOL)canLoginViaZLA;
- (BOOL)canAutoLoginViaZLA;
- (BOOL)isZLAUserAvailable;

- (NSString *)signUpURL;
- (NSString *)forgotPasswordURL;

- (NSArray<JMSSOUser>*)sharedUsers;
- (id<JMSSOUser>)appUser;
- (BOOL)removeSharedUser:(id<JMSSOUser>)user;

- (void)loginWithUserName:(NSString *)userName passWord:(NSString *)aPassWord listener:(id<JMSSOResponseListener>)aListener;
- (void)loginWithZLA:(id<JMSSOResponseListener>)aListener;
- (void)autoLoginWithZLA:(id<JMSSOResponseListener>)aListener;

- (void)loginWithUser:(id<JMSSOUser>)user listener:(id<JMSSOResponseListener>)aListener;

- (void)onCompleteZLALogin:(BOOL)success;

//- (NSString *)refreshSessionToken;
- (NSDictionary *)refreshSessionTokenDict;
- (void)logout;

- (BOOL)isAppUserSessionValid;//vinit_added

- (void)getOTPForUserIdentifier:(NSString *)phoneNumber listener:(id<JMSSOResponseListener>)aListener;
- (void)verifyIdentifierWithOTP:(NSString *)otpNumber UserIdentifier:(NSString *)phoneNumber listener:(id<JMSSOResponseListener>)aListener;

@end

