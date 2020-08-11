//
//  VGToolkit.h
//  VOGO Sport
//
//  Created by Hugo on 12/09/14.
//  Copyright (c) 2014 VOGO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface VGToolkit : NSObject

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

+ (BOOL)IsValidEmail:(NSString *)checkString;
+ (NSString *)pathOfFile:(NSString *)fileName;
+ (NSString *)tempPathOfFile:(NSString *)fileName;
+ (UIColor *)colorFromHexString:(NSString *)hexString;
+ (UIColor *)colorFromWindowsLong:(long)color;
+ (UIColor *)colorFromLongRGB:(long)color;
+ (NSString *)sanitizeString:(NSString *)inputString;
+ (void)ScheduleNotification:(NSString*)message withTitle:(NSString *)title atDate:(NSDate*)scheduledDate;
+ (void)NotifyUserNow:(NSString*)message withTitle:(NSString *)title isAppInForeground:(BOOL)bIsInForeground;

NSString *BundleLocalizedString(NSString* key, NSString* comment);

+(WKWebView *) addNewWebView:(UIView*)parent;

+ (void)DataCollection;

+ (void)PostData:(NSData *)data toURL:(NSString *)urlstring completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;
@end

@interface UIImage(VGPlayer)

+(UIImage *)imageFromBundle:(NSString *)name;

@end
