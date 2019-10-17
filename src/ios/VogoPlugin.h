#import <Cordova/CDV.h>

#ifndef VogoPlugin_h
#define VogoPlugin_h

@interface VogoPlugin : CDVPlugin

FOUNDATION_EXPORT NSString *const DEFAULT_TEXT;
FOUNDATION_EXPORT NSString *const DEFAULT_TEXT_HIDDEN;
FOUNDATION_EXPORT NSString *const CONNECTING_TEXT;
FOUNDATION_EXPORT NSString *const QUIT_TEXT;
FOUNDATION_EXPORT NSString *const DIALOG_ICON;
FOUNDATION_EXPORT NSString *const BACKGROUND;
FOUNDATION_EXPORT NSString *const SPONSOR1;
FOUNDATION_EXPORT NSString *const SPONSOR2;
FOUNDATION_EXPORT NSString *const SPONSOR3;
FOUNDATION_EXPORT NSString *const SPONSOR4;
FOUNDATION_EXPORT NSString *const SPONSOR5;
FOUNDATION_EXPORT NSString *const MAIN_LOGO;
FOUNDATION_EXPORT NSString *const PRIMARY_COLOR;
FOUNDATION_EXPORT NSString *const BACKGROUND_NOTIFICATION_ICON;
FOUNDATION_EXPORT NSString *const BACKGROUND_NOTIFICATION_MESSAGE;
FOUNDATION_EXPORT NSString *const BACKGROUND_NOTIFICATION_ICON_LARGE;
FOUNDATION_EXPORT NSString *const PLAYER_TITLE;
FOUNDATION_EXPORT NSString *const HIDE_CGU;
FOUNDATION_EXPORT NSString *const VOGO_EVENTS_PROJECT_ID;
FOUNDATION_EXPORT NSString *const WITH_BACKGROUND_AUDIO;
FOUNDATION_EXPORT NSString *const JSON_LISTENING_IP;

- (void) launchPlayer:(CDVInvokedUrlCommand*)command;

@end

#endif /* VogoPlugin_h */