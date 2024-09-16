//
//  Person.m
//  ClassDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import "Person.h"

@implementation Person

- (void)dealloc {
    NSLog(@"Person is released");
}

- (void)myName {
    NSLog((@"my name is %@", self.name));
}

- (instancetype)initWithName:(NSString *)name {
    if (self = [super init]) {
        self.name = name;
    }
    return self;
}

@end
