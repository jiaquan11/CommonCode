//
//  main.m
//  MethodDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        //alloc是类方法，创建了对象，为对象分配内存空间
        //init是实例方法 (初始化对象)
        Person *p = [[Person alloc] init];
        [p running];
        
        [Person eating];
    }
    return 0;
}
