#pragma once
#include <iostream>
#include <list>
using namespace std;

//�۲��ߣ�Observer)��Ϊ��Щ��Ŀ�귢���ı�ʱ��Ҫ���֪ͨ�Ķ�����һ�����½ӿڡ�
class Observer
{
public:
    virtual void OnSystem(int) = 0 ;
};

//Ŀ��(Subject) : Ŀ��֪�����Ĺ۲��ߣ��������������۲��߹۲�ͬһ��Ŀ�ꡣ 
class Subject
{
public:
    //�ṩע���ɾ���۲��߶���Ľӿڡ�
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};

//����۲��ߣ�ConcreteObserver) : ��д�ӿ�Onsystemʹ����״̬��Ŀ���״̬����һ�¡�
class ConcreteObserver1 : public Observer
{
public:
    virtual void OnSystem(int value){
        cout<<"ConcreteObserver1 get the Onsystem.New State: "<<value<<endl;
    }
};
class ConcreteObserver2 : public Observer
{
public:
    virtual void OnSystem(int value){
        cout<<"ConcreteObserver2 get the Onsystem.New State: "<<value<<endl;
    }
};

//����Ŀ�꣨ConcreteSubject) : ��������۲��ߵ�ָ�룬������״̬�����ı�ʱ�������ĸ����۲��߷���֪ͨ��
class ConcreteSubject : public Subject
{
public:
    virtual void Attach(Observer* obj){
        m_lstObserverList.push_back(obj);
    }
    virtual void Detach(Observer* obj){
        m_lstObserverList.remove(obj);
    }
    virtual void Notify(){
        for(list<Observer*>::iterator iter=m_lstObserverList.begin();iter!=m_lstObserverList.end();++iter){
            (*iter)->OnSystem(m_iState);
        }
    }
    void setState(int state){
        m_iState = state;
    }
private:
    list<Observer*> m_lstObserverList;
    int m_iState;
};

