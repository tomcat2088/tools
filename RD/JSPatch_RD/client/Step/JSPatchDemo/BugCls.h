//
//  BugCls.h
//  JSPatchDemo
//
//  Created by wangyang on 16/7/12.
//  Copyright © 2016年 ocean. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BugCls : NSObject
+ (BugCls*)shared;
- (void)bug:(NSString*)msg msg2:(NSString*)msg2;
@end
