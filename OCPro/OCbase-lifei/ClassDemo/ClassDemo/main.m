//
//  main.m
//  ClassDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>
#import "Car.h"
#import "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Car *car = [Car new];
        [car running];
        
        //1、new
        Person *p = [Person new];
        p.name = @"Jack";
        NSLog(@"result: %@", p.name);
        
        //2、alloc init(alloc 分配内存空间，init是初始化对象里面的内容)
        Person *p2 = [[Person alloc] init];
        p2.name = @"Jack";
        NSLog(@"result: %@", p2.name);
        
        Person *p3 = [[Person alloc] initWithName:@"Rose"];
        NSLog(@"result: %@", p3.name);
    }
    return 0;
}
