//
//  main.m
//  ProtocolDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>
#import "Boss.h"
#import "Staff.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        Boss *boss = [[Boss alloc] init];
        Staff *staff = [[Staff alloc] init];
        boss.delegate = staff;
        [boss askStaffToWork];
    }
    return 0;
}
