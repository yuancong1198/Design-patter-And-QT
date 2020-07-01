// CompositePatter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Demo.h"

/*
使用场景：
	       1、如果你想表示“部分整体”的层次结构，可以使用组合模式。

           2、如果你想让客户端可以忽略复杂的层次结构，使用统一的方式去操作层次结构中的所有对象，也可以使用组合模式。
*/
int _tmain(int argc, _TCHAR* argv[])
{
	Composite* root = new Composite("root");
	root->Add(new Leaf("Leaf A"));
	root->Add(new Leaf("Leaf B"));
	
	Composite* comp = new Composite("Composite X");
	comp->Add(new Leaf("Leaf XA"));
	comp->Add(new Leaf("Leaf XB"));

	root->Add(comp);

	Composite* comp2 = new Composite("Composite XY");
	comp2->Add(new Leaf("Leaf XYA"));
	comp2->Add(new Leaf("Leaf XYB"));
	comp->Add(comp2);

	root->Add(new Leaf("Leaf C"));

	Leaf* leaf = new Leaf("Leaf D");
	root->Add(leaf);
	root->Remove(leaf);
	root->Display(1);
	getchar();
	return 0;
}

