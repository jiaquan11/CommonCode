#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 需求：将二进制转换字符串只包含16个字符0123456789ABCDEF
 */

//编码用的映射表
const string base16_enc_tab = "0123456789ABCDEF";
int main() {
    string teststr = "测试用于base16的字符串";
    //base16编码
    string base16str;
    //unsigned char和char的区别
    //8位一个字节
    //unsigned 无符号在做算术运算不管符号
    //char第一位是符号位，二进制不能有正负号
    for (unsigned char c : teststr) {
        //将一个字节的二进制转换为两个字符，即一个字符8位转换两个4位
        char h = c >> 4;//移位丢弃低位
        char l = c & 0b00001111;//与运算保留低位 c++14  c & 0x0f

        base16str += base16_enc_tab[h];//0~15=>0~F
        base16str += base16_enc_tab[l];
    }
    cout << "base16编码结果：" << base16str << endl;

    //base16解码
    string ostr;
    const vector<char> base16_dec_tab = {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,//0~9
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,//10~19
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,//20~29
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,//30~39
        -1, -1, -1, -1, -1, -1, -1, -1,//40~47
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,//48~57
        -1, -1, -1, -1, -1, -1, -1,//58~64
        10, 11, 12, 13, 14, 15,//65~70
	};
    for (int i = 0; i < base16str.size(); i += 2) {
		char ch = base16str[i];
		char cl = base16str[i + 1];
        //'A'=>10 '0'=>0 'F'=>15
        // 65=>10 48=>0 70=>15
		//将两个字符转换为一个字节
        unsigned char h = base16_dec_tab[ch];
        unsigned char l = base16_dec_tab[cl];
        //将两个4位转换为一个字节
        //h 0000 1100   << 4 1100 0000
        //                 l 0000 0011 h|l =>1100 0011
        ostr += (h << 4) | l;
	}
    cout << "base16解码结果：" << ostr << endl;
    system("pause");
	return 0;
}

