//
//  main.m
//  CategoryDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "Person+Play.h"
/**
 1、类别（分类 Category）
 一个类中的功能有可能太多，此时我们可以根据逻辑等将类分开,
 不改变已有类的结构
 2、分类新建好之后，文件名是Person+Play（类名+分类名）
 分类的名称Person(Play) 类名（分类名）
 3、分类的原理
 分类中的方法是运行期才加载的，运行期系统会将分类中的方法加入到类的方法列表中.
 如果分类的方法和原来类的方法一摸一样会出现什么问题？
 分类方法会覆盖掉原来类中的方法。
 4、分类中能不能定义属性，要不要在分类中定义属性呢？
 分类中定义属性，编译不报错
 分类中定义属性，运行的时候，如果使用到了这个分类，会Crash
 ！！！分类中无法向类中新增成员变量，那么就没有办法把实习属性的实例变量合成起来
 _money = XXX;//报错
 
 5、分类中可以定义只读属性，只读属性在运行的时候也使用正常.
 6、一个特殊的分类
 直接在.m文件里面定义如下：
 @interface Person()
 
 @end
 这个分类的名称叫做class-continuation(延续类别)
 这个分类 名称（匿名）
 它的作用就是不要对外公布，仅供本类中使用（延续类别的意义）
 
 7、模拟分类中的属性
 - (NSArray *)friends {
     return objc_getAssociatedObject(self, kFriendsKey);
 }
 - (void)setFriends:(NSArray *)friends {
     objc_setAssociatedObject(self, kFriendsKey, friends, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
 }
 */
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Person *p = [[Person alloc] init];
//        p.age;//无法使用，因为age是私有的
        [p playBasketball];
        [p playGame];
        
//        p.money =100;//运行报错
        NSLog(@"money is %f", p.money);
        
        p.friends = @[@"Jack", @"Rose"];
        for (NSString *friend in p.friends) {
            NSLog(@"friend is %@", friend);
        }
    }
    return 0;
}
