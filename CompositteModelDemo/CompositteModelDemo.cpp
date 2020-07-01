// CompositteModelDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Composite.h"
#include "Left.h"

int _tmain(int argc, _TCHAR* argv[])
{
    CComposite root("root");
    /****���root�ĺ��ӽڵ�PA***/
    CLeft* pA = new CLeft("Left A");
    root.Add(pA);
    /****���root�ĺ��ӽڵ�PB***/
    CLeft* pB = new CLeft("Left B");
    root.Add(pB);
    /****���root�ķ�֧�ڵ�comp***/
    CComposite* com1 = new CComposite("Composite X");
    root.Add(com1);
    CLeft* comA = new CLeft("X Left A");
    com1->Add(comA);
    CLeft* comB = new CLeft("X Left B");
    com1->Add(comB);
    root.Display(1);
    getchar();
	return 0;
}

