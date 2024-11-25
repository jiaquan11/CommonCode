#include "xexec.h"
#include <iostream>
#include <string>
#ifdef _WIN32
#else
	#define _popen popen  //linux��û��_popen��������popen����
#endif

using namespace std;
bool XExec::Start(const char* cmd) {
	cout << "Start Cmd:" << cmd << endl;
	/*
	 *_popen �� C/C++ ��׼����һ�����ڴ����ܵ���pipe����ִ���ⲿ����ĺ�����
	 *������ǰ�������ӽ���֮�����ͨ�ţ�ͨ�����ڲ����ӽ��̵���������ӽ�����������
	*/
	auto fp = _popen(cmd, "r");//ִ���ⲿ����
	if (fp == nullptr) {
		cout << "_popen failed" << endl;
		return false;
	}
	running_ = true;

	fut_ = async([fp, this] {//�첽ִ��,lambda���ʽ
		string tmp;
		char c = 0;
		while (c = fgetc(fp)) {//��ȡ�ⲿ���̵����
			if (c == EOF) {
				break;
			}
			// /r�ص���ǰ�еĿ�ͷ��/n����һ�еĿ�ͷ
			if (c == '\n' || c == '\r') {
				//cout << tmp << endl;
				if (tmp.empty()) {
					continue;
				}
				{
					lock_guard<mutex> lock(mux_);
					outs_.push(tmp);//ÿ�λ���һ��������ַ����������У���GetOutput��ȡ
				}
				tmp = "";
				continue;
			}
			tmp += c;
		}
		_pclose(fp);
		running_ = false;
		return true;//�첽ִ�����
		});
	return true;
}

//��ȡ����̨�����
bool XExec::GetOutput(std::string& out) {
	lock_guard<mutex> lock(mux_);
	if (outs_.empty()) {
		return false;
	}
	out = move(outs_.front());
	outs_.pop();
	return true;
}