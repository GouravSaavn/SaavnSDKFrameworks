//
//  BookmarkManager.h
//  Saavn
//
//  Created by Dhruvil Vyas on 5/10/16.
//  Copyright 2009-2013 Dhruvil Vyas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MediaUtil_n.h"
 @interface BookmarkManager : NSObject {
}

+ (instancetype) sharedManager;

// Create or Update Methods
- (void) updateBookmarkEntryForMedia: (NSString *) pid
                            parentId: (NSString *) id;
- (void) createOrUpdateBookmarkEntryForMedia: (NSString *) mediaId
                                    parentId: (NSString *) parentId
                            mediaElapsedTime: (NSTimeInterval) elapsedTime
                                  lastPlayed: (NSTimeInterval) timestamp
                                  isComplete: (BOOL) complete;

// Setters
- (void) setCompletedPlayingForMedia: (NSString *) mediaId;
- (void) setElapsedTime: (NSTimeInterval) elapsed forBookmarkEntry: (NSString *) mediaId;

// Getters
- (NSTimeInterval) getElapsedTimeForBookmarkEntry: (NSString *) mediaId;
- (NSTimeInterval) getLastPlayedTimeStampForParent: (NSString *) parentId;
- (EpisodePlayState) getPlayStateForBookmarkEntry: (NSString *) mediaId;
- (NSArray *) getAllBookmarkEntryForParent: (NSString *) parentId;

// Delete
- (void) deleteBookmarkEntry:(NSString*)mediaId;
- (void) trimBookmarksDB;
@end
