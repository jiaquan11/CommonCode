//
//  Boss.h
//  ProtocolDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 1、协议：双方遵守的约定（劳动合同）【在OC中的体现就是一系列方法】
 协议的定义是@protocol
 <NSObject>表示一个协议，协议在OC中是使用<>
 协议的命名是类名+Delegate
 里面会定义一系列的条款（方法），必须遵守（@required）
 和非必须遵守的（@optional）
 可以被多个类遵循
 协议的实现只能在类的声明上，不能在类的实现上
 协议中最好不要定义属性和成员变量
 
 2、委托：就是制定协议的甲方（公司）
 Boss:NSObject(是一个类)
 委托里面会有一个代理属性 delegate
 3、代理：就是遵循协议的乙方（员工）
 Staff
 
 一个类可以遵循多个协议（一个人有多份工作）
 */
@protocol BossDelegate <NSObject>
@required
- (void)developiOS;
@optional
- (void)scanWeb;
@end

@interface Boss : NSObject
@property (nonatomic, weak) id<BossDelegate> delegate;
- (void)askStaffToWork;
@end

NS_ASSUME_NONNULL_END
