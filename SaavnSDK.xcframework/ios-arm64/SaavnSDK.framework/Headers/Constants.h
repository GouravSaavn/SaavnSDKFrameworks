//
//  Constants.h
//  Saavn
//
//  Created by Clint Balcom on 9/18/13.
//  Copyright (c) 2013 Saavn. All rights reserved.
//


#pragma mark - APP SETUP

#define Q_SECRET @"$..@.V..n..67.44"

#define APP_NAME @"JioSaavn"

#define API_SUB_CONTEXT @"com.jio.jioplay.tv"
#define API_CONTEXT @"iphoneappsdk"
//#define API_CONTEXT @"iphoneapp"
#define API_FORMAT @"json"
#define ITUNES_APP_ID @"441813332"
#define GA_ACCOUNT_ID @"UA-3091287-8"
#define API_VERSION  @"4"

// Share URLs / Icons
#define SHARE_APP_ICON_URL @"http://s.saavncdn.com/apps/app-logo.png"
#define APP_STORE_URL @"http://itunes.apple.com/us/app/saavn-bollywood-music-radio/id441813332"

// Web View URLs
#define WEB_ONLY_URL @"http://saa.vn/rights"
//#define FORGOT_PASSWORD_URL = @"https://www.jiosaavn.com/forgot-password?ctx=iphoneapp"
#ifndef __SvnSenSDK
#define FORGOT_PASSWORD_URL= @"https://www.jiosaavn.com/forgot-password?ctx=iphoneapp"
#else
#define FORGOT_PASSWORD_URL_SvnSDK= @"https://www.jiosaavn.com/forgot-password?ctx=iphoneappsdk"
#endif


// FACEBOOK
// Production
#define FACEBOOK_APP_ID @"126986924002057"
#define FACEBOOK_APP_SECRET @"0bfbef9214d824555470a29826a86f72"
#define FACEBOOK_API_KEY @"3c9c5d44e91cddfb51074c48dca6ab46"

// QA
/*
#define FACEBOOK_APP_ID @"135034979840713"
#define FACEBOOK_APP_SECRET @"bbc6e6698e0bba3072b00d92ba214b76"
#define FACEBOOK_API_KEY @"c86a3f093943d9653d004a2a37e7019d"
*/

#define DEFAULT_BITRATE 96
#define IMAGE_CACHE_DIR_MAX_SIZE 100000000

#define PLAYER_DATA_FILE @"playerData"
#define SONG_DICT_URL_KEY @"media_url"
#define RECENT_SONG_LISTENING_HISTORY @"listeningHistory"

#define USER_DATA_FILE   @"loggedInUserData"
#define DOWNLOADED_JIO_SONGS @"downloadedJids"

#define LYRICS_DATA_FILE @"lyricsData"
#define JIOTUNE_DATA_FILE @"jiotuneData"

// User Login State
#define LOGGED_IN_FB @"logggedIn_Fb"
#define LOGGED_IN_EMAIL @"logged In"
#define LOGGED_OUT @"logged Out"



#pragma mark - NETWORK

#define NETWORK_REACHABILITY_TOKEN @"NetworkReachability"
#define NETWORK_REACHABILITY_NO_NETWORK @"NetworkReachabilityNoNetwork"
#define NETWORK_REACHABILITY_WIFI @"NetworkReachabiltyWIFI"
#define NETWORK_REACHABILITY_WWAN @"NetworkReachabiltyWWAN"
#define NETWORK_REACHABILITY_NOTIFICATION @"com.saavn.networkreachability.notification"



#pragma mark - TRACKING

#define DEFAULT_ERROR_STRING @"data_unknown"
#define CUSTOM_VARIABLE_LOGIN_MODE @"state"
#define CUSTOM_VARIABLE_CONNECTION_STATE @"connection_state"
#define CUSTOM_VARIABLE_ASIDENTIFIER @"asid"
#define AB_TEST_ENABLED_FEATURES @"enabled_features"
#define CUSTOM_VARIABLE_APP_MODE @"app_state"
#define CUSTOM_VARIABLE_TZ @"tz"
#define CUSTOM_VARIABLE_MODEL @"model"
#define CUSTOM_VARIABLE_MODEL_OS @"os_version"
#define CUSTOM_VARIABLE_PROMODE @"promode"

#define PROMODE_PRO @"pro"
#define PLUSMODE_PRO @"plus"
#define PROMODE_TRIAL @"trial"
#define PROMODE_DORMANT @"dormant"
#define PROMODE_FREE @"free"
#define PROMODE_NOT_APPLICABLE @"na"
#define PROMODE_PAYWALL @"pre_trial"

#define CONNECTION_STATE_HARD_OFFLINE @"Hard_Offline"
#define CONNECTION_STATE_SOFT_OFFLINE @"Soft_Offline"
#define CONNECTION_STATE_ONLINE @"Online"



#pragma mark - COMMON STRINGS

#define MIDDOT @"·"
#define SPACED_MIDDOT @"  ·  "
#define BULLET @"•"
#define SPACED_BULLET @"  •  "

#define FB_LOSER_TITLE @"No Friends... Yet!  :)"
#define FB_LOSER_MESSAGE @"None of your Facebook friends are on Saavn.\nInvite some to join you!"



#pragma mark - CORE STYLES

// COLORS
#define APP_BG UIColorFromRGB(0xf6f6f6)
#define NAV_BAR_COLOR_LIGHT UIColorFromRGB(0xefefef)
#define COLOR_DEFAULT_DARK UIColorFromRGB(0x1e1e1e)
#define COLOR_DEFAULT UIColorFromRGB(0x3e3e3e)
#define COLOR_LIGHT UIColorFromRGB(0xa9a9a9)
#define COLOR_EXTRA_LIGHT UIColorFromRGB(0xcccccc)

#define COLOR_AD_BG UIColorFromRGB(0xe7e7e7)
#define COLOR_IMG_BG UIColorFromRGB(0xe7e7e7)
#define BTN_LIGHT UIColorFromRGB(0x9a9a9a)
#define TINT_COLOR UIColorFromRGB(0x85f3a4)
#define ALERT_COLOR UIColorFromRGB(0xff814a)
#define ALERT_COLOR_TAP_ALPHA UIColorFromRGBWithAlpha(0xff814a, .62)
#define IOS_RED UIColorFromRGB(0xFB3B2F)
#define IOS_RED_TAP_ALPHA UIColorFromRGBWithAlpha(0xFB3B2F, .62)
#define TITLE_ALPHA UIColorFromRGBWithAlpha(0xffffff, .57)
#define BADGE_COLOR UIColorFromRGB(0xf64143)

#define GRADIENT_LIGHT UIColorFromRGB(0x61be4b)
#define GRADIENT_DARK UIColorFromRGB(0x26aa7a)


// PRO COLORS
#define PRO_BG UIColorFromRGB(0x2b2b2b)
#define PRO_DEFAULT UIColorFromRGBWithAlpha(0xffffff, .93)
#define PRO_HIGHLIGHT UIColorFromRGB(0x3bbc5f)
#define PRO_DEFAULT_LIGHT UIColorFromRGBWithAlpha(0xffffff, .39)



#pragma mark - CORE SIZES

// CORE LAYOUT ITEMS
#define STATUS_BAR_HEIGHT ((IPHONE_X) ? 44 : 20)
#define NAV_BAR_HEIGHT 44
#define NAV_BAR_BTN_HEIGHT 27
#define NAV_BAR_LOGO_WIDTH 33
#define NAV_TITLE_WIDTH (([Util isiPad]) ? 340 : 200)
#define KEYBOARD_HEIGHT 216
#define KEYBOARD_PORTRAIT_HEIGHT 264
#define KEYBOARD_LANDSCAPE_HEIGHT 352

// MAIN HEADERS
#define MAIN_HEADER_HEIGHT ([Util isiPad] ? 340 : [Util getScreenWidth])
#define MAIN_HEADER_OUTER_PAD 15
#define MAIN_HEADER_INNER_PAD 10
#define MAIN_HEADER_BTN_HEIGHT 34
#define MAIN_HEADER_BTN_CONTAINER_HEIGHT 44
#define MAIN_HEADER_NO_EXTRAS 30    // Amount we'll subtract from main header height if there's no extras metadata line.

#define PROFILE_HEADER_DELTA 40
#define PROFILE_HEADER_HEIGHT (MAIN_HEADER_HEIGHT - MAIN_HEADER_NO_EXTRAS - PROFILE_HEADER_DELTA)

// SEARCH BAR
#define SEARCH_BAR_HEIGHT 44

// TAB CONTAINERS
#define TAB_CONTAINER_HEIGHT 42

// GRID v2.0
#define GRID_GUTTER 15
#define GRID_TITLE_PAD 5
#define GRID_CELL_PAD 5

// OVERLAY VIEWS
#define OVERLAY_PAD 5
#define PRO_LR_PAD 20

// iPAD MODALS
#define iPAD_MODAL_WIDTH 320
#define iPAD_MODAL_HEIGHT 600
#define STACK_PANEL_WIDTH 340
#define POPOVER_WIDTH 260
#define POPOVER_HEIGHT 420


#pragma mark - CORE SPEEDS

// ANIMATION SPEEDS
#define FADE_SPEED 0.4
#define MENU_SPEED 0.3
#define CELL_SPEED 0.3
#ifndef __SvnSenSDK

#define ALERT_TIMER_DEFAULT 1
#else
#define ALERT_TIMER_DEFAULT 3
#endif
#define LONG_PRESS_TIMER .39


#pragma mark - VIEW CONTROLLERS

#define iPAD_PLAYER_INDEX 0
#define iPAD_DETAIL_INDEX 1

#define ACTION_BAR_HEIGHT 42
#define ACTION_BAR_BTN_HEIGHT 28

// HOME VC
#define HOME_ACTION_BAR_HEIGHT 90
#define HOME_BTN_WIDTH 60
#define HOME_BTN_HEIGHT 60
#define HOME_BTN_HIGHLIGHT_TAP UIColorFromRGB(0x2e9c47)

// HEADER MENUS
#define HEADER_MENU_ITEM 36
#define HEADER_MENU_ITEM_BEVEL 0.5

// SEARCH VC
#define SONG_SCOPE @"song"
#define PLAYLIST_SCOPE @"playlist"
#define ALBUM_SCOPE @"album"

// ALBUM VC
#define ALBUM_HEADER_HEIGHT 331
#define DETAIL_ART_SIZE 250
#define ALBUM_ACTION_BAR_HEIGHT 52

// PLAYLIST VC
#define PLAYLIST_HEADER_HEIGHT 160

// BASIC TABLE VC
#define SONGS_PER_BACKGROUND_FETCH 25

// SONG VC
#define SHARE_BUTTON_SIZE 40
#define SHARE_ICON_SIZE 24

// PLAYER VC
#define PLAYER_ACTION_BAR_HEIGHT 48
#define PLAYER_BTN_WIDTH 51
#define PLAYER_BTN_HEIGHT 42
#define RADIO_THUMBS 56

// MODAL VCs
#define CLOSE_BTN_WIDTH 35
#define CLOSE_BTN_HEIGHT 35
#define BACK_BTN_WIDTH 19
#define BACK_BTN_HEIGHT 28
#define MORE_BTN_WIDTH 28
#define MORE_BTN_HEIGHT 28


#pragma mark - TABLES

// HEADERS
#define TABLE_SECTION_HEADER_HEIGHT 26

// TABLE CELLS
#define DEFAULT_CELL_HEIGHT 44
#define SONG_CELL_HEIGHT 74
#define SONG_CELL_INDENT 12
#define SONG_CELL_INDEX 22
#define AUTOCOMPLETE_CELL_HEIGHT 48
#define SETTINGS_DETAIL_CELL_HEIGHT 58
#define SHARE_CELL_HEIGHT 48
#define RADIO_CELL_HEIGHT 66

// FOOTER CELLS (ie. Last cells in a section with simple more/action)
#define FOOT_CELL_HEIGHT 62

// SEARCH CELLS
#define SEARCH_CELL 58
#define SEARCH_IMAGE 40
#define SEARCH_FOOTER_CELL 42

// PEOPLE CELLS
#define PERSON_CELL_HEIGHT 74
#define PERSON_CELL_IMAGE 60
#define PERSON_CELL_CONDENSED_HEIGHT 62
#define PERSON_CELL_CONDENSED_IMAGE 42

// SONG CELL ACTION BAR
#define CELL_ACTION_BAR_HEIGHT 46
#define CELL_ACTION_BTN_HEIGHT 34

// CELL ELEMENTS
#define ACCESSORY_WIDTH 40
#define ACCESSORY_HEIGHT 40
#define CACHE_BUTTON_WIDTH 40
#define CACHE_BUTTON_HEIGHT 40
#define CACHE_BTN_PAD 6
#define PLAYLIST_PLAY_ICON_WIDTH 48
#define PLAYLIST_PLAY_ICON_HEIGHT 48
#define PLAYLIST_TYPE_ICON_WIDTH 48
#define PLAYLIST_TYPE_ICON_HEIGHT 48
#define FRIEND_IMAGE_SIZE 39
#define RADIO_MINI_ICON_SIZE 40
#define TAG_TOGGLE 30

// COLLECTION VIEW CELLS
#define USER_IMAGE_SIZE 75
#define USER_OVERLAY_SIZE 86
#define ALBUM_CELL_WIDTH (([Util isiPad]) ? (([Util isLandscape]) ? 160 : 134) : 145)
#define ALBUM_CELL_HEIGHT (([Util isiPad]) ? (([Util isLandscape]) ? 210 : 184) : 200)
#define CHART_CELL_HEIGHT (([Util isiPad]) ? (([Util isLandscape]) ? 231 : 205) : 221)
#define RADIO_ICON_SIZE (([Util isiPad]) ? 108 : 84)

// CARD CELLS
#define CARD_GUTTER 10
#define CARD_ENTITY_PAD 12
#define CARD_INNER_PAD 14
#define CARD_PADDING 22
#define CARD_TITLE_LINE_SHIM 2
#define CARD_IMAGE 34
#define CARD_TIMESTAMP 12
#define CARD_TIMESTAMP_PAD 2
#define CARD_ENTITY_IMAGE 60
#define CARD_FONT_SIZE 12.0
#define CARD_GENERIC_CUSTOM 150

// FOLLOW BUTTON
#define FOLLOW_BTN_H 26
#define FOLLOW_BTN_W 67

// GENERIC BUTTON
#define GENERIC_BTN_H 26
#define GENERIC_BTN_W 80

// TAG & SHARE
#define SHARE_BAR_HEIGHT 90
#define SHARE_ICON 40

// SOCIAL STUFF
#define FOLLOW_BADGE_H 20
#define FOLLOW_BADGE_MIN_W 31
#define FOLLOW_BADGE_ICON_W 12


// DB BATCHING
#define NUMBER_OF_EVENTS_TO_BATCH 1000
#define TRANSITION_SPEED .34


#pragma mark - Ads

// ADS
#define AD_CONTAINER_TAG 9999
#define ADMOB_PUBLISHER_ID @"a14d9129cc6f82e"
#define DFP_PUBLISHER_ID @"/6714/SAAVNIphone"
//#define DFP_PUBLISHER_ID @"/6499/example/banner"
#define DFP_PUBLISHER_ID_PRO @"/6714/SAAVNIphonePro"
#define INMOBI_APP_ID @"4028cba630724cd901309f0bc7f10126"

// New ADS
#define DFP_IPHONE_PUBLISHER_ID                 @"/6714/SAAVNIphoneMobile"
#define DFP_SPOTLIGHT_PUBLISHER_ID              @"/6714/SaavnIphoneSpotlight"
#define DFP_IPAD_SPOTLIGHT_PUBLISHER_ID         @"/6714/SaavnIpadSpotlight"
#define DFP_BANNER_PUBLISHER_ID                 @"/6714/SaavnIphoneBanner"
#define DFP_AUDIO_COMPANION_PUBLISHER_ID        @"/6714/SaavnIphoneAC"
#define DFP_INTERSTITIAL_PUBLISHER_ID           @"/6714/SaavnIphoneInterstitial"
#define DFP_BRAND_MEDIA_PUBLISHER_ID            @"/6714/SaavnIphoneBM"
#define DFP_SHOWCASE_IP_PUBLISHER_ID            @"/6714/SaavnIphoneShowcaseHP"
#define DFP_NATIVE_IP_PUBLISHER_ID              @"/6714/SaavnIphoneNativeHP"
#define DFP_SEARCH_PUBLISHER_ID                 @"/6714/SaavnIphoneSI"


#define DFP_PRO_SHOWCASE_IP_PUBLISHER_ID            @"/6714/SaavnIphoneShowcasePro"
#define DFP_PRO_NATIVE_IP_PUBLISHER_ID              @"/6714/SaavnIphoneNativePro"


#define DFP_PRO_LAUNCH_PUBLISHER_ID            @"/6714/SaavnIphoneProLaunch"
#define DFP_LAUNCH_PUBLISHER_ID                @"/6714/SaavnIOSLaunch"

#define DFP_PRO_MAXIMUS_PUBLISHER_ID            @"/6714/SaavnIphoneMaxPro"
#define DFP_MAXIMUS_PUBLISHER_ID                @"/6714/SaavnIphoneMax"


#define DFP_PODCAST_SPOTLIGHT_PUBLISHER_ID              @"/6714/SaavnIphoneSpotlightPodcast"
#define DFP_PODCAST_SHOWCASE_IP_PUBLISHER_ID            @"/6714/SaavnIphoneShowcasePodcastHP"
#define DFP_PRO_PODCAST_SHOWCASE_IP_PUBLISHER_ID            @"/6714/SaavnIphoneShowcasePodcastHPPro"

#define DFP_PODCAST_NATIVE_IP_PUBLISHER_ID              @"/6714/SaavnIphoneNativeHP_Podcast"
#define DFP_PRO_PODCAST_NATIVE_IP_PUBLISHER_ID              @"/6714/SaavnIphoneNativeHP_PodcastPro"


//ADS SLOT STATES
#define SLOT_OPEN @"open"
#define SLOT_NORMAL @"normal"
#define SLOT_STATE_INACTVE @"slotinactive"
#define SLOT_STATE_ACTVE @"slotactive"
#define SLOT_STATE_EXPIRED @"slotexpired"
#define SLOT_STATE_SPILLAGE @"slotspillage"
#define SLOT_AUDIO_AD_INITIALIZED @"audioAdInitialized"
#define SLOT_AUDIO_AD_PLAYED @"audioAdPlayed"
#define SLOT_AUDIO_AD_FAILED @"audioAdFailed"
#define SLOT_CONSUMPTION_CLOCK_ACTIVE @"slotConsumptionClockActive"
#define SLOT_CONSUMPTION_CLOCK_PAUSED @"slotConsumptionClockPaused"
#define SLOT_CONSUMPTION_CLOCK_UNINITIALIZED @"slotConsumptionClockUninitialized"


#pragma mark - MACROS

#define IOS_GTE(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define IOS_LT(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define IOS7 (IOS_GTE(@"7.0"))
#define RETINA4 ([[UIScreen mainScreen] bounds].size.height >= 568)
#define RETINA ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] && ([UIScreen mainScreen].scale == 2.0))
#define IS_SHORT_SCREEN ([UIScreen mainScreen].bounds.size.height < 568)
#define SMALLER_THAN_IPHONE6 ([UIScreen mainScreen].bounds.size.height <= 568)

#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IPHONE_5 (IS_IPHONE && [[UIScreen mainScreen] bounds].size.height == 568.0)
#define IPHONE_6 (IS_IPHONE && [[UIScreen mainScreen] bounds].size.height == 667.0)
#define IPHONE_6PLUS (IS_IPHONE && [[UIScreen mainScreen] bounds].size.height == 736.0)
#define IPHONE_X (IS_IPHONE && ([[UIScreen mainScreen] bounds].size.height == 812.0 || [[UIScreen mainScreen] bounds].size.height == 896.0))

#define UIColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define UIColorFromRGBWithAlpha(rgbValue, a)  [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]

// History
#define  MIXED_QUEUE_SONGS_LIMIT        1000

//Autoplay
#define  AUTOPLAY_SONGS_LIMIT        10


#define FULL_PRO_SHEET_VALUE     1001
