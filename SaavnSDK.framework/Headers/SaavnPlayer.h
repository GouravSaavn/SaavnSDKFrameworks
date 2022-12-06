//
//  SaavnPlayer.h
//  Saavn
//
//  Created by Shatrughan Singh on 20/04/20.
//  Copyright © 2020 Saavn. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

typedef enum : NSUInteger {
    SaavnMediaTypeNone,
    SaavnMediaTypeAudio = 1,
    SaavnMediaTypeVideo = 2,
    SaavnMediaTypePodCast = 3,
    SaavnMediaTypeShortie = 4
} PlayerMediaType;

@class SaavnPlayer;
@protocol SaavnPlayerDelegate <NSObject>
@required
- (void) playerItemDidReachEnd:(NSNotification*) notification forAudio:(SaavnPlayer*)player;
- (void) playerItemDidStall:(NSNotification *) notification forAudio:(SaavnPlayer*)player;
- (void) playerDidErrorOccured:(NSError*)error forAudio:(SaavnPlayer*)player;
- (void) playerStatusReadyToPlayforAudio:(SaavnPlayer*)player;
- (void) playerStatusLikelyToKeepUp:(BOOL)keepUp forAudio:(SaavnPlayer*)player;
- (void) playerStatusBufferEmptyforAudio:(SaavnPlayer*)player;
- (void) playerStatusBufferFullforAudio:(SaavnPlayer*)player;
- (void) playerReadyToPlayHandling:(SaavnPlayer*)player;
@end


@interface SaavnPlayer : AVPlayer

@property (weak) id <SaavnPlayerDelegate> delegate;
@property (nonatomic, assign) PlayerMediaType mediaType;
@property (nonatomic, strong) AVURLAsset *assets;
@property (nonatomic, strong) AVAssetTrack *audioAssetTrack;
@property (nonatomic, strong) AVAudioMix *audioMix;
@property (nonatomic, strong) AVPlayerLayer *videoLayer;
@property (nonatomic, assign) BOOL assetFetchPending;
@property (nonatomic, assign) BOOL needEqualiserSupport;
@property (nonatomic, assign) BOOL adsPlaying;
@property (nonatomic, assign) BOOL hasM3u8File;
@property (nonatomic, copy) NSString *mediaUrl;
@property (nonatomic, getter = isBandpassFilterEnabled) BOOL enableBandpassFilter;
@property (nonatomic) NSTimeInterval bufferingStart;
@property (nonatomic, assign) BOOL playerOpen;


// tracking
@property(nonatomic,assign) long initial_buffer_time;
@property(nonatomic,assign) long total_buffer_time;
@property(nonatomic,assign) long total_playtime;
@property(nonatomic,assign) long start_time;

@property(nonatomic,assign) double viewed_buffer_start_time;
@property(nonatomic,assign) double total_viewed_buffer_time;

- (instancetype) init;
- (void) fetchAssetsWithUrl:(NSString *)mediaUrl;
- (void) fetchAssetsWithUrl:(NSString *)mediaUrl ofType:(PlayerMediaType)media;
- (void) playAssetsFor:(AVAsset*)asset WithUrl:(NSString*)mediaUrl ofType:(PlayerMediaType)media;
- (void) setGain:(float)gain forEqualizerBand:(float)bandIndex;
- (CMTime) playerItemDuration;
- (CMTime)playerItemCurrentTime;
- (float) getFrameRate;
- (void) updateConsumptionClock;
- (void) disposePlayer;

- (void) attachVideoLayer;
- (void) deAttachVideoLayer;
- (NSTimeInterval)playerItemBufferDuration;

- (double) getVideoTotalViewedBufferTime;
@end




