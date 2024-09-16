//
//  main.m
//  KVCAndKVODemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "PersonObserver.h"

/**
 KVC(key-value coding)
 一般是幕后操作
 1、字典中使用KVC
 [dict setValue:@"Rose" forKey:@"name2"];
 2、对象中的属性使用KVC
 [p setValue:@(20) forKey:@"age"];
 
 KVO（key-value observer）
 */
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
//        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
//        //1、直接赋值的方式
//        dict[@"name"] = @"Jack";
//        //2、使用KVC赋值
//        [dict setValue:@"Rose" forKey:@"name2"];
        
        Person *p = [[Person alloc] init];
        p.name = @"Jimmy";
//        [p setValue:@(20) forKey:@"age"];
        
        PersonObserver *observer = [[PersonObserver alloc] init];
        [p addObserver:observer forKeyPath:@"name" options:NSKeyValueObservingOptionOld |
               NSKeyValueObservingOptionNew
               context:@"external"];
        p.name = @"Rose";
        [p removeObserver:observer forKeyPath:@"name"];
    }
    return 0;
}
