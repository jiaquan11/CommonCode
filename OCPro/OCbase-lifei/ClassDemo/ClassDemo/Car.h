//
//  Car.h
//  ClassDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Car : NSObject
@property (nonatomic, copy) NSString *date;
@property (nonatomic, copy) NSString *engineeNo;

- (void)running;

@end

NS_ASSUME_NONNULL_END
