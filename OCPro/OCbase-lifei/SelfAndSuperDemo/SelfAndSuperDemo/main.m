//
//  main.m
//  SelfAndSuperDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>

/**
 self and super
 self:
 1、类方法中的self
 self 是指的类名（而且在程序运行过程中有且仅有一个类对象[Father]）
 在类方法中可以使用self调用其他的类方法
 在类方法中不能调用实例方法和属性
 
 2、实例方法中的self
 self是指的实例
 self可以调用本类中的其他实例方法
 self可以访问属性
 
 super:
 如果是+号方法，super代表的是父类的类名
 如果是-号方法，super代表的是父类的实例
 子类可以重写父类的方法或者属性
 */
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
