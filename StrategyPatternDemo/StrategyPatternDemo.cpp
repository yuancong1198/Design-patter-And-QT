// StrategyPatternDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "demo.h"

#define DEL_SAFE(p) if(p){ delete p; p = NULL;}

int _tmain(int argc, _TCHAR* argv[])
{
	StrategyObject *pStrategyA = new ConcreteStrategyObjectA;
	StrategyObject *pStrategyB = new ConcreteStrategyObjectB;
	StrategyObject *pStrategyC = new ConcreteStrategyObjectC;
	ContextObject *pContextA = new ContextObject(pStrategyA);
	ContextObject *pContextB = new ContextObject(pStrategyB);
	ContextObject *pContextC = new ContextObject(pStrategyC);
	pContextA->ContextInterface();
	pContextB->ContextInterface();
	pContextC->ContextInterface();
	DEL_SAFE(pStrategyA);
	DEL_SAFE(pStrategyB);
	DEL_SAFE(pStrategyC);
	DEL_SAFE(pContextA);
	DEL_SAFE(pContextB);
	DEL_SAFE(pContextC);
	getchar();
	return 0;
}

