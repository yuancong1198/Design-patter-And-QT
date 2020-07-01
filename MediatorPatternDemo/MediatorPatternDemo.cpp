// MediatorPatternDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "demo.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Mediator *mediator = new HouseMediator();
	Person *person1 = new Renter();
	Person *person2 = new Landlord();
	mediator->SetRenter(person1);
	mediator->SetLandlord(person2);
	person1->SetMediator(mediator);
	person2->SetMediator(mediator);
	person1->SendMessage(string("���������ڱ�վ�������׷��ӣ�һ��һ��\n"));
	person2->SendMessage(string("�ҳ���һ�����ӣ�һ��һ�������ڱ�վ����\n"));
	SAFE_DELETE(person1);
	SAFE_DELETE(person2)
	SAFE_DELETE(mediator);
	getchar();
	return 0;
}

