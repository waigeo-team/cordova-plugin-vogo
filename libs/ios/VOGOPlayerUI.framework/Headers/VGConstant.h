//
//  Constant.h
//  VOGO Sport
//
//  Created by Hugo on 10/09/14.
//  Copyright (c) 2014 VOGO. All rights reserved.
//

#ifndef VG_Constant_h
#define VG_Constant_h

#ifdef IS_FASHION
#import "FashionUIConst.h"
#else
#import "DefaultUIConst.h"
#endif

// Prefs Keys

#define kBirthday       @"birthday"
#define kBundleVersion  @"bundleversion"
#define kCountry        @"country"
#define kDataSuccess    @"datasuccess"
#define kDeviceModel    @"devicemodel"
#define kEmail          @"email"
#define kFirstName      @"firstname"
#define kJob            @"job"
#define kLastName       @"lastname"
#define kOSType         @"ostype"
#define kOSVersion      @"osversion"
#define kSex            @"sex"
#define kSexValues      @[@"M",@"F"]
#define kZipCode        @"zipcode"


// Colors
#define BLUE_VOGO       [UIColor colorWithRed:33./255 green:130./255 blue:178./255 alpha:1]
#define DARK_OPERA      [UIColor colorWithRed:0./255 green:0./255 blue:0./255 alpha:1]
#define RED_EQUIPE      [UIColor colorWithRed:228./255 green:28./255 blue:19./255 alpha:1]
#define BLACK           [UIColor colorWithRed:0./255 green:0./255 blue:0./255 alpha:1]
#define WHITE           [UIColor colorWithRed:255./255 green:255./255 blue:255./255 alpha:1]
// Images
#define DEFAULT_EVENT_IMG   @"world_archery.png"
#define DEFAULT_PARTNER_IMG @"vogo_logo.png"
#define EVENT_IMG           @"vogo_logo.png"
#define PARTNER_IMG         @"vogo_logo.png"
// Shortcuts
#define PREFS [NSUserDefaults standardUserDefaults]
#define _T(x) BundleLocalizedString(x,@"")
#define degreesToRadians(x) (M_PI * x / 180.0)
// API URL
#define API_ROOT_URL @"https://events.vogosport.com"
#define API_LOCAL_PATH @"/stats.php"
#define API_USER_PATH_V2 @"/user"
#define API_CONFIG_PATH @"/appconfig"

#endif
