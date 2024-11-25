#include <iostream>
#include "xlog.h"
#include "log_fac.h"
#include "xexec.h"
#include "user_input.h"

using namespace std;
int main() {
    {
        //cv -s test.mp4 -d test.avi
        UserInput user;
        //注册参数处理函数
        user.Reg("-s", [](const string& s) {
			cout << "----source file:" << s << endl;
		})
		.Reg("-d", [](const string& d) {
			cout << "----des file:" << d << endl;
		})
		.Reg("-p", [](const string& w) {
			cout << "password:" << w << endl;
        })
        .RegTask("cv", []() {//注册任务处理函数
            cout << "@@@@cv task@@@@" << endl;
        });

        user.Start();
        return 0;
    }

    /////////////////////////xexec test/////////////////////////
	XExec exec;
    exec.Start("ping 127.0.0.1");
    string out;
    while (exec.Running()) {
        if (exec.GetOutput(out)) {
            cout << out << endl;
        }
    }
    while (exec.GetOutput(out)) {
		cout << out << endl;
	}
    exec.Wait();

    system("pause");
    return 0;

    /////////////////////////log test/////////////////////////
    XLOGINIT();
    LOGDEBUG("test xlog");
    system("pause");
    return 0;
}
