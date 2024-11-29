#include <iostream>
#include <string>

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
