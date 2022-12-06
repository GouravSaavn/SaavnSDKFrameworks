//
//  JiotuneManager.h
//  Saavn
//
//  Created by user on 7/2/19.
//  Copyright © 2019 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JiotuneManager : NSObject

+ (JiotuneManager *) sharedManager;
- (void) checkIfJioTuneChanged:(time_t)backendLastCheck;

- (BOOL) isVcodeAvailable:(NSString*)pid;
- (NSString *) getVcodeOfSong:(NSString*)pid;
- (NSString *) getVlinkOfSong:(NSString*)pid;
- (void) HandleJioTuneForSong:(NSString*) responseString;

@end

NS_ASSUME_NONNULL_END
