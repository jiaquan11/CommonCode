//
//  Boss.m
//  ProtocolDemo
//
//  Created by jiaquan on 2024/9/17.
//

#import "Boss.h"

@implementation Boss
- (void)askStaffToWork {
    if ([self.delegate respondsToSelector:@selector(developiOS)]) {
        [self.delegate developiOS];
    }
}
@end
