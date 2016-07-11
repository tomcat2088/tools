//
//  ClassCollector.m
//  Performance
//
//  Created by wangyang on 16/7/4.
//  Copyright © 2016年 wangyang. All rights reserved.
//

#import "ClassCollector.h"
#import <UIKit/UIKit.h>
#import <objc/runtime.h>

@implementation ClassCollector
+ (void)load
{
    [self statisticsForClass:[NSObject class]];
    [self statisticsForClass:[UIView class]];
    [self statisticsForClass:[UITableView class]];
}

+ (void)statisticsForClass:(Class)cls
{
    unsigned int methodCount;
    class_copyMethodList(cls, &methodCount);
    
    unsigned int ivarCount;
    class_copyIvarList(cls, &ivarCount);
    
    unsigned int propertyCount;
    class_copyPropertyList(cls, &propertyCount);
    
    NSString* className = NSStringFromClass(cls);
    NSLog(@"%@ has %d methods",className,methodCount);
    NSLog(@"%@ has %d ivars",className,ivarCount);
    NSLog(@"%@ has %d properties",className,propertyCount);
}

+ (void)listMethods:(Class)cls
{
    unsigned int methodCount;
    Method* method = class_copyMethodList(cls, &methodCount);
    for(int i=0;i<methodCount;i++)
    {
        SEL name = method_getName(*method);
        NSLog(@"%@",NSStringFromSelector(name));
        method++;
    }
}
@end
