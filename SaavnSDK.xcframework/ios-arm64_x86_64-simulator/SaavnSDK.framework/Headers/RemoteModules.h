//
//  RemoteModules.h
//  Saavn
//
//  Created by Clint Balcom on 4/21/18.
//  Copyright © 2018 Saavn. All rights reserved.
//
@import UIKit;


@interface RemoteModules : NSObject


@property (nonatomic) NSUInteger manualSectionOffset;


#pragma mark - Setters
- (void) removeIndex:(NSUInteger)index;

#pragma mark - Getters
- (BOOL) isLoadingModule:(NSUInteger)index;
- (BOOL) shouldHideModule:(NSUInteger)index;

#pragma mark - Actions
- (void) loadRemoteSection:(NSDictionary *)module atIndex:(NSUInteger)moduleIndex withParams:(NSDictionary *)params
                   success:(void(^)(id successResponse))successBlock andFailure:(void(^)(NSError *errorResponse))failureBlock;


@end

