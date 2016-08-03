//
//  JPHttp.m
//  JSPatchDemo
//
//  Created by wangyang on 16/7/11.
//  Copyright © 2016年 ocean. All rights reserved.
//

#import "JPHttp.h"
#import <JSPatch/JPEngine.h>
#import <JavaScriptCore/JavaScriptCore.h>

typedef void(^JPHttpBlock)(NSString* result);

@implementation JPHttp
+ (void)main:(JSContext *)context
{
    context[@"httpGet"] = ^(NSString* url) {
        NSLog(url);
    };
}

- (void)httpGetWithUrl:(NSString*)url cb:(JPHttpBlock)callback
{
    
}
@end
