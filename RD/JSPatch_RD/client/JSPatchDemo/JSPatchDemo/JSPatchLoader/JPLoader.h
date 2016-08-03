//
//  JSPatch.h
//  JSPatch
//
//  Created by bang on 15/11/14.
//  Copyright (c) 2015 bang. All rights reserved.
//

#import <Foundation/Foundation.h>

const static NSString *rootUrl = @"http://127.0.0.1:7777";
static NSString *publicKey = @"-----BEGIN PUBLIC KEY-----\nMIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCzo2Cm3ZsIjIV7d5Jyo+AZ2nOe\nlVaMTZ+YthEt3QLWq4kM7PIF0WvtuC4K7EdRTwElvIwCrK2jnGIEZbZ+KsS2G68M\nT1SWL6Jw05ogEi2uNPFYZf/7csIFaL4Qf+HNFSq1bj3L9pSp78ICaUJ1uKh2Ni5d\nQY4/rQkaE8d1pE7AtQIDAQAB\n-----END PUBLIC KEY-----";

typedef void (^JPUpdateCallback)(NSError *error);

typedef enum {
    JPUpdateErrorUnzipFailed = -1001,
    JPUpdateErrorVerifyFailed = -1002,
} JPUpdateError;

@interface JPLoader : NSObject
+ (BOOL)run;
+ (void)updateToVersion:(NSInteger)version callback:(JPUpdateCallback)callback;
+ (void)runTestScriptInBundle;
+ (void)setLogger:(void(^)(NSString *log))logger;
+ (NSInteger)currentVersion;
@end