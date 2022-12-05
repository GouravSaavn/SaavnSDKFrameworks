//
//  MyLibraryManager.h
//  Saavn
//
//  Created by Dhruvil Vyas on 11/14/16.
//  Copyright © 2016 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MediaUtil_n.h"

typedef enum NSUInteger {
    EntryTypeSong = 0,
    EntryTypePlaylist = 1,
    EntryTypeAlbum = 2,
    EntryTypeArtist = 3,
    EntryTypeShow = 4,
    EntryTypeVideo = 5,
    EntryTypeEpisode = 6,
    EntryTypeNone = 100
}EntryType;

@interface MyLibraryManager : NSObject

// Properties
@property (nonatomic) BOOL isSyncing; // Always access it on the main thread.

// Methods
+ (instancetype) sharedManager;

// Configuration
- (BOOL) getAutoDownloadStatus;
- (void) setAutoDownloadStatus: (BOOL) status completion: (void (^)(BOOL)) completion;

#pragma mark - MEDIA UTILS
- (NSInteger) getMediaCount:(MediaType)type;
- (NSMutableArray *) getAllMedia:(MediaType)type;
- (NSDictionary *) getSingleMedia:(NSString*)mediaId andType:(MediaType)type;
- (NSUInteger) getMediaCountForAlbum: (NSString *) albumID andType:(MediaType)type;
- (NSMutableArray *) getNextMedia:(NSString *) previousMediaId andType:(MediaType)type;
- (NSMutableArray *) getNextMedia: (NSString *) previousMediaId tillLetter: (NSString *) letter andType:(MediaType)type;
- (NSMutableArray *) getAllMediaIdsFor:(MediaType)type;
- (void) getAllMediaIdsAsyncfor:(MediaType)type withHandler: (void (^)(NSArray *)) completion;
- (NSArray *) getMediaFromIds: (NSArray *) mediaIds withType:(MediaType)type;

#pragma mark - VIDEO METHODS
- (void) addVideosToLibrary: (NSArray *) videos explicitAction: (BOOL) explicit;
- (void) removeVideosFromLibrary: (NSArray *) videos explicitAction: (BOOL) explicit;
- (void) getAndRemoveVideosFromLibrary: (NSArray *) videos explicitAction: (BOOL) explicit;
- (void) removeVideoFromLibrary:(NSString *)mediaId explicitAction: (BOOL) explicit;
- (void) fetchandUpdateVideos: (NSString *) mediaIds;
- (void) addVideosToUserLibrary:(NSArray*)videos;
- (void) removeVideosFromUserLibrary:(NSArray*)videos;

#pragma mark - SONG METHODS
- (NSMutableArray *) getAllSongIds;
- (void) getAllSongIdsAsync: (void (^)(NSArray *)) completion;
- (NSArray *) getSongsFromIds:(NSArray *) songIds;
- (void) addSongsToLibrary: (NSArray *) songs explicitAction: (BOOL) explicit;
- (void) removeSongsFromLibrary: (NSArray *) songs explicitAction: (BOOL) explicit;
- (void) getAndRemoveSongsFromLibrary: (NSArray *) songs explicitAction: (BOOL) explicit;
- (void) removeSongFromLibrary:(NSString *)songID explicitAction: (BOOL) explicit;
- (void) fetchandUpdateSongs: (NSString *) songIds;
- (void) fetchandUpdateEntity: (NSString *) entityId andType:(NSString *) entityType;
- (void) removeEntityFromLibrary: (NSString *) entityId andType:(NSString *) entityType;
- (NSDictionary *) getSingleSong:(NSString*)songid;
- (NSUInteger) getSongsCountForAlbum: (NSString *) album;
- (void) updateSongToDB:(NSDictionary*)song;

- (NSInteger) getSongCount;
- (NSMutableArray *) getAllSongs;
- (NSMutableArray *) getNextSongs: (NSString *) previousSong;
- (NSMutableArray *) getNextSongs: (NSString *) previousSong tillLetter: (NSString *) letter;
- (NSArray *) getFilteredItemsWithSearchString: (NSString *) searchString type: (EntryType) type;
- (NSArray *) getSongsOfAlbum: (NSString *) albumId;
- (NSArray *) getUnAvailableSongFromLibrary: (NSArray *) songs;
- (NSDictionary *) getSongCountGroupedByIndices;

- (NSDictionary *) getMediaCountGroupedByIndices:(MediaType)type;
- (NSArray *) getMediasFromIndex: (int) index withType:(MediaType)type;


// Playlist
- (NSArray *) getAllPlaylist;
- (NSDictionary *) getSinglePlaylist:(NSString*)playlistid;
- (void) addSongsFromPlaylistToLibrary: (NSDictionary *) playlist;
- (void) addPlaylistToLibrary:(NSDictionary *) playlist withSongs:(NSArray*)songs;
- (void) addPlaylistsToLibrary:(NSArray*)playlists;
- (void) removePlaylistFromLibrary: (id) playlist;
- (void) fetchandUpdatePlaylist: (NSString *)playlistIds;
- (void) updateSongToPlaylistInLibrary: (NSDictionary *) playlist;
- (NSDictionary *) getForYouPlaylist;
- (void) updatePlaylistPlayedTimestamp:(NSString *)playlistId;

// Albums
- (NSArray *) getAlbumsFromIndex: (int) index;
- (NSArray *) getAllAlbums;
- (void) addAlbumToLibrary: (NSDictionary *) album;
- (void) removeAlbumFromLibrary: (NSDictionary *) album;
- (void) removeOnlyAlbumFromLibrary: (id) album;
- (void) fetchandUpdateAlbum: (NSString *) albumIds;
- (void) addAlbumOnly:(NSArray *) albums;
- (BOOL) checkIfAlbumExists:(NSString *) albumID;
- (NSDictionary *) getSingleAlbum:(NSString*)albumid;
- (void) deleteAlbumsIfNecessary: (NSArray *) albumIds;
- (NSDictionary *) getAlbumCountGroupedByIndices;
- (void) updateAlbumDBOnLaunch;


// Artists
- (void) addArtistsToLibrary: (NSArray *) artists explicit: (BOOL) explicit;
- (void) removeArtistsFromLibrary: (NSArray *) artistIDs explicit: (BOOL) explicit; // Use IDs to remove artists from the DB
- (NSArray *) getArtistsFromIndex: (int) index;
- (NSArray *) getAllArtists;
- (NSDictionary *) getSingleArtist:(NSString*)artistId;
- (NSArray *) getSongsForArtist: (NSString *) id;
- (NSDictionary *) getArtistCountGroupedByIndices;

// Show
- (NSArray *) getShowsFromIndex: (int) index;
- (void) addShowsToLibrary:(NSArray *) show;
- (void) followShow:(NSArray *) episodes;
- (void) removeShowFromLibrary: (id) show;
- (NSArray *) getAllShow;
- (NSDictionary *) getSingleShow:(NSString*)showid;
- (NSDictionary *) getShowCountGroupedByIndices;

// Sync method
- (NSArray *) getIdsforSongs;
- (NSArray *) getIdsforAlbums;
- (NSArray *) getExplicitIdsforAlbums;
- (NSArray *) getIdsforShows;
- (NSArray *) getIdsforArtists;
- (NSArray *) getExplicitIdsforArtists;
- (NSArray *) getIdsforPlaylists;
- (NSArray *) getPlaylistsForSync;
- (NSInteger) getCountforSongs;
- (NSInteger) getCountforAlbums;
- (NSInteger) getCountforShows;
- (NSInteger) getCountforArtists;
- (NSInteger) getCountforPlaylists;

- (void) clearWholeMyLibrary;

// Global
- (BOOL) checkIfEntityExists:(NSString *) entityID;

#pragma mark Remote Libray Operation
- (void) addSongsToUserLibrary:(NSArray*)songs;
- (void) removeSongsFromUserLibrary:(NSArray*)songs;
- (void) addAlbumToUserLibrary:(NSDictionary*) album;
- (void) removeAlbumFromUserLibrary:(NSDictionary*) album;

- (void) cacheSongsOfMyLibrary:(NSArray*) songs;

- (NSArray *) fetchIndexforType: (EntryType) inpType;


- (void) getAsyncCountForEntity: (EntryType) integer completion: (void (^)(NSUInteger)) completion;
@end
