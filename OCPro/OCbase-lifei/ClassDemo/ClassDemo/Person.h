//
//  Person.h
//  ClassDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject
@property (nonatomic, copy) NSString *name;

- (void)myName;
//id:定义的变量可以指向任何内容（不仅仅是对象，而且它是在运行的时候才能最终确定变量的类型）
//instancetype:编译的时候，就已经确定了返回变量的类型，更安全
//- (id)initWithName:(NSString *)name;
- (instancetype)initWithName:(NSString *)name;
@end

NS_ASSUME_NONNULL_END
