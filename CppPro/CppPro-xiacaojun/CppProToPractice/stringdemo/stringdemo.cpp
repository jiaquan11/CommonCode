#include <iostream>
#include <string>
using namespace std;

int main() {
    //字符串的初始化和赋值
    string str1 = {"hello"};//const char*字面量
    cout << "str1: " << str1 << endl;
    str1 = "world";
    string str2{str1};
    cout << "str2: " << str2 << endl;
    string str3;//string对象默认初始化为空字符串
    str3 = str1;//赋值替换的是内容，不是地址
    cout << "str3: " << str3 << endl;
    //string存放的是字符数组，不是地址
    str1 = "teststring1"; 
    cout << str2 << "\n" << str3 <<"\n" << endl;

    //字符串长度的获取,size()直接读取的是长度，不包括'\0'
    //不是实际占用的内存大小，实际占用的内存大小可能比size()大，会包括'\0'
    string str4 = "hello";
    cout << "str4.size(): " << str4.size() << endl;
    string str5 = "一二三四五";
    cout << "str5.size(): " << str5.size() << endl;

    //截断字符串
    //substr()函数的第一个参数是起始位置，第二个参数是截取的长度
    //返回的是截取的字符串
    cout << "str4.substr(1, 3): " << str4.substr(1, 3) << endl;
    
    //字符串的判断
    string strif;
    //下面三种判断方式都可以，都是等价的，都是判断是否为空字符串
    //字符串判断的是内容，不是地址
    if (strif.empty()) {//判断的是否为空字符串
		cout << "strif is empty" << endl;
	}
    if (strif.size() == 0) {
		cout << "strif.size()==0" << endl;
	}
    if (strif == "") {
        cout << "strif == \"\"" << endl;
    }

    strif = "test";
    if (strif == "test") {
		cout << "test" << endl;
	}
    if (strif != "test2") {
        cout << "!=test2" << endl;
    }
    string strif2 = "if2";
    //判断的是内容，不是地址,如果是const char*,则是比较的是地址
    if (strif == strif2) {//判断的是内容，不是地址
		cout << "strif == strif2" << endl;
	}
}

