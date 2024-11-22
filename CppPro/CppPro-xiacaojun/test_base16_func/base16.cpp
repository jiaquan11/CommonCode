#include "base16.h"
#include <iostream>
// Description: base16编码解码实现

//编码用的映射表
//静态全局变量，只在当前文件内有效
static const std::string enc_tab = "0123456789ABCDEF";

//ASCII字符
static const std::vector<char> dec_tab = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,//0~9
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,//10~19
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,//20~29
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,//30~39
	-1, -1, -1, -1, -1, -1, -1, -1,//40~47
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9,//48~57
	-1, -1, -1, -1, -1, -1, -1,//58~64
	10, 11, 12, 13, 14, 15,//65~70
};

//base16编码
//data:需要编码的二进制数据
//return:返回base16编码的字符串
std::string Base16Encode(std::vector<unsigned char>& data) {
	//unsigned char和char的区别
	//8位一个字节
	//unsigned 无符号在做算术运算不管符号
	//char第一位是符号位，二进制不能有正负号
	std::string res;
	for (unsigned char c : data) {
		//将一个字节的二进制转换为两个字符，即一个字符8位转换两个4位
		char h = c >> 4;//移位丢弃低位
		char l = c & 0b00001111;//与运算保留低位 c++14  c & 0x0f

		res += enc_tab[h];//0~15=>0~F
		res += enc_tab[l];
	}
	return res;
}

//base16解码
//str:需要解码的base16编码的字符串,必须是2的倍数
//return:返回解码后的二进制数据
std::vector<unsigned char> Base16Decode(const std::string& str) {
	if (str.empty() || str.size() % 2 != 0) {
		std::cout << "base16解码失败，字符串长度不是2的倍数" << std::endl;
		return {};
	}
	std::vector<unsigned char> res;
	for (int i = 0; i < str.size(); i += 2) {
		char ch = str[i];
		char cl = str[i + 1];
		//'A'=>10 '0'=>0 'F'=>15
		// 65=>10 48=>0 70=>15
		//将两个字符转换为一个字节
		unsigned char h = dec_tab[ch];
		unsigned char l = dec_tab[cl];
		//将两个4位转换为一个字节
		//h 0000 1100   << 4 1100 0000
		//                 l 0000 0011 h|l =>1100 0011
		res.push_back((h << 4) | l);
	}
	return res;
}