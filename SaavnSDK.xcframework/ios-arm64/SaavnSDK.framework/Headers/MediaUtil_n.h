//
//  MediaUtil.h
//  New Saavn
//
//  Created by Clint Balcom on 11/16/17.
//  Copyright © 2017 Saavn. All rights reserved.
//


// Global Utilities
#import "Layout.h"

// Parent Controllers
#import "SaavnVC_n.h"
#import "CachedSongDB.h"
//#import "PlayerLogic.h"

typedef enum {
    // Fallback
    Media_Unknown = 0,
    
    // Music
    Media_Song = 10,
    Media_Album = 11,
    
    // Lists & Charts
    Media_Playlist = 20,
    Media_Chart = 21,
    Media_Mix = 22,
    
    // People
    Media_Artist = 30,
    Media_User = 31,
    
    // Shows
    Media_Episode = 40,
    Media_Show = 41,
    Media_Season = 42,
    
    // Channels
    Media_Channel = 50,
    
    // Radio
    Media_Station = 60,
    
    // Videos
    Media_Video = 70,
    
    // Deeplink
    Media_Deeplink = 80,
    
    // Search
    Media_Search = 100,

    // Native Ads
    Media_NativeAd = 1000,
    
    // Text Cells
    Text_Lyrics = 2000,
    Text_Bio = 2100,
    Text_Description = 2200,
    
    Media_More = 2300,
    Media_Category = 2400,
    
    Media_JioTune = 13,
} MediaType;

// TODO: We should remove this. It's redundant to MediaType.
typedef enum {
    Content_ALBUM = 0,
    Content_PLAYLIST = 1,
    Content_CHART = 2,
    Content_SHOW = 3,
    Content_CHANNEL = 4,
    Content_ARTIST = 5,
    Content_SONG = 6,
    Content_MIX = 7,
    Content_EPISODE = 8,
    Content_VIDEO = 9,
    Content_UNKNOWN = 10
} ContentTypes;

typedef enum {
    NORMAL_PLAYLIST = 0,
    MIX_PLAYLIST = 1, // Algo Playlist
    CHART_PLAYLIST = 2, // Chart
    MIXED_PLAYLIST = 3 // History
} Playlist_Type;

typedef enum : NSUInteger {
    PRO_PLAYLIST = 0, //ProPlaylist
    DOLBY_PLAYLIST = 1, // DolbyPlaylist
    VIDEO_PLAYLIST = 2, // VideoPlaylist
    VIDEO_AUDIO_PLAYLIST = 3, // VideoAudioPlaylist
    JIOTUNE_ACTIVITY = 4, // PRO JioTuneActivity
    JIOTUNE_DECADE = 4, // JioTuneDecade
    JIOTUNE_ARTIST = 4, // JioTuneArtist
} Playlist_SubType;

typedef enum {
    // Fallback, in case we send non-channel data.
    ChannelTypeNone = 0,
    
    // Standard
    ChannelTypeMood = 1,
    ChannelTypeGenre = 2,
    ChannelTypeMusicPlus = 3,

    // Sponsored
    ChannelTypeBrandBar = 1000
} ChannelType;

typedef enum {
    Tag_None = 0,
    Tag_Explicit = 1,
    Tag_Ad = 2,
    Tag_Artist_Verified = 3,
    Tag_Requested = 4,
    Tag_Available = 5,
    Tag_Dolby = 6,
    Tag_U = 7,
    Tag_7 = 8,
    Tag_13 = 9,
    Tag_16 = 10,
    Tag_A = 11
} TagType;

typedef enum {
    PlayState_UNPLAYED    = 0,
    PlayState_IN_PROGRESS = 1,
    PlayState_PLAYED      = 2
} EpisodePlayState;

typedef enum {
    MetaStyle_DIRECT    = 0,
    //
    MetaStyle_HEADER    = 10,
        MetaStyle_HEADER_LIBRARY    = 11,
        MetaStyle_HEADER_OFFLINE    = 11,
    MetaStyle_SCROLLER  = 20,
    MetaStyle_ROW       = 30,
        MetaStyle_ROW_LIBRARY       = 31,
        MetaStyle_ROW_PLAYER        = 32,
        MetaStyle_ROW_SEARCH        = 33
} MetaStyle;

// Cache States
typedef enum {
    CacheState_READY = 0,
    CacheState_PENDING     = CACHE_STATE_PENDING,         // 1
    CacheState_DOWNLOADING = CACHE_STATE_DOWNLOADING,     // 2
    CacheState_CACHED      = CACHE_STATE_CACHED,          // 3
    CacheState_FAILED      = CACHE_STATE_DOWNLOAD_FAILED, // 4
    CacheState_UNKNOWN
} LocalCacheState;


@interface MediaUtil_n : NSObject


#pragma mark - Generalized String Getters
// Content
+ (NSString *) idFor:(NSDictionary *)entity;
+ (NSString *) titleFor:(NSDictionary *)entity;
+ (NSString *) metaFor:(NSDictionary *)entity inStyle:(MetaStyle)style;
+ (NSString *) imageURLFor:(NSDictionary *)entity;
+ (NSString *) getPermaURL:(NSDictionary *)entity;
+ (NSString *) getPermaUrlWithTracking:(NSDictionary *) shareEntity trackString:(NSString*)partnerString andSource:(NSString*) source;
// Sections
+ (NSString *) headerTitleFor:(NSDictionary *)section;
+ (NSString *) headerSubtitleFor:(NSDictionary *)section;
+ (NSString *) headerHighlightFor:(NSDictionary *)section;
+ (NSString *) footerStringFor:(NSDictionary *)section;


#pragma ------------------------------------------
#pragma mark - MODULE DATA HANDLING
#pragma ------------------------------------------

#pragma mark Data Getters
// Core Data Modules
+ (NSDictionary *) getSectionData:(NSUInteger)sectionIndex fromViewData:(NSArray *)data;
+ (NSArray *) getContentsFrom:(NSDictionary *)sectionData;
+ (NSDictionary *) getItem:(NSIndexPath *)indexPath fromViewData:(NSArray *)data;
+ (NSDictionary *) getItem:(NSUInteger)itemIndex fromSectionContents:(NSArray *)contents;
#ifdef __SvnSenSDK
//Song Count
+ (NSString *) getSongCount:(NSDictionary *)data;
+ (BOOL) containsSongs:(NSDictionary *)data;
#endif
// Detail Views
+ (NSDictionary *) getDetailsFrom:(NSDictionary *)sectionData;
// Feature Cells
+ (NSDictionary *) getFeatureFrom:(NSDictionary *)sectionData;
// Section Headers
+ (NSDictionary *) getHeaderAction:(NSDictionary *)sectionData;

+ (NSDictionary *) getMoreFrom:(NSDictionary *)sectionData;

#pragma mark Flag Checks
+ (BOOL) hasFeature:(NSDictionary *)section;
+ (BOOL) hasMore:(NSDictionary *)section;


#pragma ------------------------------------------
#pragma mark - GENERAL MEDIA
#pragma ------------------------------------------

#pragma mark Media Types
// Media Types
+ (MediaType) mediaType:(NSDictionary *)data;
+ (MediaType) getMediaTypeFromTypeStr:(NSString *)type;
+ (NSString *) getMediaTypeString:(MediaType)type;
+ (ContentTypes) getContentTypeFromMediaType:(MediaType)type;
+ (MediaType) getMediaTypeFromContentType:(ContentTypes)type;

// Tags
+ (TagType) tagType:(NSDictionary *)data;

#pragma mark Media Flags
+ (BOOL) isDownloaded:(NSDictionary *)data;
+ (BOOL) isExplicit:(NSDictionary *)data;
+ (BOOL) isLive:(NSDictionary *)data;
+ (BOOL) isPerson:(NSDictionary *)data;
+ (BOOL) isPersonType:(MediaType)type;
+ (BOOL) isFollowable:(MediaType)type;
+ (BOOL) isFollowed:(NSDictionary *)data;
+ (BOOL) usesWideArt:(NSDictionary *)data;
+ (BOOL) cropSquareArtForWidescreen:(NSDictionary *)data;
+ (BOOL) showsPlayCount:(NSDictionary *)data;
+ (BOOL) showsFanCount:(MediaType)type;
+ (BOOL) showsCopyright:(MediaType)type;
+ (BOOL) isTextCell:(MediaType)type;
+ (BOOL) hasEditorsNote:(NSDictionary *)data;
+ (BOOL) hasEditorsPickContent:(NSDictionary *)editorsNoteData;
+ (BOOL) hasSubtitle:(NSDictionary *)data;

#pragma mark Library Checks
+ (BOOL) inLibrary:(NSDictionary *)entity;
+ (BOOL) inLibrary:(NSDictionary *)entity viaParentVC:(SaavnVC_n *)parentVC;

#pragma mark Availability
+ (BOOL) isUnavailable:(NSDictionary *)data;
+ (NSString *) unavailableReuseId:(NSString *)originalReuseId;
+ (NSString *) unavailableReason:(NSDictionary *)data;

#pragma mark String Getters
// Language
+ (NSString *) getLanguage:(NSDictionary *)data;
// Types
+ (NSString *) getMediaTypeDisplayString:(MediaType)type;
+ (NSString *) getTrackType:(MediaType)type;
// Counts
+ (NSString *) playCountStr:(NSDictionary *)data alwaysShow:(BOOL)showAnyCount;
+ (NSString *) fanCountStr:(NSDictionary *)data asCondensed:(BOOL)shouldCondense alwaysShow:(BOOL)showAnyCount;
// Meta Fields
+ (NSString *) getYear:(NSDictionary *)data;
+ (NSString *) getCopyright:(NSDictionary *)data;
+ (NSString *) getLabel:(NSDictionary *)data;
+ (NSString *) getReleaseDate:(NSDictionary *)data;
// Time
+ (NSString *) getTrackDuration:(NSUInteger)seconds;
+ (NSString *) getTotalDuration:(NSArray *)tracks inLongform:(BOOL)longform;
+ (NSString *) getTotalDuration:(NSArray *)tracks inLongform:(BOOL)longform withRounding:(BOOL)shouldRoundSeconds;
// Description
+ (NSString *) getDescription:(NSDictionary *)data;
// Badges
+ (NSString *) getBadge:(NSDictionary *)data;

#pragma mark Data Getters
// Track Lists
+ (NSArray *) getTrackListFrom:(NSDictionary *)data;
// More Info
+ (NSDictionary *) getMoreInfo:(NSDictionary *)data;
// Artists
+ (NSArray *) getPrimaryArtists:(NSDictionary *)data;
+ (NSArray *) getAllArtists:(NSDictionary *)data excludingPrimaryArtists:(BOOL)excludePrimaryArtists;
+ (NSString *) getPrimaryArtistsString:(NSDictionary *)data;
+ (NSString *) getAllArtistsString:(NSDictionary *)data;
// Time
+ (NSUInteger) getTrackTime:(NSDictionary *)data;
// Fan Counts
+ (NSUInteger) trackCount:(NSDictionary *)data;
+ (NSUInteger) getFanCount:(NSDictionary *)data;
+ (NSArray *) fanCountTypes;
+ (NSUInteger) fanThresholdFor:(MediaType)type;
// Colors
+ (UIColor *) getColor:(NSDictionary *)data;
// Editor's Note/Pick
+ (NSDictionary *) getEditorsNote:(NSDictionary *)data;
+ (NSString *) getEditorsNoteMessage:(NSDictionary *)data;
+ (NSDictionary *) getEditorsPick:(NSDictionary *)data;
+ (NSString *) getGenericShareMessage:(NSDictionary *)data;
+ (NSString *) getGenericShareMessage:(NSDictionary *)data withTracking:(NSString*)source;
+ (NSString *) generateTweet:(NSDictionary *)data;
+ (NSString *) generateEmailSubject:(NSDictionary *)data;
+ (NSString *) generateEmailBody:(NSDictionary *)data;

#pragma mark Load More
+ (MediaType) getLoadMoreType:(NSDictionary *)data;
+ (MediaType) getLoadMoreSource:(NSDictionary *)data;


#pragma ------------------------------------------
#pragma mark - SPECIFIC MEDIA
#pragma ------------------------------------------

#pragma mark Artists
+ (NSArray *) getBio:(NSDictionary *)data;
+ (NSString *) getBioPreview:(NSDictionary *)data;

#pragma mark Channels
+ (ChannelType) channelType:(NSDictionary *)data;
+ (BOOL) isChannelFeatured:(NSDictionary *)data;

#pragma mark Playlists
+ (NSString *) getPlaylistOwnerString:(NSDictionary *)entity allowingOwner:(BOOL)allowOwner;
+ (BOOL) isProPlaylist:(NSDictionary *)data;

#pragma mark Shows
+ (NSString *) getLogoForHeader:(NSDictionary *)data;
+ (NSString *) getBackgroundForHeader:(NSDictionary *)data;
+ (NSArray *) getSeasons:(NSDictionary *)data;
+ (NSInteger) getSeasonsCount:(NSDictionary *)data;
+ (NSArray *) formatEpisodeMeta:(NSArray *)episodes;

#pragma mark Songs
+ (NSString *) getLyrics:(NSDictionary *)data;
+ (NSString *) getMoreString:(NSDictionary *)data;

#pragma mark Users
+ (NSString *) getUserLogin:(NSDictionary *)data;


#pragma ------------------------------------------
#pragma mark - LOADERS
#pragma ------------------------------------------

#pragma mark View Controllers
+ (void) loadViewType:(MediaType)type fromData:(NSDictionary *)data inSection:(NSDictionary*)sectionData via:(SaavnVC_n *)parentVC withImage:(UIImage *)preloadedImage;
+ (SaavnVC_n *) getViewType:(MediaType)type fromData:(NSDictionary *)data inSection:(NSDictionary*)sectionData via:(SaavnVC_n *)parentVC withImage:(UIImage *)preloadedImage;


#pragma ------------------------------------------
#pragma mark - ACTIONS
#pragma ------------------------------------------

#pragma mark Library
+ (void) toggleLike:(NSDictionary *)data withFollowStatus:(BOOL)isFollowed;
+ (void) toggleLike:(NSDictionary *)entity withFollowStatus:(BOOL)isFollowed withHandler:(void (^)(BOOL success))completion;

#pragma mark Playback & Queue
+ (void) play:(NSDictionary *)entity inSection:(NSDictionary*)sectionData atIndex:(NSInteger)index ofMedia:(MediaType)type withTracking:(NSDictionary *)customTrackingDict viaParent:(SaavnVC_n *)parentVC;
+ (void) play:(NSDictionary *)entity inSection:(NSDictionary*)sectionData ofMedia:(MediaType)type withTracking:(NSDictionary *)customTrackingDict viaParent:(SaavnVC_n *)parentVC;
+ (void) play:(NSDictionary *)entity ofMedia:(MediaType)type withTracking:(NSDictionary *)customTrackingDict viaParent:(SaavnVC_n *)parentVC;
+ (void) playNext:(NSDictionary *)entity ofMedia:(MediaType)type withTracking:(NSDictionary *)customTrackingDict viaParent:(SaavnVC_n *)parentVC;
+ (void) playNext:(NSDictionary *)entity ofMedia:(MediaType)type withTracking:(NSDictionary *)customTrackingDict viaParent:(SaavnVC_n *)parentVC completion:(void(^)(void))completionBlock;
+ (void) addToQueue:(NSDictionary *)entity ofMedia:(MediaType)type withTracking:(NSDictionary *)customTrackingDict viaParent:(SaavnVC_n *)parentVC;
+ (void) startStationFromSearch:(NSDictionary *)station inLanguage:(NSString *)language withTracking:(NSDictionary *)customTrackingDict;
#pragma mark User Playlists
+ (void) renamePlaylist:(NSDictionary *)entity;
+ (void) deletePlaylist:(NSDictionary *)entity;
+ (void) deletePlaylist:(NSDictionary*)entity ofParent:(SaavnVC_n*)parentVC;
+ (void) togglePrivacyOfPlaylist:(NSDictionary *)entity;

#pragma mark Bookmarks
+ (void) bookmarkAll:(NSDictionary *)entity withStatus:(EpisodePlayState)state;

#pragma mark Downloads
#ifndef __SvnSenSDK

+ (void) downloadAll:(NSDictionary *)entity;
+ (void) downloadAll:(NSDictionary *)entity withTracking:(NSString *)customTrackingStr;
+ (void) deleteDownload:(NSDictionary *)entity withTracking:(NSString *)customTrackingStr;
#endif

#pragma mark - Video
+ (BOOL) hasVideo:(NSDictionary*) data;
+ (NSDictionary *) getPrimaryVideoData: (NSDictionary *) data;
+ (NSString *) getVideoUrl: (NSDictionary *) data;
+ (NSString *) getVideoThumbnail:(NSDictionary*) data;


#pragma mark - Third party videos Util
+ (BOOL) hasThirdPartyVideosData:(NSDictionary*) data;
+ (BOOL) isThirdPartyVideosAvailable:(NSDictionary *) data;
+ (NSDictionary *) getThirdPartyVideosData: (NSDictionary *) data;
+ (NSString *) getThirdPartyVideosURL: (NSDictionary *) data;
+ (NSString *) getThirdPartyVideosThumbnail:(NSDictionary*) data;

#pragma mark - Shortie videos Util
+ (BOOL) hasShortie:(NSDictionary*) data;
+ (BOOL) hasShortVideos:(NSDictionary*) data;
+ (BOOL) isShortVideosAvailable:(NSDictionary *) data;
+ (NSDictionary *) getShortieData: (NSDictionary *) data;
+ (NSString *) getShortieUrl: (NSDictionary *) data;
+ (NSString *) getShortieThumbnail: (NSDictionary *) data;


+ (BOOL) hasLoopingVideo:(NSDictionary *) data;
+ (NSString *) getLoopingVideoThumbnail:(NSDictionary*) data;

// for Module
+ (BOOL) isVideoAvailable:(NSDictionary *) data;
+ (BOOL) isVideo:(NSDictionary *)track;
+ (BOOL) isVideoAvailableKeyAvailable:(NSDictionary *) data;
+ (NSString *) getVideoAvailableThumbnail:(NSDictionary *) data;

+ (BOOL) hasDolbyContent:(NSDictionary *) data;
+ (BOOL) hasTransparentBg:(NSDictionary *)section;

+ (BOOL) proOnlyContent:(NSDictionary *)data;
+ (NSArray *) getSubTypesOfPlaylist:(NSDictionary*)playlist;
+ (BOOL) isProContent:(NSDictionary*)data;
@end

