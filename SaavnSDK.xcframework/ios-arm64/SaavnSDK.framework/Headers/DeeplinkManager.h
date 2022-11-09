//
//  DeeplinkManager.h
//  Saavn
//
//  Created by Shatrughan Singh on 5/4/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DeeplinkManager : NSObject

- (BOOL) handleDeepLinkUrl:(NSURL *) url withHandler:(void (^)(void))handler;
- (BOOL) handlePermaUrl:(NSURL*) url;
- (BOOL) convertPermaUrlToDeepLink:(NSString *) targetURLString;

- (void) handleProDeeplinkModule:(NSDictionary*)data;
@end
