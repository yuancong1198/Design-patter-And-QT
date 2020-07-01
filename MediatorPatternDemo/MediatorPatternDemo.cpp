// MediatorPatternDemo.cpp : 定义控制台应用程序的入口点。
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
	person1->SendMessage(string("我想在深圳北站附近租套房子，一室一厅\n"));
	person2->SendMessage(string("我出租一条房子，一室一厅，深圳北站附近\n"));
	SAFE_DELETE(person1);
	SAFE_DELETE(person2)
	SAFE_DELETE(mediator);
	getchar();
	return 0;
}

