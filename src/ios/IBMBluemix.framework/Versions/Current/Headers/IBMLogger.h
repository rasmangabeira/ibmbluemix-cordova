//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013,2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////// INTERNAL IBM CODE - NOT API.  THIS CODE SHOULD BE USED WITH CAUTION AS IT CAN AND WILL CHANGE WITHOUT PUBLIC NOTICE ///////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#import <Foundation/Foundation.h>

@interface IBMLogger : NSObject

+(void) logError: (NSString *)format;
+(void) logWarning: (NSString*) format;
+(void) logInfo: (NSString *)format;
+(void) logTrace: (NSString*) format;
+(void) logDebug: (NSString*) format;
+(void) log: (NSString*) category withMessage: (NSString*) message;


+(void) logErrorWithFormat: (NSString *)format, ...;
+(void) logWarningWithFormat: (NSString*) format, ...;
+(void) logInfoWithFormat: (NSString *)format, ...;
+(void) logTraceWithFormat: (NSString*) format, ...;
+(void) logDebugWithFormat: (NSString*) format, ...;
+(void) log: (NSString*) category withFormat: (NSString*) format, ...;

+(void) addLogCategory: (NSString*) category;
+(void) removeLogCategory: (NSString*) category; 

@end