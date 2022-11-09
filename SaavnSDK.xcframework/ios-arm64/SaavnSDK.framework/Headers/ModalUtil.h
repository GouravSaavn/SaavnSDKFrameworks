//
//  ModalUtil.h
//  New Saavn
//
//  Created by Clint Balcom on 1/24/18.
//  Copyright © 2018 Saavn. All rights reserved.
//

#import "MediaUtil_n.h"
typedef enum {
    ModalError_UNKNOWN  = 0,
    
    // Playlists
    ModalError_AddToList = 1,
    ModalError_SaveList  = 2,
    
    // Delete & Unfollow
    ModalError_Delete    = 10,
} ModalErrors;


@interface ModalUtil : NSObject


#pragma mark - Simple (No Op) Dialog
+ (void) showSimpleAlert:(NSString *)title andMessage:(NSString *)message forVC:(SaavnVC_n*)vc;
+ (void) showSimpleAlert:(NSString *)title andMessage:(NSString *)message;
+ (void) showGenericError;
+ (void) showError:(ModalErrors)errorKey;

#pragma mark - Options
+ (void) showOptions:(NSDictionary *)entity withImage:(UIImage *)image;
+ (void) showOptionsForView:(SaavnVC_n *)parentVC withData:(NSDictionary *)entity andTracking:(NSMutableDictionary *)trackingDict andImage:(UIImage *)image;
+ (void) showOptionsForView:(SaavnVC_n *)parentVC
               viaIndexPath:(NSIndexPath *)indexPath
                   withData:(NSDictionary *)entity
                andTracking:(NSMutableDictionary *)trackingDict
                   andImage:(UIImage *)image;
+ (void) showOptionsForOfflineView:(SaavnVC_n *)parentVC withData:(NSDictionary *)entity andTracking:(NSMutableDictionary *)trackingDict andImage:(UIImage *)image;

#pragma mark - Playlist Management
+ (void) showPlaylistModal:(NSDictionary *)entity inParent:(SaavnVC_n *)parentVC;
+ (void) showSaveQueueModal:(NSArray *)queue;
+ (void) createPlaylistFromEntity:(NSDictionary *)weakEntity;
+ (void) createPlaylistFromQueue:(NSArray *)queue;
+ (void) createEmptyPlaylist;

#pragma mark - Library Views
+ (void) showEmptyViewModalFor:(MediaType)type;

#pragma mark - General Media Alerts
+ (void) showUnavailableModal:(NSDictionary *)entity;
+ (void) showOfflineContentModal:(NSDictionary *)entity;
+ (void) showExplicitModal:(NSDictionary *)entity;

#pragma mark - Downloads
+ (void) showSyncOverCellularModal;

#pragma mark - Sharing
+ (void) showShareModal:(NSDictionary *)data withImage:(UIImage *)image;
+ (void) showShareModal:(NSDictionary *)data withImage:(UIImage *)image isReplayPlaylist: (BOOL)isReplayPlaylist;
+ (void) showScreenshotShare:(NSDictionary *)data;

#pragma mark - Marketing
+ (void) showMarketingModal:(NSDictionary *)data;

#pragma mark - User Account
+ (void) showLogOut;
+ (void) showUnsavedChangesPrompt:(SaavnVC_n*) forVC;

#pragma mark - Clearing Local Storage
+ (void) clearRecentSearches:(void(^)(void))completion;
+ (void) clearHistory;

#pragma mark - Jiotune Preview
+ (void) showJioTunesPrompt:(NSDictionary *)entity inSection:(NSDictionary *)sectionData andImage:(UIImage*)image;

+ (void) showRestrictedDatatModal;
+ (void) showUpgradeModal;
+ (void) showDeviceExceedModal;
+ (void) showDolbySupportedPrompt;
+ (void) showDeviceExceedModal:(UIViewController *) targetVC;
@end

