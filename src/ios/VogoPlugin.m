#import "VogoPlugin.h"
#import "VOGOPlayerUI/VGPlayerLib.h"

@implementation VogoPlugin

NSString *const DEFAULT_TEXT = @"DEFAULT_TEXT";
NSString *const DEFAULT_TEXT_HIDDEN = @"DEFAULT_TEXT_HIDDEN";
NSString *const CONNECTING_TEXT = @"CONNECTING_TEXT";
NSString *const QUIT_TEXT = @"QUIT_TEXT";
NSString *const DIALOG_ICON = @"DIALOG_ICON";
NSString *const BACKGROUND = @"BACKGROUND";
NSString *const SPONSOR1 = @"SPONSOR1";
NSString *const SPONSOR2 = @"SPONSOR2";
NSString *const SPONSOR3 = @"SPONSOR3";
NSString *const SPONSOR4 = @"SPONSOR4";
NSString *const SPONSOR5 = @"SPONSOR5";
NSString *const MAIN_LOGO = @"MAIN_LOGO";
NSString *const PRIMARY_COLOR = @"PRIMARY_COLOR";
NSString *const BACKGROUND_NOTIFICATION_ICON = @"BACKGROUND_NOTIFICATION_ICON";
NSString *const BACKGROUND_NOTIFICATION_MESSAGE = @"BACKGROUND_NOTIFICATION_MESSAGE";
NSString *const BACKGROUND_NOTIFICATION_ICON_LARGE = @"BACKGROUND_NOTIFICATION_ICON_LARGE";
NSString *const PLAYER_TITLE = @"PLAYER_TITLE";
NSString *const HIDE_CGU = @"HIDE_CGU";
NSString *const VOGO_EVENTS_PROJECT_ID = @"VOGO_EVENTS_PROJECT_ID";
NSString *const WITH_BACKGROUND_AUDIO = @"WITH_BACKGROUND_AUDIO";
NSString *const JSON_LISTENING_IP = @"JSON_LISTENING_IP";


- (void)launchPlayer:(CDVInvokedUrlCommand*)command
{
    // Look for other return status like error
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];

    NSLog(@"Launching VOGO Player");

    VGPlayerLib* sharedInstance =[VGPlayerLib sharedInstance];
    if(sharedInstance)
    {
        // Fetch options from command arguments
        NSDictionary* options = [command.arguments objectAtIndex:0];
        if(options) [self setupPlayer:sharedInstance withOptions:options];
        UIViewController *vgc = [sharedInstance getPlayer];
        if(vgc)
        {
            [vgc setModalTransitionStyle:UIModalTransitionStyleCrossDissolve];
            [self.viewController presentViewController:vgc animated:YES completion:NULL];
        }
        else
        {
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"UIViewController was null"];
        }
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"VGPlayerLib instance was null"];
    }

    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)setupPlayer:(VGPlayerLib*)vgInstance withOptions:(NSDictionary*)options
{
    if(options == nil) return;

    if([options objectForKey:DEFAULT_TEXT]) [vgInstance setDefaultText:[options objectForKey:DEFAULT_TEXT]];
    if([options objectForKey:DEFAULT_TEXT_HIDDEN]) [vgInstance hideDefaultText:[[options valueForKey:DEFAULT_TEXT_HIDDEN] boolValue]];
    if([options objectForKey:CONNECTING_TEXT]) [vgInstance setConnectingText:[options valueForKey:CONNECTING_TEXT]];
    if([options objectForKey:BACKGROUND]) [vgInstance setDefaultBackgroundImage:[UIImage imageNamed:[options objectForKey:BACKGROUND]]];
    if([options objectForKey:SPONSOR1]) [vgInstance setDefaultSponsor1:[UIImage imageNamed:[options objectForKey:SPONSOR1]]];
    if([options objectForKey:SPONSOR2]) [vgInstance setDefaultSponsor2:[UIImage imageNamed:[options objectForKey:SPONSOR2]]];
    if([options objectForKey:SPONSOR3]) [vgInstance setDefaultSponsor3:[UIImage imageNamed:[options objectForKey:SPONSOR3]]];
    if([options objectForKey:SPONSOR4]) [vgInstance setDefaultSponsor4:[UIImage imageNamed:[options objectForKey:SPONSOR4]]];
    if([options objectForKey:SPONSOR5]) [vgInstance setDefaultSponsor5:[UIImage imageNamed:[options objectForKey:SPONSOR5]]];
    if([options objectForKey:MAIN_LOGO]) [vgInstance setDefaultMainLogo:[UIImage imageNamed:[options objectForKey:MAIN_LOGO]]];
    if([options objectForKey:PRIMARY_COLOR]) [vgInstance setDefaultPrimaryUIColor:[self rgbHexStringToColor:[options objectForKey:PRIMARY_COLOR]]];

    NSString* bkg_ntf_icn_name = @"default_icon";
    NSString* bkg_ntf_icn_large_name = @"default_icon_large";
    NSString* bkg_ntf_msg = @"VOGO Player Will keep on receiving the videos int the background ! Close it any time in the MediaControls.";
    NSString* player_title = @"Live & Replay by VOGO";
    if([options objectForKey:BACKGROUND_NOTIFICATION_ICON]) bkg_ntf_icn_name = [options objectForKey:BACKGROUND_NOTIFICATION_ICON];
    if([options objectForKey:BACKGROUND_NOTIFICATION_MESSAGE]) bkg_ntf_msg = [options objectForKey:BACKGROUND_NOTIFICATION_MESSAGE];
    if([options objectForKey:BACKGROUND_NOTIFICATION_ICON_LARGE]) bkg_ntf_icn_large_name = [options objectForKey:BACKGROUND_NOTIFICATION_ICON_LARGE];
    if([options objectForKey:PLAYER_TITLE]) player_title = [options objectForKey:PLAYER_TITLE];
    [vgInstance setBackgroundNotification:player_title withMessage:bkg_ntf_msg];
    [vgInstance setMediaPlayerInfo:player_title withImage:[UIImage imageNamed:bkg_ntf_icn_name]];

    if([options objectForKey:HIDE_CGU]) [vgInstance hideCGU:[[options valueForKey:HIDE_CGU] boolValue]];
    if([options objectForKey:VOGO_EVENTS_PROJECT_ID]) vgInstance.vogoEventsProjectId = [[options valueForKey:VOGO_EVENTS_PROJECT_ID] intValue];
    if([options objectForKey:WITH_BACKGROUND_AUDIO]) vgInstance.withBackgroundAudio = [[options valueForKey:WITH_BACKGROUND_AUDIO] boolValue];
    if([options objectForKey:JSON_LISTENING_IP]) vgInstance.listeningIp = [options objectForKey:JSON_LISTENING_IP];
}

- (UIColor*)rgbHexStringToColor:(NSString*)hexString
{
    UIColor* color = nil;

    if(hexString.length == 7 && [hexString characterAtIndex:0] == '#')
    {
        NSScanner* scanner = [NSScanner scannerWithString:hexString];
        unsigned hex = 0;
        //To skip the #
        [scanner setScanLocation:1];
        [scanner scanHexInt:&hex];
        color = [UIColor colorWithRed:((float)((hex & 0xFF0000) >> 16))/255.0 \
                                green:((float)((hex & 0x00FF00) >>  8))/255.0 \
                                 blue:((float)((hex & 0x0000FF) >>  0))/255.0 \
                                alpha:1.0];
    }

    return color;
}

@end
