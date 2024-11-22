#pragma once
#include <string>
#include <vector>

//base16����
//data:��Ҫ����Ķ���������
//return:����base16������ַ���
std::string Base16Encode(std::vector<unsigned char>& data);

//base16����
//str:��Ҫ�����base16������ַ���,������2�ı���
//return:���ؽ����Ķ���������
std::vector<unsigned char> Base16Decode(const std::string& str);