//
//  VGCoreToolkit.h
//  VOGOPlayer
//
//  Created by Daniel Dedisse on 06/09/2018.
//  Copyright © 2018 VOGO. All rights reserved.
//

#ifndef VGCoreToolkit_h
#define VGCoreToolkit_h

@interface VGCoreToolkit : NSObject

+ (NSString *)GenerateUUID;
+ (NSString *)GetBundleVersion;
+ (NSString *)GetSSID;
+ (NSString *)GetBSSID;
+ (NSString *)GetDeviceModel;
+ (NSString *)GetIPAddress;
+ (NSString *)GetOSType;
+ (NSString *)GetOSVersion;
+ (NSString *)GetCountryCode;

/*!
 * Sets the value returned by GetBundleVersion. This value is used in the stats sent by the Player to the VOGO server.
 */
+ (void)SetVersionName:(NSString*)name;

@end

#endif /* VGCoreToolkit_h */
