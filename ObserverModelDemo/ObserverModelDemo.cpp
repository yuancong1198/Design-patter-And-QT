// ObserverModelDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "demo.h"

#define DEL_SAFT(obj) if(obj){ delete obj; obj=NULL;}

int _tmain(int argc, _TCHAR* argv[])
{
    //1. ����Ŀ�����
    Subject* pSubject = new ConcreteSubject();
    //2.��������۲���
    Observer* pConcreteObserver1 = new ConcreteObserver1();
    Observer* pConcreteObserver2 = new ConcreteObserver2();
    //3.��Ŀ�����ע��۲���
    pSubject->Attach(pConcreteObserver1);
    pSubject->Attach(pConcreteObserver2);
    //4.����Ŀ�����״̬
    (dynamic_cast<ConcreteSubject*>(pSubject))->setState(3);
    //5.֪ͨ�۲��߽���ͳһ״̬
    pSubject->Notify();

    //6.ע��pConcreteObserver2�۲���
    pSubject->Detach(pConcreteObserver1);
    (dynamic_cast<ConcreteSubject*>(pSubject))->setState(4);
    pSubject->Notify();

    DEL_SAFT(pSubject);
    DEL_SAFT(pConcreteObserver1);
    DEL_SAFT(pConcreteObserver2);

    getchar();
	return 0;
}

