//
//  ViewTabs.h
//  Saavn
//
//  Created by Clint Balcom on 3/7/20.
//  Copyright © 2020 Saavn. All rights reserved.
//


@interface ViewTabs : UIView


@property (nonatomic) NSUInteger currentTab;


#pragma mark - Init
- (instancetype) initinView:(SaavnVC_n *)parent;

#pragma mark - UI Setup
- (void) showSettings;
- (void) showProCallout;
- (void) setTabs:(NSArray *)data;
- (NSArray *) getTabs;
#pragma mark - Setters
- (void) setToTab:(NSUInteger)tabIndex withAction:(BOOL)performTapAction;

#pragma mark - Getters
- (NSInteger) getTabsCount;

#pragma mark - Theme & Status Updates
- (void) updateUIMode;

#pragma mark - iPad Layout
- (void) iPadRefreshLayout;

@end

