//
//  Father.m
//  SelfAndSuperDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import "Father.h"

@implementation Father
+ (void)thinking {
//    [[self alloc] init];
    [self test2];
//    [self fishing];//无法调用实例方法
//    self.name;//无法使用实例属性
}

+ (void)test2 {
    NSLog(@"this is class method");
}

- (void)fishing {
    NSLog(@"Father is fishing");
}
@end
