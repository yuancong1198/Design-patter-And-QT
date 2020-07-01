// FlyweightModelDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<iostream>
#include "stdafx.h"
#include "demo.h"
#define SAFE_DEL(p) if(p){delete p; p = NULL;}



int _tmain(int argc, _TCHAR* argv[])
{
    int i = 100;
    FlyweightFactory f; //��������ֵ����һ������
    Flyweight* px = f.getFlyweight("X");
    px->Operator(--i);
    Flyweight* py = f.getFlyweight("Y");
    px->Operator(--i);
    Flyweight* pd = f.getFlyweight("D");
    px->Operator(--i);
    std::cout<<"�ɹ������ģ���У�"<<f.countN()<<"��"<<std::endl;
    getchar();
    SAFE_DEL(px);
    SAFE_DEL(py);
    SAFE_DEL(pd);
	return 0;
}

