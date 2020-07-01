#pragma once
#include <iostream>
#include <list>
using namespace std;

//观察者（Observer)：为那些在目标发生改变时需要获得通知的对象定义一个更新接口。
class Observer
{
public:
    virtual void OnSystem(int) = 0 ;
};

//目标(Subject) : 目标知道它的观察者，可以有任意多个观察者观察同一个目标。 
class Subject
{
public:
    //提供注册和删除观察者对象的接口。
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};

//具体观察者（ConcreteObserver) : 重写接口Onsystem使自身状态与目标的状态保持一致。
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

//具体目标（ConcreteSubject) : 存入各个观察者的指针，当它的状态发生改变时，向它的各个观察者发出通知。
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

