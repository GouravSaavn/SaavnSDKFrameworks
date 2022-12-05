//
//  VPlayerControls.h
//  Saavn
//
//  Created by Clint Balcom on 3/19/20.
//  Copyright © 2020 Saavn. All rights reserved.
//


// Classes
#import "PlayerLogic.h"


@protocol VPlayerControlsDelegate <NSObject>
@optional
- (void) updateProgressSlider:(double)progress;
@end


@interface VPlayerControls : UIView

@property (nonatomic, weak) id <VPlayerControlsDelegate> delegate;

#pragma mark - UI Setup
- (void) hide;
- (void) show;
- (void) updateBuffering;

#pragma mark - Theme & Status Updates
- (void) updateUIMode;

#pragma mark - Setters
- (void) setMargin:(CGFloat)tableMargin;
- (void) setPlayerMode:(VPlayerMode)playerMode andContentMode:(VPlayerContentMode)contentMode;
- (void) updateButtonStates;
#pragma mark Seek Bar & Timecode
- (void) updateProgressBar;
- (void) seekToTime:(double)timestamp;
- (void) resetProgressBar;
- (void) resetThumbsUp;
- (void) animateJioTuneButton;

#pragma mark - Getters
+ (CGFloat) height;
+ (CGFloat) controlsBottomSafeArea ;
+ (CGFloat) progressBarHeight;
- (BOOL) isHidden;
- (BOOL) thumpUpSong;
- (BOOL) thumpDownSong;


@end

