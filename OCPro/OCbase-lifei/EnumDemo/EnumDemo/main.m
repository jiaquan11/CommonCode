//
//  main.m
//  EnumDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, Season) {
    SeasonSpring = 2,
    SeasonSummer,
    SeasonAutumn,
    SeasonWinter
};

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Season season;
        switch (season) {
        case SeasonSpring:
            break;
        case SeasonSummer:
            break;
        case SeasonAutumn:
            
            break;
        case SeasonWinter:
            
            break;
        }
    }
    return 0;
}
