//
//  IBMHttpError.h
//  IBMBaaS
//
//  Created by Kevan Holdaway on 5/9/14.
//  Copyright (c) 2014 International Business Machines. All rights reserved.
//

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
