//
//  JMSSOResponseListener.h
//  libJMSSO
//
//  Created by Rishab Bokaria on 05/07/16.
//  Copyright © 2016 Reliance Jio Infocomm Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMSSOUserInfo.h"

@protocol JMSSOResponseListener <NSObject>

- (void)onSSOLoginComplete;
- (void)onSSOLoginSuccess:(id<JMSSOUser>)user;
- (void)onSSOLoginFailed:(NSError *)error userType:(JMSSOUserType)aUserType;
- (void)onSSOOTPIdentifierSuccess:(BOOL)boolValue;

@end
