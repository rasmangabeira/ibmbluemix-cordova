//
//  IBMMutableHttpRequest.h
//  IBMBaaS
//
//  Created by Kevan Holdaway on 5/9/14.
//  Copyright (c) 2014 International Business Machines. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBMBaaSService.h"
#import "BFTask.h"

/**
 IBMMutableHttpRequest provides the ability to configure and make HTTP requests.
 */
@interface IBMMutableHttpRequest : NSObject

/**
 The HTTP method for the request
 */
@property (nonatomic, copy) NSString* method;

/**
 The URI relative to the baseUrl for the HTTP request
 */
@property (nonatomic, copy) NSURL *url;

/**
 The IBMBaaSService making the HTTP request
 */
@property (nonatomic) IBMBaaSService *service;

/** 
 The data to be sent in the request (if applicable).  Use by POST/PUT
 */
@property (nonatomic, copy) NSData* contentStreamData;

/**
 The timeout for the HTTP request
 */
@property (nonatomic) NSTimeInterval timeout;

/**
The HTTP cache policy for the request.
 */
@property (nonatomic) NSURLRequestCachePolicy requestCachePolicy;

/**
 Make the HTTP request
 */
-(BFTask*) sendRequest;

/**
 @param service The IBMBaaSService that will be making HTTP requests.
 @return The newly created IBMMutableHttpRequest
 */
-(id) initWithService: (IBMBaaSService*) service;

/**
 Adds an HTTP header.  If the header name exists, it will be converted in a comma separated list.
 @param name The name of the header to add
 @param value The value of the header to add
 */
-(void) addHeaderWithName: (NSString*) name andValue: (NSString*) value;

/**
 Removes the HTTP header from the request.
 @param name The name of the header to remove
 */
-(void) removeHeaderWithName: (NSString*) name;

/**
 Sets an HTTP header.  If the header name is already present, it will replace the current header value.
 @param name The name of the header to set
 @param value The name of the value to set
 */
-(void) setHeaderWithName: (NSString*) name andValue: (NSString*) value;

@end
