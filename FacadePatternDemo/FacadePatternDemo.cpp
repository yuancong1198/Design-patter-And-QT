// FacadePatternDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Demo.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	����Facade�����ã��ͻ��˿��Ը�������֪��������ϵͳ��Ĵ��ڡ�
	*/
	Facade * m_facade = new Facade();
	m_facade->Activate();
	std::cout <<  "ֱ����!" << std::endl;
	m_facade->Deactivate();
	getchar();
	return 0;
}

