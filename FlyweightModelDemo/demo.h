#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;


class Flyweight //抽象的享元类
{
public:
    virtual void Operator(int i) = 0;
};

class ConcreteFlyweight : public Flyweight //共享的子类
{
public:
    virtual void Operator(int i) {
        cout<<"共享的FlyWeight: "<<i<<endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight //不共享的子类
{
public:
    virtual void Operator(int i){
        cout<<"不共享的FlyWeight: "<<i<<endl;
    }
};

class FlyweightFactory // 享元工厂
{
public:
    FlyweightFactory(){
        //初始共享模块列表
        m_mpFlywidghts["X"] = new ConcreteFlyweight();
        m_mpFlywidghts["Y"] = new ConcreteFlyweight();
        m_mpFlywidghts["Z"] = new ConcreteFlyweight();
    }
    //工厂返回享元对象，而这些对象的属性都存放在一个该工厂的模块名列表中
    Flyweight* getFlyweight(string key){
        if(!m_mpFlywidghts.count(key)){
            m_mpFlywidghts[key] = new ConcreteFlyweight();
        }
        return m_mpFlywidghts[key];
    }
    //返回当前有多少个可供共享的模块
    map<string,Flyweight*>::size_type countN(){
        return m_mpFlywidghts.size();
    }
private:
    map<string,Flyweight*> m_mpFlywidghts;      //模块名类表
};