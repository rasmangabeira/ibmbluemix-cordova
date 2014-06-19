//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013,2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------


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