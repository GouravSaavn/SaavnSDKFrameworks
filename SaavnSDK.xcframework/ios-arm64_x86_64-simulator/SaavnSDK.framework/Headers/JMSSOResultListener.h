//
//  JMSSOResultListener.h
//  libJMSSO
//
//  Created by Rishab Bokaria on 05/07/16.
//  Copyright © 2016 Reliance Jio Infocomm Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMSSOUNPWUserInfo.h"
#import "JMSSOZLAUserInfo.h"
#import "JMSSOOTPUserInfo.h"

@protocol JMSSOResultListener <NSObject>

- (BOOL)onUserLoggedOut;

- (BOOL)onUNPWLoginSuccess:(id<JMSSOUNPWUser>)user;
- (BOOL)onUNPWLoginFailed:(NSError *)error;

- (BOOL)onZLALoginSuccess:(id<JMSSOZLAUser>)user;
- (BOOL)onZLALoginFailed:(NSError *)error isAutoLogin:(BOOL)kIsAutoLogin;

- (BOOL)onOTPLoginSuccess:(id<JMSSOOTPUser>)user;
- (BOOL)onOTPLoginFailed:(NSError *)error;

- (void)onNotifyUserUpdate;

@end
