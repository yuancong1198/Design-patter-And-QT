// CompositteModelDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Composite.h"
#include "Left.h"

int _tmain(int argc, _TCHAR* argv[])
{
    CComposite root("root");
    /****添加root的孩子节点PA***/
    CLeft* pA = new CLeft("Left A");
    root.Add(pA);
    /****添加root的孩子节点PB***/
    CLeft* pB = new CLeft("Left B");
    root.Add(pB);
    /****添加root的分支节点comp***/
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

