//
//  ArtPager.h
//  Saavn
//
//  Created by Clint Balcom on 3/24/20.
//  Copyright © 2020 Saavn. All rights reserved.
//
@import UIKit;

@interface ArtPager : UIView <UIGestureRecognizerDelegate>


typedef enum {
    artPrev2   = 0,
    artPrev    = 1,
    artCurrent = 2,
    artNext    = 3,
    artNext2   = 4
} ArtPositions;


#pragma mark - Theme & Status Updates
- (void) updateUIMode;

#pragma mark - Setters
- (void) update;
- (void) setHeaderReference:(UIView *)targetView;

#pragma mark - Getters
+ (CGFloat) artPadding;
- (UIImage *) getNowPlayingImage;

#pragma mark - Animations
- (void) animateToNext;
- (void) animateToPrevious;
- (void) jumpToVideoUI;
- (void) jumpToMusicUI;


@end

