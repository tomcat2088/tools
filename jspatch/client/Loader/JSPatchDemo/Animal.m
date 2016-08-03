//
//  Animal.m
//  JSPatchDemo
//
//  Created by wangyang on 16/6/29.
//  Copyright © 2016年 wangyang. All rights reserved.
//

#import "Animal.h"

@implementation Animal
+ (void)main:(JSContext *)context
{
    context[@"dog_say"] = ^(NSString *classDeclaration, JSValue *instanceMethods, JSValue *classMethods){
        return [Animal new];
    };
}

- (void)freeze
{
    NSLog(@"freeze");
}
@end
