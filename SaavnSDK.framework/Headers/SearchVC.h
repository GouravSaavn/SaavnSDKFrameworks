//
//  SearchVC.h
//  Saavn
//
//  Created by Shatrughan Singh on 4/11/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import "GroupVC.h"


// Subclasses
#import "SearchField.h"


@interface SearchVC : GroupVC <UISearchBarDelegate, UITableViewDataSource, UITableViewDelegate, UICollectionViewDelegate, UICollectionViewDataSource>



// View UI
// NOTE: These are class properties instead of locals because they're shared with PlaylistBuilder.m,
//       which is a subclass of SearchVC.

// Search Data
@property (nonatomic, strong) NSArray *resultOrderDefault;
@property (nonatomic, strong) NSMutableDictionary *acResults;
@property (nonatomic, strong) NSString *queryToAutoFire;

// UI Elements
@property (nonatomic, strong) UITableView *searchTable;
@property (nonatomic, strong) SearchField *searchBar;


#pragma mark - Init
- (void) initSearchBar;
#pragma mark AC Spinner
- (void) showSpinner;
- (void) hideSpinner;

#pragma mark Errors & No Results
- (void) showNoResults;
- (void) hideError;

#pragma mark - Data Handling
- (BOOL) initData;
- (NSString *) getTypeStringFromSearchGroup:(NSString *)searchKey;
#pragma mark Direct Search
- (void) startSearch:(NSString *)searchText;
- (void) searchFromDeepLink:(NSString *)query;

#pragma mark Recent / Popular Searches
- (void) populateEmptyState;

#pragma mark - Getters
- (NSString *) getCurrentQuery;

#pragma mark - Scroll Handling
- (void) scrollToTop;

#pragma mark - Managing Table Visibility
- (void) hideKeyboard;
- (void) highlightKeyboard;

#pragma mark - Actions
- (void) clearSearchField;
- (void) deleteSearchUnit;
- (void) deleteRecentSearches:(NSDictionary*) data;
@end

