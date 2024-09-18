//
//  Person.h
//  BlockDemo
//
//  Created by jiaquan on 2024/9/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^MyBlock) (NSString *name);

@interface Person : NSObject
@property (nonatomic, copy) MyBlock myBlock;
@end

NS_ASSUME_NONNULL_END
