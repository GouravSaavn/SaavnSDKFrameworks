//
//  JMSSOUNPWUserInfo.h
//  libJMSSO
//
//  Created by Rishab Bokaria on 29/06/16.
//  Copyright © 2016 Reliance Jio Infocomm Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMSSOUserInfo.h"

@protocol JMSSOUNPWUser <NSObject, JMSSOUser>

- (NSString *)getOtpValidatedDate;
- (NSString *)getPasswordExpiry;
- (NSString *)getBillingId;
- (NSString *)getProfileId;
- (NSString *)getProfileName;
- (NSString *)getMail;
- (NSString *)getMobile;
- (NSString *)getUid;
- (NSString *)getUnique;

@end
