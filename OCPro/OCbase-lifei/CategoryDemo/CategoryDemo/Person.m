//
//  Person.m
//  CategoryDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import "Person.h"

@interface Person()
@property (nonatomic, assign) NSInteger age;//私有的
@end

@implementation Person
- (instancetype)initWithFirstName:(NSString *)firstName lastName:(NSString *)lastName {
    if (self = [super init]) {
        self.firstName = firstName;
        self.lastName = lastName;
    }
    return self;
}

- (void)playBasketball {
    NSLog(@"origin play basketball");
}

@end
