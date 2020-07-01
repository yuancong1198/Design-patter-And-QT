// CommandModelDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "demo.h"

#define SAFE_DELETE(p) if(p){ delete p; p = NULL; }


int main()
{
    //���ɿ���ʦ��������Ա����������
    Receiver* p_cook = new Receiver();
    Command* p_mutton = new BakeMuttonCommand(p_cook);
    Command* p_chilkenwind = new BakeChickenWind(p_cook);
    Waiter* p_waiter = new Waiter();
    //�������������͵����������
    p_waiter->setOrder(p_mutton);
    p_waiter->setOrder(p_chilkenwind);
    //����Ա֪ͨ����ʦ�����嶩��
    p_waiter->Notify();

    SAFE_DELETE(p_cook);
    SAFE_DELETE(p_mutton);
    SAFE_DELETE(p_chilkenwind);
    SAFE_DELETE(p_waiter);

    getchar();
	return 0;
}

