//
//  MediaCell.h
//  New Saavn
//
//  Created by Clint Balcom on 11/14/17.
//  Copyright © 2017 Saavn. All rights reserved.
//

#import "MediaUtil_n.h"

@interface MediaCell : UITableViewCell <UIGestureRecognizerDelegate>


@property (nonatomic) BOOL isTransparent, isUnavailable, standardAccessory, hideImage, customLayout, shouldRoundImage, ignoreMetaExtras, showIndexes;
@property (nonatomic) BOOL inAlbumView, inArtistView, hasTableIndex,isAvailableInLibrary, inPlayerView, inPlayerQueue, isBulkEditing, isSearchView, isSearchTrendingView, isJioTuneAvailable,isCurrentJioTune;

@property (nonatomic) CGFloat accessoryOffset, topOffset;

@property (nonatomic, strong) NSIndexPath *indexPath;
@property (nonatomic, strong) UIView *imgBevel;
@property (nonatomic, strong) UILabel *index;

// Tracking
@property (nonatomic, strong) NSMutableDictionary *trackingDict;


#pragma mark - Theme & Status Updates
- (void) updateUIMode;
- (void) setEditingTextColors:(BOOL)selectedStyle;

#pragma mark - Setters
- (void) setData:(NSDictionary *)data;
- (void) hideImageBevel;
- (void) hidePlayState;
- (void) setPlayState:(EpisodePlayState)state;
- (void) setNowPlaying;
- (void) removeTouchGestures;
- (void) disableTouchGestures:(BOOL)shouldDisable;
- (void) setAsSelectable:(BOOL)setSelectableMode;

#pragma mark - Getters
+ (NSString *) reuseIdFor:(MediaType)type;
+ (NSString *) reuseIdFor:(MediaType)type inLibraryView:(BOOL)isLibraryView;
+ (NSString *) reuseIdFor:(MediaType)type inDownloadsView:(BOOL)isDownloadsView;
+ (NSString *) reuseIdFor:(MediaType)type inSearchView:(BOOL)isSearchView;
+ (NSString *) reuseIdFor:(MediaType)type inRecentSearchView:(BOOL)isSearchView;
+ (NSString *) reuseIdFor:(MediaType)type inReqJioTuneView:(BOOL)isReqJioTuneView;
+ (NSString *) reuseIdFor:(MediaType)type forVideo:(BOOL)isVideoView;
+ (NSString *) paddedReuseId:(NSString *)currentReuseId;
- (BOOL) hasTag;
- (NSDictionary *)getMediaData;
- (NSString*) getMediaId;
- (BOOL) getNowPlaying;
#pragma mark - Actions
- (void) likeTap;


@end

