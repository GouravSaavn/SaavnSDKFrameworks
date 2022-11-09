//
//  SaavnVC_n.h
//  New Saavn
//
//  Created by Clint Balcom on 8/20/17.
//  Copyright © 2017 Saavn. All rights reserved.
//

// Global Utilities
#import "ViewTypes.h"

// Parent Controllers
#import "SaavnNavBar.h"
#define __SvnSenSDK = 1
// Subclasses
//#import "EmptyErrorState.h"
#import "FauxNav.h"
#ifndef __SvnSenSDK
#import "SaavnAdView.h"
#endif
#import "SaavnRefresh.h"
#import "SegmentTabs.h"
#import "Events.h"
//Standard Libraries
#ifndef __SvnSenSDK

//#import <FBSDKShareKit/FBSDKShareKit.h>
#endif
#import <MessageUI/MessageUI.h>
#include <UIKit/UIKit.h>
@class SaavnRefresh;
@class EmptyErrorState;
@interface SaavnVC_n : UIViewController <UIScrollViewDelegate, UITableViewDataSource, UITableViewDelegate,MFMailComposeViewControllerDelegate, MFMessageComposeViewControllerDelegate> {
    // dispatch queue for accessing and storing ads Data of this VC
    dispatch_queue_t adAccessQueue;

}


#pragma mark - Properties
// Nav
@property (nonatomic, strong) SaavnNavBar *navBar;
@property (nonatomic) BOOL navScrolls, showNavShadow, alwaysShowNavShadow, hidesNavBar;
@property (nonatomic, readwrite) BOOL isAudioJioSDK;
@property (nonatomic, strong) UIButton *navCancel, *navOptions;
@property (nonatomic, strong) FauxNav *fauxNav;                                     // Faux NavBar
#ifndef __SvnSenSDK
// Ads
@property (nonatomic, strong) SaavnAdView *fixedBanner;
#endif
// Optional (legacy) fixed ad unit. New ad units are handled as table cells.
@property (nonatomic) BOOL hasBanner;



                                                                                    // This should be set in individual VCs in their viewDidLoad before calling
                                                                                    // [super viewdidload] which sets up the banner based on this.
                                                                                    // This is *ONLY* for fixed banner ads, shown at the bottom of detail views.
                                                                                    // Eventually, we'll likely deprecate this as well, but will need it at
                                                                                    // least for a little while longer, and as a fallback.
@property (nonatomic, strong) UIActivityIndicatorView *loader;
#ifndef __SvnSenSDK
@property (nonatomic, strong) NSMutableDictionary *adObjects;
#endif
// Standard Tables
@property (nonatomic, strong) UIScrollView *childScrollView;                        // Just a generic reference pointer, in case we want to reassign this
                                                                                    // to a custom table, or collection view, or some other main container.
                                                                                    // In most cases, it will simply point to (UITableView *)mainTable.
@property (nonatomic, strong) UITableView *mainTable;
@property (nonatomic, strong) NSMutableArray *rowHeights, *sectionHeaderHeights;    // For caching row and header heights.
@property (nonatomic, strong) NSMutableDictionary *scrollerOffsets;                 // For tracking side scroller positions.
@property (nonatomic) BOOL resetScrollOffsets;                                      // For resetting side scroller positions.

// Pull-to-refresh
@property (nonatomic, strong) SaavnRefresh *refresh;

// Tabs & Sorting
@property (nonatomic, strong) NSString *sortOrder;
@property (nonatomic, strong) SegmentTabs *sortTabs;
@property (nonatomic) CGFloat tabInsetAdjustment;                                   // Store any inset adjustments made automatically by sortTabs.

// Tracking
@property (nonatomic) ViewType viewType;                                            // View type, for tracking, logic checks, etc.
@property (nonatomic, strong) NSString *viewID, *viewName;                          // Strings and storage for tracking params.
@property (nonatomic, strong) NSString *trackingPrefix, *trackingSource;            // Strings and storage for tracking params.
@property (nonatomic, strong) NSDictionary *sharedEntity;                          // for facebook,sms and mail share we wont have the shared object in the delegate callbacks to send appropriate events,hence we need to set this for them
@property (nonatomic, strong) NSMutableDictionary *topSrcData;
@property (nonatomic, strong) NSMutableDictionary *midSrcData;
@property (nonatomic, strong) NSMutableDictionary *topSrcDataDeepLink;

@property (nonatomic, assign) NSTimeInterval view_start_time;
@property (nonatomic, assign) NSTimeInterval view_end_time;

// Misc.
@property (nonatomic) BOOL isPlayer;                                                // One-off flag to make it easier to track if this SaavnVC is PlayerVC.
                                                                                    // This is a special case, since we keep the PlayerVC active even when it's not in a tab.

@property (nonatomic) BOOL isPlaylistBuilder;                                       // One-off flag to mark any view as part of playlist builder, so we can handle special layout
                                                                                    // and table logic overrides as needed, without nesting or duplicating a ton of logic.

// Empty / Error Display
@property (nonatomic, strong) EmptyErrorState *errorState;

#pragma mark - UINavigationBar
- (void) handleScroll:(UIScrollView *)scrollView;

#pragma mark - Base UI Setup
- (void) initMainTable;
- (void) updateInsets:(UIScrollView *)scrollView;
- (void) updateInsetsForPlaylistBuilderBar:(UIScrollView *)scrollView;

#ifndef __SvnSenSDK
#pragma mark - Ad Setup
- (void) initFixedBanner;
- (void) setCurrentViewType;
- (void) storeAdViewObject:(SaavnAdView *) adView withKey:(NSString*)key;
- (SaavnAdView *) getAdViewObject:(NSString*)key;
- (void) deleteStoredAdViewObject:(NSString*)key;
- (void) deleteAllStoredAdViewObjects;
- (void) hardRefreshAllStoredAdViewObjects;
#endif
#pragma mark - Theme & Status Updates
- (void) forceRefresh;
- (void) toggleUIMode;
- (void) updateUIMode;
- (void) toggleTabMode;
- (void) updateUserState:(NSNotification *)notification;
- (void) updateProMode;
- (void) updateOfflineMode;
- (void) updateFreemiumStatus;
- (void) showAudioAd;
#pragma mark - iPad Layout
- (void) iPadRefreshLayout;

#pragma mark - Track Updates
- (void) downloadUpdate:(NSNotification *)notification;
- (void) nowPlayingUpdate:(NSNotification *)notification;

#pragma mark - Keyboard Updates
- (void) updateKeyboard;

#pragma mark - TabBar Taps
- (BOOL) isTableAtTop;
- (void) scrollToTop;

#pragma mark - NavBar Standard Items
- (void) addCancelButton;
- (void) addCancelButton:(NSString *)label;
- (void) addOptionsButton;

#pragma mark - Enabling Refresh
- (void) enableRefreshAction:(void(^)(void))action;
- (void) refreshComplete;

#pragma mark - Tracking
- (NSMutableDictionary *) getTopSourceDict;
- (NSMutableDictionary *) getMidSourceDict;
- (NSMutableDictionary *) getDeeplinkTopSourceDict;
- (void) postShareClick:(NSDictionary *) shareEntity trackString:(NSString *) partnerString;
- (void) postShareEventSuccess:(NSString *)partnerString withShareEntity:(NSDictionary *)shareData;
- (void) postShareEventFail:(NSString *)partnerString withShareEntity:(NSDictionary *)shareData;
- (NSString*) getScreenName;
- (NSTimeInterval) getScreenViewTime;
- (void) postScreenViewTimeEvents;

#pragma mark - Deprecated Methods
- (ViewType) getParentViewType;

// For Search Page
- (void) deleteRecentSearches:(NSDictionary*) data;

@end

