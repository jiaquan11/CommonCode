#include <iostream>
#include <string>
#include "base16.h"

using namespace std;
int main() {
    //base 16编解码测试
    {
        string teststr = { "测试base16数据" };
        vector<unsigned char>data(teststr.begin(), teststr.end());
        data.push_back('\0');

        auto base16str = Base16Encode(data);
        cout << "base16编码后的字符串:" << base16str << endl;

        auto decode_data = Base16Decode(base16str);
        cout << "base16解码后的字符串:" << decode_data.data() << endl;
    }

    system("pause");
    return 0;
}

