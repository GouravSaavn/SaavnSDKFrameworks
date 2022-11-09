//
//  MiniPlayer.h
//  New Saavn
//
//  Created by Clint Balcom on 10/18/17.
//  Copyright © 2017 Saavn. All rights reserved.
//
#import "VPlayerControls.h"

@interface MiniPlayer : UIView


@property (nonatomic) BOOL isPlayerShowing, isTransitioning;


- (instancetype) initWithFrame:(CGRect)frame forDetailVC:(BOOL)needToShow;

#pragma mark - Interface
- (void) showPlayer;
- (void) playerWasHidden;
- (void) bouncePreview;

#pragma mark - Now Playing Updates
- (void) setNowPlaying;
- (void) clearNowPlaying;
- (void) setPlayPauseIcon;
- (void) showBuffering:(BOOL)isBuffering;

#pragma mark - Video UI
- (void) addVideoLayer:(AVPlayerLayer *)layer;
- (void) removeVideoLayer;
- (void) addVideoMiniLayer;

#pragma mark - Getters
+ (CGFloat) height;
- (CGRect) getVideoFrame;


@end

