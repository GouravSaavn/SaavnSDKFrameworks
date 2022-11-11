//
//  Events.h
//  Saavn
//
//  Created by Jagadeesh Dyaberi on 11/7/13.
//  Copyright (c) 2013 Saavn. All rights reserved.
//

/////////////////////////////////////// 6.0 Events ///////////////////////////////////////
#define TOP_SRC_KEY                         @"top_src"
#define MID_SRC_KEY                         @"mid_src"
#define BOTTOM_SRC_KEY                      @"bot_src"
#define ENTITY_CLICK                        @"iphone:click;"
#define ENTITY_VIEW                         @"iphone:view;"
#define ENTITY_VIEW_TIME                    @"iphone:view_time;"
#define ENTITY_LONGPRESS                    @"iphone:long_press;"
#define APP_LAUNCH_EVENT                    @"iphone:app_launch;"
#define DETAIL_HEADER_PLAY_BUTTON_ID        @"header_play"
#define DETAIL_HEADER_LIKE_BUTTON_ID        @"header_like"
#define DETAIL_HEADER_SET_JIOTUNE_BUTTON_ID @"header_set_jiotune"
#define DETAIL_HEADER_OVERFLOW_BUTTON_ID    @"header_overflow"
#define CELL_OVERFLOW_BUTTON_ID             @"cell_overflow"
#define CELL_DOWNLOAD_BUTTON_ID             @"download_icon"
#define CELL_LIKE_BUTTON_ID                 @"like_icon"
#define CELL_JIOTUNE_BUTTON_ID              @"jiotune_icon"
#define RECO_PLAY_ALL_SECTION_HEADER        @"reco_play_all"
#define USER_IMAGE_ID                       @"user_image"
#define PLAYER_TOP_BUTTON_ID                @"player_top_button"
#define DOWNLOAD_ROW_ID                     @"download_row"
#define SHUFFLE_ALL_LIBRARY_BUTTON_ID       @"shuffle_all"
#define DARK_MODE_TOGGLE_ON_ID              @"dark_mode_toggle_on"
#define DARK_MODE_TOGGLE_OFF_ID             @"dark_mode_toggle_off"
#define AUTO_DARK_MODE_TOGGLE_ON_ID         @"auto_dark_toggle_on"
#define AUTO_DARK_MODE_TOGGLE_OFF_ID        @"auto_dark_toggle_off"
#define USE_DEVICE_SETTINGS_TOGGLE_ON_ID    @"use_device_settings_toggle_on"
#define USE_DEVICE_SETTINGS_TOGGLE_OFF_ID   @"use_device_settings_toggle_off"
#define DOWNLOAD_SYNC_BAR_ID                @"sync_progress"
#define JIO_EVENT_MARKER                    @"jioEvent"
#define IPHONE_SUCCESS                      @"iphone:success"
#define IPHONE_FAILURE                      @"iphone:failure"
#define ALREADY_SET                         @"iphone:song:jiotune:already_set:success"
#define IPHONE_SEARCH                       @"iphone:get_autocomplete"


#define IPHONE_PLAYER_NEXT                      @"next"
#define IPHONE_PLAYER_PREV                      @"prev"

/////////////////////////////////////// 6.0 Events ///////////////////////////////////////


/////////////////////////////////////// APPLE WATCH ///////////////////////////////////////
#define APPLE_WATCH_APP_LAUNCH @"iphone:apple_watch:app::launch;"
#define APPLE_WATCH_APP_FOREGROUND @"iphone:apple_watch:app_foreground::;"
#define APPLE_WATCH_APP_BACKGROUND @"iphone:apple_watch:app_background::;"
#define APPLE_WATCH_OPEN_WEEKLY_TOP_15 @"iphone:apple_watch:home:weekly_top_15:click;"
#define APPLE_WATCH_OPEN_RADIO_STATIONS @"iphone:apple_watch:home:radio_home:click;"
#define APPLE_WATCH_OPEN_PLAYER @"iphone:apple_watch:home:player_home:click;"
#define APPLE_WATCH_WEEKLY_TOP_15_PLAY_ALL_CLICK @"iphone:apple_watch:weekly_top_15:play_all:click;"
#define APPLE_WATCH_WEEKLY_TOP_15_SONG_CLICK @"iphone:apple_watch:weekly_top_15:song_cell:click;"
#define APPLE_WATCH_WEEKLY_TOP_15_DOWNLOAD_SONG @"iphone:apple_watch:weekly_top_15:download_song:click;"
#define APPLE_WATCH_FEATURED_STATION_CLICK @"iphone:apple_watch:featured_station::click;"
#define APPLE_WATCH_ARTIST_STATION_CLICK @"iphone:apple_watch:artist_station::click;"
#define APPLE_WATCH_PLAYER_PLAY_BUTTON_CLICK @"iphone:apple_watch:player_view:play:click;"
#define APPLE_WATCH_PLAYER_PAUSE_BUTTON_CLICK @"iphone:apple_watch:player_view:pause:click;"
#define APPLE_WATCH_PLAYER_NEXT_BUTTON_CLICK @"iphone:apple_watch:player_view:next:click;"
#define APPLE_WATCH_PLAYER_PREV_BUTTON_CLICK @"iphone:apple_watch:player_view:prev:click;"
/////////////////////////////////////// APPLE WATCH ///////////////////////////////////////


/////////////////////////////////////// PRO ROW ///////////////////////////////////////
/////////////////////////////////////// Loginwall View ///////////////////////////////////////
#define PRO_ROW_INITIAL_SCREEN_LOAD @"iphone:pro_row:signup:ui:view;"
#define PRO_ROW_SIGNUPBTN_CLICK @"iphone:pro_row:signup:signup_btn:click;"
#define PRO_ROW_SIGNUP_VIEW @"iphone:pro_row:signup:signup:view;"
#define PRO_ROW_NAVBAR_LOGIN_CLICK @"iphone:pro_row:nav_bar:login:click;"
#define PRO_ROW_NAVBAR_SIGNUP_CLICK @"iphone:pro_row:nav_bar:signup:click;"
#define PRO_ROW_LOGIN_VIEW @"iphone:pro_row:login::view;"
#define PRO_ROW_PHONEBTN_SIGNUP_CLICK @"iphone:pro_row:signup:phone_btn:click;"
#define PRO_ROW_PHONEBTN_LOGIN_CLICK @"iphone:pro_row:login:phone_btn:click;"
#define PRO_ROW_FBBTN_SIGNUP_CLICK @"iphone:pro_row:signup:fb_btn:click;"
#define PRO_ROW_FBBTN_LOGIN_CLICK @"iphone:pro_row:login:fb_btn:click;"
#define PRO_ROW_FBLABEL_LOGIN_CLICK @"iphone:pro_row:login:fb_label:click;"
#define PRO_ROW_FBLABEL_SIGNUP_CLICK @"iphone:pro_row:signup:fb_label:click;"
#define PRO_ROW_PHONELABEL_LOGIN_CLICK @"iphone:pro_row:login:phone_label:click;"
#define PRO_ROW_PHONELABEL_SIGNUP_CLICK @"iphone:pro_row:signup:phone_label:click;"
#define PRO_ROW_EMAILLABEL_LOGIN_CLICK @"iphone:pro_row:login:email_label:click;"
#define PRO_ROW_EMAILLABEL_SIGNUP_CLICK @"iphone:pro_row:signup:email_label:click;"
#define PRO_ROW_EMAILLABEL_LOGIN_CLICK @"iphone:pro_row:login:email_label:click;"
#define PRO_ROW_EMAILLABEL_SIGNUP_CLICK @"iphone:pro_row:signup:email_label:click;"
#define PRO_ROW_SIGNUPEMAIL_SUBMIT @"iphone:pro_row:signup:email_btn:click;"
#define PRO_ROW_LOGINEMAIL_SUBMIT @"iphone:pro_row:login:email_btn:click;"


//////////////////////////////// Account Login View ///////////////////////////////////////
#define PRO_ROW_ACCOUNT_PHONE_LOGIN_SUCCESS @"iphone:pro_row:account:phone:success;"
#define PRO_ROW_ACCOUNT_PHONE_LOGIN_FAILURE @"iphone:pro_row:account:phone:failure;"
#define PRO_ROW_ACCOUNT_FACEBOOK_LOGIN_SUCCESS @"iphone:pro_row:account:facebook:success;"
#define PRO_ROW_ACCOUNT_FACEBOOK_LOGIN_FAILURE @"iphone:pro_row:account:facebook:failure;"
#define PRO_ROW_ACCOUNT_EMAIL_SIGNUP_SUCCESS @"iphone:pro_row:account:email_signup:success;"
#define PRO_ROW_ACCOUNT_EMAIL_SIGNUP_FAILURE @"iphone:pro_row:account:email_signup:failure;"
#define PRO_ROW_ACCOUNT_EMAIL_LOGIN_SUCCESS @"iphone:pro_row:account:email_login:success;"
#define PRO_ROW_ACCOUNT_EMAIL_LOGIN_FAILURE @"iphone:pro_row:account:email_login:failure;"
#define PRO_ROW_ACCOUNT_BACK_BUTTON_CLICK @"iphone:pro_row:account:back:click;"
//////////////////////////////// Account Login View ///////////////////////////////////////

//////////////////////////////// Phone Login View ///////////////////////////////////////
#define PHONE_LOGIN_SCREEN_VIEW @"iphone:Firebase_phone_login_screen:view;"
#define PHONE_LOGIN_SCREEN_CLICK_SUBMIT @"iphone:Firebase_phone_login_screen:click:submit_button;"
#define PHONE_LOGIN_SCREEN_COUNTRY_SELECTED @"iphone:Firebase_phone_login_screen:country_selected;"
#define PHONE_LOGIN_OPT_SCREEN_VIEW @"iphone:Firebase_phone_login_otp_screen:view;"
#define PHONE_LOGIN_OPT_SCREEN_CLICK_SUBMIT @"iphone:Firebase_phone_login_otp_screen:click_login;"
#define PHONE_LOGIN_OPT_SCREEN_CLICK_RESEND @"iphone:Firebase_phone_login_otp_screen:click_Resend_code;"
#define PHONE_LOGIN_OPT_SCREEN_SUCCESS @"iphone:Firebase_phone_login_otp_screen:success;"
#define PHONE_LOGIN_OPT_SCREEN_FAILURE @"iphone:Firebase_phone_login_otp_screen:failure;"
//////////////////////////////// Phone Login View ///////////////////////////////////////


/////////////////////////////////////// Loginwall View ///////////////////////////////////////


/////////////////////////////////////// Force Touch Shortcuts ///////////////////////////////////////
#define FORCE_TOUCH_TOP_15 @"iphone:force_touch:weekly_top_15::click;"
#define FORCE_TOUCH_RECENT @"iphone:force_touch:recent::click;"
#define FORCE_TOUCH_SEARCH @"iphone:force_touch:search::click;"
#define FORCE_TOUCH_KEEP_LISTENING @"iphone:force_touch:keep_listening::click;"
/////////////////////////////////////// Force Touch Shortcuts ///////////////////////////////////////

/////////////////////////////// Freemium Events ////////////////////////////////////////
#define FREEMIUM_UI_VIEW @"iphone:freemium_login:ui::view;"
#define FREEMIUM_KEEP_LISTENING @"iphone:freemium_login:keep_listening::click;"
#define FREEMIUM_LOGIN_CONTINUE_SAAVN_RADIO_CLICK @"iphone:freemium_login:start_freemium_radio::click;"
#define FREEMIUM_LOGIN_LOGOUT_CLICK @"iphone:freemium_login:log_out::click;"
#define FREEMIUM_LOGIN_TERMS_CLICK @"iphone:freemium_login:terms::click;"
#define FREEMIUM_MODAL_VIEW @"iphone:subscription_modal:ui::view;"
#define FREEMIUM_MODAL_GET_PRO_CLICK @"iphone:subscription_modal:get_saavn_pro::click;"
#define FREEMIUM_MODAL_NO_THANKS_CLICK @"iphone:subscription_modal:no_thanks::click;"
#define FREEMIUM_START_RADIO_CLICK @"iphone::play_freemium_radio::click;"
/////////////////////////////// Freemium Events ////////////////////////////////////////

//////////////////////////////// PRO WALL View ///////////////////////////////////////
#define PRO_ROW_PAYWALL_LOAD @"iphone:pro_row:pro_wall:load;"
#define PRO_ROW_PAYWALL_USER_SCROLLED @"iphone:pro_row:pro_wall:scrolled;"
#define PRO_ROW_PAYWALL_START_CLICK @"iphone:pro_row:pro_wall:start_btn:click;"
#define PRO_ROW_PAYWALL_SPONSORED_BUTTON_CLICK @"iphone:pro_row:pro_wall:sponsor_btn:click;"
#define PRO_ROW_PAYWALL_START_FOOTER_CLICK @"iphone:pro_row:pro_wall:start_btn:footer:click;"
#define PRO_ROW_PAYWALL_ITUNES_MODAL_SUCCESS @"iphone:pro_row:pro_wall:itunes_modal:success;"
#define PRO_ROW_PAYWALL_ITUNES_MODAL_FAILURE @"iphone:pro_row:pro_wall:itunes_modal:failure;"
#define PRO_ROW_PAYWALL_ITUNES_MODAL_CANCEL @"iphone:pro_row:pro_wall:itunes_modal:cancel;"
#define PRO_ROW_PAYWALL_FOOTER_TERMS_CLICK @"iphone:pro_row:pro_wall:footer_terms:click;"
#define PRO_ROW_PAYWALL_FOOTER_PRIVACY_CLICK @"iphone:pro_row:pro_wall:footer_privacy:click;"
#define PRO_ROW_PAYWALL_FOOTER_CONTACT_CLICK @"iphone:pro_row:pro_wall:footer_contact:click;"
#define PRO_ROW_PAYWALL_NAV_REDEEM_CLICK @"iphone:pro_row:pro_wall:nav_redeem:click;"
#define PRO_ROW_PAYWALL_NAV_LOGOUT_CLICK @"iphone:pro_row:pro_wall:nav_logout:click;"
#define PRO_ROW_PAYWALL_NAV_TERMS_CLICK @"iphone:pro_row:pro_wall:terms:click;"

        //////////////////Existing Users Paywall///////////////
#define PRO_ROW_PAYWALL_EXPIRED_LOAD @"iphone:paywall:existing_user_login_screen::load;"
#define PRO_ROW_PAYWALL_EXPIRED_USER_SCROLLED @"iphone:paywall:existing_user_login_screen::scroll;"
#define PRO_ROW_PAYWALL_EXPIRED_KEEP_LISTENING_CLICK @"iphone:paywall:existing_user_login_screen:keep_listening:click;"

#define PRO_ROW_PAYWALL_EXPIRED_ITUNES_MODAL_SUCCESS @"iphone:paywall:existing_user_login_screen:itunes_modal:success;"
#define PRO_ROW_PAYWALL_EXPIRED_ITUNES_MODAL_FAILURE @"iphone:paywall:existing_user_login_screen:itunes_modal:failure;"
#define PRO_ROW_PAYWALL_EXPIRED_NAV_REDEEM_CLICK @"iphone:paywall:existing_user_login_screen:redeem:click;"
#define PRO_ROW_PAYWALL_EXPIRED_NAV_LOGOUT_CLICK @"iphone:paywall:existing_user_login_screen:logout:click;"
#define PRO_ROW_PAYWALL_EXPIRED_NAV_TERMS_CLICK @"iphone:paywall:existing_user_login_screen:terms:click;"
#define PRO_ROW_PAYWALL_EXPIRED_INCENTIVE_LOADED @"iphone:paywall:existing_user_login_screen:row_incentive:loaded;"
#define PRO_ROW_PAYWALL_EXPIRED_INCENTIVE_CLOSE_CLICK @"iphone:paywall:existing_user_login_screen:row_incentive:close;"
#define PRO_ROW_PAYWALL_EXPIRED_INCENTIVE_CLICK @"iphone:paywall:existing_user_login_screen:row_incentive:click;"
#define PRO_ROW_PAYWALL_EXPIRED_INCENTIVE_RECEIVED @"iphone:paywall:existing_user_login_screen:row_incentive:opened;"
#define PRO_ROW_PAYWALL_EXPIRED_INCENTIVE_FAILED @"iphone:paywall:existing_user_login_screen:row_incentive:failed;"
        //////////////Existing Users Paywall///////////////
//////////////////////////////// PRO WALL View ///////////////////////////////////////

/////////////////////////////////////// PRO ROW ///////////////////////////////////////


/////////////////////////////////////// Album View ///////////////////////////////////////

#define ALBUM_UI_VIEW @"iphone:album:ui::view;"
#define ALBUM_OPTIONS_CLICK @"iphone:album:options::click;"
#define ALBUM_START_RADIO_CLICK @"iphone:album:startradio::click;"
#define ALBUM_OPTIONS_ADD_TO_QUEUE_CLICK @"iphone:album:options:add_to_queue:click;"
#define ALBUM_OPTIONS_ADD_TO_PLAYLIST_CLICK @"iphone:album:options:add_to_playlist:click;"
#define ALBUM_OPTIONS_CANCEL_CLICK @"iphone:album:options:cancel:click;"
#define ALBUM_OPTIONS_CLICK_OUT @"iphone:album:options::click_out;"

#define ALBUM_PLAY_PLAY_NOW_CLICK @"iphone:album:play:play_now:click;"
#define ALBUM_PLAY_ADD_TO_QUEUE_CLICK @"iphone:album:play:add_to_queue:click;"
#define ALBUM_PLAY_REPLACE_QUEUE_CLICK @"iphone:album:options:replace_queue:click;"
#define ALBUM_PLAY_CANCEL_CLICK @"iphone:album:play:cancel:click;"
#define ALBUM_PLAY_CLICK_OUT @"iphone:album:play::click_out;"

#define ALBUM_SONG_SONG_CLICK @"iphone:album:song:song:click;"
#define ALBUM_SAVE_OFFLINE @"iphone:album:save_offline::click;"
#define ALBUM_SHARE_CLICK @"iphone:album:share::click;"
#define ALBUM_PLAY_ART_WORK_BUTTON_CLICK @"iphone:album:play_artwork_button::click;"
#define ALBUM_PLAY_HEADER_BUTTON_CLICK @"iphone:album:play_header_button::click;"
#define ALBUM_HEADER_DOWNLOAD_CLICK @"iphone:album:header:download:click;"
#define ALBUM_OPTIONS_DOWNLOAD_CLICK @"iphone:album:options:download:click;"

#define ALBUM_SONG_SONG_CLICK @"iphone:album:song:song:click;"
#define ALBUM_SONG_PLAY_CLICK @"iphone:album:song:play:click;"
#define ALBUM_SONG_PAUSE_CLICK @"iphone:album:song:pause:click;"
#define ALBUM_SONG_QUEUE_CLICK @"iphone:album:song:queue:click;"
#define ALBUM_SONG_RADIO_CLICK @"iphone:album:song:radio:click;"
#define ALBUM_SONG_STAR_CLICK @"iphone:album:song:star:click;"
#define ALBUM_SONG_UNSTAR_CLICK @"iphone:album:song:unstar:click;"
#define ALBUM_SONG_CACHEABLE_CLICK @"iphone:album:song_cacheable::click;"
#define ALBUM_SONG_CACHED_ELSE_WHERE_CLICK @"iphone:album:song_cached_elsewhere::click;"
#define ALBUM_SONG_DELETE_CACHE_CLICK @"iphone:album:song_delete_cache::click;"
#define ALBUM_SONG_DELETE_CACHE_CONFIRM_CLICK @"iphone:album:song_delete_cache:confirm:click;"
#define ALBUM_SONG_DELETE_CACHE_CANCEL_CLICK @"iphone:album:song_delete_cache:cancel:click;"
#define ALBUM_SONG_DETAIL_CLICK @"iphone:album:song_detail::click;"

#define ALBUM_DETAIL_HORIZONTALLIST_RECOMMENDATION_VIEW  @"iphone:album_detail:horizontallist:recommendation:ui:view;"
#define ALBUM_DETAIL_HORIZONTALLIST_RECOMMENDATION_CLICK @"iphone:album_detail:horizontallist:recommendation:click;"

/////////////////////////////////////// Album View ///////////////////////////////////////



/////////////////////////////////////// Home View ///////////////////////////////////////

#define HOME_UI_VIEW @"iphone:home:ui::view;"
#define HOME_LANGUAGE_SELECT_CLICK @"iphone:home:language_select::click;"
#define HOME_LANGUAGE_SELECT_CHANGE_TO @"iphone:home:language_select::change_to;"
#define HOME_WEEKLY_TOP_15_CLICK @"iphone:home:weektop15::click;"
#define HOME_SURPRISE_ME_CLICK @"iphone:home:surpriseme::click;"
#define HOME_GO_PRO_CLICK @"iphone:home:go_pro::click;"
#define HOME_GO_PRO_NAV_CLICK @"iphone:home:go_pro:nav_bar:click;"
#define HOME_SETTINGS_CLICK @"iphone:home:settings::click;"
#define HOME_FEEDBACK_CLICK @"iphone:home:feedback::click;"
#define HOME_MY_MUSIC_CLICK @"iphone:home:mymusic::click;"
#define HOME_NEW_RELEASES_CLICK @"iphone:home:newrelease::click;"
#define HOME_CHARTS_CLICK @"iphone:home:charts::click;"
#define HOME_CHANNELS_CLICK @"iphone:home:channels::click;"
#define HOME_OTHER_CHANNELS_CLICK @"iphone:home:other_channels::click;"
#define HOME_FEATURED_PLAYLISTS_CLICK @"iphone:home:playlists::click;"
#define HOME_RADIO_CLICK @"iphone:home:radio::click;"
#define HOME_SOTD_CLICK @"iphone:home:sotd::click;"

/////////////////////////////////////// Home View ///////////////////////////////////////

/////////////////////////////////////// Equalizer View ///////////////////////////////////////


#define EQUALIZER_UI_VIEW @"iphone:equalizer:ui::view;"
#define EQUALIZER_VIEW_PRESET_CLICK @"iphone:equalizer:preset_listitem::click;"
#define EQUALIZER_VIEW_TOGGLE_ON @"iphone:equalizer:enabled::click;"
#define EQUALIZER_VIEW_TOGGLE_OFF @"iphone:equalizer:disabled::click;"
#define EQUALIZER_VIEW_GRAPH_DRAGGED @"iphone:equalizer:drag_graph::drag;"

/////////////////////////////////////// Equalizer View ///////////////////////////////////////

/////////////////////////////////////// Show View ///////////////////////////////////////
#define SHOW_UI_VIEW @"iphone:show:ui::view;"
#define SHOW_OPTIONS_LISTEN_NOW @"iphone:show:options:listennow:click;"
#define SHOW_OPTIONS_SHARE_NEW @"iphone:show:options:sharenow:click;"
#define SHOW_OPTIONS_FOLLOW_TAP @"iphone:show:options:follow:click;"
#define SHOW_LOAD_ALL_EPISODES_CLICK @"iphone:show:allepisodes:click;"
#define SHOW_EDITORSPICK_QUICKPLAY_CLICK @"iphone:show:editorspick:play:click;"
#define SHOW_LOAD_EDITORSPICK_CLICK @"iphone:show:loadeditorspick:click;"
#define SHOW_FOLLOW_CLICK @"iphone:show:follow::click;"
#define SHOW_UNFOLLOW_CLICK @"iphone:show:unfollow::click;"
#define SHOW_HORIZONTALLIST_SEASON_CLICK @"iphone:show:horizontallist:season:click;"
#define SHOW_EPISODE_ORDER_TOGGLE_CLICK @"iphone:show:toggle::click;"
#define EPISODE_DOWNLOAD_CLICK @"iphone:episode:download::click;"
#define EPISODE_OPTIONS_CLICK @"iphone:episode:options::click;"

#define SHOW_ALL_EPISODES_EPISODES_RESULT_CLICK @"iphone:show:all_episode:episode_result:click;"

/////////////////////////////////////// Show View ///////////////////////////////////////


/////////////////////////////////////// Channel View ///////////////////////////////////////
#define CHANNEL_UI_VIEW @"iphone:channel:ui::view;"
#define CHANNEL_UNFOLLOW_CLICK @"iphone:channel:unfollow::click;"
#define CHANNEL_FOLLOW_CLICK @"iphone:channel:follow::click;"
#define CHANNEL_START_RADIO_CLICK @"iphone:channel:startradio::click;"
#define CHANNEL_EDITORSPICK_QUICKPLAY_CLICK @"iphone:channel:editorspick:play:click;"
#define CHANNEL_LOAD_EDITORSPICK_CLICK @"iphone:channel:loadeditorspick::click;"
#define CHANNEL_HORIZONTALLIST_CLICK @"iphone:channel:horizontallist::click;"
#define CHANNEL_HORIZONTALLIST_ONE_CLICK @"iphone:channel:horizontallist::oneclick;"
#define CHANNEL_LOADALLPLAYLISTS_CLICK @"iphone:channel:loadallplaylists::click;"
#define CHANNEL_LOADALLSONGS_CLICK @"iphone:channel:loadallsongs::click;"
#define CHANNEL_LOADALLSHOWS_CLICK @"iphone:channel:loadallshows::click;"
#define CHANNEL_TOP_PLAYLISTS_CLICKED @"iphone:channel:topplaylists:squaregridcell:click;"

#define CHANNEL_TOP_SONG_PLAY_CLICKED @"iphone:channel:channel_top_songs:song_play:click;"
#define CHANNEL_TOP_EPISODE_PLAY_CLICKED @"iphone:channel:channel_top_episodes:episode_play:click;"
#define CHANNEL_TOP_SHOW_PLAY_CLICKED @"iphone:channel:channel_top_shows:show_play:click;"


#define CHANNEL_ALL_PLAYLISTS_UI_VIEW @"iphone:channel:all_playlist:ui:view;"
#define CHANNEL_ALL_PLAYLISTS_PLAYLIST_RESULT_CLICK @"iphone:channel:all_playlist:playlist_result:click;"

#define CHANNEL_ALL_SHOWS_UI_VIEW @"iphone:channel:all_shows:ui:view;"
#define CHANNEL_ALL_SHOWS_SHOW_RESULT_CLICK @"iphone:channel:all_shows:show_result:click;"


#define CHANNEL_ALL_SONGS_UI_VIEW @"iphone:channel:all_songs:ui:view;"
#define CHANNEL_ALL_SONGS_SONG_RESULT_CLICK @"iphone:channel:all_songs:songs_result:click;"
#define CHANNEL_OPIONS_SHARE_CLICK @"iphone:channel:options:share:click;"



/// Brand Channel
#define CHANNEL_BRAND_CLICK_TO_ACTION_CLICK   @"iphone:channel:click_to_action::click;"
#define CHANNEL_BRAND_AD_CLICK   @"iphone:brand_channel:view:ad:click;"
#define CHANNEL_BRAND_AD_SUCCESS   @"iphone:brand_channel:view:ad:success;"
#define CHANNEL_BRAND_AD_FAIL   @"iphone:brand_channel:view:ad:fail;"

/////////////////////////////////////// Channel View ///////////////////////////////////////


/////////////////////////////////////// Lock Screen ///////////////////////////////////////

#define LOCK_SCREEN_TOGGLE_PLAY_PAUSE @"iphone:lock_screen:ui::view;" //TBD
#define LOCK_SCREEN_PREV @"iphone:lock_screen:prev::click;"
#define LOCK_SCREEN_NEXT @"iphone:lock_screen:next::click;"
#define LOCK_SCREEN_TOGGLE_PAUSE @"iphone:lock_screen:toggle_pause"
#define LOCK_SCREEN_TOGGLE_PLAY @"iphone:lock_screen:toggle_play::click;"
#define LOCK_SCREEN_UI_VIEW @"iphone:lock_screen:prev::click;"
#define LOCK_SCREEN_VOLUME_ADJUST @"iphone:lock_screen:volume::volume_adjustment;" //TBD

/////////////////////////////////////// Lock Screen ///////////////////////////////////////



/////////////////////////////////////// Login Modal Events ///////////////////////////////////////

#define LOGIN_UI_VIEW @"iphone:login:ui::view;"
#define LOGIN_VIEW_DETAILS_SWIPE @"iphone:login:details::swype;"
#define LOGIN_VIEW_FACEBOOK_CLICK @"iphone:login:facebook::click;"
#define LOGIN_VIEW_EMAIL_CLICK @"iphone:login:email::click;"
#define LOGIN_VIEW_EMAIL_SUBMIT_CLICK @"iphone:login:email:submit:click;"
#define LOGIN_VIEW_SIGN_UP_CLICK @"iphone:login:sign_up::click;"
#define LOGIN_VIEW_SIGN_UP_SUCCESS @"iphone:login:sign_up::success;"
#define LOGIN_VIEW_SIGN_UP_FAIL @"iphone:login:sign_up::fail;"
#define LOGIN_VIEW_JIO_SUBMIT_CLICK @"iphone:login:jio::click;"

/////////////////////////////////////// Login Modal Events ///////////////////////////////////////



/////////////////////////////////////// Pro triggered Login Events ///////////////////////////////////////

#define LOGIN_PRO_ACTION_UI_VIEW @"iphone:login_pro_action:ui::view;"
#define LOGIN_PRO_ACTION_VIEW_DETAILS_SWIPE @"iphone:login_pro_action:details::swype;"
#define LOGIN_PRO_ACTION_VIEW_FACEBOOK_CLICK @"iphone:login_pro_action:facebook::click;"
#define LOGIN_PRO_ACTION_VIEW_EMAIL_CANCEL_CLICK @"iphone:login_pro_action:email:cancel:click;" //TBD
#define LOGIN_PRO_ACTION_VIEW_EMAIL_CLICK @"iphone:login_pro_action:email::click;"
#define LOGIN_PRO_ACTION_VIEW_EMAIL_SUBMIT_CLICK @"iphone:login_pro_action:email:submit:click;"
#define LOGIN_PRO_ACTION_VIEW_SIGN_UP_CLICK @"iphone:login_pro_action:sign_up::click;"
#define LOGIN_PRO_ACTION_VIEW_SIGN_UP_SUCCESS @"iphone:login_pro_action:sign_up::success;"
#define LOGIN_PRO_ACTION_VIEW_SIGN_UP_FAIL @"iphone:login_pro_action:sign_up::fail;"

/////////////////////////////////////// Pro triggered Login Events ///////////////////////////////////////



/////////////////////////////////////// Modal Pro Events ///////////////////////////////////////

#define SUB_MODAL_PRO_EXPLICIT_TRIAL_UNUSED_UI_VIEW @"/iphone:sub_modal_pro_explicit:trial_unused:ui:view;"
#define SUB_MODAL_PRO_EXPLICIT_TRIAL_UNUSED_CLOSE_CLICK @"/iphone:sub_modal_pro_explicit:trial_unused:close:click;"
#define SUB_MODAL_PRO_EXPLICIT_TRIAL_UNUSED_FREE_TRIAL_CLICK @"/iphone:sub_modal_pro_explicit:trial_unused:free_trial:click;"
#define SUB_MODAL_PRO_EXPLICIT_TRIAL_UNUSED_GO_PRO_CLICK @"/iphone:sub_modal_pro_explicit:trial_unused:go_pro:click;"
#define SUB_MODAL_PRO_EXPLICIT_TRIAL_USED_UI_VIEW @"/iphone:sub_modal_pro_explicit:trial_used:ui:view;"
#define SUB_MODAL_PRO_EXPLICIT_TRIAL_USED_GO_PRO_CLICK @"/iphone:sub_modal_pro_explicit:trial_used:go_pro:click;"

#define SUB_MODAL_DORMANCY_UI_VIEW @"iphone:sub_modal_dormancy:ui::view;"
#define SUB_MODAL_DORMANCY_NO_THANKS_CLICK @"iphone:sub_modal_dormancy:no_thanks::click;"
#define SUB_MODAL_DORMANCY_GO_PRO_CLICK @"iphone:sub_modal_dormancy:go_pro::click;"

#define SUB_MODAL_DORMANCY_SEND_OFF_UI_VIEW @"iphone:sub_modal_dormancy_send_off:ui::view;"
#define SUB_MODAL_DORMANCY_SEND_OFF_GO_PRO_CLICK @"iphone:sub_modal_dormancy_send_off:go_pro::click;"

#define SUB_MODAL_DORMANCY_POST_60_UI_VIEW @"iphone:sub_modal_dormancy_post_60:ui::view;"
#define SUB_MODAL_DORMANCY_POST_60_NO_THANKS_CLICK @"iphone:sub_modal_dormancy_post_60:no_thanks::click;"
#define SUB_MODAL_DORMANCY_POST_60_GO_PRO_CLICK @"iphone:sub_modal_dormancy_post_60:go_pro::click;"

#define SUB_MODAL_PRO_ACION_UI_VIEW @"iphone:sub_modal_pro_action:ui::view;"
#define SUB_MODAL_PRO_ACION_TRIAL_UNUSED_CLOSE_CLICK @"iphone:sub_modal_pro_action:trial_unused:close:click;"
#define SUB_MODAL_PRO_ACION_TRIAL_UNUSED_FREE_TRIAL_CLICK @"iphone:sub_modal_pro_action:trial_unused:free_trial:click;"
#define SUB_MODAL_PRO_ACION_TRIAL_UNUSED_GO_PRO_CLICK @"iphone:sub_modal_pro_action:trial_unused:go_pro:click;"
#define SUB_MODAL_PRO_ACION_TRIAL_USED_CANCEL_CLICK @"iphone:sub_modal_pro_action:trial_used:cancel:click;"
#define SUB_MODAL_PRO_ACION_TRIAL_USED_GO_PRO_CLICK @"iphone:sub_modal_pro_action:trial_used:go_pro:click;"

#define SUB_MODAL_TRIAL_UNUSED_FREE_TRIAL_SUCCESS @"iphone:sub_modal:trial_unused:free_trial:success;"
/////////////////////////////////////// Modal Pro Events ///////////////////////////////////////

/////////////////////////////////////// Go Pro VC ///////////////////////////////////////
#define SETTINGS_REDEEN_PROCODE_CLICK @"iphone:settings:redeem_procode::click;"
#define SETTINGS_REDEEN_PROCODE_REDEEM_NOW_CLICK @"iphone:settings:redeem_procode:redeem_now:click;"
#define SETTINGS_REDEEN_PROCODE_ERROR_UI_VIEW @"iphone:settings:redeem_procode:error_ui:view;"

#define PRO_PAGE_SQUAREGRIDMENU_CLICK @"iphone:pro_page:squaregridmenu::click;"
#define PRO_PAGE_CONTINUE_CLICK @"iphone:pro_page:continue::click;"

#define PRO_PAGE_UI_VIEW_CLICK @"iphone:pro_page:ui::view;"
#define PRO_PAGE_UI_NOTHANKS_CLICK @"iphone:pro_page:no_thanks::click;"

#define PRO_REMINDER_PAGE_UI_NOTHANKS_CLICK @"iphone:pro_reminder:no_thanks::click;"
#define PRO_REMINDER_PAGE_UI_GOPRO_CLICK @"iphone:pro_reminder:go_pro::click;"


/////////////////////////////////////// Go Pro VC ///////////////////////////////////////





/////////////////////////////////////// Pro Playlist Picker ///////////////////////////////////////

#define PLAYLIST_PICKER_UI_VIEW @"iphone:playlist_picker:ui::view;"
#define PLAYLIST_PICKER_NOT_NOW_CLICK @"iphone:playlist_picker:not_now::click;"
#define PLAYLIST_PICKER_SELECT @"iphone:playlist_picker:::select;"
#define PLAYLIST_PICKER_UNSELECT @"iphone:playlist_picker:::unselect;"

#define PLAYLIST_PICKER_DOWNLOAD_CLICK @"iphone:playlist_picker:download::click;"

#define PLAYLIST_HEADER_DOWNLOAD_CLICK @"iphone:playlist:header:download:click;"
#define PLAYLIST_MENU_OPTIONS_DOWNLOAD_CLICK @"iphone:playlist:options:download:click;"
#define CHART_MENU_OPTIONS_DOWNLOAD_CLICK @"iphone:chart:options:download:click;"
#define PLAYLIST_HISTORY_MENU_OPTIONS_DOWNLOAD_CLICK @"iphone:playlist_history:options:download:click;"

/////////////////////////////////////// Pro Playlist Picker ///////////////////////////////////////



/////////////////////////////////////// Offline Songs Playlist ///////////////////////////////////////


#define OFFLINE_SONGS_UI_VIEW @"iphone:offline_songs:ui::view;"
#define OFFLINE_SONGS_BACK_BACK_CLICK @"iphone:offline_songs:back:back:click;"
#define OFFLINE_SONGS_TOGGLE_ALBUMS_CLICK @"iphone:offline_songs:toggle_albums:toggle_albums:click;"
#define OFFLINE_SONGS_TOGGLE_SONGS_CLICK @"iphone:offline_songs:toggle_songs:toggle_songs:click;"
#define OFFLINE_SONGS_SHUFFLE_ALL_CLICK @"iphone:offline_songs:shuffle_all:shuffle_all:click;"
#define OFFLINE_SONGS_SONG_SONG_CLICK @"iphone:offline_songs:song:song:click;"
#define OFFLINE_SONGS_SONG_PLAY_CLICK @"iphone:offline_songs:song:play:click;"
#define OFFLINE_SONGS_SONG_PAUSE_CLICK @"iphone:offline_songs:song:pause:click;"
#define OFFLINE_SONGS_SONG_QUEUE_CLICK @"iphone:offline_songs:song:queue:click;"
#define OFFLINE_SONGS_SONG_RADIO_CLICK @"iphone:offline_songs:song:radio:click;"
#define OFFLINE_SONGS_SONG_STAR_CLICK @"iphone:offline_songs:song:star:click;"
#define OFFLINE_SONGS_SONG_UNSTAR_CLICK @"iphone:offline_songs:song:unstar:click;"
#define OFFLINE_SONGS_SONG_SONG_DETAIL_CLICK @"iphone:offline_songs:song:song_detail:click;"

/////////////////////////////////////// Offline Songs Playlist ///////////////////////////////////////



/////////////////////////////////////// My Music View ///////////////////////////////////////

#define MY_MUSIC_UI @"iphone:my_music:ui::view;"
#define MY_MUSIC_BACK @"iphone:my_music:back::click;"
#define MY_MUSIC_GO_OFFLINE @"iphone:my_music:go_offline::click;"
#define MY_MUSIC_PLAYER_QUEUE @"iphone:my_music:player_queue::click;"
#define MY_MUSIC_STARED_SONGS @"iphone:my_music:starred_songs::click;"
#define MY_MUSIC_OFFLINE_SONGS @"iphone:my_music:offline_songs::click;"
#define MY_MUSIC_SAVED_PLAYLIST @"iphone:my_music:saved_playlist::click;"

/////////////////////////////////////// My Music View ///////////////////////////////////////



/////////////////////////////////////// Player View ///////////////////////////////////////

#define PLAYER_VIEW_UI @"iphone:player:ui::view;"
#define PLAYER_EDIT_CLICK @"iphone:player:edit::click;"
#define PLAYER_EDIT_DONE_CLICK @"iphone:player:edit:done:click;"
#define PLAYER_EDIT_CLEAR_CLICK @"iphone:player:edit:clear:click;"
#define PLAYER_EDIT_SAVE_CLICK @"iphone:player:edit:save:click;"
#define PLAYER_EDIT_DELETE_CLICK @"iphone:player:edit:delete:click;" //TBD
#define PLAYER_EDIT_DELETE_CONFIRM_CLICK @"iphone:player:edit:delete_confirm:click;"
#define PLAYER_EDIT_REORDER @"iphone:player:edit::reorder;"

#define PLAYER_SAVE_CLICK @"iphone:player:save::click;"
#define PLAYER_REPEAT_ALL_SET_CLICK @"iphone:player:repeat_all_set::click;"
#define PLAYER_REPEAT_ONE_SET_CLICK @"iphone:player:repeat_one_set::click;"
#define PLAYER_REPEAT_UNSET_CLICK @"iphone:player:repeat_unset::click;"
#define PLAYER_NO_ADS_CLICK @"iphone:player:no_ads::click;"

#define PLAYER_PREVIOUS_CLICK @"iphone:player:previous::click;"
#define PLAYER_NEXT_CLICK @"iphone:player:next::click;"
#define PLAYER_PLAY_CLICK @"iphone:player:play::click;"
#define PLAYER_PAUSE_CLICK @"iphone:player:pause::click;"
#define PLAYER_SHUFFLE_SET_CLICK @"iphone:player:shuffle_set::click;"
#define PLAYER_SHUFFLE_UNSET_CLICK @"iphone:player:shuffle_unset::click;"
#define PLAYER_CHANGE_POSITION_CLICK @"iphone:player:change_position::click;"

#define PLAYER_AUDIO_AD_BEGIN @"iphone:player:audio_ad::begin;"
#define PLAYER_AUDIO_AD_END @"iphone:player:audio_ad::end;"

#define PLAYER_SONG_CLICK @"iphone:player:song::click;"
#define PLAYER_SONG_CACHEABLE_CLICK @"iphone:player:song_cacheable::click;"
#define PLAYER_SONG_CACHEABLE_ELSEWHERE_CLICK @"iphone:player:song_cached_elsewhere::click;"
#define PLAYER_DELETE_CACHE_CLICK @"iphone:player:song_delete_cache::click;"
#define PLAYER_DELETE_CACHE_CANCEL_CLICK @"iphone:player:song_delete_cache_cancel::click;"
#define PLAYER_DELETE_CACHE_CONFIRM_CLICK @"iphone:player:song_delete_cache_confirm::click;"
#define PLAYER_SONG_DETAIL_CLICK @"iphone:player:song_detail::click;"

#define PLAYER_TOGGLE_NOW_PLAYING_CLICK @"iphone:player:toggle_now_playing::click;"
#define PLAYER_TOGGLE_SHOW_QUEUE_CLICK @"iphone:player:toggle_show_queue::click;"
#define PLAYER_NOW_PLAYING_PREVIOUS_SWYPE @"iphone:player:now_playing:previous:swype;"
#define PLAYER_NOW_PLAYING_NEXT_SWYPE @"iphone:player:now_playing:next:swype;"
#define PLAYER_TOGGLE_RADIO_CLICK @"iphone:player:toggle_radio::click;"
#define PLAYER_TOGGLE_RADIO_NEW_FROM_SONG_CLICK @"iphone:player:toggle_radio:new_from_song:click;"
#define PLAYER_TOGGLE_RADIO_RESTART_CLICK @"iphone:player:toggle_radio:restart:click;"
#define PLAYER_TOGGLE_RADIO_CANCEL_CLICK @"iphone:player:toggle_radio:cancel:click;"
#define PLAYER_CACHE_ALL_CLICK @"iphone:player:cache_all::click;"

#define PLAYER_MORE_CLICK @"iphone:player:more::click;"
#define PLAYER_MORE_CLEAR_PLAYER_CLICK @"iphone:player:more:clear_player:click;"//
#define PLAYER_MORE_SAVE_PLAYLIST_CLICK @"iphone:player:more:save_playlist:click;"
#define PLAYER_MORE_STAR_CLICK @"iphone:player:more:star:click;"
#define PLAYER_MORE_UNSTAR_CLICK @"iphone:player:more:unstar:click;"
#define PLAYER_MORE_ADD_TO_PLALYLIST_CLICK @"iphone:player:more:add_to_playlist:click;"
#define PLAYER_MORE_SHARE_CLICK @"iphone:player:more:share:click;"
#define PLAYER_MORE_AIRPLAY_CLICK @"iphone:player:more:airplay:click;" //TBD
#define PLAYER_MORE_CANCE_CLICK @"iphone:player:more:cancel:click;" //TBD

#define PLAYER_MEDIA_END @"iphone:player:mediaend::;"
#define PLAYER_MEDIA_OPENED @"iphone:player:mediaopened::;"
#define PLAYER_MEDIA_PAUSED @"iphone:player:mediapaused::;"
#define PLAYER_MEDIA_RESUMED @"iphone:player:mediaresumed::;"
#define PLAYER_PROGRESS @"iphone:player:progress::;"

#define PLAYER_OPTIONS_EQUALIZER_CLICK @"iphone:player:options:equalizer::click;"

/////////////////////////////////////// Player View ///////////////////////////////////////



/////////////////////////////////////// Player Event Prefixes & Sufixes ///////////////////////////////////////
#define PLAYER_PREFIX @"iphone:player"
#define MEDIA_OPENED_SUFFIX @":mediaopened::;"
#define MEDIA_END_SUFFIX @":mediaend::;"
#define MEDIA_PROGRESS_SUFFIX @":progress::;"
#define MEDIA_PAUSED_SUFFIX @":mediapaused::;"
#define MEDIA_RESUMED_SUFFIX @":mediaresumed::;"

#define MEDIA_LOAD_SUFFIX @":mediaload::;"
#define MEDIA_UNLOAD_SUFFIX @":mediaunload::;"
#define MEDIA_FAILED_SUFFIX @":mediafailed::;"
#define MEDIA_SEEK_SUFFIX @":mediaseek::;"

#define JIOTUNE_UNLOAD @"jt_preview:mediaunload"
#define JIOTUNE_PAUSED @"jt_preview:mediapaused"
#define JIOTUNE_FAILED @"jt_preview:mediafailed"
#define JIOTUNE_SET @"set_jiotune"

#define JIOTUNE_UNLOAD @"jt_preview:mediaunload"
#define JIOTUNE_PAUSED @"jt_preview:mediapaused"
#define JIOTUNE_FAILED @"jt_preview:mediafailed"
#define JIOTUNE_SET @"set_jiotune"
#define JIOTUNE_REMOVE @"remove_jiotune"
#define JIOTUNE_RENEW @"renew_jiotune"

/////////////////////////////////////// Player Event Prefixes & Sufixes ///////////////////////////////////////



/////////////////////////////////////// Radio Player View ///////////////////////////////////////

#define PLAYER_RADIO_UI_VIEW @"iphone:player_radio:ui::view;"
#define PLAYER_RADIO_PAUSE_CLICK @"iphone:player_radio:pause::click;"
#define PLAYER_RADIO_PLAY_CLICK @"iphone:player_radio:play::click;"
#define PLAYER_RADIO_NEXT_CLICK @"iphone:player_radio:next::click;"
#define PLAYER_RADIO_CHANGE_POSITION_CLICK @"iphone:player_radio:change_position::click;"
#define PLAYER_RADIO_THUMBS_DOWN_CLICK @"iphone:player_radio:thumbs_down::click;"
#define PLAYER_RADIO_THUMBS_UP_CLICK @"iphone:player_radio:thumbs_up::click;"
#define PLAYER_RADIO_BACK_TO_QUEUE_CLICK @"iphone:player_radio:back_to_queue::click;"
#define PLAYER_RADIO_NO_ADS_CLICK @"iphone:player_radio:no_ads::click;"

#define PLAYER_RADIO_MORE_CLICK @"iphone:player_radio:more::click;"
#define PLAYER_RADIO_MORE_SAVE_STATION_CLICK @"iphone:player_radio:more:save_station:click;"
#define PLAYER_RADIO_MORE_STAR_CLICK @"iphone:player_radio:more:star:click;"
#define PLAYER_RADIO_MORE_UNSTAR_CLICK @"iphone:player_radio:more:unstar:click;"
#define PLAYER_RADIO_MORE_ADD_TO_PLAYLIST_CLICK @"iphone:player_radio:more:add_to_playlist:click;"
#define PLAYER_RADIO_MORE_SHARE_CLICK @"iphone:player_radio:more:share:click;"
#define PLAYER_RADIO_MORE_AIRPLAY_CLICK @"iphone:player_radio:more:airplay:click;"
#define PLAYER_RADIO_MORE_CANCEL_CLICK @"iphone:player_radio:more:cancel:click;"

#define PLAYER_RADIO_MEDIA_END @"iphone:player_radio:mediaend::;"
#define PLAYER_RADIO_MEDIA_OPENED @"iphone:player_radio:mediaopened::;"
#define PLAYER_RADIO_MEDIA_PAUSED @"iphone:player_radio:mediapaused::;"
#define PLAYER_RADIO_MEDIA_RESUMED @"iphone:player_radio:mediaresumed::;"
#define PLAYER_RADIO_PROGRESS @"iphone:player_radio:progress::;"

/////////////////////////////////////// Radio Player View ///////////////////////////////////////


/////////////////////////////////////// Radio Home View ///////////////////////////////////////

#define RADIO_HOME_UI_VIEW @"iphone:radio_home:ui::view;"
#define RADIO_HOME_BACK_CLICK @"iphone:radio_home:back::click;" //TBD
#define RADIO_HOME_TOGGLE_FEATURED_CLICK @"iphone:radio_home:toggle_featured::click;"
#define RADIO_HOME_TOGGLE_ARTIST_CLICK @"iphone:radio_home:toggle_artist::click;"
#define RADIO_HOME_TOGGLE_SAVED_CLICK @"iphone:radio_home:toggle_saved::click;"
#define RADIO_HOME_FEATURED_CREATE_STATION_SELECT @"iphone:radio_home:featured:create_a_station:select;"
#define RADIO_HOME_CREATE_STATION_CLICK @"iphone:radio_home:create_a_station:click;"
#define RADIO_HOME_FEATURED_STATION_CLICK @"iphone:radio_home:featured:station:click;"
#define RADIO_HOME_SAVED_CTREATE_STATION_SELECT @"iphone:radio_home:saved:create_a_station:select;"
#define RADIO_HOME_SAVED_CTREATE_STATION_CLICK @"iphone:radio_home:saved:create_a_station:click;"
#define RADIO_HOME_SAVED_STATION_CLICK @"iphone:radio_home:saved:station:click;"

/////////////////////////////////////// Radio Home View ///////////////////////////////////////



/////////////////////////////////////// Playlist Home View ///////////////////////////////////////

#define PLAYLIST_HOME_UI_VIEW @"iphone:playlists_home:ui::view;"
#define PLAYLIST_HOME_WEEKLY_TOP_SONGS_CLICK @"iphone:playlists_home:weekly_top_songs::click;"
#define PLAYLIST_HOME_WEEKLY_TOP_SONGS_PLAY_CLICK @"iphone:playlists_home:weekly_top_songs:play:click;" //WTH is this
#define PLAYLIST_HOME_PLAYLIST_CLICK @"iphone:playlists_home:playlist::click;"
#define PLAYLIST_HOME_PLAYLIST_PLAY_CLICK @"iphone:playlists_home:playlist:play:click;" //WTH is this
#define PLAYLIST_HOME_SPOTLIGHT_CLICK @"iphone:playlists_home:spotlight::click;"

/////////////////////////////////////// Playlist Home View ///////////////////////////////////////





/////////////////////////////////////// New Release View ///////////////////////////////////////

#define NEW_RELEASES_UI_VIEW @"iphone:new_releases_home:ui::view;"
#define NEW_RELEASES_ALBUM_CLICK @"iphone:new_releases_home:album::click;"
#define NEW_RELEASES_SPOTLIGHT_CLICK @"iphone:new_releases_home:spotlight::click;"

/////////////////////////////////////// New Release View ///////////////////////////////////////



/////////////////////////////////////// Playlist Detail View ///////////////////////////////////////


#define PLAYLIST_DETAIL_UI_VIEW @"iphone:playlist_detail:ui::view;"
#define PLAYLIST_DETAIL_START_RADIO_CLICK @"iphone:playlist_detail:startradio::click;"
#define PLAYLIST_DETAIL_BACK_CLICK @"iphone:playlist_detail:back::click;" //TBD
#define PLAYLIST_DETAIL_PLAY_ART_WORK_BUTTON_CLICK @"iphone:playlist_detail:play_artwork_button::click;"
#define PLAYLIST_DETAIL_PLAY_HEADER_BUTTON_CLICK @"iphone:playlist_detail:play_header_button::click;"
#define PLAYLIST_DETAIL_PLAY_MENU_PLAY_NOW_CLICK @"iphone:playlist_detail:play_menu:play_now:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_ADD_TO_QUEUE_CLICK @"iphone:playlist_detail:play_menu:add_to_queue:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_REPLACE_QUEUE_CLICK @"iphone:playlist_detail:play_menu:replace_queue:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_DOWNLOAD_CLICK @"iphone:playlist_detail:play_menu:cached:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_SHARE_CLICK @"iphone:playlist_detail:play_menu:share:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_CANCEL_CLICK @"iphone:playlist_detail:play_menu:cancel:click;"

#define PLAYLIST_DETAIL_HEADER_DOWNLOAD_CLICK @"iphone:playlist_detail:download::click;"
#define PLAYLIST_DETAIL_HEADER_SHARE_CLICK @"iphone:playlist_detail:share::click;"
#define PLAYLIST_DETAIL_HEADER_ADD_CLICK @"iphone:playlist_detail:add::click;"
#define PLAYLIST_DETAIL_HEADER_PLAY_CLICK @"iphone:playlist_detail:play::click;"
#define PLAYLIST_DETAIL_HEADER_FOLLOW_CLICK @"iphone:playlist_detail:follow::click;"
#define PLAYLIST_DETAIL_HEADER_UNFOLLOW_CLICK @"iphone:playlist_detail:unfollow::click;"



#define PLAYLIST_DETAIL_PLAY_MENU_SAVE_OFFLINE_CLICK @"iphone:playlist_detail:save_offline::click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_CLICK @"iphone:playlist_detail:options::click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_ADD_TO_QUEUE_CLICK @"iphone:playlist_detail:options_menu:add_to_queue:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_COPY_PLAYLIST_CLICK @"iphone:playlist_detail:options_menu:copy_playlist:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_DELETE_PLAYLIST_CLICK @"iphone:playlist_detail:options_menu:delete_playlist:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_RENAME_CLICK @"iphone:playlist_detail:options_menu:rename:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_PRIVACY_CLICK @"iphone:playlist_detail:options_menu:privacy:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_EDIT_CLICK @"iphone:playlist_detail:options_menu:edit:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_SHARE_CLICK @"iphone:playlist_detail:options_menu:share:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_FOLLOW_CLICK @"iphone:playlist_detail:options_menu:follow:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_UNFOLLOW_CLICK @"iphone:playlist_detail:options_menu:unfollow:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_PROFILE_CLICK @"iphone:playlist_detail:options_menu:profile:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_DOWNLOAD_CLICK @"iphone:playlist_detail:options_menu:download:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_CANCEL_CLICK @"phone:playlist_detail:options_menu:cancel:click;"
#define PLAYLIST_DETAIL_PLAY_MENU_OPTIONS_MENU_START_RADIO_CLICK @"iphone:playlist_detail:options_menu:start_radio:click;"

#define PLAYLIST_DETAIL_SONG_SONG_CLICK @"iphone:playlist_detail:song:song:click;"
#define PLAYLIST_DETAIL_SONG_PLAY_CLICK @"iphone:playlist_detail:song:play:click;"
#define PLAYLIST_DETAIL_SONG_PAUSE_CLICK @"iphone:playlist_detail:song:pause:click;"
#define PLAYLIST_DETAIL_SONG_QUEUE_CLICK @"iphone:playlist_detail:song:queue:click;"
#define PLAYLIST_DETAIL_SONG_RADIO_CLICK @"iphone:playlist_detail:song:radio:click;"
#define PLAYLIST_DETAIL_SONG_STAR_CLICK @"iphone:playlist_detail:song:star:click;"
#define PLAYLIST_DETAIL_SONG_UNSTAR_CLICK @"iphone:playlist_detail:song:unstar:click;"
#define PLAYLIST_DETAIL_SONG_CACHEABLE_CLICK @"iphone:playlist_detail:song_cacheable::click;"
#define PLAYLIST_DETAIL_SONG_CACHEABLE_ELSEWHERE_CLICK @"iphone:playlist_detail:song_cached_elsewhere::click;"
#define PLAYLIST_DETAIL_SONG_DELETE_CACHE_CLICK @"iphone:playlist_detail:song_delete_cache::click;"
#define PLAYLIST_DETAIL_SONG_DELETE_CACHE_CANCEL_CLICK @"iphone:playlist_detail:song_delete_cache_cancel::click;"
#define PLAYLIST_DETAIL_SONG_DELETE_CACHE_CONFIRM_CLICK @"iphone:playlist_detail:song_delete_cache_confirm::click;"
#define PLAYLIST_DETAIL_SONG_SONG_DETAL_CLICK @"iphone:playlist_detail:song:song_detail:click;"
#define PLAYLIST_DETAIL_MOBILE_BANNER_CLICK @"iphone:playlist_detail:mobile_banner::click;"

#define PLAYLIST_DETAIL_FOLLOW_CLICK @"iphone:playlist_detail:follow::click;"
#define PLAYLIST_DETAIL_UNFOLLOW_CLICK @"iphone:playlist_detail:unfollow::click;"
#define PLAYLIST_DETAIL_ADDSONGS_CLICK @"iphone:playlist_detail:add_songs::click;"
                        ////FOR YOU////
#define FY_DETAIL_UI_VIEW @"iphone:for_you_playlist_detail:ui::view;"
#define EMPTY_FY_DETAIL_UI_VIEW @"iphone:for_you_empty_playlist_detail:ui::view;"
                        ////FOR YOU////

/////////////////////////////////////// Playlist Detail View ///////////////////////////////////////


/////////////////////////////////////// Zero State Playlist View ///////////////////////////////////////

#define MY_MUSIC_CREATE_PLAYLIST_PANEL_CONTINUE_BTN_CLICK @"iphone:my_music:create_playlist_panel:continue:click;"
#define MY_MUSIC_CREATE_PLAYLIST_PANEL_CLOSE_CLICK  @"iphone:my_music:create_playlist_panel:close:click;"
#define SEARCH_ADD_SONGS_UI_VIEW @"iphone:my_music:search_add_songs:ui:view;"
#define SEARCH_ADD_SONGS_DISMISS_VIEW_CLICK @"iphone:my_music:search_add_songs:cancel:click;"
#define MY_MUSIC_CREATE_PLAYLIST_SAVE_FOOTER_CLICK @"iphone:my_music:create_playlist:save_playlist_footer:click;"
#define MY_MUSIC_CREATE_PLAYLIST_SAVE_SUCCESSFUL @"iphone:my_music:create_playlist:save:successful;"
#define MY_MUSIC_CREATE_PLAYLIST_SAVE_FAILURE @"iphone:my_music:create_playlist:save:failure;"
#define MY_MUSIC_CREATE_PLAYLIST_BTN_CLICK @"iphone:my_music:create_playlist_btn:click;"

/////////////////////////////////////// Zero State Playlist View ///////////////////////////////////////


/////////////////////////////////////// Add To Playlist View ///////////////////////////////////////

#define ADD_TO_PLAYLIST_UI_VIEW @"iphone:add_to_playlists:ui::view;"
#define ADD_TO_PLAYLIST_CLOSE_CLICK @"iphone:add_to_playlists:close::click;"
#define ADD_TO_PLAYLIST_CREATE_NEW_PLAYLIST_CLICK @"iphone:add_to_playlists:create_new_playlist::click;"
#define ADD_TO_PLAYLIST_CREATE_NEW_PLAYLIST_SAVE_CLICK @"iphone:add_to_playlists:create_new_playlist:save:click;"
#define ADD_TO_PLAYLIST_CREATE_NEW_PLAYLIST_CANCEL_CLICK @"iphone:add_to_playlists:create_new_playlist:cancel:click;"
#define ADD_TO_PLAYLIST_CREATE_NEW_PLAYLIST_CLOSE_CLICK @"iphone:add_to_playlists:create_new_playlist:close:click;"
#define ADD_TO_PLAYLIST_UI_SAVED_PLAYLIST_CLICK @"iphone:add_to_playlists:saved_playlist::click;"

/////////////////////////////////////// Add To Playlist View ///////////////////////////////////////



///////////////////////////////////////Search view ///////////////////////////////////////


//Empty Search View
#define EMPTY_SEARCH_UI_VIEW @"iphone:empty_search:ui::view;"
#define EMPTY_SEARCH_TOP_TRENDING_CLICK @"iphone:empty_search:top_trending::click;"
#define EMPTY_SEARCH_RECENT_SEARCH_CLICK @"iphone:empty_search:recent_search::click;"
#define EMPTY_SEARCH_CLEAR_CLICK @"iphone:empty_search:clear::click;"
#define EMPTY_SEARCH_CLEAR_YES_CLICK @"iphone:empty_search:clear:yes:click;"
#define EMPTY_SEARCH_CLEAR_CANCEL_CLICK @"iphone:empty_search:clear:cancel:click;"
#define EMPTY_SEARCH_SURPRISE_ME_CLICK @"iphone:empty_search:surpriseme::click;"


#define SEARCH_UI_VIEW @"iphone:search:ui::view;"
#define SEARCH_VIEW_LANGUAGE_SELECT_CHANGE_TO @"iphone:search:language_select::change_to;"
#define SEARCH_VIEW_SUGGESTIONS_CLICK @"iphone:search:suggestions:click:;"
#define SEARCH_VIEW_SEARCH_BAR_CURSOR_SELECT @"iphone:search:search_bar::cursor_select;"
#define SEARCH_VIEW_SEARCH_BAR_TEXT_ENTERED @"iphone:search:search_bar::text_entered;"
#define SEARCH_VIEW_TOGGLE_ALBUM_CLICK @"iphone:search:toggle_album::click;"
#define SEARCH_VIEW_ALBUM_VIEW_ALBUM_CLICK @"iphone:search:album_view:album:click;"
#define SEARCH_VIEW_TOGGLE_PLAYLISTS_CLICK @"iphone:search:toggle_playlists::click;"
#define SEARCH_VIEW_PLAYLIS_VIEW_PLAYLIST_DETAIL_CLICK @"iphone:search:playlist_view:playlist_detail:click;"
#define SEARCH_VIEW_PLAYLIS_VIEW_PLAYLIST_QUICK_PLAY @"iphone:search:playlist_view:playlist:quickplay;"
#define SEARCH_VIEW_TOGGLE_SONGS_CLICK @"iphone:search:toggle_songs::click;"
#define SEARCH_SONG_VIEW_SONG_SONG_CLICK @"iphone:search:song_view:song:click;"
#define SEARCH_SONG_VIEW_SONG_PLAY_CLICK @"iphone:search:song_view:play:click;"
#define SEARCH_SONG_VIEW_SONG_PAUSE_CLICK @"iphone:search:song_view:pause:click;"
#define SEARCH_SONG_VIEW_SONG_QUEUE_CLICK @"iphone:search:song_view:queue:click;"
#define SEARCH_SONG_VIEW_SONG_RADIO_CLICK @"iphone:search:song_view:radio:click;"
#define SEARCH_SONG_VIEW_SONG_STAR_CLICK @"iphone:search:song_view:star:click;"
#define SEARCH_SONG_VIEW_SONG_UNSTAR_CLICK @"iphone:search:song_view:unstar:click;"
#define SEARCH_SONG_VIEW_SONG_CACHEABLE_CLICK @"iphone:search:song_view:song_cacheable:click;"
#define SEARCH_SONG_VIEW_SONG_CACHEABLE_ELSEWHERE_CLICK @"iphone:search:song_view:song_cached_elsewhere:click;"
#define SEARCH_SONG_VIEW_SONG_DELETE_CACHE_CLICK @"iphone:search:song_view:song_delete_cache:click;"
#define SEARCH_SONG_VIEW_SONG_DELETE_CACHE_CANCEL_CLICK @"iphone:search:song_view:song_delete_cache_cancel:click;"
#define SEARCH_SONG_VIEW_SONG_DELETE_CACHE_CONFIRM_CLICK @"iphone:search:song_view:song_delete_cache_confirm:click;"
#define SEARCH_SONG_VIEW_SONG_SONG_DETAIL_CLICK @"iphone:search:song_view:song_detail:click;"
#define SEARCH_RETRY_CLICK @"iphone:search:no_network:retry::click;"
#define SEARCH_NOCONNECTION_EMPTY_VIEW @"iphone:search:no_network:ui:view;"
#define SEARCH_NORESULT_EMPTY_VIEW @"iphone:search:no_results:ui:view;"


#define RADIO_HOME_ARTIST_CREATE_STATION_CLICK @"iphone:radio_home:artist:create_a_station:click;"
#define RADIO_HOME_STATION_CLICK @"iphone:radio_home:artist:station:click;"

#define SEARCH_TRENDING_CLICK @"iphone:search:trending::click;"
#define SEARCH_RECENT_SEARCHES_CLICK @"iphone:search:recent_searches::click;"
#define SEARCH_SEARCH_BAR_CURSOR_SELECT_CLICK @"iphone:search:search_bar::cursor_select;"
#define SEARCH_SEARCH_BAR_TEXT_ENTERED_CLICK @"iphone:search:search_bar::text_entered;"
#define SEARCH_TOGGLE_ALBUM_CLICK @"iphone:search:toggle_album::click;"
#define SEARCH_TOP_RESULT_CLICK @"iphone:search:top_result::click;"
#define SEARCH_ARTIST_RESULT_CLICK @"iphone:search:artist_result::click;"
#define SEARCH_ALL_ARTISTS_CLICK @"iphone:search:all_artists::click;"
#define SEARCH_ALBUM_RESULT_CLICK @"iphone:search:album_result::click;"
#define SEARCH_ALL_ALBUMS_CLICK @"iphone:search:all_albums::click;"
#define SEARCH_ALL_SHOWS_CLICK @"iphone:search:all_shows::click;"
#define SEARCH_ALL_ALBUMS_ALBUM_RESULT_CLICK @"iphone:search:all_albums:album_result:click;"
#define SEARCH_SONG_RESULT_CLICK @"iphone:search:song_result::click;"
#define SEARCH_ALL_SONGS_CLICK @"iphone:search:all_songs::click;"
#define SEARCH_ALL_EPISODES_CLICK @"iphone:search:all_episodes::click;"
#define SEARCH_ALL_VIDEOS_CLICK @"iphone:search:all_videos::click;"
#define SEARCH_ALL_SONGS_PLAY_CLICK @"iphone:search:all_songs:play:click;"
#define SEARCH_ALL_SONGS_PAUSE_CLICK @"iphone:search:all_songs:pause:click;"
#define SEARCH_ALL_SONGS_QUEUE_CLICK @"iphone:search:all_songs:queue:click;"
#define SEARCH_ALL_SONGS_RADIO_CLICK @"iphone:search:all_songs:radio:click;"
#define SEARCH_ALL_SONGS_STAR_CLICK @"iphone:search:all_songs:star:click;"
#define SEARCH_ALL_SONGS_UNSTAR_CLICK @"iphone:search:all_songs:unstar:click;"
#define SEARCH_ALL_SONGS_SONG_CACHEABLE_CLICK @"iphone:search:all_songs:song_cacheable:click;"
#define SEARCH_ALL_SONGS_SONG_CACHED_ELSEWHERE_CLICK @"iphone:search:all_songs:song_cached_elsewhere:click;"
#define SEARCH_ALL_SONGS_SONG_DELETE_CACHE_CLICK @"iphone:search:all_songs:song_delete_cache:click;"
#define SEARCH_ALL_SONGS_SONG_DELETE_CACHE_CANCEL_CLICK @"iphone:search:all_songs:song_delete_cache_cancel:click;"
#define SEARCH_ALL_SONGS_SONG_DELETE_CACHE_CONFIRM_CLICK @"iphone:search:all_songs:song_delete_cache_confirm:click;"
#define SEARCH_ALL_SONGS_SONG_DETAIL_CLICK @"iphone:search:all_songs:song_detail:click;"
#define SEARCH_PLAYLIST_RESULT_CLICK @"iphone:search:playlist_result::click;"
#define SEARCH_ALL_PLAYLISTS_CLICK @"iphone:search:all_playlists::click;"
#define SEARCH_ALL_PLAYLISTS_PLAYLIST_RESULT_CLICK @"iphone:search:all_playlists:playlist_result:click;"
#define SEARCH_RADIO_RESULT_CLICK @"iphone:search:radio_result::click;"
#define SEARCH_ALL_RADIO_CLICK @"iphone:search:all_radio::click;"
#define SEARCH_ALL_RADIO_RADIO_RESULT_CLICK @"iphone:search:all_radio:radio_result:click;"
#define SEARCH_SHOW_RESULT_CLICK @"iphone:search:show_result::click;"
#define SEARCH_CHANNEL_RESULT_CLICK @"iphone:search:channel_result::click;"

#define SEARCH_ALL_ALBUMS_UI_VIEW @"iphone:search:all_albums:ui:view;"
#define SEARCH_ALL_PLAYLISTS_UI_VIEW @"iphone:search:all_playlist:ui:view;"
#define SEARCH_ALL_SONGS_SONG_CLICK @"iphone:search:all_songs:song_result:click;"
#define SEARCH_ALL_ARTISTS_ARTIST_RESULT_CLICK @"iphone:search:all_artists:artist_result:click;"

#define SEARCH_TRENDING_BAD_DATA @"iphone:search:trending:data:error;"


///////////////////////////////////////Search view ///////////////////////////////////////



///////////////////////////////////////Settings view ///////////////////////////////////////

#define SETTINGS_UI_VIEW @"iphone:settings:ui::view;"
#define SETTINGS_CLOSE_CLICK @"iphone:settings:close::click;"
#define SETTINGS_UPGRADE_TO_PRO_CLICK @"iphone:settings:upgrade_to_pro::click;"
#define SETTINGS_GO_OFFLINE_CLICK @"iphone:settings:go_offline::click;"
#define SETTINGS_SYNC_CLICK @"iphone:settings:sync::click;"
#define SETTINGS_EQUALIZER_CLICK @"iphone:settings:equalizer::click;"
#define SETTINGS_CLEAR_CACHE_CLICK @"iphone:settings:clear_cache::click;"
#define SETTINGS_CLEAR_CACHE_YES_CLICK @"iphone:settings:clear_cache:yes:click;"
#define SETTINGS_CLEAR_CACHE_NO_CLICK @"iphone:settings:clear_cache:no:click;"
#define SETTINGS_MANAGE_OFFLINE_MUSIC_CLICK @"iphone:settings:manage_offline_music::click;"
#define SETTINGS_DOWNLOAD_QUALITY_CLICK @"iphone:settings:download_quality::click;"
#define SETTINGS_DOWNLOAD_QUALITY_BACK_CLICK @"iphone:settings:download_quality:back:click;"
#define SETTINGS_DOWNLOAD_QUALITY_CLOSE_CLICK @"iphone:settings:download_quality:close:click;"
#define SETTINGS_DOWNLOAD_QUALITY_PRO_CLICK @"iphone:settings:download_quality:pro:click;"
#define SETTINGS_DOWNLOAD_QUALITY_NORMAL_CLICK @"iphone:settings:download_quality:normal:click;"
#define SETTINGS_SYNC_OVER_CELL_ON_CLICK @"iphone:settings:sync_over_cell:on:click;"
#define SETTINGS_SYNC_OVER_CELL_OFF_CLICK @"iphone:settings:sync_over_cell:off:click;"
#define SETTINGS_DEAUTHORIZE_DEVICE_CLICK @"iphone:settings:deauthorize_device::click;"
#define SETTINGS_DEAUTHORIZE_DEVICE_YES_CLICK @"iphone:settings:deauthorize_device:yes:click;"
#define SETTINGS_DEAUTHORIZE_DEVICE_NO_CLICK @"iphone:settings:deauthorize_device:no:click;"
#define SETTINGS_STRAMING_QUALITY_CLICK @"iphone:settings:streaming_quality::click;"
#define SETTINGS_STRAMING_QUALITY_BACK_CLICK @"iphone:settings:streaming_quality:back:click;"
#define SETTINGS_STRAMING_QUALITY_CLOSE_CLICK @"iphone:settings:streaming_quality:close:click;"
//#define SETTINGS_STRAMING_QUALITY_HIGH_CLICK @"iphone:settings:streaming_quality:high:click;"
//#define SETTINGS_STRAMING_QUALITY_MEDIUM_CLICK @"iphone:settings:streaming_quality:medium:click;"
//#define SETTINGS_STRAMING_QUALITY_LOW_CLICK @"iphone:settings:streaming_quality:low:click;"
#define SETTINGS_STRAMING_QUALITY_HIGH_QUALITY_CLICK @"iphone:settings:streaming_quality:high:click;"
#define SETTINGS_STRAMING_QUALITY_MEDIUM_QUALITY_CLICK @"iphone:settings:streaming_quality:medium:click;"
#define SETTINGS_STRAMING_QUALITY_LOW__QUALITY_CLICK @"iphone:settings:streaming_quality:low:click;"
#define SETTINGS_STRAMING_QUALITY_POOR_QUALITY_CLICK @"iphone:settings:streaming_quality:poor:click;"
#define SETTINGS_STRAMING_QUALITY_LOWEST_CLICK @"iphone:settings:streaming_quality:lowest:click;"
#define SETTINGS_STREAM_TO_FACEBOOK_ON_CLICK @"iphone:settings:stream_to_facebook:on:click;"
#define SETTINGS_STREAM_TO_FACEBOOK_OFF_CLICK @"iphone:settings:stream_to_facebook:off:click;"
#define SETTINGS_SHARE_CLICK @"iphone:settings:share::click;"
#define SETTINGS_CONTACT_US_CLICK @"iphone:settings:contact_us::click;"
#define SETTINGS_CONTACT_US_SEND_FEEDBACK_CLICK @"iphone:settings:contact_us:send_feedback:click;"
#define SETTINGS_CONTACT_US_GET_HELP_CLICK @"iphone:settings:contact_us:get_help:click;"
#define SETTINGS_CONTACT_US_REPORT_A_BUG_CLICK @"iphone:settings:contact_us:report_a_bug:click;"
#define SETTINGS_RATE_ON_ITUNES_CLICK @"iphone:settings:rate_on_itunes::click;"
#define SETTINGS_TERMS_PRIVACY_CLICK @"iphone:settings:terms_and_privacy::click;"
#define SETTINGS_LOGIN_CLICK @"iphone:settings:login::click;"
#define SETTINGS_LOGOUT_CLICK @"iphone:settings:logout::click;"
    #define SETTINGS_LOGOUT_CONFIRM @"iphone:settings:logout:confirm:click;"
    #define SETTINGS_LOGOUT_CANCEL @"iphone:settings:logout:cancel:click;"
#define SETTINGS_TRY_SAAVN_PRO_CLICK @"iphone:settings:try_saavn_pro::click;"
#define SETTINGS_HELP_SITE_CLICK @"iphone:settings:terms_and_privacy::click;"

#define SETTINGS_CLEARHISTORY_CLICK @"iphone:settings:clear_history::click;"
    #define SETTINGS_CLEARHISTORY_CONFIRM @"iphone:settings:clear_history:confirm:click;"
    #define SETTINGS_CLEARHISTORY_CANCEL @"iphone:settings:clear_history:cancel:click;"

#define SETTINGS_CLEARSEARCH_CLICK @"iphone:settings:clear_search::click;"
    #define SETTINGS_CLEARSEARCH_CONFIRM @"iphone:settings:clear_search:confirm:click;"
    #define SETTINGS_CLEARSEARCH_CANCEL @"iphone:settings:clear_search:cancel:click;"

            ///////////// EDIT_PROFILE VIEW/////////////////////
#define EDITPROFILE_PHONE_CLICK @"iphone:update_profile:phone::click;"
#define EDITPROFILE_EMAIL_EDITEND @"iphone:update_profile:email::click;"
#define EDITPROFILE_FIRSTNAME_EDITEND @"iphone:update_profile:firstname::click;"
#define EDITPROFILE_LASTNAME_EDITEND @"iphone:update_profile:lastname::click;"
#define EDITPROFILE_FACEBOOK_CLICK @"iphone:update_profile:facebook::click;"
#define EDITPROFILE_FACEBOOKPHOTO_CLICK @"iphone:update_profile:facebook_photo::click;"
#define EDITPROFILE_DOB_SUBMIT @"iphone:update_profile:dob::click;"
#define EDITPROFILE_GENDER_SUBMIT @"iphone:update_profile:gender::click;"
#define EDITPROFILE_SAVE_CLICK @"iphone:update_profile:save_button::click;"
#define EDITPROFILE_CANCEL_CLICK @"iphone:update_profile:cancel_button::click;"
#define EDITPROFILE_MERGECANCEL_CLICK @"iphone:update_profile:merge_accounts:cancel:click;"
#define EDITPROFILE_MERGEOK_CLICK @"iphone:update_profile:merge_accounts:sync::click;"
#define EDITPROFILE_VERFIYPASSWORD_CLICK @"iphone:update_profile:verify_password_dialog::click;"
#define EDITPROFILE_PASSWORDSUBMIT_CLICK @"iphone:update_profile:password_dialog:submit::click;"
            ///////////// EDIT_PROFILE VIEW/////////////////////
            /////////////Invoices View/////////////////////
#define SETTINGS_INVOICE_CLICK @"ios:settings:invoices::click;"
#define INVOICES_LIST_LOAD @"ios:invoices:list::load;"
#define INVOICE_DETAIL_CLICK @"ios:invoices:list:invoice_detail:click;"
#define INVOICES_VIEW_MORE_FOOTER_CLICK @"ios:invoices:list:view_more:click;"
              /////////////Invoices View/////////////////////
///////////////////////////////////////Settings view ///////////////////////////////////////



///////////////////////////////////////Share view ///////////////////////////////////////

#define SHARE_UI_VIEW @"iphone:share:ui::view;"
#define SHARE_ALBUM_CLOSE_CLICK @"iphone:share:album:close:click;"
#define SHARE_ALBUM_PARTER_SHARE_CLICK @"iphone:share:album:partner_share:click;"
#define SHARE_ALBUM_PARTER_SHARE_SUCCESS @"iphone:share:album:partner_share:success;"
#define SHARE_ALBUM_PARTER_SHARE_FAIL @"iphone:share:album:partner_share:fail;"

#define SHARE_APP_CLOSE_CLICK @"iphone:share:app:close:click;"
#define SHARE_APP_PARTER_SHARE_CLICK @"iphone:share:app:partner_share:click;"
#define SHARE_APP_PARTER_SHARE_SUCCESS @"iphone:share:app:partner_share:success;"
#define SHARE_APP_PARTER_SHARE_FAIL @"iphone:share:app:partner_share:fail;"

#define SHARE_PLAYLIST_CLOSE_CLICK @"iphone:share:playlist:close:click;"
#define SHARE_PLAYLIST_PARTER_SHARE_CLICK @"iphone:share:playlist:partner_share:click;"
#define SHARE_PLAYLIST_PARTER_SHARE_SUCCESS @"iphone:share:playlist:partner_share:success;"
#define SHARE_PLAYLIST_PARTER_SHARE_FAIL @"iphone:share:playlist:partner_share:fail;"

#define SHARE_SONG_CLOSE_CLICK @"iphone:share:song:close:click;"
#define SHARE_SONG_PARTER_SHARE_CLICK @"iphone:share:song:partner_share:click;"
#define SHARE_SONG_PARTER_SHARE_SUCCESS @"iphone:share:song:partner_share:success;"
#define SHARE_SONG_PARTER_SHARE_FAIL @"iphone:share:song:partner_share:fail;"

#define SHARE_ARTIST_CLOSE_CLICK @"iphone:share:artist_detail:close:click;"
#define SHARE_ARTIST_PARTER_SHARE_CLICK @"iphone:share:artist_detail:partner_share:click;"
#define SHARE_ARTIST_PARTER_SHARE_SUCCESS @"iphone:share:artist_detail:partner_share:success;"
#define SHARE_ARTIST_PARTER_SHARE_FAIL @"iphone:share:artist_detail:partner_share:fail;"

#define SHARE_SHOW_CLOSE_CLICK @"iphone:share:show:close:click;"
#define SHARE_SHOW_PARTER_SHARE_CLICK @"iphone:share:show:partner_share:click;"
#define SHARE_SHOW_PARTER_SHARE_SUCCESS @"iphone:share:show:partner_share:success;"
#define SHARE_SHOW_PARTER_SHARE_FAIL @"iphone:share:show:partner_share:fail;"

#define SHARE_CHANNEL_CLOSE_CLICK @"iphone:share:channel:close:click;"
#define SHARE_CHANNEL_PARTER_SHARE_CLICK @"iphone:share:channel:partner_share:click;"
#define SHARE_CHANNEL_PARTER_SHARE_SUCCESS @"iphone:share:channel:partner_share:success;"
#define SHARE_CHANNEL_PARTER_SHARE_FAIL @"iphone:share:channel:partner_share:fail;"

#define SHARE_EPISODE_CLOSE_CLICK @"iphone:share:episode:close:click;"
#define SHARE_EPISODE_PARTER_SHARE_CLICK @"iphone:share:episode:partner_share:click;"
#define SHARE_EPISODE_PARTER_SHARE_SUCCESS @"iphone:share:episode:partner_share:success;"
#define SHARE_EPISODE_PARTER_SHARE_FAIL @"iphone:share:episode:partner_share:fail;"

#define SHARE_TAG_USER_TAG_CLICK @"iphone:share:tag:user_tag:click;"
#define SHARE_TAG_USER_UNTAG_CLICK @"iphone:share:tag:user_untag:click;"
#define SHARE_TAG_NEXT_CLICK @"iphone:share:tag:next:click;"
#define SHARE_TAG_MESSAGE_TEXT_ENTERED @"iphone:share:tag:message:text_entered;"
#define SHARE_TAG_SEND_CLICK @"iphone:share:tag:send:click;"
#define SHARE_TAG_SOCIAL_HEAD_CLICK @"iphone:share:tag:social_head:click;"
#define SHARE_PARTNER_SHARE_CLICK @"iphone:share:partner_share::click;"
#define SHARE_PARTNER_SHARE_SUCCESS @"iphone:share:partner_share::success;"
#define SHARE_PARTNER_SHARE_FAIL @"iphone:share:partner_share::fail;"


///////////////////////////////////////Share view ///////////////////////////////////////



///////////////////////////////////////Song Detail view ///////////////////////////////////////

#define SONG_DETAIL_UI_VIEW @"iphone:song_detail:ui::view;"
#define SONG_DETAIL_START_RADIO_CLICK @"iphone:song_detail:startradio::click;"
#define SONG_DETAIL_BACK_CLICK @"iphone:song_detail:back::click;"
#define SONG_DETAIL_HEADER_SHARE_CLICK @"iphone:song_detail:header:share:click;"
#define SONG_DETAIL_HEADER_DOWNLOAD_CLICK @"iphone:song_detail:header:download:click;"
#define SONG_DETAIL_HEADER_ADD_CLICK @"iphone:song_detail:header:add:click;"
#define SONG_DETAIL_HEADER_DELETE_CACHE_CLICK @"iphone:song_detail:header:song_delete_cache:click;"
#define SONG_DETAIL_HEADER_DELETE_CACHE_CONFIRM_CLICK @"iphone:song_detail:header:song_delete_cache_confirm:click;"
#define SONG_DETAIL_HEADER_DELETE_CACHE_CANCEL_CLICK @"iphone:song_detail:header:song_delete_cache_cancel:click;"
#define SONG_DETAIL_HEADER_DELETE_CACHE_CONFIRM_CLICK @"iphone:song_detail:header:song_delete_cache_confirm:click;"
#define SONG_DETAIL_PLAY_ARTWORK_BUTTON_CLICK @"iphone:song_detail:play_artwork_button::click;"
#define SONG_DETAIL_PLAY_HEADER_BUTTON_CLICK @"iphone:song_detail:play_header_button::click;"
#define SONG_DETAIL_TOGGLE_OPTIONS_CLICK @"iphone:song_detail:toggle_options::click;"
#define SONG_DETAIL_OPTIONS_ADD_TO_QUEUE_CLICK @"iphone:song_detail:options:add_to_queue:click;"
#define SONG_DETAIL_OPTIONS_ADD_TO_PLAYLIST_CLICK @"iphone:song_detail:options:add_to_playlist:click;"
#define SONG_DETAIL_OPTIONS_SONG_CACHEABLE_CLICK @"iphone:song_detail:options:song_cacheable:click;"
#define SONG_DETAIL_OPTIONS_SONG_CACHED_ELSEWHERE_CLICK @"iphone:song_detail:options:song_cached_elsewhere:click;"
#define SONG_DETAIL_OPTIONS_DELETE_CACHE_CLICK @"iphone:song_detail:options:song_delete_cache:click;"
#define SONG_DETAIL_OPTIONS_DELETE_CACHE_CANCEL_CLICK @"iphone:song_detail:options:song_delete_cache_cancel:click;"
#define SONG_DETAIL_OPTIONS_DELETE_CACHE_CONFIRM_CLICK @"iphone:song_detail:options:song_delete_cache_confirm:click;"
#define SONG_DETAIL_OPTIONS_STAR_CLICK @"iphone:song_detail:options:star:click;"
#define SONG_DETAIL_OPTIONS_UNSTAR_CLICK @"iphone:song_detail:options:unstar:click;"
#define SONG_DETAIL_OPTIONS_START_RADIO_CLICK @"iphone:song_detail:options:start_radio:click;"
#define SONG_DETAIL_OPTIONS_SHARE_CLICK @"iphone:song_detail:options:share:click;"
#define SONG_DETAIL_OPTIONS_BACK_TO_ALBUM_CLICK @"iphone:song_detail:options:back_to_album:click;"
#define SONG_DETAIL_TOGGLE_ARTISTS_CLICK @"iphone:song_detail:toggle_artists::click;"
#define SONG_DETAIL_ARTISTS_METADATA_CLICK @"iphone:song_detail:metadata::click;"
#define SONG_DETAIL_HORIZONTALLIST_RECOMMENDATION_CLICK @"iphone:song_detail:horizontallist:recommendation:click;"
#define SONG_DETAIL_LOAD_ALBUM_CLICK @"iphone:song_detail:load_album:click;"
#define SONG_DETAIL_SHOW_LYRICS_CLICK @"iphone:song_detail:show_lyrics:click;"
#define SONG_DETAIL_HIDE_LYRICS_CLICK @"iphone:song_detail:hide_lyrics:click;"
#define SONG_DETAIL_EXPAND_ARTISTS @"iphone:song_detail:expand_artists:click;"
#define SONG_DETAIL_HIDE_ARTISTS @"iphone:song_detail:hide_artists:click;"
#define SONG_DETAIL_TOP_ARTIST_CLICK @"iphone:song_detail:top_artists:click;"
#define SONG_DETAIL_PLAY_ALL_RECOMMENDED_CLICK @"iphone:song_detail:playall:click;"

///////////////////////////////////////Song Detail view ///////////////////////////////////////


///////////////////////////////////////Episode Detail view ///////////////////////////////////////
#define EPISODE_DETAIL_UI_VIEW @"iphone:episode_detail:ui::view;"
#define EPISODE_DETAIL_BACK_CLICK @"iphone:episode_detail:back::click;"
#define EPISODE_DETAIL_HEADER_ADD_CLICK @"iphone:episode_detail:header:add:click;"
#define EPISODE_DETAIL_HEADER_DOWNLOAD_CLICK @"iphone:episode_detail:header:download:click;"
#define EPISODE_DETAIL_HEADER_SHARE_CLICK @"iphone:episode_detail:header:share:click;"
#define EPISODE_DETAIL_LOAD_ALBUM_CLICK @"iphone:episode_detail:load_album:click;"
#define EPISODE_DETAIL_SHOW_LYRICS_CLICK @"iphone:episode_detail:show_lyrics:click;"
#define EPISODE_DETAIL_HIDE_LYRICS_CLICK @"iphone:episode_detail:hide_lyrics:click;"
#define EPISODE_DETAIL_PLAY_HEADER_BUTTON_CLICK @"iphone:episode_detail:play_header_button::click;"
///////////////////////////////////////Episode Detail view ///////////////////////////////////////



/////////////////////////////////////// Channels View(s) ///////////////////////////////////////
//#define GENRE_HOME_VIEW @"iphone:genre:home:ui::view;"
//#define GENRE_TILE_CLICK @"iphone:genre:home:genre_tile:click;"

//#define GENRE_VIEW @"iphone:genre:detail:ui:view;"
#define GENRE_RADIO_START @"iphone:genre:detail:header:start_radio:click;"
#define GENRE_LOAD_MORE @"iphone:genre:detail:load_more:view;"
/////////////////////////////////////// Genre View ///////////////////////////////////////



/////////////////////////////////////// Charts View(s) ///////////////////////////////////////
//#define CHARTS_HOME_VIEW @"iphone:charts:home:ui:view;"
//#define CHARTS_TILE_CLICK @"iphone:charts:home:chart_tile:click;"
/////////////////////////////////////// Charts View ///////////////////////////////////////

//////////////////////////////////////////CHARTS & CHANNELS HOME EVENTS///////////////////////////////////////////////////////

#define CHARTS_UI_VIEW @"iphone:charts:ui::view;"
#define CHARTS_BACK_CLICK @"iphone:charts:back::click;"
#define CHARTS_CHART_CLICK @"iphone:charts:chart::click;"

#define CHANNELS_UI_VIEW @"iphone:channels:ui::view;"
#define CHANNELS_BACK_CLICK @"iphone:channels:back::click;"
#define CHANNELS_GENRE_CLICK @"iphone:channels:genre::click;"


// Ad Related
#define CHARTS_SPOTLIGHT_CLICK @"iphone:charts:spotlight::click;"
#define CHARTS_SPOTLIGHT_REQUEST_REFRESH @"iphone:charts:spotlight::request_refresh;"
#define CHANNELS_SPOTLIGHT_CLICK @"iphone:channels:spotlight::click;"
#define CHANNELS_SPOTLIGHT_REQUEST_REFRESH @"iphone:channels:spotlight::request_refresh;"

#define ALBUM_DETAIL_MOBILE_BANNER_CLICK @"iphone:album_detail:mobile_banner::click;"
#define PLAYLIST_DETAIL_MOBILE_BANNER_CLICK @"iphone:playlist_detail:mobile_banner::click;"
#define SONG_DETAIL_MOBILE_BANNER_CLICK @"iphone:song_detail:mobile_banner::click;"
#define PLAYER_MOBILE_BANNER_CLICK @"iphone:player:mobile_banner::click;"
#define PLAYER_RADIO_MOBILE_BANNER_CLICK @"iphone:player_radio:mobile_banner::click;"
#define ARTIST_DETAIL_MOBILE_BANNER_CLICK @"iphone:artist_detail:mobile_banner::click;"
#define USER_DETAIL_MOBILE_BANNER_CLICK @"iphone:user_detail:mobile_banner::click;"



#define MY_MUSIC_SPOTLIGHT_CLICK @"iphone:my_music:spotlight::click;"

#define IPHONE_AUDIO_COMPANION_IMPRESSION  @"iphone::audio_companion::impression;"
#define IPHONE_AUDIO_COMPANION_FAILED  @"iphone::audio_companion::failed;"
#define IPHONE_AUDIO_COMPANION_CLICK  @"iphone::audio_companion::click;"
#define IPHONE_AUDIO_COMPANION_REMOVE_ADS_CLICK  @"iphone:audio_companion:remove_ads::click;"


//////////////////////////////////////////CHARTS & CHANNELS HOME EVENTS////////////////////////////////////////////////////////



////////////////////////////////////////////CHART DETAIL VIEW ////////////////////////////////////////////

#define CHART_DETAIL_VIEW @"iphone:chart_detail:ui::view;"
#define CHART_DETAIL_BACK_CLICK @"iphone:chart_detail:back::click;"

#define CHART_DETAIL_PLAY_ART_WORK_BUTTON_CLICK @"iphone:chart_detail:play_artwork_button::click;"
#define CHART_DETAIL_PLAY_HEADER_BUTTON_CLICK @"iphone:chart_detail:play_header_button::click;"
#define CHART_DETAIL_PLAY_MENU_SAVE_OFFLINE_CLICK @"iphone:chart_detail:save_offline::click;"
#define CHART_DETAIL_PLAY_MENU_SHARE_CLICK @"iphone:chart_detail:share::click;"
#define CHART_DETAIL_PLAY_MENU_OPTIONS_CLICK @"iphone:chart_detail:options::click;"
#define CHART_DETAIL_PLAY_MENU_OPTIONS_MENU_REPLACE_QUEUE_CLICK @"iphone:chart_detail:options_menu:replace_queue:click;"
#define CHART_DETAIL_PLAY_MENU_OPTIONS_MENU_ADD_TO_QUEUE_CLICK @"iphone:chart_detail:options_menu:add_to_queue:click;"
#define CHART_DETAIL_PLAY_MENU_OPTIONS_MENU_SAVE_TOP_20_CLICK @"iphone:chart_detail:options_menu:save_top_20:click;"
#define CHART_DETAIL_PLAY_MENU_CANCEL_CLICK @"iphone:chart_detail:options:cancel:click;"

#define CHART_DETAIL_SONG_SONG_CLICK @"iphone:chart_detail:song:song:click;"
#define CHART_DETAIL_SONG_PLAY_CLICK @"iphone:chart_detail:song:play:click;"
#define CHART_DETAIL_SONG_PAUSE_CLICK @"iphone:chart_detail:song:pause:click;"
#define CHART_DETAIL_SONG_QUEUE_CLICK @"iphone:chart_detail:song:queue:click;"
#define CHART_DETAIL_SONG_RADIO_CLICK @"iphone:chart_detail:song:radio:click;"
#define CHART_DETAIL_SONG_STAR_CLICK @"iphone:chart_detail:song:star:click;"
#define CHART_DETAIL_SONG_UNSTAR_CLICK @"iphone:chart_detail:song:unstar:click;"
#define CHART_DETAIL_SONG_CACHEABLE_CLICK @"iphone:chart_detail:song_cacheable::click;"
#define CHART_DETAIL_SONG_CACHEABLE_ELSEWHERE_CLICK @"iphone:chart_detail:song_cached_elsewhere::click;"
#define CHART_DETAIL_SONG_DELETE_CACHE_CLICK @"iphone:chart_detail:song_delete_cache::click;"
#define CHART_DETAIL_SONG_DELETE_CACHE_CANCEL_CLICK @"iphone:chart_detail:song_delete_cache_cancel::click;"
#define CHART_DETAIL_SONG_DELETE_CACHE_CONFIRM_CLICK @"iphone:chart_detail:song_delete_cache_confirm::click;"
#define CHART_DETAIL_SONG_SONG_DETAL_CLICK @"iphone:chart_detail:song:song_detail:click;"

// Ad Related
#define CHART_DETAIL_MOBILE_BANNER_CLICK @"iphone:chart_detail:mobile_banner::click;"
#define CHART_DETAIL_MOBILE_BANNER_REQUEST_REFRESH @"iphone:chart_detail:mobile_banner::request_refresh;"


////////////////////////////////////////////CHART DETAIL VIEW ////////////////////////////////////////////

////////////////////////////////////////////GENRE DETAIL VIEW ////////////////////////////////////////////

#define GENRE_DETAIL_VIEW @"iphone:genre_detail:ui::view;"
#define GENRE_DETAIL_BACK_CLICK @"iphone:genre_detail:back::click;"
#define GENRE_DETAIL_RADIO_HEADER_BUTTON_CLICK @"iphone:genre_detail:radio_header_button::click;"
#define GENRE_DETAIL_RADIO_ART_WORK_BUTTON_CLICK @"iphone:genre_detail:radio_artwork_button::click;"

#define GENRE_DETAIL_SONG_SONG_CLICK @"iphone:genre_detail:song:song:click;"
#define GENRE_DETAIL_SONG_PLAY_CLICK @"iphone:genre_detail:song:play:click;"
#define GENRE_DETAIL_SONG_PAUSE_CLICK @"iphone:genre_detail:song:pause:click;"
#define GENRE_DETAIL_SONG_QUEUE_CLICK @"iphone:genre_detail:song:queue:click;"
#define GENRE_DETAIL_SONG_RADIO_CLICK @"iphone:genre_detail:song:radio:click;"
#define GENRE_DETAIL_SONG_STAR_CLICK @"iphone:genre_detail:song:star:click;"
#define GENRE_DETAIL_SONG_UNSTAR_CLICK @"iphone:genre_detail:song:unstar:click;"
#define GENRE_DETAIL_SONG_CACHEABLE_CLICK @"iphone:genre_detail:song_cacheable::click;"
#define GENRE_DETAIL_SONG_CACHEABLE_ELSEWHERE_CLICK @"iphone:genre_detail:song_cached_elsewhere::click;"
#define GENRE_DETAIL_SONG_DELETE_CACHE_CLICK @"iphone:genre_detail:song_delete_cache::click;"
#define GENRE_DETAIL_SONG_DELETE_CACHE_CANCEL_CLICK @"iphone:genre_detail:song_delete_cache_cancel::click;"
#define GENRE_DETAIL_SONG_DELETE_CACHE_CONFIRM_CLICK @"iphone:genre_detail:song_delete_cache_confirm::click;"
#define GENRE_DETAIL_SONG_SONG_DETAL_CLICK @"iphone:genre_detail:song:song_detail:click;"

// Ad Related
#define CHANNEL_DETAIL_MOBILE_BANNER_CLICK @"iphone:channel_detail:mobile_banner::click;"
#define CHANNEL_DETAIL_MOBILE_BANNER_REQUEST_REFRESH @"iphone:channel_detail:mobile_banner::request_refresh;"


////////////////////////////////////////////GENRE DETAIL VIEW ////////////////////////////////////////////



/////////////////////////////////////// Artist View(s) ///////////////////////////////////////
#define ARTIST_VIEW @"iphone:artist_detail:ui::view;"
#define ARTIST_START_RADIO @"iphone:artist_detail:start_radio:click;"
#define ARTIST_SHARE_HEADER @"iphone:artist_detail:header:share:click;"
#define ARTIST_SHARE_OPTIONS @"iphone:artist_detail:options:share:click;"
#define ARTIST_SHARE_FOOTER @"iphone:artist_detail:footer:share:click;"
#define ARTIST_OPTIONS @"iphone:artist_detail:header:options:click;"

#define ARTIST_TOP_ALBUMS_CLICK @"iphone:artist_detail:top_albums:album:click;"
#define ARTIST_TOP_ALBUMS_MORE @"iphone:artist_detail:top_albums:all_albums:click;"

// [CB] These are shared between main view (top songs) and subview (all songs).
// The cell pos is passed as a param to distinguish... > 3 and we know it was the subview.
// This is the best we can do for now without a huge amount of redundancy.
#define ARTIST_SONGS_CLICK @"iphone:artist_detail:songs:song:click;"
#define ARTIST_SONGS_PLAY @"iphone:artist_detail:songs:play:click;"
#define ARTIST_SONGS_PAUSE @"iphone:artist_detail:songs:pause:click;"
#define ARTIST_SONGS_QUEUE @"iphone:artist_detail:songs:queue:click;"
#define ARTIST_SONGS_RADIO @"iphone:artist_detail:songs:radio:click;"
#define ARTIST_SONGS_STAR @"iphone:artist_detail:songs:star:click;"
#define ARTIST_SONGS_UNSTAR @"iphone:artist_detail:songs:unstar:click;"
#define ARTIST_SONGS_DETAIL @"iphone:artist_detail:songs:song_detail:click;"
#define ARTIST_SONGS_CACHE @"iphone:artist_detail:songs:song_cacheable:click;"
#define ARTIST_SONGS_CACHE_ELSEWHERE @"iphone:artist_detail:songs:song_cached_elsewhere:click;"
#define ARTIST_SONGS_CACHE_DELETE @"iphone:artist_detail:songs:song_delete_cache:click;"
#define ARTIST_SONGS_CACHE_DELETE_CANCEL @"iphone:artist_detail:songs:song_delete_cache_cancel:click;"
#define ARTIST_SONGS_CACHE_DELETE_CONFIRM @"iphone:artist_detail:songs:song_delete_cache_confirm:click;"

#define ARTIST_TOP_SONGS_MORE @"iphone:artist_detail:songs:all_songs:click;"

#define ARTIST_RELATED_CLICK @"iphone:artist_detail:related_artist::click;"

#define ARTIST_ALBUMS_VIEW @"iphone:artist_detail:albums:ui:view;"
#define ARTIST_ALBUMS_CLICK @"iphone:artist_detail:albums:album:click;"
#define ARTIST_ALBUMS_LOAD_MORE @"iphone:artist_detail:albums:load_more:view;"
#define ARTIST_ALBUMS_SORT_POPULARITY @"iphone:artist_detail:albums:sort:popularity:click;"
#define ARTIST_ALBUMS_SORT_DATE @"iphone:artist_detail:albums:sort:date:click;"
#define ARTIST_ALBUMS_SORT_NAME @"iphone:artist_detail:albums:sort:name:click;"

#define ARTIST_SONGS_VIEW @"iphone:artist_detail:songs:ui::view;"
#define ARTIST_SONGS_LOAD_MORE @"iphone:artist_detail:songs:load_more::view;"
#define ARTIST_SONGS_SORT_POPULARITY @"iphone:artist_detail:songs:sort:popularity:view;"
#define ARTIST_SONGS_SORT_DATE @"iphone:artist_detail:songs:sort:date:view;"
#define ARTIST_SONGS_SORT_NAME @"iphone:artist_detail:songs:sort:name:view;"
/////////////////////////////////////// Artist View ///////////////////////////////////////



/////////////////////////////////////// SOTD View ///////////////////////////////////////

#define SOTD_HOME_UI_VIEW @"sotd_home:ui::view;"
#define SOTD_HOME_SONG_SONG_CLICK @"iphone:sotd_home:song:song:click;"
#define SOTD_HOME_SONG_PLAY_CLICK @"iphone:sotd_home:song:play:click;"
#define SOTD_HOME_SONG_PAUSE_CLICK @"iphone:sotd_home:song:pause:click;"
#define SOTD_HOME_SONG_QUEUE_CLICK @"iphone:sotd_home:song:queue:click;"
#define SOTD_HOME_SONG_RADIO_CLICK @"iphone:sotd_home:song:radio:click;"
#define SOTD_HOME_SONG_STAR_CLICK @"iphone:sotd_home:song:star:click;"
#define SOTD_HOME_SONG_UNSTAR_CLICK @"iphone:sotd_home:song:unstar:click;"
#define SOTD_HOME_SONG_CACHEABLE_CLICK @"iphone:sotd_home:song_cacheable::click;"
#define SOTD_HOME_SONG_CACHEABLE_ELSEWHERE_CLICK @"iphone:sotd_home:song_cached_elsewhere::click;"
#define SOTD_HOME_SONG_DELETE_CACHE_CLICK @"iphone:sotd_home:song_delete_cache::click;"
#define SOTD_HOME_SONG_DELETE_CACHE_CANCEL_CLICK @"iphone:sotd_home:song_delete_cache_cancel::click;"
#define SOTD_HOME_SONG_DELETE_CACHE_CONFIRM_CLICK @"iphone:sotd_home:song_delete_cache_confirm::click;"
#define SOTD_HOME_SONG_SONG_DETAL_CLICK @"iphone:sotd_home:song:song_detail:click;"

/////////////////////////////////////// SOTD View ///////////////////////////////////////



/////////////////////////////////////// Store Kit Events ///////////////////////////////////////

#define STOREKIT_SUBSCRITION_FAILED @"iphone:storekit:subsciption::failed;"
#define STOREKIT_SUBSCRITION_SUCCESS @"iphone:storekit:subsciption::success;"
#define STOREKIT_SUBSCRITION_RESTORE @"iphone:storekit:subsciption::restore;"

/////////////////////////////////////// Store Kit Events ///////////////////////////////////////



/////////////////////////////////////// Went Offline Events ///////////////////////////////////////

#define WENT_OFFLINE @"iphone:went_offline:::;"

/////////////////////////////////////// Went Offline Events ///////////////////////////////////////


/////////////////////////////////////// Ads 2.0 Events ///////////////////////////////////////

#define SLOT_BEGIN @"iphone:slot_begin;"
#define SLOT_END @"iphone:slot_end;"
#define MEDIA_AD_BEGIN @"iphone:media_ad_begin;"
#define MEDIA_AD_END @"iphone:media_ad_end;"
#define MEDIA_AD_NO_FILL @"iphone:media_ad_no_fill;"
#define MEDIA_AD_FAILURE @"iphone:media_ad_failure;"
#define CONSUMPTION_CLOCK_END @"iphone:consumption_clock_end;"
#define INITIAL_DURATION_BEGIN @"iphone:initial_duration_begin;"
#define INITIAL_DURATION_END @"iphone:initial_duration_end;"


#define ALBUM_MOBILE_BANNER_REFRESH @"iphone:album:mobile_banner::request_refresh;"
#define PLAYER_MOBILE_BANNER_REFRESH @"iphone:player:mobile_banner::request_refresh;"
#define PLAYER_RADIO_MOBILE_BANNER_REFRESH @"iphone:player_radio:mobile_banner::request_refresh;"
#define PLAYLIST_DETAIL_MOBILE_BANNER_REFRESH @"iphone:playlist_detail:mobile_banner::request_refresh;"
#define SONG_DETAIL_MOBILE_BANNER_REFRESH @"iphone:song_detail:mobile_banner::request_refresh;"
#define ARTIST_DETAIL_MOBILE_BANNER_REFRESH @"iphone:artist_detail:mobile_banner::request_refresh;"
#define MOBILE_BANNER_REFRESH @"iphone:mobile_banner::request_refresh;"


#define MY_MUSIC_SPOTLIGHT_REFRESH @"iphone:my_music:spotlight::request_refresh;"
#define PLAYLISTS_HOME_SPOTLIGHT_REFRESH @"iphone:playlists_home:spotlight::request_refresh;"
#define NEW_RELEASES_SPOTLIGHT_REFRESH @"iphone:new_releases:spotlight::request_refresh;"

#define IPHONE_IDLESCREEN_IMPRESSION @"iphone::mobile_idlescreen::impression;"
#define IPAD_IDLESCREEN_IMPRESSION @"ipad::mobile_idlescreen::impression;"
#define IPHONE_IDLESCREEN_CLICK @"iphone::mobile_idlescreen::click;"
#define IPHONE_IDLESCREEN_CLOSE_CLICK @"iphone::mobile_idlescreen:close:click;"
#define IPAD_IDLESCREEN_CLICK @"iphone::mobile_idlescreen::click;"
#define IPAD_IDLESCREEN_CLOSE_CLICK @"iphone::mobile_idlescreen:close:click;"

#define IPHONE_IDLESCREEN_REQUESTED @"iphone:mobile_idlescreen:requested;"
#define IPHONE_MAXIMUS_REQUESTED @"iphone:max:requested;"

#define IADS_SEARCH_ATTRIBUTION_KEY @"iphone::iads_srch_attribution;"




/////////////////////////////////////// DAAST Events ///////////////////////////////////////
#define IPHONE_DAAST_REQUESTED @"iphone:daast:requested;"
#define IPHONE_DAAST_RECIEVED @"iphone:daast:recieved;"
#define IPHONE_DAAST_FAILED @"iphone:daast:failed;"
#define IPHONE_DAAST_REJECTED @"iphone:daast:rejected;"

#define IPHONE_AUDIO_COMPANION_REQUESTED @"iphone:audio_companion:requested;"
#define IPHONE_MEDIA_AD_REQUESTED @"iphone:media_ad_requested;"
#define IPHONE_BANNER_AD_REQUESTED @"iphone:mobile_banner:requested;"


/////////////////////////////////////// History Events ///////////////////////////////////////

#define MY_HISTORY_CLEAR_CLICK @"iphone:my_history:clear::click;"
#define MY_HISTORY_CLEAR_YES_CLICK @"iphone:my_history:clear:yes:click;"
#define MY_HISTORY_CLEAR_NO_CLICK @"iphone:my_history:clear:no:click;"

#define MY_HISTORY_ONE_CLICK_PLAY_CLICK @"iphone:my_history:queue_oneclickplay::click;"
#define MY_HISTORY_QUEUE_PLAY_CLICK @"iphone:my_history:queue_play::click;"
#define MY_HISTORY_QUEUES_CLICK @"iphone:my_history:queues::click;"
#define MY_HISTORY_QUEUE_OPTIONS_CLICK @"iphone:my_history:queue_options::click;"
#define MY_HISTORY_QUEUE_OPTIONS_CHOOSE_CLICK @"iphone:my_history:queue_options_choose::click;"

#define MY_HISTORY_QUEUE_UI_VIEW @"iphone:my_history:queues:ui::view;"
#define MY_HISTORY_SONGS_CLICK @"iphone:my_history:songs::click;"
#define MY_HISTORY_SONGS_UI_VIEW @"iphone:my_history:songs:ui::view;"


#define MY_HISTORY_LOGIN_CLICK @"iphone:history:login::click;"
#define MY_PLAYER_HORIZONTAL_SWIPE @"iphone:my_player:horizontal::swype;"
#define MY_PLAYER_VIEW_HISTORY_CLICK @"iphone:my_player:view_history::click;"
#define MY_PLAYER_AD_CANCEL_CLICK @"iphone:my_player:ad_cancel::click;"
#define MY_PLAYER_DRAG_SONG_CLICK @"iphone:my_player:dragsong::click;"
#define RADIO_BACK_TO_QUEUE_CLICK @"iphone:radio:back_to_queue::click;"
#define RADIO_TOGGLE_CLICK @"iphone:radio:toggle::click;"
#define LIBRARY_BACK_TO_QUEUE_CLICK @"iphone:mylibrary:back_to_queue::click;"



#define MY_MUSIC_HISTORY_CLICK @"iphone:my_music:history:click"


#define SONGS_SONG_PLAY_CLICK @"iphone::songs:play::click;"
#define SONGS_SONG_PAUSE_CLICK @"iphone::songs:pause::click;"
#define SONGS_SONG_CACHEABLE_CLICK @"iphone::songs:song_view:song_cacheable:click;"
#define SONGS_SONG_CACHEABLE_ELSEWHERE_CLICK @"iphone::songs:song_view:song_cached_elsewhere:click;"
#define SONGS_SONG_DELETE_CACHE_CLICK @"iphone::songs:song_view:song_delete_cache:click;"
#define SONGS_SONG_DELETE_CACHE_CANCEL_CLICK @"iphone::songs:song_view:song_delete_cache_cancel:click;"
#define SONGS_SONG_DELETE_CACHE_CONFIRM_CLICK @"iphone::songs:song_view:song_delete_cache_confirm:click;"

#define SONGS_OPTIONS_CHOOSE_CLICK @"iphone::songs:options_choose::click;"
#define SONGS_OPTIONS_CLICK @"iphone::songs:options::click;"
#define SONGS_LONG_TAP_OPTIONS_CLICK @"iphone::songs:long_tap_options::click;"


/////////////////////////////////////// History Events ///////////////////////////////////////

/////////////////////////////////////// Chromecast events ///////////////////////////////////////


#define CHROMECAST_CLICK @"iphone:chromecast::click;"
#define CHROMECAST_OPTIONS_CLICK @"iphone:chromecast:options::click;"
#define CHROMECAST_ERROR @"iphone:chromecast:connection_error::view;"

/////////////////////////////////////// Chromecast Events ///////////////////////////////////////




/////////////////////////////////////// Social Events ///////////////////////////////////////

#define INBOX_ALL_CLICK @"iphone:inbox:all::click;"
#define INBOX_ALL_CONTENT_CLICK @"iphone:inbox:all:content:click;"
#define INBOX_ALL_REPLY_CLICK @"iphone:inbox:all:reply:click;"
#define INBOX_ALL_REPLIED_CLICK @"iphone:inbox:all:replied:click;"
#define INBOX_ALL_THREAD_CLICK @"iphone:inbox:all:thread:click;"
#define INBOX_ALL_SOCIAL_HEAD_ON_BOTTOM_CLICK @"iphone:inbox:all:social_head_on_bottom:click;"
#define INBOX_ALL_SOCIAL_HEAD_IN_TITLE_CLICK @"iphone:inbox:all:social_head_in_title:click;"
#define INBOX_ALL_NAME_IN_TITLE_CLICK @"iphone:inbox:all:name_in_title:click;"
#define INBOX_FRIENDS_CLICK @"iphone:inbox:friends::click;"
#define INBOX_FRIENDS_CONTENT_CLICK @"iphone:inbox:friends:content:click;"
#define INBOX_FRIENDS_REPLY_CLICK @"iphone:inbox:friends:reply:click;"
#define INBOX_FRIENDS_REPLIED_CLICK @"iphone:inbox:friends:replied:click;"
#define INBOX_FRIENDS_THREAD_CLICK @"iphone:inbox:friends:thread:click;"
#define INBOX_FRIENDS_SOCIAL_HEAD_ON_BOTTOM_CLICK @"iphone:inbox:friends:social_head_on_bottom:click;"
#define INBOX_FRIENDS_SOCIAL_HEAD_IN_TITLE_CLICK @"iphone:inbox:friends:social_head_in_title:click;"
#define INBOX_FRIENDS_NAME_IN_TITLE_CLICK @"iphone:inbox:friends:name_in_title:click;"
#define INBOX_TAGS_CLICK @"iphone:inbox:tags::click;"
#define INBOX_TAGS_CONTENT_CLICK @"iphone:inbox:tags:content:click;"
#define INBOX_TAGS_REPLY_CLICK @"iphone:inbox:tags:reply:click;"
#define INBOX_TAGS_REPLIED_CLICK @"iphone:inbox:tags:replied:click;"
#define INBOX_TAGS_THREAD_CLICK @"iphone:inbox:tags:thread:click;"
#define INBOX_TAGS_SOCIAL_HEAD_ON_BOTTOM_CLICK @"iphone:inbox:tags:social_head_on_bottom:click;"
#define INBOX_TAGS_SOCIAL_HEAD_IN_TITLE_CLICK @"iphone:inbox:tags:social_head_in_title:click;"
#define INBOX_TAGS_NAME_IN_TITLE_CLICK @"iphone:inbox:tags:name_in_title:click;"
#define INBOX_BACK_CLICK @"iphone:inbox:back::click;"
#define INBOX_RECEIVED @"iphone:inbox:received::;"
#define INBOX_SENT @"iphone:inbox:sent::;"
#define INBOX_THREAD_TEXT_INPUTTED @"iphone:inbox:thread::text_inputted;"
#define INBOX_THREAD_BACK_CLICK @"iphone:inbox:thread:back:click;"
#define INBOX_THREAD_SEND_CLICK @"iphone:inbox:thread:send:click;"
#define INBOX_THREAD_SOCIAL_HEAD_IN_TITLE_CLICK @"iphone:inbox:thread:social_head_in_title:click;"
#define INBOX_THREAD_NAME_IN_TITLE_CLICK @"iphone:inbox:thread:name_in_title:click;"
#define INBOX_THREAD_CONTENT_CLICK @"iphone:inbox:thread:content:click;"
#define INBOX_THREAD_SOCIAL_HEAD_IN_THREAD_CLICK @"iphone:inbox:thread:social_head_in_thread:click;"
#define INBOX_THREAD_NAME_IN_THREAD_CLICK @"iphone:inbox:thread:name_in_thread:click;"
#define INBOX_THREAD_UI_VIEW @"iphone:inbox:ui::view;"
#define INBOX_FOLLOW_CLICK @"iphone:inbox:follow::click;"
#define INBOX_UNFOLLOW_CLICK @"iphone:inbox:unfollow::click;"



#define PEOPLE_ARTISTS_TAB_CLICK @"iphone:people:artists_tab::click;"
#define PEOPLE_ARTISTS_TAB_FOLLOW_CLICK @"iphone:people:artists_tab:follow:click;"
#define PEOPLE_ARTISTS_TAB_PROFILE_CLICK @"iphone:people:artists_tab:profile:click;"
#define PEOPLE_ARTISTS_TAB_UNFOLLOW_CLICK @"iphone:people:artists_tab:unfollow:click;"
#define PEOPLE_BACK_CLICK @"iphone:people:back::click;"
#define PEOPLE_FOLLOWING_TAB_CLICK @"iphone:people:following_tab::click;"
#define PEOPLE_FOLLOWING_TAB_FOLLOW_CLICK @"iphone:people:following_tab:follow:click;"
#define PEOPLE_FOLLOWING_TAB_PROFILE_CLICK @"iphone:people:following_tab:profile:click;"
#define PEOPLE_FOLLOWING_TAB_UNFOLLOW_CLICK @"iphone:people:following_tab:unfollow:click;"
#define PEOPLE_FRIENDS_TAB_CLICK @"iphone:people:friends_tab::click;"
#define PEOPLE_FRIENDS_TAB_FOLLOW_CLICK @"iphone:people:friends_tab:follow:click;"
#define PEOPLE_FRIENDS_TAB_PROFILE_CLICK @"iphone:people:friends_tab:profile:click;"
#define PEOPLE_FRIENDS_TAB_UNFOLLOW_CLICK @"iphone:people:friends_tab:unfollow:click;"
#define PEOPLE_HEADER_PROFILE_CLICK @"iphone:people:header_profile::click;"
#define PEOPLE_UI_VIEW @"iphone:people:ui::view;"


#define PROFILE_ALL_PLAYLISTS_CLICK @"iphone:profile:all_playlists::click;"
#define PROFILE_IMAGE_CLICK @"iphone:profile:image::click;"
#define PROFILE_BACK_CLICK @"iphone:profile:back::click;"
#define PROFILE_FOLLOW_CLICK @"iphone:profile:follow::click;"
#define PROFILE_FOLLOWERS_CLICK @"iphone:profile:followers::click;"
#define PROFILE_FOLLOWERS_FOLLOW_CLICK @"phone:profile:followers:follow:click;"
#define PROFILE_FOLLOWERS_PROFILE_CLICK @"iphone:profile:followers:profile:click;"
#define PROFILE_FOLLOWERS_UNFOLLOW_CLICK @"iphone:profile:followers:unfollow:click;"
#define PROFILE_FOLLOWING_CLICK @"iphone:profile:following::click;"
#define PROFILE_FOLLOWING_FOLLOW_CLICK @"iphone:profile:following:follow:click;"
#define PROFILE_FOLLOWING_PROFILE_CLICK @"iphone:profile:following:profile:click;"
#define PROFILE_FOLLOWING_UNFOLLOW_CLICK @"iphone:profile:following:unfollow:click;"
#define PROFILE_OPTIONS_HOME_CLICK @"iphone:profile:options:home:click;"
#define PROFILE_OPTIONS_SETTINGS_CLICK @"iphone:profile:options:settings:click;"
#define PROFILE_PLAY_MIX_CLICK @"iphone:profile:play_mix::click;"
#define PROFILE_PLAYLIST_OPTIONS_CLICK @"iphone:profile:playlist_options::click;"
#define PROFILE_PLAYLIST_OPTIONS_ADD_TO_PLAYLIST_CLICK @"iphone:profile:playlist_options:add_to_playlist:click;"
#define PROFILE_PLAYLIST_OPTIONS_ADD_TO_QUEUE_CLICK @"iphone:profile:playlist_options:add_to_queue:click;"
#define PROFILE_PLAYLIST_OPTIONS_DOWNLOAD_CLICK @"iphone:profile:playlist_options:download:click;"
#define PROFILE_PLAYLIST_OPTIONS_PLAY_ALL_CLICK @"iphone:profile:playlist_options:play_all:click;"
#define PROFILE_PLAYLIST_OPTIONS_REPLACE_QUEUE_CLICK @"iphone:profile:playlist_options:replace_queue:click;"
#define PROFILE_PLAYLIST_CLICK @"iphone:profile:playlist::click;"
#define PROFILE_RECENT_SONG_CLICK @"iphone:profile:recent_song::click;"
#define PROFILE_RECENT_SONG_PLAY_CLICK @"iphone:profile:recent_song:play:click;"
#define PROFILE_RECENT_SONG_PAUSE_CLICK @"iphone:profile:recent_song:pause:click;"
#define PROFILE_RECENT_SONG_QUEUE_CLICK @"iphone:profile:recent_song:queue:click;"
#define PROFILE_RECENT_SONG_RADIO_CLICK @"iphone:profile:recent_song:radio:click;"
#define PROFILE_RECENT_SONG_SONG_DETAIL_CLICK @"iphone:profile:recent_song:song_detail:click;"
#define PROFILE_RECENT_SONG_STAR_CLICK @"iphone:profile:recent_song:star:click;"
#define PROFILE_RECENT_SONG_UNSTAR_CLICK @"iphone:profile:recent_song:unstar:click;"
#define PROFILE_SEARCH_CLICK @"iphone:profile:search::click;"
#define PROFILE_UI_VIEW_CLICK @"iphone:profile:ui::view;"
#define PROFILE_UNFOLLOW_CLICK @"iphone:profile:unfollow::click;"

#define SETTINGS_EMAIL_NOTIFICATIONS_CLICK @"iphone:settings:email_notifications::click;"
#define SETTINGS_EMAIL_NOTIFICATIONS_TURN_OFF_ALL_CLICK @"iphone:settings:email_notifications:turn_off_all:click;"
#define SETTINGS_EMAIL_NOTIFICATIONS_TURN_ON_ALL_CLICK @"iphone:settings:email_notifications:turn_on_all:click;"
#define SETTINGS_EMAIL_NOTIFICATIONS_SAAVN_CONTENT_SHARES_ON @"iphone:settings:email_notifications:saavn_content_shares:on;"
#define SETTINGS_EMAIL_NOTIFICATIONS_SAAVN_CONTENT_SHARES_OFF @"iphone:settings:email_notifications:saavn_content_shares:off;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWS_ME_ON @"iphone:settings:email_notifications:follows_me:on;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWS_ME_OFF @"iphone:settings:email_notifications:follows_me:off;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWED_USER_CREATED_PLAYLIST_ON @"iphone:settings:email_notifications:followed_user_creates_playlist:on;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWED_USER_CREATED_PLAYLIST_OFF @"iphone:settings:email_notifications:followed_user_creates_playlist:off;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWS_MY_PLAYLIST_ON @"iphone:settings:email_notifications:follows_my_playlist:on;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWS_MY_PLAYLIST_OFF @"iphone:settings:email_notifications:follows_my_playlist:off;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWED_USER_UPDATES_PLAYLIST_ON @"iphone:settings:email_notifications:followed_user_updates_playlist:on;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWED_USER_UPDATES_PLAYLIST_OFF @"iphone:settings:email_notifications:followed_user_updates_playlist:off;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWED_PLAYLIST_UPDATE_ON @"iphone:settings:email_notifications:followed_playlist_update:on;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWED_PLAYLIST_UPDATE_OFF @"iphone:settings:email_notifications:followed_playlist_update:off;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWED_ARTIST_NEW_CONTENT_ON @"iphone:settings:email_notifications:followed_artist_new_content:on;"
#define SETTINGS_EMAIL_NOTIFICATIONS_FOLLOWED_ARTIST_NEW_CONTENT_OFF @"iphone:settings:email_notifications:followed_artist_new_content:off;"
#define SETTINGS_EMAIL_NOTIFICATIONS_USER_CONTENT_SHARES_ON @"iphone:settings:email_notifications:user_content_shares:on;"
#define SETTINGS_EMAIL_NOTIFICATIONS_USER_CONTENT_SHARES_OFF @"iphone:settings:email_notifications:user_content_shares:off;"
#define SETTINGS_EMAIL_NOTIFICATIONS_SAVE_CLICK @"iphone:settings:email_notifications:save:click;"
#define SETTINGS_MOBILE_NOTIFICATIONS_CLICK @"iphone:settings:mobile_notifications::click;"
#define SETTINGS_MOBILE_NOTIFICATIONS_TURN_OFF_ALL_CLICK @"iphone:settings:mobile_notifications:turn_off_all:click;"
#define SETTINGS_MOBILE_NOTIFICATIONS_TURN_ON_ALL_CLICK @"iphone:settings:mobile_notifications:turn_on_all:click;"
#define SETTINGS_MOBILE_NOTIFICATIONS_SAAVN_CONTENT_SHARES_ON @"iphone:settings:mobile_notifications:saavn_content_shares:on;"
#define SETTINGS_MOBILE_NOTIFICATIONS_SAAVN_CONTENT_SHARES_OFF @"iphone:settings:mobile_notifications:saavn_content_shares:off;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWS_ME_ON @"iphone:settings:mobile_notifications:follows_me:on;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWS_ME_OFF @"iphone:settings:mobile_notifications:follows_me:off;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWED_USER_CREATES_PLAYLIST_ON @"iphone:settings:mobile_notifications:followed_user_creates_playlist:on;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWED_USER_CREATES_PLAYLIST_OFF @"iphone:settings:mobile_notifications:followed_user_creates_playlist:off;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWS_MY_PLAYLIST_ON @"iphone:settings:mobile_notifications:follows_my_playlist:on;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWS_MY_PLAYLIST_OFF @"iphone:settings:mobile_notifications:follows_my_playlist:off;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWED_USER_UPDATES_PLAYLIST_ON @"iphone:settings:mobile_notifications:followed_user_updates_playlist:on;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWED_USER_UPDATES_PLAYLIST_OFF @"iphone:settings:mobile_notifications:followed_user_updates_playlist:off;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWED_PLAYLIST_UPDATE_ON @"iphone:settings:mobile_notifications:followed_playlist_update:on;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWED_PLAYLIST_UPDATE_OFF @"iphone:settings:mobile_notifications:followed_playlist_update:off;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWED_ARTIST_NEW_CONTENT_ON @"iphone:settings:mobile_notifications:followed_artist_new_content:on;"
#define SETTINGS_MOBILE_NOTIFICATIONS_FOLLOWED_ARTIST_NEW_CONTENT_OFF @"iphone:settings:mobile_notifications:followed_artist_new_content:off;"
#define SETTINGS_MOBILE_NOTIFICATIONS_USER_CONTENT_SHARES_ON @"iphone:settings:mobile_notifications:user_content_shares:on;"
#define SETTINGS_MOBILE_NOTIFICATIONS_USER_CONTENT_SHARES_OFF @"iphone:settings:mobile_notifications:user_content_shares:off;"
#define SETTINGS_MOBILE_NOTIFICATIONS_SAVE_CLICK @"iphone:settings:mobile_notifications:save:click;"


/////////////////////////////////////// Social Events ///////////////////////////////////////

////////////////////////////////////// Social Empty Events //////////////////////////////////

#define PEOPLE_FRIENDS_EMPTY_NO_DATA_VIEW @"iphone:people:friends_empty_no_data:ui:view;"
#define PEOPLE_FRIENDS_EMPTY_NO_DATA_CONNECT_FB_CLICK @"iphone:people:friends_empty_no_data:connect_facebook:click;"
#define PEOPLE_FRIENDS_EMPTY_NO_DATA_SHARE_FB_CLICK @"iphone:people:friends_empty_no_data:share_facebook:click;"
#define PEOPLE_FRIENDS_EMPTY_NO_DATA_SHARE_TWITTER_CLICK @"iphone:people:friends_empty_no_data:share_twitter:click;"
#define PEOPLE_FRIENDS_EMPTY_NO_DATA_SHARE_CLICK @"iphone:people:friends_empty_no_data:share:click;"
#define PEOPLE_FOLLOWING_EMPTY_CONNECT_FB_VIEW @"iphone:people:following_empty_connect_fb:ui:view;"
#define PEOPLE_FOLLOWING_EMPTY_CONNECT_FB_CLICK @"iphone:people:following_empty_connect_fb:connect_facebook:click;"
#define PEOPLE_FOLLOWING_EMPTY_CONNECT_FB_SHARE_FB_CLICK @"iphone:people:following_empty_connect_fb:share_facebook:click;"
#define PEOPLE_FOLLOWING_EMPTY_CONNECT_FB_SHARE_TWITTER_CLICK @"iphone:people:following_empty_connect_fb:share_twitter:click;"
#define PEOPLE_FOLLOWING_EMPTY_CONNECT_FB_SHARE_CLICK @"iphone:people:following_empty_connect_fb:share:click;"

#define INBOX_ALL_EMPTY_NO_DATA_VIEW @"iphone:inbox:all_empty_no_data:ui:view;"
#define INBOX_ALL_EMPTY_NO_DATA_SHARE_FACEBOOK_CLICK @"iphone:inbox:all_empty_no_data:share_facebook:click;"
#define INBOX_ALL_EMPTY_NO_DATA_SHARE_TWITTER_CLICK @"iphone:inbox:all_empty_no_data:share_twitter:click;"
#define INBOX_ALL_EMPTY_NO_DATA_SHARE_CLICK @"iphone:inbox:all_empty_no_data:share:click;"
#define INBOX_ALL_EMPTY_CONNECT_FB_VIEW @"iphone:inbox:all_empty_connect_fb:ui:view;"
#define INBOX_ALL_EMPTY_CONNECT_FB_CONNECT_FB_CLICK @"iphone:inbox:all_empty_no_data:share_facebook:click;"
#define INBOX_FRIENDS_EMPTY_CONNECT_FB_VIEW @"iphone:inbox:friends_empty_connect_fb:ui:view;"
#define INBOX_FRIENDS_EMPTY_CONNECT_FB_CONNECT_FB_CLICK @"iphone:inbox:friends_empty_connect_fb:connect_facebook:click;"
#define INBOX_FRIENDS_EMPTY_NO_DATA_VIEW @"iphone:inbox:friends_empty_no_data:ui:view;"
#define INBOX_FRIENDS_EMPTY_NO_DATA_SHARE_FB_CLICK @"iphone:inbox:friends_empty_no_data:share_facebook:click;"
#define INBOX_FRIENDS_EMPTY_NO_DATA_SHARE_TWITTER_CLICK @"iphone:inbox:friends_empty_no_data:share_twitter:click;"
#define INBOX_FRIENDS_EMPTY_NO_DATA_SHARE_CLICK @"iphone:inbox:friends_empty_no_data:share:click;"
#define INBOX_TAGS_EMPTY_CONNECT_FB_VIEW @"iphone:inbox:tags_empty_connect_fb:ui:view;"
#define INBOX_TAGS_EMPTY_CONNECT_FB_CONNECT_FB_CLICK @"iphone:inbox:tags_empty_connect_fb:connect_facebook:click;"
#define INBOX_TAGS_EMPTY_NO_DATA_VIEW @"iphone:inbox:tags_empty_no_data:ui:view;"
#define INBOX_TAGS_EMPTY_NO_DATA_SHARE_FB_CLICK @"iphone:inbox:tags_empty_no_data:share_facebook:click;"
#define INBOX_TAGS_EMPTY_NO_DATA_SHARE_TWITTER_CLICK @"iphone:inbox:tags_empty_no_data:share_twitter:click;"
#define INBOX_TAGS_EMPTY_NO_DATA_SHARE_CLICK @"iphone:inbox:tags_empty_no_data:share:click;"


////////////////////////////////////// Social Empty Events //////////////////////////////////

/////////////////////////////////////// Miscellaneous Events ///////////////////////////////////////

#define APP_INSTALLED @"iphone:application:install::;"
#define APP_UPGRADE @"iphone:application:upgrade::;"
#define NOTIFICATION_OPENED @"iphone:notification:open::;"
#define MOBILE_REFERRER @"iphone:mobile:referrer::;"
#define ERROR_TRY_AGAIN_CLICK @"iphone:error:tryagain:click::;"
#define UTM_REFERRER @"ios:application:referrer_src;"
#define CLEAR_CACHE @"ios:application:clearcache::;"
#define DUPLICATE_COOKIES @"ios:application:duplicatecookies::;"
#define NEW_UTM_REFERRER @"ios:application:new_referrer:;"

/////////////////////////////////////// Miscellaneous Events ///////////////////////////////////////




//////////////////////////////////////iPhone 4.0 Events /////////////////////////////////////////////////
#define HOME_BOTTOMMENU_TRYPRO_CLICK @"iphone:home:bottommenu:trypro:click;"
#define MYMUSIC_SWIPE @"iphone:my_music:ui::swipe;"
#define MYMUSIC_UI_VIEW @"iphone:my_music:ui::view;"
#define MYMUSIC_OPTIONS_GOOFFLINE_CLICK @"iphone:my_music:go_offline::click;"

#define MYMUSIC_VERTICALLIST_CLICK @"iphone:my_music:verticallist::click;"
#define MYMUSIC_MYPLAYLISTS_CLICK @"iphone:my_music:myplaylists::click;"
#define MYMUSIC_FOLLOWEDPLAYLISTS_CLICK @"iphone:my_music:followedplaylists::click;"
#define MYMUSIC_SQUAREGRIDMENU_CLICK @"iphone:my_music:squaregridmenu::click;"
#define MYMUSIC_SQUAREGRIDMENU_CLICK_OUT @"iphone:my_music:squaregridmenu::click_out;"
#define MYMUSIC_GOPRO @"iphone:my_music::gopro;"
//iphone:offlinemymusic::swipe;
#define LANGUAGE_SELECT_UNCLICK @"iphone:language_select:::unclick;"
#define LANGUAGE_SELECT_DONE_CLICK @"iphone:language_select:done::click;"
#define LANGUAGE_SELECT_ONBOARDING_CLICK @"iphone:language_select:onboarding:click;"
#define LANGUAGE_SELECT_ONBOARDING_UNCLICK @"iphone:language_select:onboarding:unclick;"
#define LANGUAGE_SELECT_DONE_ONBOARDING_CLICK @"iphone:language_select:done:onboarding::click;"
//iphone:home:startinfomessage::swipe;
//iphone:home:startinfomessage::click;
#define HOME_SEARCH_CLICK @"iphone:home:search::click;"
#define HOME_INBOX_BADGE_CLICK @"iphone:home:inbox:badge:click;"
//iphone:home:inbox:no_badge:click;
#define SETTINGS_BTN_CLICK @"iphone::settings:click;"
#define HOME_HORIZONTALLIST_WEEKLY15_CLICK @"iphone:home:horizontallist:weektop15:click;"
#define HOME_HORIZONTALLIST_SWIPE @"iphone:home:horizontallist::swipe;"
#define HOME_HORIZONTALLIST_CLICK @"iphone:home:horizontallist::click;"
#define HOME_HORIZONTALLIST_ONE_CLICK @"iphone:home:horizontallist::oneclick;"

#define HOME_SQUAREGRIDMENU_NEWRELEASES_CLICK @"iphone:home:squaregridmenu:newreleases:click;"
#define HOME_SQUAREGRIDMENU_CHARTSANDLISTS_CLICK @"iphone:home:squaregridmenu:chartsandlists:click;"
#define HOME_SQUAREGRIDMENU_RADIO_CLICK @"iphone:home:squaregridmenu:radio:click;"
#define HOME_SQUAREGRIDMENU_BROWSE_DISCOVER_CLICK @"iphone:home:squaregridmenu:browse_discover:click;"
#define HOME_SQUAREGRIDMENU_CLICK @"iphone:home:squaregridmenu::click;"
#define HOME_HORIZONTALLIST_USERPROFILE_CLICK @"iphone:home:horizontallist:userprofile:click;"
#define HOME_HORIZONTALLIST_SURPRISEME_CLICK @"iphone:home:horizontallist:surpriseme:click;"
#define HOME_SQUAREGRIDMENU_MORECHARTTOPPERS_CLICK @"iphone:home:squaregridmenu:morecharttoppers:click;"
#define HOME_BOTTOMMENU_FINDPEOPLE_CLICK @"iphone:home:bottommenu:findpeople:click;"
#define HOME_BOTTOMMENU_FEEDBACK_CLICK @"iphone:home:bottommenu:feedback:click;"
#define HOME_BOTTOMMENU_SURPRISEME_CLICK @"iphone:home:bottommenu:surpriseme:click;"
//iphone:home:popupmenu:new:click;
//iphone:home:popupmenu:lists:click;
//iphone:home:popupmenu:radio:click;
//iphone:home:popupmenu:genres:click;
//iphone:home:spotlight::click;
//iphone:home:spotlight::request_refresh;
#define GENERIC_SPOTLIGHT_CLICK @"iphone:generic:spotlight::click;"
#define GENERIC_BANNER_CLICK @"iphone:generic:banner::click;"

/////////////////////////////////////// ********* My Music 2.0 ************* ///////////////////////////////////////


#define MYMUSIC_GROUP_ROW_CLICK @"iphone:my_music:group_row::click;"
#define MYMUSIC_GROUP_LIST_VIEW @"iphone:my_music:group_list::view;"
#define MYMUSIC_GROUP_LIST_ROW_CLICK @"iphone:my_music:group_list_row::click;"
#define MYMUSIC_GROUP_CACHED_LIST_VIEW @"iphone:my_music:group_cached_list::view;"
#define MYMUSIC_GROUP_CACHED_LIST_CLICK @"iphone:my_music:group_cached_list::click;"
#define MYMUSIC_SHUFFLE_ALL_CLICK @"iphone:my_music:shuffle_all::click;"

#define MYMUSIC_SETTINGS_CLICK @"iphone:my_music:settings::click;"
#define MYMUSIC_FOLLOWER_CLICK @"iphone:my_music:follower::click;"
#define MYMUSIC_FOLLOWING_CLICK @"iphone:my_music:following::click;"
#define MYMUSIC_GO_PRO_CLICK @"iphone:my_music:go_pro::click;"
#define MYMUSIC_PROFILE_CLICK @"iphone:my_music:profile::click;"
#define MYMUSIC_EDIT_PROFILE_CLICK @"iphone:my_music:edit_profile::click;"


#define MYMUSIC_HISTORY_VIEW_ALL_CLICK @"iphone:my_music:history_view_all::click;"
#define MYMUSIC_HISTORY_ROW_CLICK @"iphone:my_music:history_view_row::click;"
#define MYMUSIC_HISTORY_MORE_CLICK @"iphone:my_music:more_history::click;"

#define MYMUSIC_HISTORY_CLEAR_CLICK @"iphone:my_music:history:clear::click;"
#define MYMUSIC_HISTORY_CLEAR_YES_CLICK @"iphone:my_music:history:clear:yes:click;"
#define MYMUSIC_HISTORY_CLEAR_NO_CLICK @"iphone:my_music:history:clear:no:click;"

#define MYMUSIC_PLAYLIST_VIEW_ALL_CLICK @"iphone:my_music:playlist_view_all::click;"
#define MYMUSIC_PLAYLIST_ROW_CLICK @"iphone:my_music:playlist_row_all::click;"
#define MYMUSIC_PLAYLIST_MORE_CLICK @"iphone:my_music:more_playlist::click;"


#define MYMUSIC_DOWNLOADING_PAUSE_CLICK @"iphone:my_music:downloading_pause::click;"
#define MYMUSIC_DOWNLOADING_RESUME_CLICK @"iphone:my_music:downloading_resume::click;"
#define MYMUSIC_DOWNLOADING_CANCEL_ALL_CLICK @"iphone:my_music:downloading_cancel_all::click;"

#define MYMUSIC_DOWNLOAD_ALL_CLICK @"iphone:my_music:download_all::click;"
#define MYMUSIC_INIT_SYNC_UPDATE @"iphone:my_music:init_sync::;"
#define MYMUSIC_REFRESH_SYNC_CANCEL_CLICK @"iphone:my_music:refresh_sync:cancel:click;"

#define MYMUSIC_ARTIST_VIEW @"iphone:my_music:artist_detail:ui:view;"

#define MYMUSIC_ADD_CONTROLLER_CLICK @"iphone:add_contoller::click;"
#define MYMUSIC_ADD_CONTROLLER_VIEW @"iphone:add_contoller:ui::view;"
#define MYMUSIC_ADD_CONTROLLER_CLOSE_CLICK @"iphone:add_contoller:cancel::click;"
#define MYMUSIC_ADD_CONTROLLER_CREATE_NEW_PLAYLIST_CLICK @"iphone:add_contoller:create_new_playlist::click;"
#define MYMUSIC_ADD_CONTROLLER_CREATE_NEW_PLAYLIST_CANCEL_CLICK @"iphone:add_contoller:create_new_playlist:cancel:click;"
#define MYMUSIC_ADD_CONTROLLER_SAVE_NEW_PLAYLIST_CLICK @"iphone:add_contoller:create_new_playlist:save:click;"
#define MYMUSIC_ADD_CONTROLLER_OLD_SAVED_CLICK @"iphone:add_contoller:saved_playlist::click;"
#define MYMUSIC_ADD_CONTROLLER_ADD_QUEUE_CLICK @"iphone:add_controller:add_to_queue::click;"
#define MYMUSIC_ADD_CONTROLLER_MY_MUSIC_CLICK @"iphone:add_controller:add_to_my_music::click;"

#define MYMUSIC_ARTIST_DETAIL_PROFILE_CLICK @"iphone:my_music:artist_detail:profile:click;"
#define MYMUSIC_ARTIST_DETAIL_ALBUM_CLICK @"iphone:my_music:artist_detail:album:click;"
#define MYMUSIC_ARTIST_DETAIL_SONG_CLICK @"iphone:my_music:artist_detail:song:click;"
#define MYMUSIC_ARTIST_DETAIL_SHUFFLE_ALL_CLICK @"iphone:my_music:artist_detail:shuffle_all:click;"
#define MYMUSIC_ARTIST_DETAIL_FOLLOW_CLICK @"iphone:my_music:artist_detail:follow:click;"
#define MYMUSIC_ARTIST_DETAIL_UNFOLLOW_CLICK @"iphone:my_music:artist_detail:unfollow:click;"
#define MYMUSIC_ARTIST_DETAIL_RADIO_CLICK @"iphone:my_music:artist_detail:radio:click;"


#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_CLICK @"iphone:my_music:myplaylist:menu_options:click;"
#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_ADD_TO_QUEUE_CLICK @"iphone:my_music:myplaylist:menu_options:add_to_queue:click;"
#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_PRIVACY_CLICK @"iphone:my_music:myplaylist:menu_options:privacy:click;"
#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_RENAME_CLICK @"iphone:my_music:myplaylist:menu_options:rename:click;"
#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_DELETE_CLICK @"iphone:my_music:myplaylist:menu_options:delete:click;"
#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_SHARE_CLICK @"iphone:my_music:myplaylist:menu_options:share:click;"
#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_FOLLOW_CLICK @"iphone:my_music:myplaylist:menu_options:folloe:click;"
#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_UNFOLLOW_CLICK @"iphone:my_music:myplaylist:menu_options:unfollow:click;"
#define MYMUSIC_PLAYLISTS_MENU_OPTIONS_PROFILE_CLICK @"iphone:my_music:myplaylist:menu_options:profile:click;"
#define MYMUSIC_PLAYLISTS_GO_PRO_CLICK @"iphone:my_music:myplaylist:go_pro:click;"

#define MY_MUSIC_ALBUM_SHOW_FULL_ALBUM_CLICK @"iphone:my_music:album:show_full_album:click;"
#define MY_MUSIC_ALBUM_ADD_TO_MY_MUSIC_CLICK @"iphone:my_music:album:add_full_album:click;"



/////////////////////////////////////// ********* IPAD Only Events ************* ///////////////////////////////////////


#define IPAD_HOME_SEARCH_CLICK @"ipad:home:search::click;"
#define IPAD_NEW_RELEASES_HOME_SEARCH_CLICK @"ipad:new_releases_home:search::click;"

#define IPAD_PLAYER_RADIO_OPTIONS_CLICK @"ipad:player_radio:options::click;"
#define IPAD_PLAYER_RADIO_OPTIONS_ADD_TO_PLAYLISTCLICK @"ipad:player_radio:options:add_to_playlist:click;"
#define IPAD_PLAYER_RADIO_OPTIONS_SHARE_CLICK @"ipad:player_radio:options:share:click;"
#define IPAD_PLAYER_RADIO_OPTIONS_STAR_CLICK @"ipad:player_radio:options:star:click;"
#define IPAD_PLAYER_RADIO_OPTIONS_UNSTAR_CLICK @"ipad:player_radio:options:star:click;"
#define IPAD_PLAYER_RADIO_QUEUE_BACK_TO_QUEUE_CLICK @"ipad:player_radio:queue:back_to_queue:click;"

#define IPAD_PLAYER_OPTIONS_CLICK @"ipad:player:options::click;"
#define IPAD_PLAYER_OPTIONS_ADD_TO_PLAYLISTCLICK @"ipad:player:options:add_to_playlist:click;"
#define IPAD_PLAYER_OPTIONS_SHARE_CLICK @"ipad:player:options:share:click;"
#define IPAD_PLAYER_OPTIONS_STAR_CLICK @"ipad:player:options:star:click;"
#define IPAD_PLAYER_OPTIONS_UNSTAR_CLICK @"ipad:player:options:star:click;"

#define IPAD_PLAYLISTS_HOME_SEARCH_CLICK @"ipad:playlists_home:search::click;"
#define IPAD_SPOTLIGHT_CLICK @"ipad:spotlight:::click;"

/////////////////////////////////////// ********* SOFT/HARD UPGRADE ************* ///////////////////////////////////////
#define HARD_UPGRADE_VIEW @"iphone:hard_upgrade:ui::view;"
#define SOFT_UPGRADE_VIEW @"iphone:soft_upgrade:ui::view;"
#define SOFT_UPGRADE_UPDATE_CLICK @"iphone:soft_upgrade:update::click;"
#define HARD_UPGRADE_UPDATE_CLICK @"iphone:hard_upgrade:update::click;"

/////////////////////////////////////// ********* SOCKET ************* ///////////////////////////////////////
#define SOCKET_CONNECTION_FAILED @"iphone:search:socket::error;"

/////////////////////////////////////// ********* Mobile Brand Ads ************* ///////////////////////////////////////
#define SEARCH_SPOTLIGHT_AD_REFRESH     @"iphone:search:spotlight::request_refresh;"
#define SEARCH_SPOTLIGHT_AD_CLICK       @"iphone:search_spotlight:view:ad:click;"
#define SEARCH_SPOTLIGHT_AD_SUCCESS     @"iphone:search_spotlight:view:ad:success;"
#define SEARCH_SPOTLIGHT_AD_FAIL        @"iphone:search_spotlight:view:ad:fail;"

#define MY_MUSIC_SPOTLIGHT_AD_CLICK       @"iphone:mymusic_spotlight:view:ad:click;"
#define MY_MUSIC_SPOTLIGHT_AD_SUCCESS     @"iphone:mymusic_spotlight:view:ad:success;"
#define MY_MUSIC_SPOTLIGHT_AD_FAIL        @"iphone:mymusic_spotlight:view:ad:fail;"

///////////////////////////////////////// ********* CREATE PLAYLIST EVENT ************* ///////////////////////////////////////

#define PLAYLIST_CREATE_ALL_ALBUMS_UI_VIEW @"iphone:create_playlist:all_albums:ui:view;"
#define PLAYLIST_CREATE_ALL_ALBUMS_ALBUM_CLICK @"iphone:create_playlist:all_albums:album_result:click;"


/////////////////////////////////////// ********* Pro page - Source Tracking ************* ///////////////////////////////////////
#define PLAYER_REMOVE_ADS_CLICK               @"iphone:player:options:remove_ads:click;"

///////////////////////////////*********  ProBenefit Events ************* ////////////////////////////////////////
#define PRO_BENEFIT_PROMPT_VIEW @"iphone:pro_benefits_prompt:ui::view;"
#define PRO_BENEFIT_PROMPT_REDEEM_SUCCESS @"iphone:pro_benefits_prompt:redeem::success;"
#define PRO_BENEFIT_PROMPT_EXTEND_PRO_CLICK @"iphone:pro_benefits_prompt:cta::click;"
#define PRO_BENEFIT_PROMPT_PURCHASE_PRO_A @"iphone:pro_benefits_prompt:go_pro:variant_A:success;"
#define PRO_BENEFIT_PROMPT_PURCHASE_PRO_B @"iphone:pro_benefits_prompt:go_pro:variant_B:success;"
/////////////////////////////// ************* ProBenefit Events ************* ////////////////////////////////////////

///////////////////////////////*************  Tab click events ************* ////////////////////////////////////////
#define HOME_TAB_CLICK @"iphone:bottommenu:home::click;"
#define SEARCH_TAB_CLICK @"iphone:bottommenu:search::click;"
#define PLAYER_TAB_CLICK @"iphone:bottommenu:player::click;"
#define BROWSE_TAB_CLICK @"iphone:bottommenu:browse::click;"
#define MYMUSIC_TAB_CLICK @"iphone:bottommenu:mymusic::click;"

///////////////////////////////*************  iCloud Autorefill Modal ************* ////////////////////////////////////////
#define AUTOFILL_MODAL_VIEW @"iphone:autofill:ui::view;"
#define AUTOFILL_CLOSE_CLICK @"iphone:autofill:close::click;"
#define AUTOFILL_ACCOUNT_ROW_CLICK @"iphone:autofill:row::click;"


///////////////////////////////*************  Contextual Share ************* ////////////////////////////////////////
#define CONTEXTUAL_SHARE_VIEW @"iphone:contextual_share:ui::view;"

#define MOBILE_DATA_USAGE @"iphone:app_mobile_data_usage::;"

///////////////////////////////*************  LYRICS EVENTS ************* ////////////////////////////////////////

#define LYRICS_SNIPPET_VIEW                             @"iphone:lyrics:snippet:view;"
#define LYRICS_SNIPPET_VIEW_CLICK                       @"iphone:lyrics:snippet:click;"
#define LYRICS_POPOVER_VIEW                             @"iphone:lyrics:full:view;"
#define LYRICS_POPOVER_CLOSE                            @"iphone:lyrics:full:minimized;"
#define LYRICS_API_SUCCESS                              @"iphone:lyrics::loaded;"
#define LYRICS_API_FAILED                               @"iphone:lyrics::failed;"
#define LYRICS_ANNOTATIONS_SUCCESS                      @"iphone:lyrics:annotations:loaded;"
#define LYRICS_ANNOTATIONS_FAILED                       @"iphone:lyrics:annotations:failed;"
#define LYRICS_MUSIXMATCH_TRACKING_URL_CALLED           @"iphone:lyrics:musixmatch:tracking:called;"

#define LYRICS_SONG_EXPANDED_CLICK                      @"iphone:lyrics:song:expanded;"

#define SETTINGS_LYRICS_TOGGLE_CLICK                    @"iphone:settings:lyrics:toggle:click;"
#define SETTINGS_ANNOTATION_TOGGLE_CLICK                @"iphone:settings:annotation:toggle:click;"

///////////////////////////////*************  MAXIMUS EVENTS ************* ////////////////////////////////////////

#define IPHONE_MAXIMUS_IMPRESSION           @"iphone:max:request_refresh;"
#define IPHONE_MAXIMUS_CLICK                @"iphone:max_click;"
#define IPHONE_MAXIMUS_DISMISS               @"iphone:max_click_dismiss;"

#define IPHONE_PRO_MAXIMUS_IMPRESSION           @"iphone:max_pro:request_refresh;"
#define IPHONE_PRO_MAXIMUS_CLICK                @"iphone:max_pro_click;"
#define IPHONE_PRO_MAXIMUS_DISMISS               @"iphone:max_pro_click_dismiss;"

///////////////////////////////*************  SHOWCASE EVENTS ************* ////////////////////////////////////////
#define IPHONE_SHOWCASE_REQUESTED           @"iphone:infeed:requested;"
#define IPHONE_SHOWCASE_IMPRESSION           @"iphone:infeed:request_refresh;"
#define IPHONE_SHOWCASE_CLICK                @"iphone:infeed_click;"
#define IPHONE_SHOWCASE_FAILED               @"iphone:infeed_refresh:failed;"

#define IPHONE_PRO_SHOWCASE_REQUESTED           @"iphone:infeed_pro:requested;"
#define IPHONE_PRO_SHOWCASE_IMPRESSION           @"iphone:infeed_pro:request_refresh;"
#define IPHONE_PRO_SHOWCASE_CLICK                @"iphone:infeed_pro_click;"
#define IPHONE_PRO_SHOWCASE_FAILED               @"iphone:infeed_pro_refresh:failed;"

///////////////////////////////*************  NATIVE EVENTS ************* ////////////////////////////////////////
#define IPHONE_NATIVE_REQUESTED           @"iphone:native:requested;"
#define IPHONE_NATIVE_IMPRESSION           @"iphone:native:request_refresh;"
#define IPHONE_NATIVE_CLICK                @"iphone:native_click;"
#define IPHONE_NATIVE_FAILED                @"iphone:native_refresh:failed;"

#define IPHONE_PRO_NATIVE_REQUESTED           @"iphone:native_pro:requested;"
#define IPHONE_PRO_NATIVE_IMPRESSION           @"iphone:native_pro:request_refresh;"
#define IPHONE_PRO_NATIVE_CLICK                @"iphone:native_pro_click;"
#define IPHONE_PRO_NATIVE_FAILED                @"iphone:native_pro_refresh:failed;"

///////////////////////////////*************  HOME SPOTLIGHT EVENTS ************* ////////////////////////////////////////

#define HOME_SPOTLIGHT_REQUESTED      @"iphone:showcase:requested;"
#define HOME_SPOTLIGHT_REFRESH      @"iphone:showcase:request_refresh;"
#define HOME_SPOTLIGHT_CLICK        @"iphone:showcase_click;"
#define HOME_SPOTLIGHT_FAILED       @"iphone:showcase_refresh:failed;"

#define HOME_PRO_SPOTLIGHT_REQUESTED      @"iphone:showcase_pro:requested;"
#define HOME_PRO_SPOTLIGHT_REFRESH      @"iphone:showcase_pro:request_refresh;"
#define HOME_PRO_SPOTLIGHT_CLICK        @"iphone:showcase_pro_click;"
#define HOME_PRO_SPOTLIGHT_FAILED       @"iphone:showcase_pro_refresh:failed;"

///////////////////////////////************* PODCAST SHOWCASE EVENTS ************* ////////////////////////////////////////

#define IPHONE_PODCAST_SHOWCASE_REQUESTED	@"iphone:podcast:infeed:requested;"
#define IPHONE_PODCAST_SHOWCASE_IMPRESSION	@"iphone:infeed:request_podcast_refresh;"
#define IPHONE_PODCAST_SHOWCASE_CLICK	@"iphone:infeed_podcast_click;"
#define IPHONE_PODCAST_SHOWCASE_FAILED	@"iphone:infeed_podcast_refresh:failed;"

///////////////////////////////************* PODCAST  NATIVE EVENTS ************* ////////////////////////////////////////

#define IPHONE_PODCAST_NATIVE_REQUESTED		@"iphone:native:requested_podcast;"
#define IPHONE_PODCAST_NATIVE_IMPRESSION	@"iphone:native_podcast:request_refresh;"
#define IPHONE_PODCAST_NATIVE_CLICK		@"iphone:native_podcast_click;"
#define IPHONE_PODCAST_NATIVE_FAILED	@"iphone:native_podcast_refresh:failed;"

///////////////////////////////*************  PODCAST SPOTLIGHT EVENTS ************* ////////////////////////////////////////

#define PODCAST_SPOTLIGHT_REQUESTED		@"iphone:podcast:showcase:requested;"
#define PODCAST_SPOTLIGHT_REFRESH	@"iphone:showcase:request_podcast_refresh;"
#define PODCAST_SPOTLIGHT_CLICK		@"iphone:showcase_podcast_click;"
#define PODCAST_SPOTLIGHT_FAILED	@"iphone:showcase_podcast_refresh:failed;"

///////////////////////////////*************  In App Browser EVENTS ************* ////////////////////////////////////////
#define IPHONE_INAPP_BROWSER_APP_RESUME                    @"iphone:inapp_browser:app_resume;"
#define IPHONE_INAPP_BROWSER_WEBVIEW_TRIGGER_INSTANTIATE   @"iphone:inapp_browser:webview_trigger_instantiate;"
#define IPHONE_INAPP_BROWSER_WEBVIEW_TRIGGER_DISMISS       @"iphone:inapp_browser:webview_trigger_dismiss;"
#define IPHONE_INAPP_BROWSER_TOOLBAR_LINK_SHARE_CLICKED    @"iphone:inapp_browser:toolbar_link_share_clicked;"
#define IPHONE_INAPP_BROWSER_PREV_CLICK                    @"iphone:inapp_browser:toolbar_link_prev_clicked;"
#define IPHONE_INAPP_BROWSER_NEXT_CLICK                    @"iphone:inapp_browser:toolbar_link_next_clicked;"



#define CLEAR_DOWNLOAD_PROMPT_CLICK @"iphone:clear_download::click;"
#define SWITCH_ACCOUNTS_PROMPT_CLICK @"iphone:switch_accounts::click;"
#define CLEAR_DOWNLOAD_PROMPT_VIEW @"iphone:clear_download::view;"


#define IPHONE_LAUNCH_API_REQUESTED @"iphone:get_launch_data:requested;"
#define IPHONE_LAUNCH_API_RECEIVED @"iphone:get_launch_data:received;"
#define IPHONE_LAUNCH_API_FAILED @"iphone:get_launch_data:failed;"


#define IPHONE_AD_LAUNCH_CONFIG_REQUESTED @"iphone:ad_launch_config:requested;"
#define IPHONE_AD_LAUNCH_CONFIG_RECEIVED @"iphone:ad_launch_config:received;"
#define IPHONE_AD_LAUNCH_CONFIG_FAILED @"iphone:ad_launch_config:failed;"

#define IPHONE_AD_LAUNCH_CONFIG_DATA_RECEIVED @"iphone:ad_launch_config:url_data:received;"
#define IPHONE_AD_LAUNCH_CONFIG_DATA_FAILED @"iphone:ad_launch_config:url_data:failed;"


