#include "base16.h"
#include <iostream>
// Description: base16�������ʵ��

//�����õ�ӳ���
//��̬ȫ�ֱ�����ֻ�ڵ�ǰ�ļ�����Ч
static const std::string enc_tab = "0123456789ABCDEF";

//ASCII�ַ�
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

//base16����
//data:��Ҫ����Ķ���������
//return:����base16������ַ���
std::string Base16Encode(std::vector<unsigned char>& data) {
	//unsigned char��char������
	//8λһ���ֽ�
	//unsigned �޷��������������㲻�ܷ���
	//char��һλ�Ƿ���λ�������Ʋ�����������
	std::string res;
	for (unsigned char c : data) {
		//��һ���ֽڵĶ�����ת��Ϊ�����ַ�����һ���ַ�8λת������4λ
		char h = c >> 4;//��λ������λ
		char l = c & 0b00001111;//�����㱣����λ c++14  c & 0x0f

		res += enc_tab[h];//0~15=>0~F
		res += enc_tab[l];
	}
	return res;
}

//base16����
//str:��Ҫ�����base16������ַ���,������2�ı���
//return:���ؽ����Ķ���������
std::vector<unsigned char> Base16Decode(const std::string& str) {
	if (str.empty() || str.size() % 2 != 0) {
		std::cout << "base16����ʧ�ܣ��ַ������Ȳ���2�ı���" << std::endl;
		return {};
	}
	std::vector<unsigned char> res;
	for (int i = 0; i < str.size(); i += 2) {
		char ch = str[i];
		char cl = str[i + 1];
		//'A'=>10 '0'=>0 'F'=>15
		// 65=>10 48=>0 70=>15
		//�������ַ�ת��Ϊһ���ֽ�
		unsigned char h = dec_tab[ch];
		unsigned char l = dec_tab[cl];
		//������4λת��Ϊһ���ֽ�
		//h 0000 1100   << 4 1100 0000
		//                 l 0000 0011 h|l =>1100 0011
		res.push_back((h << 4) | l);
	}
	return res;
}