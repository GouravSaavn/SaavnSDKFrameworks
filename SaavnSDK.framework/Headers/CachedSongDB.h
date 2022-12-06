//
//  CachedSongDB.h
//  Saavn
//
//  Created by Ramesh Sudini on 11/7/12.
//
//

#import <Foundation/Foundation.h>

#ifndef CACHEDSONGDB_H
#define CACHEDSONGDB_H

#define CACHE_STATE_PENDING 1
#define CACHE_STATE_DOWNLOADING 2
#define CACHE_STATE_CACHED 3
#define CACHE_STATE_DOWNLOAD_FAILED 4

#define NUMBER_OF_CACHED_SONGS_TO_BATCH 5000
#import <Foundation/Foundation.h>
#import <sqlite3.h>

extern NSString * const subsDatabaseName;


@interface CachedSongDB : NSObject {
    
    NSString *databasePath;
    sqlite3 *database;
    volatile BOOL isDirty;
    
    
}

- (BOOL) updateDB:(NSDictionary *) song;
- (BOOL) storeToDB:(NSDictionary *) song localPath:(NSString *) localPath;
- (id) getSongPidsForLibrary;
- (NSMutableArray *) getSongs:(BOOL)ignoreProState;
- (NSMutableArray *) getSongs:(BOOL)ignoreProState onlyCached:(BOOL)offline;
- (NSMutableArray *) getsongPids;
- (void) getSongPidsAsync: (void (^)(NSArray *)) completion;
- (NSMutableArray *) getPendingSongs;
- (void) checkAndCreateDatabase;
- (void) checkAndCreateCachedSongsTable;
- (void) updateImageLocalCache:(NSString *) songid imgpath:(NSString *)imgpath;
- (void) updateCachePathAndState:(NSString *) songid cacheState:(int)cacheState path:(NSString*) path;
- (void) updateCacheState:(NSString *) songid cacheState:(int)cacheState;
- (BOOL) isCacheDirty;
- (void) purgeDB;
- (NSMutableDictionary *) getSingleSong:(NSString *) songid;
- (void) removeSong:(NSDictionary *) song;
- (void) deletePendingSongs;
- (NSMutableArray *) getCacheDataForDisplay;
- (void) printTheDamnDB;
- (NSInteger) countDownloadedSongs;
- (NSDictionary*) getUnCachedVersion:(NSDictionary*) song;
- (int)  getPendingSongsCount;
- (NSMutableArray *) getCachedSongPids;

+ (CachedSongDB*) cachedSongDBSingleton;

- (NSInteger) getDownloadedSongs;
- (BOOL) updateSongObjectInDBFromUpdateManager:(NSDictionary *) song;
@end

#endif
