// FacadePatternDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Demo.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	由于Facade的作用，客户端可以根本不用知道三个子系统类的存在。
	*/
	Facade * m_facade = new Facade();
	m_facade->Activate();
	std::cout <<  "直播中!" << std::endl;
	m_facade->Deactivate();
	getchar();
	return 0;
}

