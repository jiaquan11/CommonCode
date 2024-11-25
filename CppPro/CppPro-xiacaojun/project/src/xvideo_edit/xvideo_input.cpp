#include "xvideo_input.h"
#include <iostream>
#include "user_input.h"

using namespace std;
void XVideoInput::Start(std::unique_ptr<XTask> task) {
	cout << __FUNCSIG__ << endl;
	UserInput user;
	XTask::Data data;

	user.RegTask("play", [&] {//������Ƶ������
		data.type = "play";
		task->Start(data);
		})
		.RegTask("cv", [&] {//cv����������
		cout << "cv task" << endl;
		cout << data.src << " " << data.des << endl;
		data.type = "cv";
		task->Start(data);
		//�ȴ������������ʾ����
		int p = 0;
		int l = -1;
		while (task->Running()) {
			p = task->Progress();
			if (p != l) {
				cout << "\r%" << task->Progress();
				l = p;
			}
		}
		cout << "\r%" << "100" << endl;
	})
	.Reg("-s", [&](const string& s) {//Դ�ļ�
		cout << "-s: " << s << endl;
		data.src = s;
	})
	.Reg("-d", [&](const string& s) {//Ŀ���ļ�
		cout << "-d: " << s << endl;
		data.des = s;
	})
	.Reg("-b", [&](const string& s) {//���п�ʼ��
		data.begin_sec = stoi(s);
	})
	.Reg("-e", [&](const string& s) {//���н�����
		data.end_sec = stoi(s);
	})
	.Reg("-p", [&](const string& s) {//����
		if (s.empty()) {
			cout << "password:" << flush;
			string pass;
			cin >> pass;
			data.password = pass;
		} else {
			data.password = s;
		}
	})
	.Reg("-dp", [&](const string& s) {//����
	if (s.empty()) {
		cout << "password:" << flush;
		string pass;
		cin >> pass;
		data.password = pass;
	} else {
		data.password = s;
		data.is_enc = false;
	}
	});

	user.Start([&](vector<string> para) {
		cout << "init task" << endl;
		data = XTask::Data();
		//play test.mp4
		//cv test.mp4 out.mp4
		if (para.size() < 4) {
			if (para.size() > 1) {
				data.src = para[1];
			}
			if (para.size() > 2) {
				data.des = para[2];
			}
		}
	});
}