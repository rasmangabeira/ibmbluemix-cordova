//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013,2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

typedef enum IBMSecurityProvider{
    IBMSecurityProvider_GOOGLE, IBMSecurityProvider_WORKLIGHT
}IBMSecurityProvider;

#import <Foundation/Foundation.h>
#import <IBMBluemix/IBMBluemixService.h>
#import <IBMBluemix/IBMHttpError.h>
#import <IBMBluemix/IBMHttpRequest.h>
#import <IBMBluemix/IBMMutableHttpRequest.h>
#import <IBMBluemix/IBMHttpResponse.h>
#import <IBMBluemix/IBMCurrentUser.h>
#import <IBMBluemix/IBMCurrentDevice.h>


/**
 IBMBluemix is the entry point for interacting with the MBaaS SDKs. The method initializeWithApplicationId:andApplicationRoute:andApplicationSecret must be invoked before any other API calls. IBMBluemix provides information about the current SDK level and access to service plugins.
 */
@interface IBMBluemix : NSObject

#pragma mark SDK Initialization API
/** This must be the first method called.  It initializes the SDK framework.
 
 @param applicationId The IBM Mobile Cloud Services application's ID
 @param applicationSecret The IBM Mobile Cloud Services application's secret
 @param applicationRoute  The IBM Mobile Cloud Services application's route
 */
+(void) initializeWithApplicationId: (NSString*) applicationId andApplicationSecret: (NSString*) applicationSecret andApplicationRoute: (NSString*) applicationRoute;

/**
 Sets the security token and the provider used to obtain and validate it.  The token will be validated and decoded on the MAS service. 
 @param provider The security provider used to obtain and validate the token
 @param token The user's security token received from the provider
 @return A BFTask that will indicate the status of the authentication.
 */
+(BFTask*) setSecurityToken: (NSString *) token fromProvider: (IBMSecurityProvider) provider;

/**
  Resets the security context to nil
 */
+(BFTask*) clearSecurityToken;

/**
 The current version of the Bluemix SDK
 @return The SDK version. Format vMajor.Minor.Service.Qualifier

 */
+(NSString*) version;

/**
 @return The current user that is logged in (if any)
 */
+(IBMCurrentUser*) currentUser;

/**
 @return The current device using the SDK.
 */
+(IBMCurrentDevice*) currentDevice;


@end
