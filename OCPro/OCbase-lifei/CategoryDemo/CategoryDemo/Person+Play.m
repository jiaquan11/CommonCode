//
//  Person+Play.m
//  CategoryDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import "Person+Play.h"
#import <objc/runtime.h>

@implementation Person (Play)

static const char *kFriendsKey = "kFriendsKey";

- (void)playBasketball {
    NSLog(@"Person play basketball");
}

- (void)playGame {
    NSLog(@"Person play game");
}

//这个就是属性money的get方法
- (CGFloat)money {
    return 100;
}

- (NSArray *)friends {
    return objc_getAssociatedObject(self, kFriendsKey);
}

- (void)setFriends:(NSArray *)friends {
    objc_setAssociatedObject(self, kFriendsKey, friends, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
@end
