// CommandModelDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "demo.h"

#define SAFE_DELETE(p) if(p){ delete p; p = NULL; }


int main()
{
    //生成烤肉师傅、服务员、订单对象
    Receiver* p_cook = new Receiver();
    Command* p_mutton = new BakeMuttonCommand(p_cook);
    Command* p_chilkenwind = new BakeChickenWind(p_cook);
    Waiter* p_waiter = new Waiter();
    //将订单对象推送到命令队列中
    p_waiter->setOrder(p_mutton);
    p_waiter->setOrder(p_chilkenwind);
    //服务员通知烤肉师傅具体订单
    p_waiter->Notify();

    SAFE_DELETE(p_cook);
    SAFE_DELETE(p_mutton);
    SAFE_DELETE(p_chilkenwind);
    SAFE_DELETE(p_waiter);

    getchar();
	return 0;
}

