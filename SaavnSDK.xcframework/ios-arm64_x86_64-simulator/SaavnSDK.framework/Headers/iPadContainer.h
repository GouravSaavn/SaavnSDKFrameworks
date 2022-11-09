//
//  iPadContainer.h
//  Saavn
//
//  Created by Clint Balcom on 1/20/14.
//  Copyright (c) 2014 Saavn. All rights reserved.
//


@interface iPadContainer : UIViewController


@property (nonatomic) BOOL isLandscape;


#pragma mark - Orientation Changes
- (UIDeviceOrientation) getLastOrientation;

#pragma mark - ProRow Splash
- (void) hideProRowCover:(BOOL)animated;


@end

