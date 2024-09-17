//
//  Person.h
//  CycleDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 两个类之间循环引用，使用@class,只引用类名，
 不引用全部内容，否则会有问题
 */
@class Dog;
@interface Person : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, weak) Dog *dog;
@end

NS_ASSUME_NONNULL_END
