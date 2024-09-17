//
//  main.m
//  CycleDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "Dog.h"

/**
 循环引用的原因：就是两方互相强引用
 循环引用的解决方法：
 就是一方弱化（使用weak即可）
 */
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Person *p = [[Person alloc] init];
        Dog *d = [[Dog alloc] init];
        p.name = @"Jack";
        p.dog = d;
        
        d.name = @"旺财";
        d.person = p;
    }
    return 0;
}
