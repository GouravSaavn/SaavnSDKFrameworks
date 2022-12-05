//
//  SegmentTabs.h
//  New Saavn
//
//  Created by Clint Balcom on 2/6/18.
//  Copyright © 2018 Saavn. All rights reserved.
//
@import UIKit;
@class SaavnVC_n;

@interface SegmentTabs : UIView

#pragma mark - Init
- (instancetype) initInView:(SaavnVC_n *)parent withTabs:(NSArray *)tabs andMargins:(UIEdgeInsets)insets;
- (void) refreshTabs;

#pragma mark - Manage Tabs
- (void) addTab:(NSString *)label withAction:(void(^)(void))tapAction;

#pragma mark - Actions
- (void) setCurrentTab:(NSUInteger)current;

#pragma mark - Getter
- (NSInteger) getSelectedTab;

@end

