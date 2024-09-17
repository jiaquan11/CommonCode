//
//  main.m
//  InheritDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>
#import "Son.h"

/**
 类（封装，继承）
 封装（属性，方法）
 继承：
 1、NSObject是所有类的基类（最原始的那个类，所有类最终都继承自它）
 2、OC中的继承是使用冒号来体现的
 3、子类可以继承父类的属性
 4、子类可以继承父类的方法
 5、子类不可以继承父类的成员变量
 6、子类不可以继承父类的.m文件【匿名分类】中的属性
 7、子类和父类有相同的方法，子类会重写父类的方法
 为什么使用继承
 */
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Son *son = [[Son alloc] init];
        son.money = 30;
        [son learning];
//        son->experience;//父类的私有成员不可以继承访问
    }
    return 0;
}
