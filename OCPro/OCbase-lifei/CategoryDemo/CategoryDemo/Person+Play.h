//
//  Person+Play.h
//  CategoryDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import "Person.h"

NS_ASSUME_NONNULL_BEGIN

@interface Person (Play)
@property (nonatomic, assign, readonly) CGFloat money;

- (void)playBasketball;
- (void)playGame;

- (NSArray *)friends;
- (void)setFriends:(NSArray *)friends;
@end

NS_ASSUME_NONNULL_END
