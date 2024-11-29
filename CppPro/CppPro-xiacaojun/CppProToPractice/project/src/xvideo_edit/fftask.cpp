#include "fftask.h"
#include <iostream>
#include <string>
#include "xexec.h"

using namespace std;
#define DEFAULTPASS "0123456789ABCDEF0123456789ABCDEF"

static int TimeToSec(const string& s) {
	if (s.size() < 8) return 0;
	//00:02:31
	int h = 0, m = 0, sec = 0;
	try {
		h = stoi(s.substr(0, 2));
		m = stoi(s.substr(3, 2));
		sec = stoi(s.substr(6, 2));
	} catch (const std::exception&) {
		
	}
	return h * 3600 + m * 60 + sec;
}

//��������Ƶ�����������̷��أ����߳��д���
bool FFTask::Start(const Data& para) {
	cout << "FFTask Start" << endl;
	//ffmpeg -y -i biterate9.mp4 out.mp4
	///////////��Ƶ����/////////////////////
	//ffmpeg -y -ss 10 -t 5 -i biterate9.mp4 out.mp4
	//-ss������-i֮ǰ
	string cmd = "ffmpeg -y";
	if (para.type == "play") {
		cmd = "ffplay ";
	}

	if (para.begin_sec > 0) {
		cmd += " -ss " + to_string(para.begin_sec);
	}
	if (para.end_sec > 0) {
		int t = para.end_sec - para.begin_sec;
		if (t > 0) {
			cmd += " -t " + to_string(t);
		}
	}
	//////////////////////////////////////////
	//////////////////////////////////////////////////// 
	// ��Ƶ���� ��Կ������-i֮ǰ
	///ffmpeg -decryption_key 1234566789ABCDEF0123456789ABCDEF -i out.mp4 outde.mp4
	if (!para.is_enc) {
		if (!para.password.empty()) {
			string pass = DEFAULTPASS;
			for (int i = 0; i < para.password.size() && i < pass.size(); i++) {
				pass[i] = para.password[i];
			}
			cmd += " -decryption_key ";
			cmd += pass;
		}
	}

	///////////��Ƶ����/////////////////////
	//��Ƶ���ܣ���Կ�������-i֮��
	//ffmpeg -y -i test.mp4 -encryption_key  0123456789ABCDEF0123456789ABCDEF -encryption_scheme cenc-aes-ctr -encryption_kid 0123456789ABCDEF0123456789ABCDEF  en.mp4
	//�����ļ�
	cmd += " -i " + para.src;
	if (!para.password.empty() && para.is_enc) {
		string pass = DEFAULTPASS;
		cmd += " -encryption_scheme cenc-aes-ctr -encryption_kid 0123456789ABCDEF0123456789ABCDEF";
		cmd += " -encryption_key ";
		for (int i = 0; i < para.password.size() && i < pass.size(); i++) {
			pass[i] = para.password[i];
		}
		cmd += pass;
	}

	//����ļ�
	if (!para.des.empty()) {
		cmd += " " + para.des;
	}
	cout << "cmd: " << cmd << endl;

	exec_.Start(cmd.c_str(), [this](const string& s) {
		//cout << s << endl;
		//1 ��ȡ��Ƶʱ��
	//Duration: 00:00:10.00, start: 0.000000, bitrate: 9 kb/s
		if (total_sec_ <= 0) {
			auto pos = s.find("Duration:");
			if (pos != string::npos) {
				string tmp = s.substr(pos + 10, 8);
				//00:00:10
				//cout << tmp << endl;
				total_sec_ = TimeToSec(tmp);
				cout << "total_sec_:" << total_sec_ << "s" << endl;
				return;
			}
		}
		//frame=100 fps=0 q=0.0 size=0kB time=00:00:04.00 bitrate=0.0kbits/s speed=7.99x
		//��ȡ����
		{
			auto pos = s.find("time=");
			if (pos != string::npos) {
				string tmp = s.substr(pos + 5, 8);
				int p = TimeToSec(tmp);
				if (total_sec_ > 0) {
					progress_ = p * 100 / total_sec_;
				}
				return;
			}
		}
	});
	return true;
}