//
//  BugCls.h
//  JSPatchDemo
//
//  Created by wangyang on 16/7/12.
//  Copyright © 2016年 ocean. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BugCls : NSObject
+ (BugCls*)shared;
+ (void)clsBug;
- (void)bug;
- (void)bug1:(NSString*)msg;
- (void)bug2:(NSString*)msg arg:(NSString*)arg;
- (CGRect)bug3:(NSString*)msg;
@end
