//
//  main.m
//  SimpleDemo
//
//  Created by jiaquan on 2024/9/15.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int sum(int a, int b) {
    return a + b;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        int a = 0;
        NSInteger a1 = 0;
        NSLog(@"result is %ld", (long)a1);
        
        float b = 0.3;
        CGFloat b1 = 0.3;
        NSLog(@"result2 is %.2f", b1);
        
        // string,  char
        NSString *str = @"Hello";
        NSLog(@"result3 is %@", str);
        
//        char scores[2] = {'a', 'b'};
        NSArray *arr = [NSArray arrayWithObjects:@"mother", @"father", nil];
        NSArray *arr2 = @[@"mother", @"father"];
        NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:@"Jack", @"name1",
                              @"Rose", @"name2", nil];
        NSDictionary *dict2 = @{@"name1" : @"Jack",
                                @"name2" : @"Rose"
                                };
        
        // while, do...while   for
//        for (NSInteger i = 0; i < arr2.count; i++) {
//            NSLog(@"element is %@", arr2[i]);
//        }
        for (NSString *element in arr2) {
            NSLog(@"element is %@", element);
        }
     
        NSLog(@"Sum Result is %d", sum(1, 2));
    }
    return 0;
}
