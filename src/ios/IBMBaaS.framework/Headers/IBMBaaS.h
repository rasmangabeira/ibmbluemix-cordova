//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013,2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <IBMBaaS/IBMBaaSService.h>
#import <IBMBaaS/IBMHttpError.h>
#import <IBMBaaS/IBMHttpRequest.h>
#import <IBMBaaS/IBMMutableHttpRequest.h>
#import <IBMBaaS/IBMHttpResponse.h>

typedef enum SecurityProvider{
    GOOGLE, WORKLIGHT
}SecurityProvider;

/**
 IBMBaaS is the entry point for interacting with the MBaaS SDKs. The method initializeSDK must be invoked before any other API calls. IBMBaaS provides information about the current SDK level and access to service plugins. Below is an example of initializing the SDK and using the IBMPluginManager to access a service plugin.
 
 [IBMBaaS initializeSDK: applicationId];
 IBMPush * pushService = [IBMPush initializeService];
 
 */
@interface IBMBaaS : NSObject

#pragma mark SDK Initialization API
/** This must be the first method called.  It initializes the SDK framework.
 * @param applicationId the Mobile Cloud Services Application id
 * @param applicationRoute the Mobile Cloud Service Application route found on BlueMix
 * TODO -- this is JUST FOR NOW -- MUST BE FIXED BEFORE MERGE BACK TO MAIN
 */
+(void) initializeSDK: (NSString*) applicationId withApplicationRoute: (NSString*)applicationRoute;

/**
 Sets the security token and the provider used to obtain and validate it
 @param provider The security provider used to obtain and validate the token
 @param token The user's security token received from the provider
 */
+(void) setSecurityContext: (SecurityProvider) provider withToken: (NSString *) token;

/**
  Resets the security context to nil
 */
+(void) clearSecurityContext;

@end
