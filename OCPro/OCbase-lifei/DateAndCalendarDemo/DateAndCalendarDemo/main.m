//
//  main.m
//  DateAndCalendarDemo
//
//  Created by jiaquan on 2024/9/16.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        //1、获取当前时间
        NSDate *date = [NSDate date];
        NSLog(@"date is %@", date);
        
        //格式化时间点
        NSString *str = @"2008-08-08 09:10:03";
        NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
        formatter.dateFormat = @"yyyy-MM-dd HH:mm:ss";
        NSDate *date2 = [formatter dateFromString:str];
        NSLog(@"date is %@", date2);
        
        //基准时间
        NSString *timeStampStr = @"1517138144000";
        NSTimeInterval timeStamp = [timeStampStr longLongValue] / 1000.0;
        NSDate *newDate = [NSDate dateWithTimeIntervalSince1970:timeStamp];
        NSLog(@"newDate is %@", newDate);
        
        //日历
        NSCalendar *calendar = [NSCalendar currentCalendar];
        NSInteger day = [calendar component:NSCalendarUnitDay fromDate:newDate];
        NSLog(@"current day is %ld", (long)day);
        
        //时间的比较
        NSComparisonResult result = [date compare:newDate];
    }
    return 0;
}
