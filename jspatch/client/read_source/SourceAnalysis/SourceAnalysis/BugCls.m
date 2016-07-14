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
        //va_list_test(_shared,2,4,5);
    });
    return _shared;
}

//static void va_list_test(id slf , ...)
//{
//    va_list args;
//    va_start(args, slf);
//    int a = va_arg(args, int);
//    int b = va_arg(args, int);
//    int c = va_arg(args, int);
//    va_end(args);
//}

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
