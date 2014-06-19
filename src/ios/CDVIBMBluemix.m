//
//  CDVIBMBluemix.m
//  IBMBluemix_Cordova_IOS
//
//  JJ-TODO : license header for publishing
//
//

#import "CDVIBMBluemix.h"

// IBMSecurityProvider strings
#define PROVIDER_GOOGLE    @"GOOGLE"
#define PROVIDER_WORKLIGHT @"WORKLIGHT"

// JSON representations for JS
#define JSON_VERSION       @"{version:%@}"
#define JSON_CURRENTUSER   @"{uuid:%@,securityProvider:%@,securityToken:%@}"
#define JSON_CURRENTDEVICE @"{hardwareId:%@,model:%@,platform:%@,platformVersion:%@,name:%@}"

@implementation CDVIBMBluemix

- (void)initialize:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* result = nil;
    NSString* applicationId = [command.arguments objectAtIndex:0];
    NSString* applicationRoute = [command.arguments objectAtIndex:1];
    NSString* applicationSecret = [command.arguments objectAtIndex:2];
    
    if (applicationId != nil && [applicationId length] > 0) {
        __weak CDVIBMBluemix* weak_self = self;
        [[IBMBluemix initializeWithApplicationId: applicationId
                             andApplicationRoute: applicationRoute
                            andApplicationSecret: applicationSecret] continueWithBlock:^id(BFTask *task) {
            if (task.error){
                CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
                [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
            } else {
                CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK ];
                [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
            }
            return nil;
        }];
    } else {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"The application id to initialize is not specified."];
    }
    
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)setSecurityToken:(CDVInvokedUrlCommand*)command
{
    NSString* token = [command.arguments objectAtIndex:0];
    NSString* providerArg = [command.arguments objectAtIndex:1];
    IBMSecurityProvider provider = IBMSecurityProvider_GOOGLE;  // default
    
    if ([providerArg caseInsensitiveCompare:PROVIDER_WORKLIGHT] == NSOrderedSame){
        provider = IBMSecurityProvider_WORKLIGHT;
    } else {
        provider = IBMSecurityProvider_GOOGLE;
    }
    
    __weak CDVIBMBluemix* weak_self = self;
    [[IBMBluemix setSecurityToken:token fromProvider:provider] continueWithBlock:^id(BFTask *task) {
        if (task.error){
            CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
            [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
        } else {
            CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK ];
            [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
        }
        return nil;
    }];
}

- (void)clearSecurityToken:(CDVInvokedUrlCommand*)command
{
    __weak CDVIBMBluemix* weak_self = self;
    [[IBMBluemix clearSecurityToken] continueWithBlock:^id(BFTask *task){
        if (task.error){
            CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
            [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
        } else {
            CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK ];
            [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
        }
        return nil;
    }];
}

- (void)version:(CDVInvokedUrlCommand*)command
{
    NSString* version = [IBMBluemix version];
    NSString* json = nil;
    
    json = [NSString stringWithFormat:JSON_VERSION,version];
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:json];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
    
}

- (void)currentUser:(CDVInvokedUrlCommand*)command
{
    IBMCurrentUser* user = [IBMBluemix currentUser];
    NSString* securityProvider = nil;
    NSString* json = nil;
    
    switch (user.securityProvider){
        case IBMSecurityProvider_WORKLIGHT:
            json = PROVIDER_WORKLIGHT;
            break;
        case IBMSecurityProvider_GOOGLE:
        default:
            json = PROVIDER_GOOGLE;
            break;
    }
    
    json = [NSString stringWithFormat:JSON_CURRENTUSER,user.uuid,securityProvider,user.securityToken];
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:json];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)currentDevice:(CDVInvokedUrlCommand*)command
{
    IBMCurrentDevice* device = [IBMBluemix currentDevice];
    NSString* json = nil;
    
    json = [NSString stringWithFormat:JSON_CURRENTDEVICE,device.uuid,device.model,device.platform,device.platformVersion,device.name];
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:json];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

@end