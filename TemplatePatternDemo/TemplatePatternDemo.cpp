// TemplatePatternDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "demo.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//ConcreteClassA��ConcreteClassB���໥�滻
 	AbstractClass* pAbstract = new ConcreteClassA();
	pAbstract->TemplateMethod();

	pAbstract = new ConcreteClassB();
	pAbstract->TemplateMethod();
	getchar();
	return 0;
}

