#include <iostream>
#include <string>

/*
说明一下控制台输出重定向命令
test_iostream.exe > 1.txt  表示只将标准输出到文件1.txt中，不包括错误输出
test_iostream.exe 1> file.out 2 > file.err 表示将标准输出重定向到file.out中，错误输出重定向到file.err中
test_iostream.exe 1> file.out 2>&1 表示将标准输出和错误输出都重定向到file.out中
*/

using namespace std;
int main() {
    for (;;) {
        cout << "请输入数字:"<<flush;
        string line;
        int x{ 0 };
        cin >> x;
        //if(cin.rdstate() == std::ios_base_failbit)
        if (cin.fail()) {
            cin.clear();//恢复状态为正常
            getline(cin, line);//需要将错误的输入读取并丢弃，不然会陷入死循环
            cout << "cin fail" << line << endl;
            continue;
        }
        cout << "x=" << x << endl;
    }

    return 0;
}
