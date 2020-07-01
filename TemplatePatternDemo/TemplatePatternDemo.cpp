// TemplatePatternDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "demo.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//ConcreteClassA与ConcreteClassB可相互替换
 	AbstractClass* pAbstract = new ConcreteClassA();
	pAbstract->TemplateMethod();

	pAbstract = new ConcreteClassB();
	pAbstract->TemplateMethod();
	getchar();
	return 0;
}

