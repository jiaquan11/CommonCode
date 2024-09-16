//
//  main.m
//  EmptyDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        /**
         * ARC & MRC
         * ARC: Auto reference counting
         * 内存操作或者管理由系统处理
         * MRC：Mannuly reference counting
         * 需要程序员手动管理内存
         *
         *一、nil(空对象)
         *1、nil:系统将一块内存释放掉，那么arr的值就是nil
         *2、OC情况下，NSArray 与 NSDictionary中的元素不能是nil(会crash)
         *二、NSNull (值为空的对象)
         *NSNull是一个类型（NSArray与NSDictionary)
         *NSArray 与 NSDictionary中的元素不能是nil,但是可以使用NSNull来代替
         */
        
        NSNull *instanceNull = [NSNull null];
        NSArray *arr = @[@"1", instanceNull];
        
        //实际经验：在开发过程中，后端有可能返回的数据是nil,会出现问题，这个时候，我们可以将其转换为NSNull
        //来处理
        NSString *json = @"{\"name\" : \"jack\", \"address\" : nil}";
        
        //NULL 对应C语言中的空指针（OC里面就是nil）
        int *p = NULL;
    }
    return 0;
}
