//
//  DataUtil.h
//  Saavn
//
//  Created by Shatrughan Singh on 3/26/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Layout.h"

@interface DataUtil : NSObject

+ (NSInteger) getNumberOfModules:(NSDictionary*)dict;
+ (NSDictionary *) getModules:(NSDictionary*) dict;
+ (NSMutableArray *) getModulesData:(NSDictionary*)dict;
+ (NSMutableArray *) getSortedModulesData:(NSDictionary*)dict;
+ (NSMutableArray*) getContentForModule:(NSString*)module from:(NSDictionary*)dict;
+ (NSMutableArray*) getContentForAPIModule:(NSString*)module from:(NSDictionary*)dict;
+ (NSArray*) sortModuleDataBasedOnPosition:(NSArray*) data;

#pragma mark - Layout adapter
+ (NSString *) getSectionTypeString:(NSDictionary*)dict;
+ (SectionType) getSectionType:(NSDictionary*)dict;
+ (NSString *) getSectionTypeStringFromEnum:(SectionType) type;

#pragma mark - Utils
+ (BOOL) isAnyClientSourceAvailable:(NSDictionary*)dict;
+ (BOOL) isAnyApiSourceAvailable:(NSDictionary*)dict;

// Module Entity
+ (NSString *) getSourceInfo:(NSDictionary*) dict;
+ (NSInteger) getPositionOfModule:(NSDictionary*)dict;
+ (NSString *) getTitleOfModule:(NSDictionary*)dict;
+ (NSString *) getSubtitleOfModule:(NSDictionary*)dict;
+ (BOOL) getSimpleHeaderOfModule:(NSDictionary*)dict;
+ (BOOL) getNoHeaderOfModule:(NSDictionary*)dict;
+ (BOOL) getFeaturedOfModule:(NSDictionary*)dict;
+ (BOOL) getHideMediaOfModule:(NSDictionary*)dict;
+ (BOOL) isSourceClient:(NSDictionary*)dict;
+ (BOOL) isSourceAPI:(NSDictionary*)dict;
+ (BOOL) isShowMoreAvailable:(NSDictionary*)dict;

@end
