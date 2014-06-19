//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013,2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 The IBMCurrentDevice represents the current device using the SDK.
 */
@interface IBMCurrentDevice : NSObject

/**
 The deviceId that identifies the device.
 */
@property (readonly, nonatomic) NSString *hardwareId;

/**
 The deviceModel that identifies the device.
 */
@property (readonly, nonatomic) NSString *model;

/**
 The platform is IOS
 */
@property (readonly, nonatomic) NSString *platform;

/**
 The devicePlatformVersion that the device is running.
 */
@property (readonly, nonatomic) NSString *platformVersion;

/**
 The user defined device name.  Used to provide a human readable device name.
 */
@property (readonly, nonatomic) NSString *name;

/**
 The current location of the device. This can be nil if the location is not available.
 */
@property (readonly, nonatomic) CLLocation *lastLocation;

/**
 The unique identifier from Mobile Application Security Service
 */
@property (readonly, nonatomic) NSString *uuid;

@end
