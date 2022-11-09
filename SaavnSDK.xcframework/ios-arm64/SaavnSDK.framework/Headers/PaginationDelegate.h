//
//  PaginationDelegate.h
//  Saavn
//
//  Created by Clint Balcom on 3/21/18.
//  Copyright © 2018 Saavn. All rights reserved.
//


@protocol PaginationDelegate <NSObject>


- (void) fetchDataForPage:(NSUInteger)thePage;
- (void) changingScope:(BOOL)startChanging;


@end

