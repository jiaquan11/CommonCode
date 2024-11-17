#include <iostream>

int main() {
    std::cout << "Hello World!\n";
    //常量的语法
    //运行时常量
    const int a{ 400 };
    //a = 200;//编译错误 常量初始化后不能再修改
    int t1 = 10;
    const int b{t1 + 2};//运行时常量,可以在运行时初始化

    //编译时常量
    constexpr int cx{ 1 };
    //cx = a;//编译错误 常量初始化后不能再修改
    int t2 = 10;
    //constexpr int cy{ t2 + 2 };//报错，编译时常量,必须在编译时初始化
    return 0;
}

