//
//  JMSSOUserInfo.h
//  libJMSSO
//
//  Created by Rishab Bokaria on 29/06/16.
//  Copyright © 2016 Reliance Jio Infocomm Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, JMSSOUserType)
{
    JMSSOUserTypeUNPW = 1,
    JMSSOUserTypeZLA,
    JMSSOUserTypeOTP
};


@protocol JMSSOUser <NSObject>

- (NSString *)getjToken;
- (NSString *)getLbCookie;
- (NSString *)getCommonName;
- (NSString *)getPreferredLocale;
- (NSString *)getSsoLevel;
- (NSString *)getSubscriberId;
- (NSString *)getSsoToken;
- (JMSSOUserType)getUserType;

- (NSDictionary *)getUserExtra;
- (NSString *)getUserTypeTitle;

@end

