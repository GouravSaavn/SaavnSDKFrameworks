//
//  ListTableVC.h
//  Saavn
//
//  Created by Shatrughan Singh on 4/12/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import "ListVC.h"

@interface ListTableVC : ListVC


@property (nonatomic) BOOL blockDefaultFetch;


// Subtype-Specific Properties
// Shows
@property (nonatomic) NSUInteger season;


#pragma mark - Init & Lifecycle
- (void) initSortTabs;

#pragma mark - Getters
- (NSArray *) getEntities;


@end

