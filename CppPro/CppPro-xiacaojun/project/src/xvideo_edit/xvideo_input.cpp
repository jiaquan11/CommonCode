#include "xvideo_input.h"
#include <iostream>
#include "user_input.h"

using namespace std;
void XVideoInput::Start(std::unique_ptr<XTask> task) {
	cout << __FUNCSIG__ << endl;
	UserInput user;
	XTask::Data data;

	user.RegTask("play", [&] {//播放视频处理函数
		data.type = "play";
		task->Start(data);
		})
		.RegTask("cv", [&] {//cv处理任务函数
		cout << "cv task" << endl;
		cout << data.src << " " << data.des << endl;
		data.type = "cv";
		task->Start(data);
		//等待任务结束，显示进度
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
	.Reg("-s", [&](const string& s) {//源文件
		cout << "-s: " << s << endl;
		data.src = s;
	})
	.Reg("-d", [&](const string& s) {//目标文件
		cout << "-d: " << s << endl;
		data.des = s;
	})
	.Reg("-b", [&](const string& s) {//剪切开始秒
		data.begin_sec = stoi(s);
	})
	.Reg("-e", [&](const string& s) {//剪切结束秒
		data.end_sec = stoi(s);
	})
	.Reg("-p", [&](const string& s) {//加密
		if (s.empty()) {
			cout << "password:" << flush;
			string pass;
			cin >> pass;
			data.password = pass;
		} else {
			data.password = s;
		}
	})
	.Reg("-dp", [&](const string& s) {//解密
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