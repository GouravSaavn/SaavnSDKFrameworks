//
//  SaavnNC.h
//  Saavn 6.0
//
//  Created by Clint Balcom on 8/20/17.
//  Copyright © 2017 Saavn. All rights reserved.
//

// Parent Controllers
#import "SaavnNavBar.h"

// Subclasses
#ifndef __SvnSenSDK
#import "PlaylistBuilderBar.h"
#endif

@interface SaavnNC : UINavigationController <UINavigationControllerDelegate>


#pragma mark - Setters
- (void) showLightStatusBar;
- (void) showDarkStatusBar;
- (void) resetStatusBar;

#pragma mark - Getters
- (UIStatusBarStyle) preferredRootStatusBarStyle;
+ (UIStatusBarStyle) currentStatusBarStyle;
#ifndef __SvnSenSDK
- (PlaylistBuilderBar *) getPlaylistBuilderBar;
#endif

#pragma mark - Playlist Builder Setup
- (void) showPlaylistBuilderBar;


@end

