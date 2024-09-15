//
//  main.m
//  ArrayAndDictionaryDemo
//
//  Created by jiaquan on 2024/9/15.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        //1.创建数组
        //1.1 实例化创建
        NSArray *arr1 = [[NSArray alloc] initWithObjects:@"Jack", @"Rose", nil];
        //1.2 类方法创建
        NSArray *arr2 = [NSArray arrayWithObjects:@"Jack", @"Rose", nil];
        //1.3 语法糖
        NSArray *arr3 = @[@"Jack", @"Rose", @"Tony"];
        
        //2.索引元素
        NSString *name1 = arr3[1];
        //数组元素的个数
//        arr3.count;
//        arr3.firstObject;
//        arr3[arr3.count -1];
//        arr3.lastObject;
        
        //3、数组元素的位置
        NSUInteger index = [arr3 indexOfObject:@"Tony"];
        NSLog(@"the index of Tony is %lu", (unsigned long)index);
        
        //字典(key - value)
        NSDictionary *dict = @{
            @"name" : @"Jack",
            @"address" : @"Shanghai"
        };
        //取值
        NSString *name2 = dict[@"name"];
        NSString *name3 = [dict objectForKey:@"name"];
        
        //获取所有的key或者所有的value
//        dict.allKeys;
//        dict.allValues;
        //说明一点：OC中的数组和字典里面的元素必须是对象（不能是基本数据类型）
//        NSArray *arr3 = @[3, 5];//错误
    }
    return 0;
}
