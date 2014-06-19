//-------------------------------------------------------------------------------
// Licensed Materials - Property of IBM
// XXXX-XXX (C) Copyright IBM Corp. 2013,2014. All Rights Reserved.
// US Government Users Restricted Rights - Use, duplication or
// disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//-------------------------------------------------------------------------------


#import <Foundation/Foundation.h>
#import "IBMHttpRequest.h"

/**
 An error class used to report failurs for IBMHttpRequest invocations
 */
@interface IBMHttpError : NSError

/**
 The IBMHttpRequest used to obtain this IBMHttpResponse
 */
@property (readonly, nonatomic) IBMHttpRequest *request;

/**
 The NSError that caused this error (if any)
 */
@property (readonly, nonatomic) NSError *cause;


@end
