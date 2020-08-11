//
//  VGChannel.h
//  VOGOPlayerFramework
//
//  Created by VOGO on 11/04/2018.
//  Copyright © 2018 VOGO. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VGChannel : NSObject
//
@property(assign, nonatomic, readonly) NSInteger Id;
//
@property(copy, nonatomic, readonly) NSString* title;
//
@property(assign, nonatomic, readonly) BOOL isFile;
//
@property(assign, nonatomic, readonly) BOOL isPaid;
//
@property(assign, nonatomic, readonly) BOOL isPaying;
//
@property(assign, nonatomic, readonly) NSInteger payTier;
//
@property(assign, nonatomic, readonly) BOOL isBuffered;

- (instancetype) init NS_UNAVAILABLE;


//+ (instancetype)initMOCKChannel;

@end

NS_ASSUME_NONNULL_END
