//
//  BugCls.m
//  JSPatchDemo
//
//  Created by wangyang on 16/7/12.
//  Copyright © 2016年 ocean. All rights reserved.
//

#import "BugCls.h"
#import "MemTestObj.h"
#import <UIKit/UIKit.h>

@implementation BugCls
+ (BugCls*)shared
{
    static BugCls* _shared;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _shared = [BugCls new];
        //[_shared alloc_demo];
    });
    return _shared;
}

- (void)alloc_demo
{
    NSLog(@"alloc_demo start >>>>>>>>");
    id cls = [MemTestObj class];
    
    //MemTestObj* testObj = [MemTestObj alloc];
    
    NSString* allocSelector = @"alloc";
    
//    id memTestObj = [cls performSelector:NSSelectorFromString(allocSelector) withObject:nil];
//    void* pointer = (__bridge void *)(memTestObj);
//    MemTestObj* testObj = (__bridge_transfer MemTestObj*) pointer;
    
    MemTestObj* memTestObj = (MemTestObj*)[cls performSelector:NSSelectorFromString(allocSelector) withObject:nil];
    NSLog(@"alloc_demo finish >>>>>>>>");
}

+ (void)clsBug
{
    NSLog(@"cls bug");
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
