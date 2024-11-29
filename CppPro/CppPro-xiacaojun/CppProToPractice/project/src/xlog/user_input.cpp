#include "user_input.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

static vector<string> Split(const string& s) {
	vector<string> vec;
	string tmp;
	istringstream is(s);
	while (getline(is, tmp,' ')) {
		if (tmp.empty())
			continue;
		vec.push_back(tmp);
	}
	return vec;
}

void UserInput::Start(std::function<void(std::vector<std::string>)>init) {
	cout << "UserInput::Start()" << endl;
	//接收用户的输入
	while (!is_exit) {
		string input;
		cout << "\n>>" << flush;
		getline(cin, input);
		if (input.empty())
			continue;
		if (input == "exit")
			break;
		//用空格分隔字符串
		auto vec = Split(input);
		if (vec.empty())
			continue;
		/*for (auto& s : vec) {
			cout << s << endl;
		}*/
		//cout << input << endl;
		//cv -s test.mp4 -d test.avi
		//1初始化任务
		init(vec);

		string type = vec[0];
		//2参数处理
		for (int i = 1; i < vec.size(); i++) {
			//判断是否是关键字 -s -d
			//-s test.mp4 -p -d out.mp4
			auto& k = vec[i];
			auto fitr = key_funcs_.find(k);
			if (fitr != key_funcs_.end()) {
				if (vec.size() - 1 > i) {//后面还有参数
					auto &v = vec[i + 1];
					if (key_funcs_.find(v) == key_funcs_.end()) {//值不是关键字
						cout << k << ":" << v << endl;
						fitr->second(v);
						i++;
						continue;
					}
				}
				fitr->second("");
				cout << k << ":" << " " << endl;
			}
		}
		//3执行任务
		auto task = task_funcs_.find(type);
		if (task == task_funcs_.end()) {
			cout << type << " not support" << endl;
		}
		else {
			task->second();
		}
	}
}