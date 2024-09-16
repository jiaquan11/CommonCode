//
//  Person.h
//  PropertyDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *属性的定义使用@property关键字
 *atomic(原子性：访问属性的时候（写属性的时候）会加锁)
 *nonatomic(非原子性的)
 *assign:(是修饰基本数据类型的)
 *strong:(是用来修饰对象的，而且是强引用)
 *weak:(是用来修饰对象的，而且是弱引用)
 *copy:(就是将原来的内容拷贝一份)
 *默认是存储在栈上面，拷贝是拷贝到堆上面，（NSString,block）
 *readwrite(表明属性是可读可写的)
 *readonly(表明属性是只读的)
 *
 */
@interface Person : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) NSInteger age;
@property (nonatomic, strong) NSArray *hobbies;

@property (nonatomic, assign, readonly) NSInteger PI;
@end

NS_ASSUME_NONNULL_END
