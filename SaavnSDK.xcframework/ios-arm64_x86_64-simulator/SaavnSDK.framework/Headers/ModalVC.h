//
//  ModalVC.h
//  New Saavn
//
//  Created by Clint Balcom on 12/3/17.
//  Copyright © 2017 Saavn. All rights reserved.
//

#import "SaavnVC_n.h"


typedef enum {
    Modal_Present = 0,
    Modal_Dismiss = 1
} ModalTransitionType;

typedef NS_ENUM(NSUInteger, ModalViewType){
    ModalType_UNKNOWN    = 0,
    
    // Standard System Stuff
    ModalType_Dialog     = 0,
    ModalType_Input      = 1,
    
    // Action Sheets
    ModalType_Sheet      = 10,
    ModalType_Share      = 11,
    ModalType_SheetPlayer = 12,
    
    // JIO Tune Modal
    ModalType_JioTuneModal      = 13,
    ModalType_JioTuneUnAvailableModal      = 14,
    ModalType_JioTuneExhaustedModal      = 15,

    // Dolby Popup
    ModalType_DolbyAtmos = 16,

    // Takeover Units
    ModalType_SmallModal = 100,
    ModalType_FullModal  = 101,
    ModalType_Fullscreen = 102
};

typedef NS_ENUM(NSUInteger, ModalViewStyle){
    ModalStyle_DEFAULT  = 0,
    ModalStyle_SUCCESS  = 1,
    ModalStyle_WARNING  = 2,
    ModalStyle_SUBTLE   = 3,
    ModalStyle_DISABLED = 4
};

typedef enum {
    ModalAnimate_UNKNOWN  = 0,
    
    // Standard Animations
    ModalAnimate_SpringIn = 1,
    ModalAnimate_FadeIn   = 2,
    ModalAnimate_SlideIn  = 3
} ModalAnimationType;


@interface ModalVC : SaavnVC_n <UIViewControllerTransitioningDelegate, UIViewControllerAnimatedTransitioning, UITableViewDataSource, UITableViewDelegate>


@property (nonatomic) ModalViewType type;
@property (nonatomic) ModalViewStyle style;
@property (nonatomic) ModalAnimationType animationType;
@property (nonatomic, strong) UIImage *preloadedImage;
@property (nonatomic) BOOL tapOutsideToDismiss, blursBackground, customSheetSizing;

// Dialog Input
@property (nonatomic, strong) UITextField *dialogInput;

// Callbacks
@property (nonatomic, weak) SaavnVC_n *callbackTargetVC;
@property (nonatomic, copy) void(^completion)(void);    // NOTE: This is a generic completion block which will be superceded by any button completion blocks passed when adding actions.
@property (nonatomic, copy) void(^tapAction)(NSString *tapDetails);    // NOTE: This is a specific completion block which will be superceded by any button completion blocks passed when adding actions.
@property (nonatomic, copy) void(^modalAction)(NSDictionary *modalData);    // NOTE: This is a specific completion block which will be superceded by any button completion blocks passed when adding actions.

@property (nonatomic, copy) void(^cancelled)(void);     // Called when user taps cancel button, unless it was otherwise cleared (ie. dismissWithoutCallbacks).


#pragma mark - Init & Lifecycle
- (void) initContents;
- (void) adjustActionSheetSize;

#pragma mark - Dialogs & Inputs
- (void) setDialogTitle:(NSString *)title andMessage:(NSString *)message;

#pragma mark - Managing Actions
- (void) addAction:(NSString *)label handler:(void(^)(void))completion;
- (void) addAction:(NSString *)label icon:(NSString *)iconName handler:(void(^)(void))completion;
- (void) addAction:(id)action;
- (void) handleAction:(NSDictionary *)tappedItem;

#pragma mark - Action Sheet Headers
- (void) addContentHeader:(NSDictionary *)media;
- (void) setSheetTitle:(NSString *)title andMessage:(NSString *)message;

#pragma mark - UITableViewDelegate
// NOTE: We're exposing these methods so that subclasses (like ShareModal) can override them.
//       This should be uncommon, but it's better than duplicating a bunch of logic.
// Cells
- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
// Sections & Rows
- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;

#pragma mark - Getters
- (UIView *) sectionDivider;
- (NSArray *) getActions;
- (UITableView *) getTable;
- (UIView *) getModalWrap;
- (UIView *) getContentsWrap;
- (UIView *) getButtonWrap;
- (UIButton *) getCancelButton;
- (ModalTransitionType) getTransitionType;

#pragma mark - Dismissal
- (void) dismiss;
- (void) dismissWithoutCallbacks;


@end

