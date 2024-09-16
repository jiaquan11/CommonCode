//
//  PersonObserver.m
//  KVCAndKVODemo
//
//  Created by jiaquan on 2024/9/16.
//

#import "PersonObserver.h"

@implementation PersonObserver
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    [change enumerateKeysAndObjectsUsingBlock:^(NSKeyValueChangeKey  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        NSLog(@"key:%@, obj:%@", key, obj);
    }];
}
@end
