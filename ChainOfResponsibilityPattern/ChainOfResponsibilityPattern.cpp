// ChainOfResponsibilityPattern.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Demo.h"
#include <iostream>
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }

int _tmain(int argc, _TCHAR* argv[])
{

	DM *pDM = new DM(nullptr);
	PS *pPS = new PS(pDM);
	//PS *pPS = new PS(null),���ž����ڣ�������Ŀ���ܴ�����
	PM *pPM = new PM(pPS);
	HolidayRequest *pHolidayRequest = new HolidayRequest(10);
	pPM->HandleRequest(pHolidayRequest);
	SAFE_DELETE(pHolidayRequest);

	pHolidayRequest = new HolidayRequest(2);
	pPM->HandleRequest(pHolidayRequest);

	//SAFE_DELETE(pDM);
	SAFE_DELETE(pPS);
	SAFE_DELETE(pPM);
	SAFE_DELETE(pHolidayRequest);

	system("pause");
	return 0;
}

