//
//  main.m
//  ForDemo
//
//  Created by jiaquan on 2024/9/15.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        NSArray *items = @[@"Jack", @"Rose", @"Tom"];
        //1、for
        for (NSInteger i = 0; i < items.count; i++) {
            NSLog(@"Each item is %@", items[i]);
        }
        //2、for in
        for (NSString *item in items) {
            NSLog(@"for in Each item is %@", item);
        }
        //3.enumerate
        [items enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            NSLog(@"item: %@, index:%lu", obj, (unsigned long)idx);
        }];
        
        NSDictionary *dict = @{
            @"name" : @"Jack",
            @"address" : @"Shanghai"
        };
        for (NSString *key in dict) {
            NSLog(@"Dict key: %@, value: %@", key, dict[key]);
        }
        
        [dict enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
            
        }];
    }
    return 0;
}
