//
//  SongUtil.h
//  Saavn
//
//  Created by Dhruvil Vyas on 3/23/16.
//  Copyright © 2016 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SongUtil : NSObject

// People
+ (NSArray*) getActorsForSongInArray: (NSDictionary*) song;
+ (NSArray*) getSingersForSongInArray: (NSDictionary*) song;
+ (NSArray*) getMusicDirectorsForSongInArray: (NSDictionary*) song;

+ (NSString*) getActorsForSong: (NSDictionary*) song;
+ (NSString*) getSingersForSong: (NSDictionary*) song;
+ (NSString*) getMusicDirectorsForSong: (NSDictionary*) song;
+ (NSString*) getShowTitle: (NSDictionary*) song;
+ (NSString *) getBestArtist:(NSDictionary *)song withHyphen:(BOOL)showHyphen;

// Get full standardized metadata string for song rows.
+ (NSString *) getFullMeta:(NSDictionary *)song;

+ (NSDictionary*) getArtistMapForSong: (NSDictionary*) song;

+ (NSArray *) getArtistsForSong: (NSDictionary *) song;
+ (NSArray *) getPrimaryArtistsForSong: (NSDictionary *) song;
+ (NSArray *) getFeaturedArtistsForSong: (NSDictionary *) song;

// Rights
+ (NSDictionary*) getRightsForSong: (NSDictionary*) song;
+ (NSUInteger) getRightsCodeForSong: (NSDictionary*) song;
+ (NSString*) getRightsReasonForSong: (NSDictionary*) dictionary;

// Storage Checks
+ (BOOL) isSongCacheable: (NSDictionary*) song;
+ (BOOL) isSongAvailable: (NSDictionary*) song;
+ (BOOL) isSongPlayable: (NSDictionary*) song;
+ (BOOL) isSongAvailableForPlay: (NSDictionary*) song;

// Images
+ (NSURL*) getImageUrlForSong: (NSDictionary*) song;
+ (NSString*) getImageStringForSong: (NSDictionary*) song;

// Media Path/URL
+ (NSString*) getPermaUrlForSong: (NSDictionary*) song;
+ (NSString *) getPermaUrlForAlbumFromSong: (NSDictionary *) song;
+ (NSString*) getEncryptedMediaUrlForSong: (NSDictionary*) song;
+ (NSString*) getEncryptedMediaPathForSong: (NSDictionary*) song;
+ (NSString*) getAlbumUrlForSong: (NSDictionary*) song;
+ (NSString*) getLocalImagePathForSong: (NSDictionary*) song;
+ (NSString*) getLocalMediaPathForSong: (NSDictionary*) song;

// Meta data
+ (NSDictionary *) getAlbumDetailsForSong: (NSDictionary *) song;
+ (NSDictionary*) getSongFromDictionary: (NSDictionary*) songDictionary forId: (NSString*) songId;
+ (NSString*) getLanguageForSong: (NSDictionary*) song;
+ (NSString*) getNameForSong: (NSDictionary*) song;
+ (NSString*) getAlbumForSong: (NSDictionary*) song;
+ (NSString*) getAlbumIdForSong: (NSDictionary*) song;
+ (NSString*) getYearForSong: (NSDictionary*) song;
+ (NSString*) getCopyrightForSong: (NSDictionary *) song;
+ (NSString*) getLabelForSong: (NSDictionary*) song;
+ (NSString*) getIdForSong: (NSDictionary*) song;
+ (BOOL) isJioTransferredSong: (NSDictionary *) song;
+ (NSString *) getJidForSong: (NSDictionary *) song;
+ (NSString*) getDurationForSong: (NSDictionary*) song;
+ (NSString*) getEncPartialForSong: (NSDictionary*) song;
+ (NSString *) getSongType: (NSDictionary *) song;
+ (NSString *) getOrigin: (NSDictionary *) song;
+ (NSString *) getReferrerId: (NSDictionary *) song;
+ (BOOL) isLongFormContent: (NSDictionary *) song;
+ (BOOL) isBrandChannelContent: (NSDictionary *) song;
+ (NSInteger) getPlayCount: (NSDictionary *)song;
+ (NSString *) getPartner: (NSDictionary *) song;
+ (NSInteger) getFavouriteForSong:(NSDictionary*)song;
+ (BOOL) hasLyrics: (NSDictionary *)song;
+ (NSArray *) getVideoMappingsForSong: (NSDictionary *) song;


// Cache State
+ (int) getSavedCacheStateForSong: (NSDictionary*) song;
+ (int) getCacheStateForSong: (NSDictionary*) song;
+ (int) checkLocalCacheState: (NSDictionary*) song;

// Setters
// Removing attributes
+ (NSMutableDictionary*) removeLocalMediaPathForSong: (NSMutableDictionary*) song;
+ (NSMutableDictionary*) removeLocalImagePathForSong: (NSMutableDictionary*) song;
+ (NSMutableDictionary*) removeCacheStateForSong: (NSMutableDictionary*) song;

// Add/Update Attributes
+ (NSMutableDictionary*) updateRightsCode: (NSNumber*) code forSong: (NSMutableDictionary*) song;
+ (NSMutableDictionary *) updateRightsObject: (NSDictionary *) new_rights forSong: (NSMutableDictionary *) song;
+ (NSMutableDictionary*) conformSongToNewFormatIfRequired: (NSMutableDictionary*) song;

// Artists Helper routines

// Primary Artist Ids
+ (NSArray *) getPrimaryArtistIdsForSongTypeArray: (NSDictionary *) song;
+ (NSString *) getPrimaryArtistIdsForSongTypeString: (NSDictionary *) song;
// Primary Artist Names
+ (NSString*) getPrimaryArtistNamesForSong: (NSDictionary*) song;
+ (NSString*) getFeaturedArtistNamesForSong: (NSDictionary*) song;
+ (BOOL) localPathExistsForSong: (NSDictionary *) song;
+ (NSString *) getIdForArtistName: (NSString *) artistName fromSong: (NSDictionary *) song;

// Download - bitrate
+ (BOOL) get320Kbps: (NSDictionary*) song;

// Explicit Content
+ (BOOL) isExplicitSong :(NSDictionary*) song;

//jiotune
//+ (BOOL) isJioTuneAvailable:(NSDictionary *) song ;
// Tracking
+ (NSString *) getSourceViewForSong:(NSDictionary *) song;

#pragma mark - Listening History Song
+ (NSArray*) getSongsForHistory :(NSDictionary*) list;
+ (NSDictionary*) getSongForHistory:(NSDictionary*)song;

// Util
+ (NSDictionary *) getMoreInfo: (NSDictionary *) song;
+ (NSString *) getLyricsSnippet:(NSDictionary *) song;
+ (NSString *) getLyricsId:(NSDictionary *) song;

+ (BOOL) getMulti_bitrateInfo:(NSDictionary *) song;

+ (NSString *) getMediaVideoUrl:(NSDictionary*)song;
@end
