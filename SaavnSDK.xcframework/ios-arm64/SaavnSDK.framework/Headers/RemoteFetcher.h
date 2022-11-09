//
//  RemoteFetcher.h
//  Saavn
//
//  Created by Shatrughan Singh on 4/27/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MediaUtil_n.h"

// These are action which user can take from 3D touch or menu options
// This will be used when media object is incomplete

typedef enum {
    Content_Play = 1,
    Content_AddToQueue = 2,
    Content_AddToPlaylist = 3,
    Content_Follow = 4,
    Content_PlayRadio = 5,
    Content_Download = 6,
    Content_Share = 7,
    Content_Radio = 8,
    Content_AddToLibrary = 9,
    Content_NextToPlay = 10
} ActionType;

@interface RemoteFetcher : NSObject

+ (void) fetchEntity:(NSString *)entityId ofType:(ContentTypes)type andAction:(ActionType)action fromEntity:(NSString *)mediaId  withExtras:(NSDictionary*) extras;

@end
