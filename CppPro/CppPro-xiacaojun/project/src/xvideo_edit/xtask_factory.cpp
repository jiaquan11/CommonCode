#include "xtask_factory.h"
#include <iostream>
#include "fftask.h"

using namespace std;
std::unique_ptr<XTask> XTaskFactory::Create(int type) {
	switch (type) {
	case 0:
		return std::make_unique<FFTask>();
		break;
	default:
		cerr << "XTasktype: " << type << "not support" << endl;
		break;
	}
	return nullptr;
}