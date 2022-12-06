//
//  ModalAction.h
//  New Saavn
//
//  Created by Clint Balcom on 12/29/17.
//  Copyright © 2017 Saavn. All rights reserved.
//


// View Controllers
#import "ModalVC.h"


typedef enum {
    // Default
    ModalAccessory_None = 0,
    
    // Other Options
    ModalAccessory_Browse = 1,
    ModalAccessory_Modal = 2,
    ModalAccessory_Checkmark = 3
} ModalActionAccessory;


@interface ModalAction : NSObject


@property (nonatomic, strong) NSString *label, *value, *iconName;
@property (nonatomic, strong) NSDictionary *modalData; // for refrence where modalaction can be multiple for single media object
                                                       // for example - we are fetching artist map from album and displaying multiple modal action for that
@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic) BOOL hasDivider, isPushingNewView, isPlayAction, isLive, isSelected, isSaveButton, noTinting, shouldDismissParentVC;
@property (nonatomic) ModalViewStyle style;
@property (nonatomic) ModalActionAccessory accessoryStyle;
@property (nonatomic, copy) void(^completion)(void);
@property (nonatomic, copy) void(^tapAction)(NSString *label);
@property (nonatomic, copy) void(^modalAction)(NSDictionary *data);


#pragma mark - Getters
- (NSDictionary *) getData;


@end

