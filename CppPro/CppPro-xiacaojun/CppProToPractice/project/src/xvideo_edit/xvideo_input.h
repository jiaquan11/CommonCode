#pragma once
#include <memory>
#include "xtask.h"
//��ȡ�û������룬ִ����Ƶ��������
class XVideoInput {
public:
	//��ʼ�����û����룬������taskִ������
	void Start(std::unique_ptr<XTask> task);

private:
	void RunTask(XTask& task, const XTask::Data& data);
};

