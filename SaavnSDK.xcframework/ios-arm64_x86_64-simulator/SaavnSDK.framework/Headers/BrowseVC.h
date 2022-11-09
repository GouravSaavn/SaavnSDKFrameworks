//
//  BrowseVC.h
//  Saavn
//
//  Created by Clint Balcom on 3/19/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import "GroupVC.h"
//@class EmptyStateView;
//@protocol EmptyStateViewDelegate;

@interface BrowseVC : GroupVC <UITableViewDataSource, UITableViewDelegate, UICollectionViewDataSource, UICollectionViewDelegate, UISearchBarDelegate>


#pragma mark - Getters
- (NSArray *) getChannelData;
- (BOOL) isCurrentlySearching;

@end

