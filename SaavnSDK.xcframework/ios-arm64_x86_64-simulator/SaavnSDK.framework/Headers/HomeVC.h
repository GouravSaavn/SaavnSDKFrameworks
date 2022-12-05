//
//  HomeVC.h
//  Saavn 4.0
//
//  Created by Clint Balcom on 2/19/15.
//  Copyright (c) 2015 Saavn. All rights reserved.
//

#import "GroupVC.h"

// Subclasses
#import "ViewTabs.h"


static NSString *typeAlbum = @"album",
                *typeArtist = @"artist",
                *typeChart = @"chart",
                *typeChannel = @"channel",
                *typeMyMusic = @"my_music",
                *typePlaylist = @"playlist",
                *typeRadio = @"radio_station",
                *typeShow = @"show",
                *typeSong = @"song",
                *typeVideo = @"video",
                *typeEpisode = @"episode",
                *typeSurprise = @"surprise",
                *typeMixPlaylist = @"mix";


@interface HomeVC : GroupVC <UITableViewDataSource, UITableViewDelegate, UICollectionViewDataSource, UICollectionViewDelegate>


#pragma mark - Notification Handling
- (void) setNotificationBadge;

#pragma mark - Getters
- (BOOL) isViewSetUp;
- (ViewTabs *) getViewTabs;

- (void) handleProStatusChanges;
- (void) checkAndPerformDownloadMigration;

#pragma mark - Setters
- (void) setToTab:(NSUInteger)tabIndex withAction:(BOOL)performTapAction;
- (void) showJioTunes;
- (void) setTabUnderline:(NSUInteger)tabIndex withAction:(BOOL)performTapAction;
@end

