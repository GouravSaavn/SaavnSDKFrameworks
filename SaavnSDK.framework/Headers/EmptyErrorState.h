//
//  EmptyErrorState.h
//  Saavn
//
//  Created by Clint Balcom on 5/14/18.
//  Copyright © 2018 Saavn. All rights reserved.
//


@class SaavnVC_n;
@import UIKit;


@interface EmptyErrorState : UIView


#pragma mark - Init
- (instancetype) initInVC:(SaavnVC_n *)parentVC withTitle:(NSString *)titleStr message:(NSString *)messageStr;
- (instancetype) initInVC:(SaavnVC_n *)parentVC withTitle:(NSString *)titleStr message:(NSString *)messageStr buttonLabel:(NSString *)buttonStr andAction:(void(^)(void))buttonAction;


@end

