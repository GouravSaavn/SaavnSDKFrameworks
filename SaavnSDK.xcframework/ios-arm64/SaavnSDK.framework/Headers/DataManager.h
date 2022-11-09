//
//  DataManager.h
//  Saavn
//
//  Created by Shatrughan Singh on 3/27/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SaavnVC_n.h"
extern NSString *const kAPIDataManager;
extern NSString *const kHomeDataManager;

typedef NS_ENUM (NSInteger, DataStatus) {
    Data_Fetching = 1,
    Data_Fetched = 2,
    Data_Failed = 3,
    Data_Unknown = 0
};

@interface DataManager : NSObject

+ (DataManager *) sharedManager;

#pragma mark - Default Config
@property(nonatomic,strong) NSDictionary *appLaunchData;
@property(nonatomic,strong) NSDictionary *globalConfig;
@property(nonatomic,strong) NSMutableDictionary *homepageData;
@property(nonatomic,strong) NSDictionary *loggedUserData;
@property(nonatomic,strong) NSMutableArray *topSearchesData;
@property(nonatomic,strong) NSDictionary *radioData;
@property(nonatomic,strong) NSMutableDictionary *viewedChannel;
@property(nonatomic,strong) NSDictionary *browseData;
@property(nonatomic,strong) NSDictionary *deferredLoginConfig;

#pragma mark - API

// Don't call these for any background process 
- (void) fetchData:(NSString *)method withParams:(NSDictionary*)params inDict:(NSDictionary **)mediaData;  // broadcast the notification based on datastatus
- (void) fetchData:(NSString *)method withParams:(NSDictionary*)params inArray:(NSArray **)mediaData;      // mediaData holds the response itself
- (void) fetchData:(NSString *)method withParams:(NSDictionary*)params from:(SaavnVC_n*)parent;            // Manager holds response in requestedData
- (void) fetchData:(NSString *)method withParams:(NSDictionary*)params;
- (void) fetchData:(NSString *)method withParams:(NSDictionary *)params success:(void(^)(id successResponse))successBlock andFailure:(void(^)(NSError *errorResponse))failureBlock;                                                                           // return success/fail block based on results
                                                                                                            // NO broadcast notification

#pragma mark - HOME Handler
- (void) fetchHomepageData;
- (void) fetchBrowsepageData;
- (void) parseHomepageData:(id)JSON isLocal:(BOOL)local;
- (void) parsePaginatedHomepageData:(id)JSON withModules:(NSMutableDictionary*) modules;
- (void) replaceProStatus:(NSDictionary *) prostatus;
- (void) fetchDataForSource:(NSString *) source;

#pragma mark - Getters
- (id) getCurrentResponseData;
- (id) getCurrentResponseDataFor:(SaavnVC_n*)vc;
- (SaavnVC_n *) getRequestedVC;
- (void) flushRequestedData;

#pragma mark - Cache Data handling
// Get saved data
+ (NSDictionary *) getSavedLaunchData;
+ (NSMutableDictionary *) getSavedHomeData;
+ (NSDictionary *) getSavedUserData;
+ (NSDictionary *) getSavedHomeSourceApiData;
+ (NSDictionary *) getSavedZlaUserData;
+ (NSDictionary *) getSavedBrowseData;

// Set current data
+ (void) savedCurrentLaunchData:(id)dict;
+ (void) savedCurrentHomeData:(id)dict;
+ (void) savedCurrentUserData:(id)dict;
+ (void) savedBrowseData:(id)dict;
+ (void) savedCurrentData:(id)dict withKey:(NSString*)key;
+ (void) flushCachedData;
+ (void) savedZlaUserData:(id)dict;

#pragma mark - Get LaunchData Utils Getters
- (NSDictionary*) getLaunchData;
- (NSDictionary*) getHomeData;
- (NSDictionary*) getUserData;
- (NSArray *) getTopSearchesData;
- (NSArray *) getFeaturedStation;
- (NSArray *) getNewAlbums;
- (NSArray *) getNewTrending;
- (NSArray *) getTopPlaylist;
- (NSArray *) getSuggestions;
- (NSArray *) getChannels;
- (NSArray *) getRecentlyPlayed;
- (NSMutableArray *) getTopShows;
- (NSMutableArray *) getCharts;
- (NSDictionary *) getBrowseData;
- (NSDictionary *) getDeferredLoginConfigData;


#pragma mark - Utils
// Language Data
- (NSArray *) getSupportedLanguages;

// Radio language Data.
- (NSArray *) getSupportedRadioLanguages;

// Top15 Data
- (NSDictionary *) getTop15s;

// Surpise Data
- (NSDictionary *) getSurpriseMes;

// Global config
- (NSDictionary *) getGlobalConfig;
- (NSDictionary *) getAdConfig;
- (NSDictionary *) getStreamConfig;
- (NSString *) getGlobalConfigVal:(NSString *)key;
- (NSObject *) getGlobalConfigObject:(NSString *)key;


- (BOOL) isUnAvailableChannelPromptViewed:(NSDictionary*)channelData;
- (NSArray *) getChannelData;
@end
