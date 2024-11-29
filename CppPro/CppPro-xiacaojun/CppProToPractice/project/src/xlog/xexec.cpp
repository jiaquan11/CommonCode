#include "xexec.h"
#include <iostream>
#include <string>
#ifdef _WIN32
#else
	#define _popen popen  //linux��û��_popen��������popen����
#endif

using namespace std;
bool XExec::Start(const char* cmd, std::function<void(const std::string&)> func) {
	/*
	 *_popen �� C/C++ ��׼����һ�����ڴ����ܵ���pipe����ִ���ⲿ����ĺ�����
	 *������ǰ�������ӽ���֮�����ͨ�ţ�ͨ�����ڲ����ӽ��̵���������ӽ�����������
	*/
	//�ض����������ض��򵽱�׼���
	//ffmpeg -y -i biterate9.mp4 out.mp4 2>&1
	string tmp = cmd;
	tmp += " 2>&1";//2>&1��ʾ��2�������crr�ض���1��׼��� 1
	cout << "Start Cmd:" << tmp << endl;
	auto fp = _popen(tmp.c_str(), "r");//ִ���ⲿ����
	if (fp == nullptr) {
		cout << "_popen failed" << endl;
		return false;
	}
	running_ = true;

	fut_ = async([fp, this, func] {//�첽ִ��,lambda���ʽ
		string tmp;
		char c = 0;
		while (c = fgetc(fp)) {//��ȡ�ⲿ���̵����
			//cout << c << flush;
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
					if (func) {
						func(tmp);//��������˻ص��������͵��ûص�����
					} else {
						lock_guard<mutex> lock(mux_);
						outs_.push(tmp);//ÿ�λ���һ��������ַ����������У���GetOutput��ȡ
					}
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