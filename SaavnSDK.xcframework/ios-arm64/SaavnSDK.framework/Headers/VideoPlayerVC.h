//
//  VideoPlayerVC.h
//  Saavn
//
//  Created by Clint Balcom on 3/19/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

// Subclasses
#import "ArtPager.h"
#import "VPlayerControls.h"

//Apple APIs
#import <CoreMotion/CoreMotion.h>

typedef enum {
    Section_CARDS = 0,
    Section_QUEUE = 1,
    Section_AUTOPLAY = 2
} PlayerSections;

typedef enum {
    VideoThumb_PREV = 0,
    VideoThumb_CURRENT = 1,
    VideoThumb_NEXT = 2
} VideoThumb;

typedef enum{
    Portrait = 0,
    Portrait_Reverse = 1,
    Landscape_Left = 2,
    Landscape_Right = 3
} PlayerControlsSide;

@interface VideoPlayerVC : SaavnVC_n <UIGestureRecognizerDelegate>

@property (strong, nonatomic) CMMotionManager *motionManager;
@property (assign, nonatomic) PlayerControlsSide controlsSide;
@property (assign, nonatomic) BOOL hideStatusBar;
@property (assign, nonatomic) CGFloat stickyAngle;
@property (assign, nonatomic) CGFloat currentAngle;

#pragma mark - Editing
- (void) endBulkEditingViaCancel:(BOOL)didCancel;

#pragma mark - Getters
- (ArtPager *) getArtPager;
- (VPlayerControls *) getControls;
- (UIView *) getLandscapeControls;
- (UIView *) getLandscapeAnimationView;
- (CGFloat) getControlsPosition;
- (UIView *) lyricsView;
- (UIView *) videoView;
- (BOOL) isBulkEditing;

#pragma mark - Video UI Handling
- (void) addVideoLayer:(AVPlayerLayer *)layer;
- (void) removeVideoLayer;
- (void) showVideoThumb:(VideoThumb)thumb;

#pragma mark - Lyrics
- (void) showLyricsView;
- (void) hideLyricsView;

#pragma mark - Interactive Transitions
- (void) initInteractiveTransitions;

#pragma mark - Foreground & Background Transitions
- (void) enterForegroundState;

#pragma mark - Update Header
- (void) updateHeader:(NSDictionary*)dict;
- (void) updateWatermark;

#pragma mark - Update UI
- (void) hideLanscapeControls;
- (void) setVideoArtistViewHidden:(BOOL)hide;
- (void) enterFullscreen;

@end

