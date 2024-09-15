//
//  main.m
//  StringDemo
//
//  Created by jiaquan on 2024/9/15.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        //1、字符串创建
        NSString *str1 = @"Jack";
        NSString *str2;//默认值是nil
        str2 = @"Rose";
        //2、格式化字符串(拼接字符串)
//        NSString *str3 = concat(str1, str2);
//        NSString *str3 = str1 + str2;//错误
        NSString *str3 = [NSString stringWithFormat:@"My name is %@", str2];
        
        //3、包含字符串的判断
        NSString *str4 = @"I Love Shanghai";
        //YES(1) / NO(0)
        BOOL prefix = [str4 hasPrefix:@"I"];
        NSLog(@"str4 has prefix I? %d", prefix);
        BOOL suffix = [str4 hasSuffix:@"Shanghai"];
        NSLog(@"str4 has suffix Shanghai? %d", suffix);
        NSRange result = [str4 rangeOfString:@"ang"];
        NSLog(@"str4 contains 'ang', location is %lu, length is %lu", (unsigned long)result.location, (unsigned long)result.length);
        
        //4、字符串的比较
        //4.1 值得比较
        NSString *str5 = @"One1";
        NSString *str6 = @"One2";
        BOOL result1 = [str5 isEqualToString:str6];
        NSLog(@"result1: %d", result1);
        //4.2 排序的比较(-1:升序 0:相等  1:降序)
        NSComparisonResult result2 = [str5 compare:str6];
        NSLog(@"Comparison result is %d", result2);
        //不区分大小写的比较
        [str5 caseInsensitiveCompare:str6];
        
        //5、大小写
        NSString *str7 = @"i am a boy";
        //大写
        [str7 uppercaseString];
        //小写
        [str7 lowercaseString];
        //首字母大写
        [str7 capitalizedString];
        
        //6、字符串替换
        NSString *newStr = [str7 stringByReplacingOccurrencesOfString:@"boy" withString:@"girl"];
        NSLog(@"new string is %@", newStr);
        
        //7、字符串的分割与串接
        NSString *str8 = @"I am a student";
        NSArray *arr = [str8 componentsSeparatedByString:@" "];
        NSString *str9 = [arr componentsJoinedByString:@"_"];
        NSLog(str9);
        
        //8、字符串的提取
        NSString *str10 = @"I am a student";
        //substringToIndex 截取0-3的字符串
        NSString *strTo = [str10 substringToIndex:3];
        //substringFromIndex 截取5-最后的字符串
        NSString *strFrom = [str10 substringFromIndex:5];
        //substringWithRange 截取指定位置的字符串
        NSString *strRange = [str10 substringWithRange:NSMakeRange(4, 3)];
        NSLog(@"Final Result is to: %@, from: %@, range:%@",
              strTo, strFrom, strRange);
    }
    return 0;
}
