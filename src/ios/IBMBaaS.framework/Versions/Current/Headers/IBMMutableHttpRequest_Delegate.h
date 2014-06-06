//
//  IBMMutableHttpRequest_Delegate.h
//  IBMBaaS
//
//  Created by Kevan Holdaway on 5/12/14.
//  Copyright (c) 2014 International Business Machines. All rights reserved.
//

#import <IBMBaaS/IBMMutableHttpRequest.h>


@interface IBMMutableHttpRequest ()

/**
 Temporary workaround to avoid major re-write.  This is not API and will likely be removed ASAP.  Do not use this.
 @param delegate - The NSURLConnectionDataDelegate to receive HTTP responses
 @return the NSURLConnection for the request
 */
-(NSURLConnection*) sendRequestWithDelegate: (id<NSURLConnectionDataDelegate>) delegate;

@end
