//
//  VGPlayerLibPrivate.h
//  VGPlayerLib
//
//  Created by Hugo on 11/03/15.
//  Copyright (c) 2015 VOGO. All rights reserved.
//
#import "VGPlayerLib.h"

@class VOGOParameters;




@interface VGPlayerLib ()

@property (nonatomic, readwrite) BOOL wifiAwake;
@property (nonatomic, readwrite) BOOL withStats;
//
@property (nonatomic, assign) BOOL isAudioSessionOpen;
@property (nonatomic, assign) BOOL isMpInfoCenterOpen;
@property (nonatomic, assign) BOOL backgroundNotificationHasBeenShown;





/*
 Tell if screen Record with iOS11 is Allowed.
 Default: YES
 */
@property (nonatomic, assign) BOOL screenCaptureAllowed;

@end
