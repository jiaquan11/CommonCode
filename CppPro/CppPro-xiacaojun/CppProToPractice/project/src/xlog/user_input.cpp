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
	//�����û�������
	while (!is_exit) {
		string input;
		cout << "\n>>" << flush;
		getline(cin, input);
		if (input.empty())
			continue;
		if (input == "exit")
			break;
		//�ÿո�ָ��ַ���
		auto vec = Split(input);
		if (vec.empty())
			continue;
		/*for (auto& s : vec) {
			cout << s << endl;
		}*/
		//cout << input << endl;
		//cv -s test.mp4 -d test.avi
		//1��ʼ������
		init(vec);

		string type = vec[0];
		//2��������
		for (int i = 1; i < vec.size(); i++) {
			//�ж��Ƿ��ǹؼ��� -s -d
			//-s test.mp4 -p -d out.mp4
			auto& k = vec[i];
			auto fitr = key_funcs_.find(k);
			if (fitr != key_funcs_.end()) {
				if (vec.size() - 1 > i) {//���滹�в���
					auto &v = vec[i + 1];
					if (key_funcs_.find(v) == key_funcs_.end()) {//ֵ���ǹؼ���
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
		//3ִ������
		auto task = task_funcs_.find(type);
		if (task == task_funcs_.end()) {
			cout << type << " not support" << endl;
		}
		else {
			task->second();
		}
	}
}