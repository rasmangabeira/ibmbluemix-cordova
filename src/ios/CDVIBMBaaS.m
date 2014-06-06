//
//  CDVIBMBaaS.m
//  IBMBaaS_Cordova_IOS
//
//  Created by Ramakrishna Boggarapu on 3/27/14.
//
//

#import "CDVIBMBaaS.h"


@implementation CDVIBMBaaS

- (void)initializeSDK:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* result = nil;
    NSString* applicationId = [command.arguments objectAtIndex:0];
    
    if (applicationId != nil && [applicationId length] > 0) {
        [IBMBaaS initializeSDK: applicationId];
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK ];
        
    } else {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"The application id to initialize is not specified."];
    }
    
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

@end