//
//  API.h
//  New Saavn
//
//  Created by Clint Balcom on 1/16/18.
//  Copyright © 2018 Saavn. All rights reserved.
//
@import UIKit;
typedef enum
{
    ResponseContentTypeXML,
    ResponseContentTypeHTML,
    ResponseContentTypeJSON,
    ResponseContentTypeDEFAULT,
    ResponseContentTypeNONE
} ResponseContentType;

@class AFHTTPSessionManager;

@interface API : NSObject


#pragma mark - Main Methods
+ (void) GET:(NSString *)method
  withParams:(NSDictionary *)params
 saavnCookie:(BOOL)useCookie
     success:(void(^)(id successResponse))successBlock
  andFailure:(void(^)(NSError *errorResponse))failureBlock;

+ (void) GET:(NSString *)method
  withParams:(NSDictionary *)params
 saavnCookie:(BOOL)useCookie
 dataSampling:(BOOL)sampling
     success:(void(^)(id successResponse))successBlock
  andFailure:(void(^)(NSError *errorResponse))failureBlock;

+ (void) POST:(NSString *)method
   withParams:(NSDictionary *)params
  saavnCookie:(BOOL)useCookie
      success:(void(^)(id successResponse))successBlock
   andFailure:(void(^)(NSError *errorResponse))failureBlock;

+ (void) POSTURL:(NSString *)url
      withParams:(NSDictionary *)params
     saavnCookie:(BOOL)useCookie
         success:(void(^)(id successResponse))successBlock
      andFailure:(void(^)(NSError *errorResponse))failureBlock;


+ (void) GETURL:(NSString *)url
     withParams:(NSDictionary *)params
    saavnCookie:(BOOL)useCookie
   dataSampling:(BOOL)sampling
acceptableContentType:(ResponseContentType)contentType
timeOutInterval:(NSTimeInterval)timeout
        success:(void(^)(id successResponse))successBlock
     andFailure:(void(^)(NSError *errorResponse))failureBlock;

+ (void) GETURL:(NSString *)url
    withParams:(NSDictionary *)params
   saavnCookie:(BOOL)useCookie
  dataSampling:(BOOL)sampling
acceptableContentType:(ResponseContentType)contentType
       success:(void(^)(id successResponse))successBlock
    andFailure:(void(^)(NSError *errorResponse))failureBlock;

+ (void) GETURL:(NSString *)url
  withParams:(NSDictionary *)params
 saavnCookie:(BOOL)useCookie
dataSampling:(BOOL)sampling
     success:(void(^)(id successResponse))successBlock
  andFailure:(void(^)(NSError *errorResponse))failureBlock;

+ (void) requestURL:(NSString *)url
     withParams:(NSDictionary *)params
    saavnCookie:(BOOL)useCookie
   dataSampling:(BOOL)sampling
        success:(void(^)(id successResponse))successBlock
     andFailure:(void(^)(NSError *errorResponse))failureBlock;

#ifndef __SvnSenSDK
+ (void) POSTREQUEST:(NSURLRequest *)request
saavnCookie:(BOOL)useCookie
    success:(void(^)(id successResponse))successBlock
 andFailure:(void(^)(NSError *errorResponse))failureBlock;
#endif

#pragma mark - Getters
+ (NSString *) constructApiRequest:(NSString *)method withParams:(NSDictionary *)params;
+ (void) writeToLogFile:(NSString*)content;

@end

