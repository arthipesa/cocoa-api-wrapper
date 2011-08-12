/*
 * Copyright 2010, 2011 nxtbgthng for SoundCloud Ltd.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *
 * For more information and documentation refer to
 * http://soundcloud.com/api
 * 
 */

#import <Foundation/Foundation.h>

typedef void(^SCRequestResponseHandler)(NSURLResponse *response, NSData *responseData, NSError *error);
typedef void(^SCRequestSendingProgressHandler)(unsigned long long bytesSend, unsigned long long bytesTotal);

enum SCRequestMethod {
    SCRequestMethodGET = 0,
    SCRequestMethodPOST,
    SCRequestMethodPUT,
    SCRequestMethodDELETE
};
typedef enum SCRequestMethod SCRequestMethod;

@class NXOAuth2Request;
@class SCAccount;

@interface SCRequest : NSObject {
@private
    NXOAuth2Request *oauthRequest;
}

#pragma mark Class Methods

+ (id)   performMethod:(SCRequestMethod)aMethod
            onResource:(NSURL *)resource
       usingParameters:(NSDictionary *)parameters
           withAccount:(SCAccount *)account
sendingProgressHandler:(SCRequestSendingProgressHandler)progressHandler
       responseHandler:(SCRequestResponseHandler)responseHandler;

+ (void)cancelRequest:(id)request;

+ (SCRequest *)request;

#pragma mark Accessors

@property (nonatomic, readwrite, retain) SCAccount *account;

@property (nonatomic, assign) SCRequestMethod requestMethod;
@property (nonatomic, readwrite, retain) NSURL *resource;
@property (nonatomic, readwrite, retain) NSDictionary *parameters;


#pragma mark Signed NSURLRequest

- (NSURLRequest *)signedRequest;

#pragma mark Perform Request

- (void)performRequestWithSendingProgressHandler:(SCRequestSendingProgressHandler)aSendingProgressHandler
                                 responseHandler:(SCRequestResponseHandler)aResponseHandler;

#pragma Cancel Request

- (void)cancel;

@end
