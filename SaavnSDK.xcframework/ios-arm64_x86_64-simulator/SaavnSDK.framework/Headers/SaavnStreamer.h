//
//  SaavnStreamer.h
//  Saavn
//
//  Created by SRIRANJAN MANJUNATH on 11/1/11.
//  Copyright 2011 Saavn. All rights reserved.
//

//#import "AudioStreamer.h"
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MPNowPlayingInfoCenter.h>
#import <MediaPlayer/MPMediaItem.h>
#define __SvnSenSDK = 1
#ifndef __SvnSenSDK

#import "ChromecastManager.h"
#import "EqualizerManager.h"
#endif
#import "SaavnPlayer.h"

#define FB_POST_TIME_INTERVAL 15.0
//#define CROSSFADE_DURATION 15
//#define GAIN_CHANGE 25
//#define GAIN_STEP (GAIN_CHANGE * 0.01333333333)

typedef enum : NSUInteger {
    PlayerItemStateReady,
    PlayerItemStateRunning = 1,
    PlayerItemStatePlaying = (1 << 1) | PlayerItemStateRunning,
    PlayerItemStateBuffering = (1 << 2) | PlayerItemStateRunning,
    PlayerItemStatePaused = (1 << 3) | PlayerItemStateRunning,
    PlayerItemStateStopped = (1 << 4),
    PlayerItemStateError = (1 << 5),
    PlayerItemStateDisposed = (1 << 6)
    
} PlayerItemState;

#ifndef __SvnSenSDK
@class AppDelegate;
#else
@class SaavnSDKDelegate;
#endif

@protocol SaavnStreamerDelegate <NSObject>
- (void) handleStreamerPlay;
- (void) handleStreamerPause;
- (void) handleStreamerFinished;
- (void) handleStreamerFinishedAudioAdFailed;
- (void) handleStreamerStopped;
- (void) updateProgress:(NSTimer*) timer;
- (NSDictionary *) getStreamerContext;

- (void) pausePlayer;
- (void) next;
- (NSInteger) getIndexOfSong;
- (void) logEvent:(NSString *)eventSuffix songId:(NSString*)sId;
- (void) handleStreamerVideoUIHandling:(AVPlayerLayer*)layer;
@optional
- (void) previous;
@end

@interface SaavnStreamer : NSObject <AVAudioPlayerDelegate
#ifndef __SvnSenSDK

,EqualizerDelegate, SaavnPlayerDelegate
#endif
> {
    NSInteger audioQualityBitrate;
    
    // Current Playing Media Object
    NSString *currentlyPlayingSongUrl;
    NSString *currentlyPlayingAdsUrl;
    
    // looping video
    NSString *currentlyPlayingLoopingVideoUrl;
    NSInteger currentlyPlayingLoopingVideoIndex;
    NSMutableArray *currentlyPlayingLoopingVideoData;
    
    NSTimer *progressTimer;
    NSTimer *reportPlaybackProgressTimer;
    
    NSTimer *adsProgressTimer;
    
    NSThread *timerThread;
    volatile BOOL timerStopPending;
    
    NSThread *adsTimerThread;

    #ifndef __SvnSenSDK
    AppDelegate *appDelegate;
    #else
    SaavnSDKDelegate *appDelegate;
    #endif
    BOOL playerSeeked;
    NSString *currentPlayingSongPid;
    BOOL isFinishing, songStored;
    
    NSInteger playCount;

    
    // AVPlayer* hlsPlayer;
//    UIBackgroundTaskIdentifier bgTaskId;
    NSDictionary *songData;
    
    id delegate;
    BOOL fbUpdatePosted;
    NSInteger retryCount;
    
    NSString *audioAdUrl;
    BOOL audioAdPlaying, showingMidrollAd, paintMidrollAds;
    BOOL videoAdPlaying;
    NSString *videoAdUrl;
    
    // Crossfade
    int   crossfadeDuration, crossfadeGainChange;
    double gainStep;
    BOOL  crossFadeEnabled;
    
    // Prefetcher
    NSDictionary *nextFetchedSong;
    BOOL shouldFetchNextSong;
    
    //AVAudioPlayer *avAudioPlayer;
    volatile BOOL avAudioPlayerLoading;
    volatile BOOL avAudioPlayerLoadedOnce;
    BOOL currentlyPlayingCachedSongDeleted;
    volatile BOOL skipNextAdsCheck;
    dispatch_queue_t avAudioBackgroundQueue;
    volatile BOOL lastMediaMusicPlus;
    volatile BOOL avFakeBuffeWhileDecrypting;
    
    volatile BOOL partialEnc; //Used for backward comptability
    volatile BOOL reloadFromConnectionLost;
    
    // AVPlayer state variables
    PlayerItemState previousAdsPlayerState;
    PlayerItemState previousPlayerItemState;
    volatile BOOL isObservingCurrentItem;
    NSInteger interruptionType;
    
    #ifndef __SvnSenSDK

    EqualizerManager *eqManager;
    
    ChromecastManager * castManager;
    #endif

    BOOL mediaObjectUpdating;
    NSString *mediaObjectID;
    
    // AVPlayer
    volatile BOOL seekTimeRequested;
    volatile double requestedSeekTime;
    
    volatile BOOL assetFetchPending;
    NSString *currentlyPlayingAudioUrl;
    
    
}

// AVPlayer
@property (nonatomic, strong) SaavnPlayer *player;
@property (nonatomic, strong) SaavnPlayer *loopingPlayer;
@property (nonatomic, strong) SaavnPlayer *adsPlayer;
@property (nonatomic, assign) BOOL hasVideo;
@property (nonatomic, assign) BOOL hasLoopingVideo;
@property (nonatomic, assign) BOOL hasShortie;
@property (nonatomic, assign) BOOL hasThirdPartyVideos;
@property (nonatomic, assign) NSInteger playCount;
//@property (nonatomic, strong) AVURLAsset *assets;
//@property (nonatomic, strong) AVPlayerItem *playerItem;
@property (assign) PlayerItemState playerItemState;
@property (assign) PlayerItemState adsplayerItemState;

//@property (nonatomic, strong) AVAssetTrack *audioAssetTrack;
@property (nonatomic, getter = isBandpassFilterEnabled) BOOL enableBandpassFilter;
@property (nonatomic) float centerFrequency; // [0 .. 1]
@property (nonatomic) float bandwidth; // [0 .. 1]

@property(nonatomic,retain) NSString *audioAdUrl;
@property(nonatomic,retain) NSString *videoAdUrl;
@property(nonatomic) BOOL showingMidrollAd;
@property(nonatomic) BOOL audioAdPlaying;
@property(nonatomic) BOOL videoAdPlaying;
@property(nonatomic) BOOL jioTunePreviewPlaying;
@property(nonatomic) BOOL replayPlayerPlaying;
@property(nonatomic,assign)NSInteger audioQualityBitrate;
//@property (strong, nonatomic) AVPlayer *hlsPlayer;
@property(nonatomic) BOOL mediaObjectUpdating;
@property(nonatomic) BOOL adsFetching;
@property(nonatomic,retain) NSString *mediaObjectID;

@property(nonatomic,assign) BOOL enableJioCDN;


// testing
@property(nonatomic,copy) NSString *streamingEggUrl;
@property(nonatomic,copy) NSString *streamingEggID;

- (BOOL) checkSlotStatus:(NSDictionary *) song;

+ (SaavnStreamer*) getInstance;

- (id) delegate;
- (void) setDelegate:(id)del;
- (PlayerItemState) getStreamerState;

- (void) stopStreamer;
- (void) clearStreamer;
- (void) loadSong:(NSDictionary *)song;
- (void) updatePlayerRoles;
//- (AudioStreamer*) getStreamer;
- (void) setPlayerSeeked:(BOOL)state;
- (void) startPlayback:(NSNumber*) time;
- (void) stopPlayback;
- (void) startTimerThread;
- (void) stopProgressTimer;
- (void) stopReportPlaybackProgressTimer;
- (void) pausePlayback;
- (void) resumePlayback;
- (NSString*) getCurrentPid;
- (NSDictionary*) getSongData;
- (NSString*) getBitrateUrl:(NSInteger) value;
- (void) switchAudioQuality:(NSInteger) value;
- (void) postSongListenSuccess:(NSString*) response;
- (void) postSongListenFailed:(NSString*) response;
- (void) togglePlayPause;
- (BOOL) isPlaying;
- (BOOL) isWaiting;
- (BOOL) isStopping;
- (BOOL) isPaused;
- (BOOL) isIdle;
- (BOOL) isValid;
- (BOOL) isSeeking;
- (void) setPause;
- (void) playIntroAd:(NSString*)audioUrl;
- (void) seekToTime:(float) value;
- (double) getDuration;
- (double) bufferedDuration;
- (double) getBufferDuration;
- (double) getStreamingProgress;
- (double) getBitRate;
- (BOOL) seekWasRequested;
- (void) resetCrossFadeProgress;
- (double) getNextAdBreakTimestamp;
- (BOOL) checkAndUpdateIfAdbreakPassedAtTime: (double) currentSeekTime playMidrollAd: (BOOL) showPlayAd;
- (void) loadCachedSong:(NSDictionary *) song;
- (void) startCachedPlayback:(NSString *)localMediaURL;
- (BOOL) isAVPlayerLoading;
- (void) start;
//- (void) songDeleted;
- (void) restartSongAfterConnLost;
- (void) resetSongAfterConnLost;
- (BOOL) isPlayingOnlineSong;
- (double) getLastStreamerProgress;
- (double) getLastStreamerDuration;
- (void) loadAudioAd: (NSString*) url;
- (BOOL) isChromeCasting;
- (void) skipNextAdsCheck :(BOOL) value;
- (void) setOpenSlotMediaTypeMPlus;
- (void) setConnLostTime;
- (void) listenersOff;


- (void)setMuted:(BOOL)state;
- (void)setVolume:(float)level;
- (BOOL)isTimerRunning;
- (BOOL) isStreamerPlaying;
- (double) getStreamerProgress;
- (void)setStreamerStop;
- (void)stopPlaybackOfCasting;
- (void) setupAudioSession;
- (NSString*) getCurrentlyAudioFormat;
- (NSString*) getCurrentMediaURL;
- (NSInteger) getCurrentAudioQuality;
- (NSArray *) getPendingAdbreaks;

- (double) getCurrentRadioProgress;


// Video Handling
- (void) handleIMAAdsPlay:(NSString*)videoUrl withType:(NSString*)type;
- (void) handleIMAAdsFinished:(NSString*)type;
- (void) handleIMAAdsError:(NSString*)type;

// Crossfade and Prefetching
- (void) removeLastPlayedCachedSong: (NSDictionary *) song;
- (void) decryptAndCreateNextSongURL: (NSDictionary *) dictionary completion: (void (^)(BOOL, NSURL *)) completion;
- (void) fetchNextSong: (NSDictionary *) nextSong currentSong:(NSDictionary *) currentSong;
- (void) clearPrefetchedSongIfAny;


- (void) setPlayerSpeed:(NSInteger)speedValue;
- (void) setPlayerForward;
- (void) setPlayerBackward;

#pragma mark JIO Ads Callback
- (void) handleJIOAdsPlay;
- (void) handleJIOAdsFinished: (BOOL) dismiss;
- (void) handleJIOAdsError;


- (NSDictionary *) getPlayingMediaEventData :(SaavnPlayer *)player;

- (void) enterForegroundState;
- (void) enterBackgroundState;

- (void) playThirdPartyVideo:(NSMutableArray *)shortieData forAudio:(NSDictionary*)nowplaying;
- (void) playShortieVideoforAudio:(NSDictionary*)nowplaying;

#pragma mark - Video View Time Tracking
- (void) playerViewStatus:(BOOL)open;
- (double) getVideoViewTimeInMilliSeconds;
- (void) updateVideoViewTime;
- (void) updateVideoViewStartTimeStamp;
-(void) resetVideoViewTime;
@end
