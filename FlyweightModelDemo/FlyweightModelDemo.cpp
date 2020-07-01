// FlyweightModelDemo.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include "stdafx.h"
#include "demo.h"
#define SAFE_DEL(p) if(p){delete p; p = NULL;}



int _tmain(int argc, _TCHAR* argv[])
{
    int i = 100;
    FlyweightFactory f; //整个过程值采用一个工厂
    Flyweight* px = f.getFlyweight("X");
    px->Operator(--i);
    Flyweight* py = f.getFlyweight("Y");
    px->Operator(--i);
    Flyweight* pd = f.getFlyweight("D");
    px->Operator(--i);
    std::cout<<"可供共享的模块有："<<f.countN()<<"个"<<std::endl;
    getchar();
    SAFE_DEL(px);
    SAFE_DEL(py);
    SAFE_DEL(pd);
	return 0;
}

