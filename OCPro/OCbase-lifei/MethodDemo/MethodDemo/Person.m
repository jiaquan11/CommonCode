//
//  Person.m
//  MethodDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import "Person.h"

/**
 1、实例方法与类方法的特点
 实例方法：- 开头(并且是实例调用的)
 类方法： + 开头(并且是类调用的)
 
 2、有哪些特性
 2.1 类方法可以调用类方法
 2.2 实例方法不能调用类方法，但是类方法可以通过创建对象来调用实例方法
 2.3 类方法不能使用属性，因为属性是实例方法使用的
 
 3、实例方法与类方法里面的self的含义
 3.1 实例方法中的self是指向对象的首地址（self:实例）
 3.2 类方法中的self是Class (self：类)
 
 4.类方法创建的对象，需要释放吗？ （因为创建的对象是放在释放池中）
 
 5、实例方法与类方法经常用到
 */
@implementation Person
- (void)running {
    NSLog(@"Person is running");
}

+ (void)eating {
    NSLog(@"Person is eatting.");
    [self sleeping];
    
    [[self alloc] running];
}

+ (void)sleeping {
    NSLog(@"Person is sleeping");
}
@end
