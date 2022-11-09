//
//  TableSectionHeader.h
//  Saavn
//
//  Created by Clint Balcom on 5/26/16.
//  Copyright © 2016 Saavn. All rights reserved.
//
@import UIKit;
typedef enum {
    TableHeader_Plain = 0,
    TableHeader_Plain_Padded = 1,
    TableHeader_Block = 2
} TableHeaderType;

@interface TableSectionHeader : UIView

#pragma mark - Init Methods
- (void) setHeaderForTable:(UITableView *)table ofType:(TableHeaderType)type withLabel:(NSString *)text;
- (void) setHeaderForTable:(UITableView *)table ofType:(TableHeaderType)type withLabel:(NSString *)text andBadge:(NSString *)badge;
- (void) setHeaderForTable:(UITableView *)table ofType:(TableHeaderType)type withLabel:(NSString *)text andPadding:(UIEdgeInsets)padding;
- (void) setHeaderForTable:(UITableView *)table ofType:(TableHeaderType)type withLabel:(NSString *)text andBadge:(NSString *)badge andPadding:(UIEdgeInsets)padding;

#pragma mark - Extras

- (void) showLoader;
- (void) hideLoader;
- (void) showButton:(NSString *)btnTitle asButton:(BOOL)isFramed;
#ifndef __SvnSenSDK
- (void) setButtonAction:(SEL)selector inParent:(SaavnVC *)parent;
#endif

#pragma mark - Getter Methods
+ (UIEdgeInsets) getPaddingForTableHeaderType:(TableHeaderType)type;
+ (float) getTableHeaderHeight:(TableHeaderType)type;
+ (float) getTableHeaderHeight:(TableHeaderType)type withPadding:(UIEdgeInsets)padding;

@end
