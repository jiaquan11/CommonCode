//
//  Dog.h
//  CycleDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class Person;
@interface Dog : NSObject
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) Person *person;
@end

NS_ASSUME_NONNULL_END
