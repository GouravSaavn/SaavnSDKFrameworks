//
//  PlayerLogic.h
//  Saavn
//
//  Created by Clint Balcom on 3/20/20.
//  Copyright © 2020 Saavn. All rights reserved.
//


// Classes
#ifndef __SvnSenSDK

#import "ChromecastManager.h"
#endif

#import "SaavnStreamer.h"

// Global Utilities
#import "MediaUtil_n.h"
@class HistoryObject;

#define CONTEXTUAL_PLAY_LENGTH 50
#define RADIO_QUEUE_LENGTH 20


typedef enum {
    // Standard playback.
    VPlayerMode_QUEUE = 0,
    // Library and radio are both endless modes, but use
    // somewhat different fetching logic. Also, library
    // mode can be shuffled or linear, whereas radio justs
    // hides shuffle since all tracks are randomized anyway.
    VPlayerMode_LIBRARY = 1,
    VPlayerMode_RADIO = 2
} VPlayerMode;

typedef enum {
    // Standard playback, show standard controls.
    VPlayerContentMode_MUSIC = 0,
    // Show podcast controls.
    VPlayerContentMode_PODCAST = 1,
    // Show video controls, and allow hiding/showing of control layer.
    VPlayerContentMode_VIDEO = 2
} VPlayerContentMode;

typedef enum {
    // Autoplay based on queue contents.
    VPlayerRadio_AUTOPLAY = 0,
    // Explicit station types.
    VPlayerRadio_SONG = 1,
    VPlayerRadio_ALBUM = 2,
    VPlayerRadio_ARTIST = 3,
    VPlayerRadio_PLAYLIST = 4,
    VPlayerRadio_CHANNEL = 5,
    VPlayerRadio_USER = 6,
    VPlayerRadio_VIDEO = 7,
    // Featured station types.
    VPlayerRadio_FEATURED = 10,
    VPlayerRadio_FEATURED_ARTIST = 11,
    VPlayerRadio_FEATURED_VIDEO = 12
} VPlayerRadioMode;

typedef enum : NSUInteger {
    VPlayerSpeed_0_5 = 0,
    VPlayerSpeed_1   = 1,
    VPlayerSpeed_1_5 = 2,
    VPlayerSpeed_2   = 3,
} VPlayerPodcastSpeed;

typedef enum {
    // Standard phone playback.
    Speaker_NONE = 0,
    // External speakers.
    Speaker_AIRPLAY = 1,
    Speaker_BLUETOOTH = 2,
    Speaker_CHROMECAST = 3
} SpeakerType;

typedef enum : NSUInteger {
    // Standard Inserting to Queue : At Last
    VPlayerQueue_Last = 0,
    VPlayerQueue_First = 1
} VPlayerQueueInsertion;

@interface PlayerLogic : NSObject


@property (nonatomic) VPlayerMode playerMode;
@property (nonatomic) VPlayerContentMode playerContentMode;
@property (strong) HistoryObject *queueobj, *radioQueueObj;
@property (strong) NSMutableDictionary *radioStation;
#ifdef __SvnSenSDK

@property (nonatomic)  PlayerItemState playerItemState;

#endif
// Tracking
@property(nonatomic, strong) NSMutableDictionary *globalParams;

#pragma mark - Init
+ (PlayerLogic *) singleton;

#pragma mark - Player Actions
- (void) setNowPlaying:(NSUInteger)rowIndex;
- (void) playAutoplayTrack:(NSUInteger)rowIndex;
- (void) play;
- (void) pause;
- (void) togglePlayPause;
- (void) resume;
- (void) playNext;
- (void) playNextAnimated;
- (void) playPrevious;
- (void) playPreviousAnimated;
- (void) handleAutoplayTap;
- (void) showBuffering:(BOOL)isBuffering;
- (void) updateOfflineMode;
// Radio
- (void) stopAutoplay;
- (void) thumbsUp;
- (void) thumbsDown;
// Song Actions
- (void) jioTuneTapped;
- (void) downloadTapped;
- (void) likeTapped;
- (void) jumpAheadTapped;
- (void) jumpBackTapped;

- (void) addNext:(NSDictionary *)entity withTracking:(NSDictionary *)tracking viaParent:(SaavnVC_n *)parentVC;
#pragma mark - State Setters
- (void) setShuffle:(BOOL)shouldShuffle;
- (void) setRepeat:(BOOL)shouldRepeat;
- (void) setRepeatSingle:(BOOL)shouldRepeatSingle;
- (void) setPodcastSpeed:(VPlayerPodcastSpeed)speed;

#pragma mark - Getters
// Streamer
- (SaavnStreamer *) streamer;

// Queues
- (BOOL) isEmpty;
- (NSUInteger) queueLength;
- (NSUInteger) autoplayQueueLength;
- (NSArray *) getFullQueue;
- (NSArray *) getCurrentQueue;
- (NSArray *) getIndexesToSelect;
- (NSUInteger) getCurrentIndex;
// Chromecast
#ifndef __SvnSenSDK

- (ChromecastManager *) castManager;
#endif

// States
- (VPlayerMode) getPlayerMode;
- (BOOL) isPlaying;
- (BOOL) isPaused;
- (BOOL) isBuffering;
- (BOOL) isStreaming;
- (BOOL) isShuffle;
- (BOOL) isRepeat;
- (BOOL) isRepeatSingle;
- (BOOL) modeSupportsAutoplay;
- (BOOL) showAutoplayPreview;
- (BOOL) nowPlayingHasCards;
- (BOOL) hasNextTrack;
- (BOOL) hasPreviousTrack;
- (BOOL) isJioTuneAvailable;
- (BOOL) hasAvaliableTracks;

// Tracks
- (NSDictionary *) getNowPlaying;
- (NSDictionary *) getThirdPartyVideosExtraData;
- (NSMutableArray *) getThirdVideosList;
- (NSDictionary *) getNextTrack;
- (NSDictionary *) getSecondNextTrack;
- (NSDictionary *) getPreviousTrack;
- (NSDictionary *) getSecondPreviousTrack;
- (NSInteger) getOriginalIndex:(NSDictionary *)track;
- (NSDictionary *) getPlayerQueueTrack:(NSUInteger)rowIndex;
- (NSDictionary *) getAutoplayPreviewTrack:(NSUInteger)rowIndex;
- (BOOL) isVideo:(NSDictionary *)track;
- (UIColor *) getNowPlayingAccentColor;

// Radio
+ (VPlayerRadioMode) radioModeFor:(NSDictionary *)stationData;
- (BOOL) isAutoplay;

// Podcast
- (VPlayerPodcastSpeed) getPodcastSpeed;



#pragma mark - Queue Actions
- (void) addQueueToPlaylist;
- (void) saveQueueAsNewPlaylist;
- (void) downloadQueue;

#pragma mark - Queue Management
- (void) fetchAutoplayPreview;
#pragma mark — Clearing & Replacing
- (void) replaceQueue:(NSArray *)newQueue;      // Call this for any play event that replaces the player contents.
- (void) clearQueueAndSave:(BOOL)shouldSave;    // Generally shouldn't be called directly, but can be if we need to wipe the player.
#pragma mark — Adding, Removing, and Reordering
- (void) addToQueue:(NSArray *)itemsToAdd;      // Call for any add to queue action. If the player is empty, it will handle playback too.
- (void) addToQueue:(NSArray *)itemsToAdd through:(VPlayerQueueInsertion)insertion;
- (void) addToQueue:(NSArray *)itemsToAdd through:(VPlayerQueueInsertion)insertion completion:(void(^)(void))completionBlock;
- (void) removeFromQueue:(NSArray *)indexesToRemove inTable:(UITableView *)tableView withReload:(BOOL)shouldRelaod;
- (void) moveTrack:(NSIndexPath *)fromIndex to:(NSIndexPath *)toIndex;
- (void) addToSelectedItems:(NSUInteger)rowIndex;
- (void) removeFromSelectedItems:(NSUInteger)rowIndex;

#pragma mark - Direct & Contextual Play Actions
- (void) directPlay:(NSArray *)itemsToPlay fromPosition:(NSUInteger)startPosition withTracking:(NSDictionary *)trackingInfo;
- (void) sectionPlay:(NSDictionary *)itemData fromPosition:(NSInteger)startPosition forSection:(NSDictionary*)section viaParent:(SaavnVC_n *)parentVC withTracking:(NSDictionary *)trackingInfo;
- (void) contextualPlay:(NSDictionary *)itemData fromPosition:(NSInteger)startPosition viaParent:(SaavnVC_n *)parentVC withTracking:(NSDictionary *)contextualInfo;
- (void) fetchAndPlay:(NSString *)itemId ofType:(MediaType)type andStartFromTrack:(NSDictionary *)trackData withTracking:(NSDictionary *)trackingDict;
- (void) fetchAndAddRecos:(NSDictionary *)songData;

#pragma mark - Radio, Library, and Autoplay Management
#pragma mark — Library
- (void) playFromLibrary:(NSDictionary *)startSong onShuffle:(BOOL)shouldShuffle onlyDownloads:(BOOL)onlyDownloads withTracking:(NSDictionary *)trackingInfo;
- (void) playFromLibrary:(NSDictionary *)startSong onShuffle:(BOOL)shouldShuffle onlyDownloads:(BOOL)onlyDownloads withTracking:(NSDictionary *)trackingInfo sortStatus:(NSUInteger)sortValue;
#pragma mark — Radio
- (void) stationSuccess:(NSDictionary *)response withName:(NSString *)stationName type:(VPlayerRadioMode)type tracking:(NSDictionary *)trackingInfo andCompletion:(void(^)(void))completionBlock;
- (void) addNextRadioSongs:(NSUInteger)count;
- (void) updateRadioHistory:(VPlayerRadioMode)type fromSource:(id)stationSource withStationId:(NSString *)stationId;
- (void) resetQueueData;
- (void) clearQueueAndSave:(BOOL)shouldSave;
- (void) prepareForRadio;
- (void) startRadio:(VPlayerRadioMode)type fromSource:(id)source atFirstSong:(NSDictionary *)song withTracking:(NSDictionary *)trackingInfo;
- (void) startSiriRadio:(VPlayerRadioMode)type fromId:(NSString*)stationId withName:(NSString*)name withTracking:(NSDictionary *)trackingInfo;

#pragma mark - Tracking
- (void) logEvent:(NSString *)eventSuffix songId:(NSDictionary *)params;
- (void) logSwipeEvent:(NSString *)entity_name andType:(NSString*)entity_type;

#pragma mark - Streamer Events
- (void) handleStreamerPlay;
- (void) handleStreamerPause;
- (void) handleStreamerStopped;
- (void) handleStreamerFinished;
- (void) updateProgress:(NSTimer *)timer;

#pragma mark - External Notification / Callback Handles
- (void) resetOnLogOut;
- (void) queueSaved:(NSDictionary *)response fromPlayer:(BOOL)fromPlayer;

#pragma mark - Foreground & Background Transitions
- (void) enterForegroundState;
- (void) enterBackgroundState;


#pragma mark - Speakers, Bluetooth, Chromecast
- (BOOL) speakersConnected;
- (BOOL) isCastConnecting;
- (SpeakerType) getSpeakerType;
- (NSString *) getSpeakerName;
- (void) updateSpeakerStatus;




#pragma mark - TODO: Port Old Methods

// Queue Data Management
- (void) refreshLibrarySongIDs:(NSArray *)songIDArray playAtIndex:(NSUInteger)currentPlayIndex deleteCurrentSong:(BOOL)markedForDelete;
- (void) clearAllCachedSongs;
- (void) songRightsChanged:(int)rights_code songId:(NSString *)songId deleteCachedObj:(BOOL)delete_cached_obj new_cache_rights:(NSDictionary *) new_cache_rights;
- (NSDictionary *) updateSingleSongInPlayerQueue:(NSDictionary *)songDict;
- (void) updatePlayerQueueSongs:(NSDictionary *)songsDict;
- (void) replaceSongObjectinOtherQueues:(NSDictionary*)newDict from:(NSDictionary *) oldDict;
- (void) updateShortiInPlayerQueue:(NSDictionary *)songsDict;
- (void) updateMediaURLInPlayerQueue:(NSDictionary *)songsDict;

#pragma mark -  Chromecast
- (void) CCast_updateTitle;
- (NSArray *) CCast_getQueue;
- (NSArray *) CCast_getOriginalQueue;
- (NSInteger) CCast_getQueueIndex;
- (void) CCast_updateNowPlayingWithIndex:(NSInteger)index;
- (void) CCast_playAndSeekWithValue:(double)value;

#pragma mark - Remote Command Centre
- (void) updateControlCenterDetails:(BOOL)updateDetail andProgress:(double)progress;

#pragma mark - Dev Helpers
- (void) printCurrentQueue:(NSString *)source;
- (NSUInteger) findIndex:(NSString *)itemId inList:(NSArray *)itemList;


@end

