//
//  ViewTypes.h
//  Saavn
//
//  Created by Clint Balcom on 12/21/15.
//  Copyright © 2015 Saavn. All rights reserved.
//

// Virtual "sitemap" of view types, for easier logic checks, context, sources, tracking, etc.

typedef enum {
    
    ViewType_UNKNOWN                    = 0,
        // These should rare and just fallbacks, in case any of the
        // reusable views weren't properly specified during init.
        ViewType_UNKNOWN_ALBUM_GRID         = 9990,
        ViewType_UNKNOWN_PLAYLIST_GRID      = 9991,
        ViewType_UNKNOWN_SONG_LIST          = 9992,
        ViewType_UNKNOWN_PROFILE            = 9993,
        ViewType_UNKNOWN_PROFILE_SUBVIEW    = 9994,
    
    // Main Tabs.
    ViewType_HOME                       = 1,
        ViewType_NEW_RELEASES               = 100,
        ViewType_TOP_PLAYLISTS              = 101,
        ViewType_CHARTS                     = 102,
        ViewType_RADIO_HOME                 = 103,
        ViewType_BROWSE                     = 104,
        ViewType_SUGGESTIONS                = 105,
        ViewType_VIDEOS                     = 106,
        // New Home Tabs
        ViewType_PODCASTS                   = 110,
        ViewType_JIOTUNE                    = 120,
    ViewType_SEARCH                     = 2,
        ViewType_SEARCH_ARTISTS             = 200,
        ViewType_SEARCH_ALBUMS              = 201,
        ViewType_SEARCH_SONGS               = 202,
        ViewType_SEARCH_PLAYLISTS           = 203,
        ViewType_SEARCH_ADD_SONGS           = 204,
        ViewType_SEARCH_EPISODES            = 205,
        ViewType_SEARCH_SHOWS               = 206,
		ViewType_SEARCH_VIDEOS				= 207,
    ViewType_PLAYER                     = 3,
        ViewType_VPLAYER                    = 301,
    
    // Library Views
    ViewType_LIBRARY                    = 4,
        ViewType_LIBRARY_SONGS              = 400,
        ViewType_LIBRARY_ALBUMS             = 401,
        ViewType_LIBRARY_ARTISTS            = 402,
        ViewType_LIBRARY_PLAYLISTS          = 403,
        ViewType_LIBRARY_SHOWS              = 404,
        ViewType_DOWNLOADS                  = 405,
        ViewType_CURRENT_DOWNLOADS          = 406,
        ViewType_HISTORY                    = 407,
        ViewType_TOP_FAN_CODES              = 408,
        ViewType_AUDIO_JIO                  = 409,
        ViewType_AUDIO                      = 410,
        ViewType_REPLAY2020                 = 411,
        ViewType_LIBRARY_VIDEO              = 412, //Library

    
    // Main Content Views
    ViewType_SONG                       = 5,
    ViewType_ALBUM                      = 6,
    ViewType_PLAYLIST                   = 7,
        ViewType_Mix_PLAYLIST               = 700, // for algo playlist
        ViewType_Mixed_PLAYLIST             = 701, // for history playlist
    ViewType_CHART                      = 9,
    ViewType_SHOW                       = 10,
        ViewType_SHOW_EPISODES              = 1000,
    ViewType_EPISODE                    = 11,
    
    // Channel Views
    ViewType_CHANNEL                    = 12,
        ViewType_GENRE                      = 1200,
            ViewType_GENRE_SONGS                = 12000,
            ViewType_GENRE_PLAYLISTS            = 12001,
        ViewType_MOOD                       = 1201,
            ViewType_MOOD_SONGS                 = 12010,
            ViewType_MOOD_PLAYLISTS             = 12011,
        ViewType_MUSICPLUS                  = 1203,
            ViewType_MUSICPLUS_SHOWS            = 12030,
        ViewType_BRANDBAR                   = 1204,
            ViewType_BRANDBAR_SONGS             = 12040,
            ViewType_BRANDBAR_PLAYLISTS         = 12041,
    
    // Social Views
    ViewType_INBOX                      = 13,
        ViewType_TAG                        = 1300,
        ViewType_TAG_RECAP                  = 1301,
        ViewType_THREAD                     = 1302,
    
    // People Views
    ViewType_PEOPLE                     = 14,
        ViewType_ARTIST                     = 1400,
            ViewType_ARTIST_ALBUMS              = 14000,
            ViewType_ARTIST_SONGS               = 14001,
            ViewType_ARTIST_FOLLOWERS           = 14002,
            ViewType_ARTIST_LIBRARY             = 14003,
        ViewType_USER                       = 1401,
            ViewType_USER_FOLLOWING             = 14010,
            ViewType_USER_FOLLOWERS             = 14011,
            ViewType_USER_PLAYLISTS             = 14012,
    
    // Settings
    ViewType_SETTINGS                   = 15,
        ViewType_LANGUAGE_SELECT            = 1500,
        ViewType_SETTINGS_SUBVIEW           = 1501,
        ViewType_LOGIN                      = 1502,
        ViewType_SIGNUP                     = 1503,
    
    // Pro
    ViewType_PRO                        = 16,
        ViewType_PICKER                     = 1600,
        ViewType_PRO_EXPIRED                = 1601,
        ViewType_PRO_REMINDER               = 1602,
        ViewType_PRO_THANKS                 = 1603,
    
    ViewType_ALERT_UNKNOWN              = 17,
        ViewType_ALERT_DIALOG               = 1700,
        ViewType_ALERT_SHEET                = 1701,
        ViewType_ALERT_TUTORIAL             = 1702,
        ViewType_ALERT_LOGIN                = 1703,
        ViewType_ALERT_REDEEM_PRO           = 1704,
        ViewType_ALERT_PASSWORD             = 1705,

    // Playlist Builder
    ViewType_PLAYLIST_BUILDER             = 20,
        ViewType_PLAYLIST_BUILDER_SONGS     = 2000,
        ViewType_PLAYLIST_BUILDER_ALBUMS    = 2001,
            ViewType_PLAYLIST_BUILDER_ALBUM     = 20001,
    
    ViewType_GENERAL_GRID                   = 25,

} ViewType;

