#pragma once
#include <string>
#include <vector>

//base16编码
//data:需要编码的二进制数据
//return:返回base16编码的字符串
std::string Base16Encode(std::vector<unsigned char>& data);

//base16解码
//str:需要解码的base16编码的字符串,必须是2的倍数
//return:返回解码后的二进制数据
std::vector<unsigned char> Base16Decode(const std::string& str);