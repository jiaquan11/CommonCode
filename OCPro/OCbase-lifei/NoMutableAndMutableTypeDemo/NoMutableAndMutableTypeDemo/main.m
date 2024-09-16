//
//  main.m
//  NoMutableAndMutableTypeDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        //NSString NSArray  NSDictinary(不可变类型)
        NSString *name = @"Shanghai";
        name = @"Beijing";//两个字符串变量里面的内容都没变，只是指向发生变化
        //NSMutableString NSMutableArray  NSMutableDictionary(可变类型)
        NSMutableArray *arr = [NSMutableArray array];
        [arr addObject:@"Jack"];
        [arr addObject:@"Rose"];
        [arr insertObject:@"Tom" atIndex:0];
        [arr removeObject:@"Tom"];
        [arr removeObjectAtIndex:1];
        [arr removeAllObjects];
        [arr addObjectsFromArray:@[@"1", @"2"]];
        
        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
        [dict setObject:@"Jack" forKey:@"name"];
        [dict removeObjectForKey:@"name"];
    }
    return 0;
}
