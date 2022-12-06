//
//  ListVC.h
//  Saavn
//
//  Created by Shatrughan Singh on 4/12/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import "GroupVC.h"
#import "MediaUtil_n.h"
// Subclasses
#import "PaginationDelegate.h"
#import "SegmentTabs.h"


@interface ListVC : GroupVC <UITableViewDataSource, UITableViewDelegate, PaginationDelegate>


// VC Info regarding view, source and media type.
@property(nonatomic, assign) MediaType entityType;          // contents that need to display
@property(nonatomic, assign) MediaType sourceType;          // view type
@property(nonatomic, strong) NSString *entityId;            // entity Id
@property(nonatomic, strong) NSDictionary *entityData;      // entity data

@property(nonatomic, strong) NSString *searchParams;        // more params

// Pagination Delegate & Properties
@property (nonatomic, weak) id <PaginationDelegate> pagination;
@property (nonatomic) BOOL isFetching, endReached, scopeChanged;
@property (nonatomic) NSUInteger page, itemsPerFetch;
@property (nonatomic) CGFloat paginationOffset;


#pragma mark - Data Handling
- (void) initData;


@end

