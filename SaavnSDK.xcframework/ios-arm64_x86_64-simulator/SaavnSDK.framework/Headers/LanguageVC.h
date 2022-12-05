//
//  LanguageVC.h
//  Saavn
//
//  Created by Clint Balcom on 5/27/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import "GroupVC.h"

// Subclasses
#import "TopLanguagesButton.h"


@interface LanguageVC : GroupVC <UITableViewDataSource, UITableViewDelegate>


#pragma mark - Actions
- (void) topBtnTapped:(TopLanguagesButton *)btn;


@end

