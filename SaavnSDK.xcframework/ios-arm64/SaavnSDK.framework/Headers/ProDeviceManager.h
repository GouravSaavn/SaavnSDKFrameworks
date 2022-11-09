//
//  ProDeviceManager.h
//  Saavn
//
//  Created by Jagadeesh Dyaberi on 11/11/13.
//  Copyright (c) 2013 Saavn. All rights reserved.
//
@import UIKit;
@interface ProDeviceManager : NSObject
{
    volatile BOOL isValidDevice;
    

}

@property (nonatomic, assign) BOOL isValidDevice;

+ (ProDeviceManager *) getSingleton;

- (BOOL) isDeviceTokenValid;
- (void) registerDevice;
- (void) registerDeviceResponse:(NSString*)responseString;
- (void) deregisterDevice;
- (void) deregisterDeviceWithId: (NSString *)deviceId;
- (void) deregisterDeviceResponse: (NSString *)responseString;


- (void) setDeviceValidity:(BOOL) token;
- (void) checkDeviceStatus;

@end
