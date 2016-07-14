//
//  BugCls.m
//  JSPatchDemo
//
//  Created by wangyang on 16/7/12.
//  Copyright © 2016年 ocean. All rights reserved.
//

#import "BugCls.h"
#import <UIKit/UIKit.h>

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

- (void)bug
{
    NSLog(@"bug");
}

- (void)bug1:(NSString*)msg
{
    NSLog(@"bug1 %@",msg);
}

- (void)bug2:(NSString*)msg arg:(NSString*)arg
{
    NSLog(@"bug2 %@ - arg:%@",msg,arg);
}

- (CGRect)bug3:(NSString*)msg
{
    return CGRectMake(0, 0, 0, 0);
}
@end
