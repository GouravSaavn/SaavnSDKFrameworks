//
//  DataAdapter.h
//  Saavn
//
//  Created by Shatrughan Singh on 3/28/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ModuleAdapter : NSObject

+ (NSMutableDictionary *) getSingleModuleData:(NSDictionary *)module from:(NSDictionary *)data;
+ (NSMutableDictionary*) getSingleModuleData:(NSDictionary *)module fromClientData:(NSArray *)data;
+ (NSMutableDictionary*) getSingleModuleData:(NSDictionary *)module fromAPIData:(NSArray *)data;
+ (NSMutableArray *) getModuleData:(NSDictionary *)dict;

// Filter
+ (NSMutableDictionary *) getMediaDetailsWithoutModuleInfo:(NSDictionary*)data;

// Default Module
+ (NSArray *) getDefaultAlbumModules;
+ (NSArray *) getDefaultPlaylistModules;
+ (NSArray *) getDefaultSongModules;
+ (NSArray *) getDefaultArtistModules;
+ (NSDictionary *) getDefaultShowMoreModule:(NSDictionary *)module;

+ (NSMutableDictionary *) getVideoModule;
@end
