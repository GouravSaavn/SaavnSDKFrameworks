//
//  SearchField.h
//  Saavn
//
//  Created by Clint Balcom on 6/10/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

@import UIKit;
#import "SaavnVC_n.h"
@interface SearchField : UISearchBar


#pragma mark - Init
- (instancetype) initInNavBar:(SaavnVC_n *)parentVC;
- (instancetype) initInMainTable:(SaavnVC_n *)parentVC;
// Embed into view, fixed under the nav bar.
- (instancetype) initInVC:(SaavnVC_n *)parentVC;
// Don't embed anywhere, just return and let the called handle placement.
- (instancetype) initForVC:(SaavnVC_n *)parentVC;

#pragma mark - Setters
- (void) bringToFront;
- (void) updateWrapperForView:(UIView *)view;
- (void) useUnderlineStyle;
- (void) useUnderlineStyleWithMargins:(CGFloat)margins;
- (void) setUnderlineMargin:(CGFloat)margin;

#pragma mark - Getters
- (UIView *) getWrapper;
- (CGFloat) getWrapperHeight;


@end

