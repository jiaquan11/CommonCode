#pragma once
/*
windows下的dll导出宏定义
xlog.h会在导出库中和引入库的应用程序中都会被使用，
两个地方的定义是不一样的，所以需要使用宏定义来区分
在导出库中需要定义XLOG_EXPORTS，在引入库的应用程序中不需要定义XLOG_EXPORTS
另外在其它平台下，不需要使用这个宏定义，定义为空即可
*/
#ifdef _WIN32
	#ifdef XLOG_EXPORTS
		#define XLOG_API __declspec(dllexport)
	#else
		#define XLOG_API __declspec(dllimport)
	#endif
#else
	#define XLOG_API
#endif
