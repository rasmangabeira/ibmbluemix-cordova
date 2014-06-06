//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013,2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

@class IBMBaaSService;

/**
IBMHttpRequest contains all the information that is needed in order to invoke an http request to a secured endpoint
*/
@interface IBMHttpRequest : NSObject

/**
  The HTTP method for the request
 */
@property (readonly, nonatomic) NSString* method;

/**
 The target URL for the HTTP request
 */
@property (readonly, nonatomic) NSURL* url;


/**
 The IBMBaaSService making the HTTP request
 */
@property (readonly, nonatomic) IBMBaaSService *service;

/**
 The HTTP request headers
 */
@property (readonly, nonatomic) NSDictionary *headers;

@end
