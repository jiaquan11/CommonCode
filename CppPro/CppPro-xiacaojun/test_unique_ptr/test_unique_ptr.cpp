#include <iostream>
#include <memory>

using namespace std;
class Data {
public:
	Data() { cout << "create data\n"; }
	~Data() { cout << "drop data\n"; }
	void Print() { cout << "print data\n"; }
};

class DataPtr {
public:
	DataPtr() = default;//恢复默认构造
	DataPtr(Data* d) { d_ = d; }
	//禁止拷贝构造
	DataPtr(const DataPtr&) = delete;
	//移动时候，不需要拷贝，直接指向新的对象
	DataPtr(DataPtr&& dp) {
		d_ = dp.d_;
		dp.d_ = nullptr;
	}
	//移动赋值，不需要拷贝，直接指向新的对象
	DataPtr& operator= (DataPtr&& dp) {
		if (this == &dp)return *this;
		delete d_;
		d_ = dp.d_;
		dp.d_ = nullptr;
	}
	//禁止赋值拷贝
	DataPtr& operator= (const DataPtr&) = delete;
	~DataPtr() { delete d_; d_ = nullptr; }
	Data* Get() { return d_; }
	Data* Release() {
		auto d = d_;
		d_ = nullptr;
		return d;
	}
	void Reset(Data* d) {
		if (d == d_)return;
		delete d_;
		d_ = d;
	}
private:
	Data* d_{ nullptr };
};

int main() {
	{
		DataPtr ptr1(new Data);
		//限制使用 拷贝构造
		//DataPtr(const DataPtr& ) = delete;
		//DataPtr ptr2 = ptr1;//拷贝构造
		DataPtr ptr3;
		//限制赋值 
		//DataPtr& operator= (const DataPtr &) = delete;
		//ptr3 = ptr1;//赋值
		ptr1.Get()->Print();
		ptr1.Reset(new Data);
		auto p = ptr1.Release();
		p->Print();
		delete p;
		DataPtr ptr4 = move(ptr1);
		ptr4.Get()->Print();
		DataPtr ptr5;
		ptr5 = move(ptr4);
	}
	getchar();
	{
		//一 创建智能指针
		unique_ptr<Data> ptr1(new Data);
		//c++14 支持，尽量用make_unique
		//1 编译器产生更小更快的代码
		//2 减少重复类型设置
		//3 内存安全
		auto ptr2 = make_unique<Data>();

		//二 智能指针使用
		ptr2->Print();
		(*ptr2).Print();
		auto ptr2_ptr = ptr2.get();
		ptr2_ptr->Print();

		//三 智能指针修改
		auto ptr3 = make_unique<Data>();
		ptr3.reset(new Data);//释放原有空间
		ptr3.reset(nullptr);//释放空间
		{
			auto ptr4 = make_unique<Data>();
			//释放控制权
			auto ptr4_ptr = ptr4.release();
			delete ptr4_ptr;
		}
		//智能指针移动
		auto ptr5 = make_unique<Data>();
		unique_ptr<Data> ptr6 = move(ptr5);
		unique_ptr<Data> ptr7;
		ptr7 = move(ptr6);
		cout << "-----------------------" << endl;
	}
}