//
//  VGPlayerLib.h
//  VGPlayerLib
//
//  Created by Hugo on 09/03/15.
//  Copyright (c) 2015 VOGO. All rights reserved.
//
#import <UIKit/UIKit.h>


#define kVOGO_NOTIFICATION_SHARE_CLIP          @"VOGO_notification_share_clip"
#define kVOGO_NOTIFICATION_SHARE_CLIP_FILEPATH @"VOGO_notification_share_clip_filepath"
#define kVOGO_NOTIFICATION_SHARE_CLIP_HASHTAG  @"VOGO_notification_share_clip_hashtag"

NS_ASSUME_NONNULL_BEGIN



@class VGController;
@interface VGPlayerLib : UIResponder
{}

/*
 Access shared instance of VGPlayerLib
 */
+ (instancetype)sharedInstance;

/*
 Currently active player instance,
 Note : read only
 */
- (UIViewController*) getPlayer;

/*
 Customize UI :
 
    - primary Color
    - secondary Color
    - background Image
    - mainlogo -> First top left logo
    - sponsor1 - 4 -> top logos starting after main logo
    - sponsor5 -> bottom left logo
    
    these settings will take precedence only if the user is not in the stadium.
    in witch case the server settings takes precedence.
*/

- (void)setDefaultText:(NSString *)defaultText; // default wifi message string
- (void)hideDefaultText:(BOOL)hidden;           // default visible
- (void)hideCGU:(BOOL)hidden;                   // default visible

- (void)setDefaultBackgroundImage:(UIImage *)image;
- (void)setDefaultPrimaryUIColor:(UIColor *)color;
- (void)setDefaultSecondaryUIColor:(UIColor *)color;

- (void) setEventImage:(UIImage *)image;
- (void) setDefaultMainLogo:(UIImage *)image;
- (void) setDefaultSponsor1:(UIImage *)image;
- (void) setDefaultSponsor2:(UIImage *)image;
- (void) setDefaultSponsor3:(UIImage *)image;
- (void) setDefaultSponsor4:(UIImage *)image;
- (void) setDefaultVideo:(NSString *)url;

- (void)setConnectingText:(NSString *)connectingText;
//
- (void) setMediaPlayerInfo:(NSString*) title withImage:(nullable UIImage*) image;
- (void) setBackgroundNotification:(NSString*) title withMessage:(NSString*) message;

- (void) setProductTiers:(NSDictionary<NSNumber *, NSString *> *) dic;
- (NSString* _Nullable ) getIdentifierFor:(NSInteger)tiers;


/*
 Alias to hideCGU:YES
 Default: NO
 */
@property (nonatomic, assign) BOOL cguHidden;
/* 
 Display debug Logs if set to YES.
 Default: NO
*/
@property (nonatomic, assign) BOOL debugEnabled;

/*
 Registered Project ID in VOGO Events online database. Contact VOGO to get your own Project ID.
 Default: 0
 */
@property (nonatomic, assign) int vogoEventsProjectId;

/*
 Multicast address to listen for a VOGO JSON.
 Default: 234.1.1.99
 */
@property (nonatomic, assign) NSString* listeningIp;

/*
 If the player is the only ViewController of the App. You should leave this to NO.
 Default: NO
 */
@property (nonatomic, assign) BOOL isStandalone;

/*
 If YES, play audio while the player is in background.
 Default: NO
 */
@property (nonatomic, assign) BOOL withBackgroundAudio;

/*
Return current values for banners and colors
*/
@property(nonatomic, retain)  NSDictionary* currentImagesAndColorsValues;

/*
 If YES, a notification will be showed when the player is in background.
 Default: YES
 */
@property (nonatomic, assign) BOOL showBackgroundNotification;

@end

NS_ASSUME_NONNULL_END

