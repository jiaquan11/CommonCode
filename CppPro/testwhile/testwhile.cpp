#include <iostream>

using namespace std;
int main() {
    /*
     * 项目实战 支持ls的shell
     * 实现一个在windows上支持ls命令的shell
     * 使用cin接收用户输入
     * 使用system调用dir命令模拟ls
     * 支持ls不传参数和传递参数
     * 用户输入exit和quit退出
     */
    {
        bool is_exit = false;//控制循环退出
        while (!is_exit) {
			string cmd;//存储用户输入命令
			string execcmd;//执行的命令

            cout << "xshell>>";//flush刷新缓冲区
            cin >> cmd;
            if (cmd == "ls") {
                execcmd = "dir";
                string arg;
                //结尾至少还有一个\n
                if (cin.rdbuf()->in_avail() > 1) {
                    cin >> arg;
                    execcmd += " " + arg;
				}
                system(execcmd.c_str());
            }
            else if (cmd == "clear") {
                system("cls");
            } else if (cmd == "exit") {
                break;
            } else if (cmd == "quit") {
                is_exit = true;
                continue;
            } else {
                cout << "命令" << cmd << "不支持" << endl;
            }
		}
        cout << "xshell exit" << endl;
    }

    //system执行系统命令
    system("cd");
    //列出当前目录下的文件
    string cmd = "cd";
    system(cmd.c_str());
    //接收用户输入的命令,再用system执行
    cout << ">>";
    cin >> cmd;//以空格为分隔符的字符串只取一个 dir c:\ >> dir
    cout << cmd << endl;
    system(cmd.c_str());
    //同时支持用户输入dir和dir c:两种命令
    //判断cin中是否还有数据未取
    cout << "in_avail:"<< cin.rdbuf()->in_avail() << endl;
    //结尾至少还有一个\n
    if (cin.rdbuf()->in_avail() > 1) {
        string tmp;
        cin >> tmp; 
        cmd = cmd + " " + tmp;
	}
    system(cmd.c_str());// dir   dir c:\\

    system("pause");
}

