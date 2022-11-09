//
//  SettingsVC.h
//  New Saavn
//
//  Created by Clint Balcom on 9/9/17.
//  Copyright © 2017 Saavn. All rights reserved.
//

#import "SaavnVC_n.h"

@interface SettingsVC : SaavnVC_n <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic) BOOL isModal;


#pragma mark - Actions

#pragma mark Music & Playback
- (void) showStreamingOptionsDirect:(BOOL)openingDirectly;
- (void) showCellSecondaryOptions: (UINavigationController *) navController;


@end

