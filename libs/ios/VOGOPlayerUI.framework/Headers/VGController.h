//
//  VGController.h
//  VGPlayerLib
//
//  Created by Hugo on 10/03/15.
//  Copyright (c) 2015 VOGO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VOGOPlayerCore/VGPlayer.h>
#import <VOGOPlayerCore/VGDefines.h>

@class VGPlayer;
@class VOGOParameters;

@interface VGController : UIViewController <VGEventListener>


//
- (void) setPlayerConfiguration:(VOGOParameters *) properties;
/*
 Default is NO
 */
@property (nonatomic, assign) BOOL isStandalone;
/*
 Default is NO
 */
@property (nonatomic, assign) BOOL withBackgroundAudio;

@property(nonatomic, strong) VOGOParameters* parameters;

@property(nonatomic, strong) VGPlayer* player;
@property(nonatomic, weak) IBOutlet UIScrollView* scrollView;

- (void) updateDesyncLabel;
- (void) onScreenCaptureCheck:(NSNotification*) notification NS_AVAILABLE_IOS(11_0);
@end
