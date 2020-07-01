// CompositePatter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Demo.h"

/*
ʹ�ó�����
	       1����������ʾ���������塱�Ĳ�νṹ������ʹ�����ģʽ��

           2����������ÿͻ��˿��Ժ��Ը��ӵĲ�νṹ��ʹ��ͳһ�ķ�ʽȥ������νṹ�е����ж���Ҳ����ʹ�����ģʽ��
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

