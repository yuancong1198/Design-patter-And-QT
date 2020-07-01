// ObserverModelDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "demo.h"

#define DEL_SAFT(obj) if(obj){ delete obj; obj=NULL;}

int _tmain(int argc, _TCHAR* argv[])
{
    //1. 创建目标对象
    Subject* pSubject = new ConcreteSubject();
    //2.创建具体观察者
    Observer* pConcreteObserver1 = new ConcreteObserver1();
    Observer* pConcreteObserver2 = new ConcreteObserver2();
    //3.向目标对象注册观察者
    pSubject->Attach(pConcreteObserver1);
    pSubject->Attach(pConcreteObserver2);
    //4.更改目标对象状态
    (dynamic_cast<ConcreteSubject*>(pSubject))->setState(3);
    //5.通知观察者进行统一状态
    pSubject->Notify();

    //6.注销pConcreteObserver2观察者
    pSubject->Detach(pConcreteObserver1);
    (dynamic_cast<ConcreteSubject*>(pSubject))->setState(4);
    pSubject->Notify();

    DEL_SAFT(pSubject);
    DEL_SAFT(pConcreteObserver1);
    DEL_SAFT(pConcreteObserver2);

    getchar();
	return 0;
}

