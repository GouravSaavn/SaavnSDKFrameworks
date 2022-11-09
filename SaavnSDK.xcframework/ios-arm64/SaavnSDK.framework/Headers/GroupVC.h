//
//  GroupVC.h
//  Saavn
//
//  Created by Shatrughan Singh on 3/14/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import "SaavnVC_n.h"


@interface GroupVC : SaavnVC_n <UIGestureRecognizerDelegate, UITableViewDataSource, UITableViewDelegate, UICollectionViewDataSource, UICollectionViewDelegate>


@property (nonatomic, strong) NSMutableArray *groupData;                // The table data source (all sections) in this group view.
@property (nonatomic, strong) NSMutableDictionary *groupDetails;        // The main details (object) for this group view (ie. Channel details).
                                                                        // Often times this will be nil, such as for root views. Mostly applies to Channels and Shows.
@property (nonatomic) BOOL usesWideLayoutMargin, isFollowed;

// Header Play and Like tap actions.
@property (nonatomic, copy) void(^playAction)(void);
@property (nonatomic, copy) void(^likeAction)(void);

#pragma mark - Loading
- (void) showLoading;
- (void) hideLoading;
- (void) showEmptyState;
- (void) hideEmptyState;
#pragma mark Pagination Loading
- (void) startPaginationSpinner;
- (void) stopPaginationSpinner;

#pragma mark - Cleanup
- (void) dismissView;

#pragma mark - Library & Social Updates
- (void) libraryUpdate:(NSNotification *)notification;
- (void) followUpdate:(NSNotification *)notification;

@end

