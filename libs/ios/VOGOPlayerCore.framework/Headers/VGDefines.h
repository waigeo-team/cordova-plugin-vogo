//
//  VGDefines.h
//  VOGOPlayer
//
//  Created by VOGO on 23/04/2018.
//  Copyright © 2018 VOGO. All rights reserved.
//
#import <Foundation/Foundation.h>

// SubtitlesReceived : SubTitle dictionary keys
extern NSString* const kSubtitleText;			// NSString containing the Subtitle text.
extern NSString* const kSubtitleHorzPos;		// NSNumber with integer value. the subtitle horizontal position.
extern NSString* const kSubtitleVertPos;		// NSNumber with integer value. the subtitle vertical position.
extern NSString* const kSubtitleColor;			// NSNumber with long value. this long value will be the representation of 0xRRBBGG
extern NSString* const kSubtitleDisplayDelay;	// NSNumber with float value. this value is in millseconds.
extern NSString* const kSubtitleSize;			// NSNumber with integer value. the subtitle height.
extern NSString* const kSubtitleChannel;		// NSString containing the Subtitle Channel text.
// ConfigChanged, ContentChanged : Images banner dictionary keys
extern NSString* const kImageMainLogo;			// NSString containing the Main Logo file name. this value can be empty. Use VOGO Player resourcesFolder property to get the image full path.
extern NSString* const kImageEvent;				// NSString containing the Event Logo file name. this value can be empty. Use VOGO Player resourcesFolder property to get the image full path.
extern NSString* const kImagePartner1;			// NSString containing the Partner1 Logo file name. this value can be empty. Use VOGO Player resourcesFolder property to get the image full path.
extern NSString* const kImagePartner2;			// NSString containing the Partner2 Logo file name. this value can be empty. Use VOGO Player resourcesFolder property to get the image full path.
extern NSString* const kImagePartner3;			// NSString containing the Partner3 Logo file name. this value can be empty. Use VOGO Player resourcesFolder property to get the image full path.
extern NSString* const kImagePartner4;			// NSString containing the Partner4 Logo file name. this value can be empty. Use VOGO Player resourcesFolder property to get the image full path.
extern NSString* const kUrlPartner1;            // NSString containing the URL associated to Partner1 logo. this value can be empty.
extern NSString* const kUrlPartner2;            // NSString containing the URL associated to Partner2 logo. this value can be empty.
extern NSString* const kUrlPartner3;            // NSString containing the URL associated to Partner3 logo. this value can be empty.
extern NSString* const kUrlPartner4;            // NSString containing the URL associated to Partner4 logo. this value can be empty.

// ConfigChanged, ContentChanged : Application colors dictionary keys
extern NSString* const kColorButtonNormal;		// NSNumber with long value. this long value will be the representation of 0xRRBBGG
extern NSString* const kColorButtonSelected;	// NSNumber with long value. this long value will be the representation of 0xRRBBGG
extern NSString* const kColorTopHeader;			// NSNumber with long value. this long value will be the representation of 0xRRBBGG
extern NSString* const kColorTransport;			// NSNumber with long value. this long value will be the representation of 0xRRBBGG
// ConfigChanged
extern NSString* const kCanReplay;				// NSNumber with BOOL value.
extern NSString* const kCanRecord;				// NSNumber with BOOL value.
extern NSString* const kCanShare;               // NSNumber with BOOL value.
extern NSString* const kShareHashtag;           // NSString.
extern NSString* const kFullScreen;             // NSNumber with BOOL value.
extern NSString* const kZeroStreamsText;        // NSString.
extern NSString* const kWithScreenCapture;      // NSNumber with BOOL value.
extern NSString* const kMarkers;                // Array of Markers
//
// Event data keys
extern NSString* const kAddedChannels; // Array of integers
//
extern NSString* const kRemovedChannels; // Array of integers
//
extern NSString* const kWaiting; // Bool
//
extern NSString* const kSpeed; // Integer
//
extern NSString* const kState; // Integer
//
extern NSString* const kChannel; // Integer
//
extern NSString* const kPreviousChannel; // Integer
//
extern NSString* const kRenderingId; // Integer
//
extern NSString* const kFilename; // String: recorded filename, Datafile filename
//
extern NSString* const kDisplayAsked; // Bool
//
extern NSString* const kIsConnectedToWifi; // Bool

// Advanced rendering configuration
extern NSInteger const kRENDERING_WITH_VIDEO;
extern NSInteger const kRENDERING_WITH_AUDIO;
extern NSInteger const kRENDERING_WITH_ZOOM;
extern NSInteger const kRENDERING_WITH_SUBTITLES;
extern NSInteger const kRENDERING_WITH_TIME_OVERLAY;
extern NSInteger const kRENDERING_WITH_AUTO_REDUCE_RESOLUTION;
extern NSInteger const kRENDERING_WITH_LAST_SAMPLE;
extern NSInteger const kRENDERING_WITH_CHANNEL_NAME_OVERLAY;
extern NSInteger const kRENDERING_WITH_SOUNDGRAPH;
extern NSInteger const kRENDERING_WITH_DECODEBIN;
extern NSInteger const kRENDERING_WITH_LOGO_OVERLAY;
extern NSInteger const kRENDERING_WITH_CENSOR;
extern NSInteger const kRENDERING_WITH_RECORDING;
extern NSInteger const kRENDERING_WITH_LINE_VISION;

extern NSInteger const kRENDERING_MAIN_VIDEO_OPTIONS;
extern NSInteger const kRENDERING_THUMBNAIL_VIDEO_OPTIONS;

extern NSInteger const kRENDERING_TYPE_MAIN;
extern NSInteger const kRENDERING_TYPE_THUMBNAILS;

extern NSInteger const kCHANNEL_AUTO_SELECT;

extern NSInteger const kMAIN_RENDERING_ID;
extern NSInteger const kRENDERING_ID_ANY;

// Preferences
#define kDeviceID @"deviceid"

