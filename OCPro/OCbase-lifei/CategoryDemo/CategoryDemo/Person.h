//
//  Person.h
//  CategoryDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject
@property (nonatomic, copy) NSString *firstName;
@property (nonatomic, copy) NSString *lastName;

- (instancetype)initWithFirstName:(NSString *)firstName lastName:(NSString *)lastName;
- (void)playBasketball;
@end

NS_ASSUME_NONNULL_END
