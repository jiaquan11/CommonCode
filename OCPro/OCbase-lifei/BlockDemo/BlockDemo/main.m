//
//  main.m
//  BlockDemo
//
//  Created by jiaquan on 2024/9/18.
//

#import <Foundation/Foundation.h>
#import "Person.h"

/**
 1、block(块)
 1.1有时候它只是定义在一个函数里面
 1.2用^表示，后面会跟着一对大括号{}
 block在有地方调用它的时候，才会执行里面的代码
 1.3 return_type (^blockName)(parameters),
 函数的定义： return_type methodName(parameters)
 有参数的block
 int (^addBlock)(int a, int b) = ^(int a, int b) {
     return a + b;
 };
 1.4 调用block blockName(parameters)
 1.5 在声明的范围内，所有的变量都可以捕获到
 int additional = 5;
 int (^addBlock)(int a, int b) = ^(int a, int b) {
     return a + b + additional;
 };
 int result = addBlock(3, 4);
 NSLog(@"result is %d: ", result);
 1.6 block 更新值（被更新的值，要使用__block 修饰）
 __block int temp = 10;
 void (^updateBlock)() = ^{
     temp = 12;
 };
 NSLog(@"before update: %d", temp);
 updateBlock();
 NSLog(@"after update: %d", temp);
 
 2、block的作用域
 2.1 block默认是分配在栈上面的
 2.2 为了解决block在栈上面释放的问题，出现了copy关键字
 copy的目的就是将block从栈上面，复制到堆上面，然后复制完之后的block就是对象了
 
 3、使用typedef简化block的定义，注意点就是用typedef定义的block，名称首字母大写
 typedef void (^MyBlock) (NSString *name);
 使用的时候
 @property (nonatomic, copy) MyBlock myBlock;
 
 4、block的循环引用问题
 */
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        void (^myBlock)(void) = ^{
            NSLog(@"it is a block");
        };
        //调用block
        myBlock();
        
        int additional = 5;
        int (^addBlock)(int a, int b) = ^(int a, int b) {
            return a + b + additional;
        };
        int result = addBlock(3, 4);
        NSLog(@"result is %d: ", result);
        
        __block int temp = 10;
        void (^updateBlock)(void) = ^{
            temp = 12;
        };
        NSLog(@"before update: %d", temp);
        updateBlock();
        NSLog(@"after update: %d", temp);
        
        ///////////////////////////
        int a = 3;
        int b = 4;
        void (^testBlock)(void);
        if (a < b) {
            testBlock = [^{
                NSLog(@"Block A");
            } copy];
        }else {
            testBlock = [^{
                NSLog(@"Block B");
            } copy];
        }
        testBlock();
        
        ////////////////////////////////////////
        Person *p = [[Person alloc] init];
        p.myBlock = ^(NSString *name) {
          
        };
    }
    return 0;
}
