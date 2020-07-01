#pragma once

/*
	本文就以租房为例子，如果没有房屋中介，那么房客要自己找房东，而房东也要自己找房客，非常不方便。有了房屋中介机构就方便了，
房东可以把要出租的房屋信息放到中介机构，而房客可以去中介机构咨询。在软件中，就是多个对象之间需要通信，如果没有中介，
对象就需要知道其他对象，最坏情况下，可能需要知道所有其他对象，而有了中介对象就方便多了，对象只需与中介对象通信，而不用知道其他的对象。
这就是中介者模式.
*/

#include <iostream>  
#include <string>
using namespace std;

 #define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

/*声明抽象中介类*/
class Mediator;

/*定义抽象人类*/
class Person
{
public:
	virtual void SetMediator(Mediator *mediator){} 
	virtual void SendMessage(string &message){}
	virtual void GetMessage(string &message){}
protected:
	Mediator *p_mediator; //中介    
};
 
/*定义抽象中介类*/
//Mediator抽象中介者角色，定义统一接口，用于各个同事角色之间的通信
class Mediator
{
public:
     virtual void Send(string &message, Person *person){}
     virtual void SetRenter(Person *renter){}
     virtual void SetLandlord(Person *landlord){}
 };
 
/*定义租客类*/
//Colleague同事角色，每个同事角色都应该知道中介的存在，且同事间通信一定是通过中介协作；同事行为分：自发行为，依赖行为
class Renter:public Person
{
public:
    void SetMediator(Mediator *mediator){p_mediator = mediator;}
    void SendMessage(string &message){ p_mediator->Send(message,this);}
    void GetMessage(string &message){cout<<"租房者收到房东发来的消息："<<message;}
};

/*定义房东类*/
class Landlord:public Person
{
public:
    void SetMediator(Mediator *mediator){p_mediator = mediator;}
    void SendMessage(string &message){ p_mediator->Send(message,this);}
    void GetMessage(string &message){cout<<"房东收到租客发来的消息："<<message;}
};

/*定义具体中介类*/
//ConcreteMediator具体中介者角色，通过协调各个同事角色实现协作行为，依赖于各个同事
class HouseMediator:public Mediator
{
public:
    HouseMediator():p_renter(NULL),p_landlord(NULL){}
    void SetRenter(Person *renter){p_renter = renter;}
    void SetLandlord(Person *landlord){p_landlord = landlord;}
    void Send(string &message, Person *person)
	{//接收消息的对象为该对象的对应对象
		if(person == p_renter)
			p_landlord->GetMessage(message);
		else
			p_renter->GetMessage(message);
	}
private:
    Person *p_renter;
    Person *p_landlord;
};