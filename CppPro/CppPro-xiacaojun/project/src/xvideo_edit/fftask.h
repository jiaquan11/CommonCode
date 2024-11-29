#pragma once
#include "xtask.h"
#include "xexec.h"

//����ffmpeg��ffplay����ʵ�ֵ�����Ƶģ��
class FFTask : public XTask {
	//��������Ƶ�����������̷��أ����߳��д���
	bool Start(const Data&) override;
	//��ȡ�������0-100
	int Progress() override {
		return progress_;
	}
	bool Running() override {
		return exec_.Running();
	}
	int TotalSec() override {
		return total_sec_;
	}
	void Clear() {
		total_sec_ = 0;
		progress_ = 0;
	}
private:
	int total_sec_{ 0 };//��Ƶ��ʱ��
	int progress_{ 0 };//�������
	XExec exec_;
};

