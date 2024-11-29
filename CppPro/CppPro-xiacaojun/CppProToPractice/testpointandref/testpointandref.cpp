#include <iostream>

using namespace std;
int main() {
    int x{10};
    cout << "------------x------------" << endl;
    cout << x << endl;//值
    cout << &x << endl;//打印指针
    //定义指针变量
    int* p{ &x };//p存放了x的内存地址，指针就是内存地址
    cout << "------------p------------" << endl;
    cout << *p << endl;//存放内存地址中的值x
    cout << p << endl;//存放的指针&x
    cout << &p << endl;//指针变量p本身也在栈区分配内存
    (*p)++;
    cout << "(*p)++ x = " << x << endl;
    cout << "*p = " << *p << endl;

    /**
     * 引用区别指针
     * 定义时有特定语法，使用时和普通变量一样
     * 定义时必须初始化
     * 定义后不可改为引用其它变量
     */
    //引用  别名，引用本身不占用内存
    int& ref{ x };//必须初始化
    cout << "------------ref------------" << endl;
    cout << ref << endl;
    cout << &ref << endl;//引用本身不占用内存
    ref++;
    cout << "ref++ x = " << x << endl;

    system("pause");
}
