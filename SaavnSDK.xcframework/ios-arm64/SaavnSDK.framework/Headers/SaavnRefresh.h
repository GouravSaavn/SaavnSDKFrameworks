//
//  SaavnRefresh.h
//  New Saavn
//
//  Created by Clint Balcom on 12/19/17.
//  Copyright © 2017 Saavn. All rights reserved.
//


#import "SaavnVC_n.h"


@interface SaavnRefresh : UIView


@property (nonatomic, copy) void(^action)(void);
@property (nonatomic) BOOL isRefreshing, isEnabled;


#pragma mark - Init
- (void) addRefreshTo:(SaavnVC_n *)targetView withAction:(void(^)(void))actionBlock;

#pragma mark - Theme & Status Updates
- (void) updateUIMode;

#pragma mark - Setters
- (void) setRefreshThreshold:(CGFloat)threshold;
- (void) enableRefresh:(BOOL)shouldEnable;

#pragma mark - Actions
- (void) startRefreshing;
- (void) endRefreshing;

#pragma mark - "Delegate" Methods
- (void) scrollViewDidScroll:(UIScrollView *)scrollView;
- (void) scrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void) scrollViewDidEndDragging:(UIScrollView *)scrollView;


@end

