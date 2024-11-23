#include <iostream>
#include <vector>
#include <string>
using namespace std;
//测试拷贝构造函数
//自定义字符串类String
class String {
public:
	~String() {
		cout << "Drop String:" << size_ << endl;
		delete str_;
		str_ = nullptr;
		size_ = 0;
	}

	String(const char* str = "") {
		cout << "Create String:" << str << endl;
		size_ = strlen(str);
		if (size_ == 0) {
			return;
		}
		str_ = new char[size_ + 1]; //+1存储\0
		memcpy(str_, str, size_ + 1);
	}
	//拷贝构造函数
	String(const String& s) {
		cout << "Copy String:" << s.str_ << endl;
		size_ = s.size_;
		str_ = new char[size_ + 1];
		memcpy(str_, s.str_, size_ + 1);
	}

	//移动构造函数，右值引用，不会调用拷贝构造函数，
	//不需拷贝内存，直接移动，提高效率
	String(String&& s) {
		cout << "Move String:" << s.str_ << endl;
		size_ = s.size_;
		str_ = s.str_;
		s.size_ = 0;
		s.str_ = nullptr;
	}

	//赋值运算符重载
	String& operator=(const String& s) {
		cout << "Assign String:" << s.str_ << endl;
		if (this == &s) {
			return *this;
		}
		delete str_;
		size_ = s.size_;
		str_ = new char[size_ + 1];
		memcpy(str_, s.str_, size_ + 1);
		return *this;
	}

	//移动赋值运算符重载
	String& operator=(String&& s) {
		cout << "Move Assign String:" << s.str_ << endl;
		if (this == &s) {
			return *this;
		}
		delete str_;
		size_ = s.size_;
		str_ = s.str_;
		s.size_ = 0;
		s.str_ = nullptr;
		return *this;
	}

	const char* c_str() {
		if (!str_)return "";
		return str_;
	}
private:
	char* str_{ nullptr };
	int size_{ 0 };
};

void TestString(String s) { //函数栈区变量
	cout << "TestString:" << s.c_str() << endl;
}

void TestStringRef(String& s) {//函数栈区变量
	cout << "TestStringRef:" << s.c_str() << endl;
}

class MyString {
public:
	MyString(String& str) :
		str_(str) {

	}
private:
	String str_;
};

class Data {
public:
	Data() {
		cout << "Create Data" << endl;
	}
	Data(const Data& d) {
		cout << "Copy Data" << endl;
	}
	~Data() {
		cout << "Drop Data:" << endl;
	}
};

void TestData(vector<Data> datas) {

}

int main() {
	{
		String str1;
		String str2{ "test string 002" };
		str1 = str2;//赋值运算符重载
		str1 = move(str2);//移动赋值运算符重载

		Data d1;
		Data d2;
		d2 = d1;//d1的内存复制到d2,不会调用拷贝构造函数
	}

	getchar();
	{
		String str1("Test String 001");
		String str2 = str1;//对象初始化，调用拷贝构造函数
		cout << "str1= " << str1.c_str() << endl;
		cout << "str2= " << str2.c_str() << endl;
		String str3{ move(str2) };//str2的堆内存移动到str3,不会调用拷贝构造函数,str2内部没有数据和内存占用
		cout << "str1= " << str1.c_str() << endl;
		cout << "str2= " << str2.c_str() << endl;
		cout << "str3= " << str3.c_str() << endl;
	}

	getchar();

	{
		vector<Data> datas(3);//创建3个Data对象
		TestData(move(datas));//move转移语义,转为右值引用，不会调用拷贝构造函数,
	}

	{
		String str1("Test my String str1 ");
		TestString(str1);//对象初始化，调用拷贝构造函数
		String str2 = str1;//对象初始化，调用拷贝构造函数
		cout << "-------TestStringRef------" << endl;
		TestStringRef(str1);//引用传递，不会调用拷贝构造函数
		cout << "----------------------------" << endl;
		String str3("Test my String str3 ");
		MyString ms{ str3 };
	}

	system("pause");
	return 0;
}

