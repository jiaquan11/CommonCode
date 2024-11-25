#include <iostream>
#include "xtask_factory.h"
#include "xvideo_input.h"

int main() {
	XVideoInput input;
	input.Start(XTaskFactory::Create());
	/*auto task = XTaskFactory::Create();
	XTask::Data data;
	data.src = "biterate9.mp4";
	data.des = "out.mp4";
	data.type = "cv";
	task->Start(data);*/
    //system("ffplay biterate9.mp4");
    return 0;
}