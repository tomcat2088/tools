//
//  BugCls.m
//  JSPatchDemo
//
//  Created by wangyang on 16/7/12.
//  Copyright © 2016年 ocean. All rights reserved.
//

#import "BugCls.h"

@implementation BugCls
+ (BugCls*)shared
{
    static BugCls* _shared;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _shared = [BugCls new];
    });
    return _shared;
}

- (void)bug:(NSString*)msg msg2:(NSString*)msg2
{
    NSLog(@"bug cls");
}
@end
