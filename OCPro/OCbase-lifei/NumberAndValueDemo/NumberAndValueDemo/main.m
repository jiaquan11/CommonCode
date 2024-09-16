//
//  main.m
//  NumberAndValueDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
//        NSArray, NSDictionary(元素或者是内容只能是对象形式的，而不能是基本数据类型)
        
//        NSNumber与NSValue
//        NSNumber可以将int float char bool 基本数据类型包装成对象(包装之后的内容，可以成为NSArray
//            NSDictionary的元素)
        int a = 3;
        NSNumber *number = [NSNumber numberWithInt:a];
        NSString *str = @"Jack";
        NSNumber *number2 = @(a);
        NSArray *arr = @[number];
        
        int a2 = [number2 intValue];
        
        //NSValue 可以将结构体进行包装
        //将基本数据类型包装成对象的这个操作叫做装箱
        //将对象里面的内容取出来的操作叫做拆箱
        CGPoint p = CGPointMake(2, 3);
        NSValue* value = [NSValue valueWithPoint:p];
    }
    return 0;
}
