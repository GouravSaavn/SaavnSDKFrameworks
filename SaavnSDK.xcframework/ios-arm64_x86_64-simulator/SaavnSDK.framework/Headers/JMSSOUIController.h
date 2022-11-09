//
//  JMSSOUIController.h
//  libJMSSOUI
//
//  Created by Rishab Bokaria on 12/07/16.
//  Copyright © 2016 Reliance Jio Infocomm Ltd. All rights reserved.
//


//version 2.4

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JMSSOController.h"

@interface JMSSOUIController : NSObject

+ (NSString *)libVersion;
+ (void)initializeSSOUIControllerWithAppName:(NSString *)appName IDAMAppName:(NSString *)idamAppName APIKey:(NSString *)kAPIKey mode:(JMSSOModeType)aMode listener:(id<JMSSOResultListener>)aListener;

+ (instancetype)getInstance;



- (instancetype)init NS_UNAVAILABLE __attribute__((unavailable("Must call getInstance instead.")));
+ (instancetype)new NS_UNAVAILABLE __attribute__((unavailable("Must call getInstance instead.")));

- (void)setThemePath:(NSString *)themePath;



- (NSBundle *)getResourcesBundle;
- (UIViewController *)getViewController;
- (void)dismissSSOController;
- (BOOL)checkAndPerformAutoLoginViaZLA;

- (BOOL)isOTPEnabled;
- (void)setOTPEnabledDisable:(BOOL)isEnable;
@end
