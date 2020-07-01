#pragma once

/*
	���ľ����ⷿΪ���ӣ����û�з����н飬��ô����Ҫ�Լ��ҷ�����������ҲҪ�Լ��ҷ��ͣ��ǳ������㡣���˷����н�����ͷ����ˣ�
�������԰�Ҫ����ķ�����Ϣ�ŵ��н�����������Ϳ���ȥ�н������ѯ��������У����Ƕ������֮����Ҫͨ�ţ����û���н飬
�������Ҫ֪���������������£�������Ҫ֪�������������󣬶������н����ͷ�����ˣ�����ֻ�����н����ͨ�ţ�������֪�������Ķ���
������н���ģʽ.
*/

#include <iostream>  
#include <string>
using namespace std;

 #define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

/*���������н���*/
class Mediator;

/*�����������*/
class Person
{
public:
	virtual void SetMediator(Mediator *mediator){} 
	virtual void SendMessage(string &message){}
	virtual void GetMessage(string &message){}
protected:
	Mediator *p_mediator; //�н�    
};
 
/*��������н���*/
//Mediator�����н��߽�ɫ������ͳһ�ӿڣ����ڸ���ͬ�½�ɫ֮���ͨ��
class Mediator
{
public:
     virtual void Send(string &message, Person *person){}
     virtual void SetRenter(Person *renter){}
     virtual void SetLandlord(Person *landlord){}
 };
 
/*���������*/
//Colleagueͬ�½�ɫ��ÿ��ͬ�½�ɫ��Ӧ��֪���н�Ĵ��ڣ���ͬ�¼�ͨ��һ����ͨ���н�Э����ͬ����Ϊ�֣��Է���Ϊ��������Ϊ
class Renter:public Person
{
public:
    void SetMediator(Mediator *mediator){p_mediator = mediator;}
    void SendMessage(string &message){ p_mediator->Send(message,this);}
    void GetMessage(string &message){cout<<"�ⷿ���յ�������������Ϣ��"<<message;}
};

/*���巿����*/
class Landlord:public Person
{
public:
    void SetMediator(Mediator *mediator){p_mediator = mediator;}
    void SendMessage(string &message){ p_mediator->Send(message,this);}
    void GetMessage(string &message){cout<<"�����յ���ͷ�������Ϣ��"<<message;}
};

/*��������н���*/
//ConcreteMediator�����н��߽�ɫ��ͨ��Э������ͬ�½�ɫʵ��Э����Ϊ�������ڸ���ͬ��
class HouseMediator:public Mediator
{
public:
    HouseMediator():p_renter(NULL),p_landlord(NULL){}
    void SetRenter(Person *renter){p_renter = renter;}
    void SetLandlord(Person *landlord){p_landlord = landlord;}
    void Send(string &message, Person *person)
	{//������Ϣ�Ķ���Ϊ�ö���Ķ�Ӧ����
		if(person == p_renter)
			p_landlord->GetMessage(message);
		else
			p_renter->GetMessage(message);
	}
private:
    Person *p_renter;
    Person *p_landlord;
};