//
//  IBMHttpResponse.h
//  IBMBaaS
//
//  Created by Kevan Holdaway on 5/9/14.
//  Copyright (c) 2014 International Business Machines. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IBMHttpRequest.h"

/**
 IBMHttpResponse is the result obtained from making an IBMHttpRequest.
 */
@interface IBMHttpResponse : NSObject

/**
 The NSData containing the payload for the HTTP response.
 */
@property (readonly, nonatomic) NSData *responseData;

/**
 The IBMHttpRequest used to obtain this IBMHttpResponse
 */
@property (readonly, nonatomic) IBMHttpRequest *request;

/**
 The NSHTTPURLResponse for this HTTP request.
 */
@property (readonly, nonatomic) NSHTTPURLResponse *httpResponse;


@end
