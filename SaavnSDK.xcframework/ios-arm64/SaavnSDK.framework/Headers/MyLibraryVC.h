//
//  MyLibraryVC.h
//  Saavn
//
//  Created by Clint Balcom on 12/29/16.
//  Copyright © 2016 Saavn. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "SaavnVC_n.h"
//@class DeferredLoginScreenViewController;
@interface MyLibraryVC : SaavnVC_n <UITableViewDataSource, UITableViewDelegate>


// PRE-6.0
@property (nonatomic) BOOL libraryLoadedFromHome;
@property (nonatomic) int pageToShowOnLoad;


#pragma mark - Data Handling
- (void) fetchMyMusic:(BOOL)isRefresh;

#pragma mark - Actions
- (void) scrollToHistory;

#pragma mark - Offline
- (void) setOffline:(BOOL)isOffline;

@end

