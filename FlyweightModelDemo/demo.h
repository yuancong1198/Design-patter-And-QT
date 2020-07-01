#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;


class Flyweight //�������Ԫ��
{
public:
    virtual void Operator(int i) = 0;
};

class ConcreteFlyweight : public Flyweight //���������
{
public:
    virtual void Operator(int i) {
        cout<<"�����FlyWeight: "<<i<<endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight //�����������
{
public:
    virtual void Operator(int i){
        cout<<"�������FlyWeight: "<<i<<endl;
    }
};

class FlyweightFactory // ��Ԫ����
{
public:
    FlyweightFactory(){
        //��ʼ����ģ���б�
        m_mpFlywidghts["X"] = new ConcreteFlyweight();
        m_mpFlywidghts["Y"] = new ConcreteFlyweight();
        m_mpFlywidghts["Z"] = new ConcreteFlyweight();
    }
    //����������Ԫ���󣬶���Щ��������Զ������һ���ù�����ģ�����б���
    Flyweight* getFlyweight(string key){
        if(!m_mpFlywidghts.count(key)){
            m_mpFlywidghts[key] = new ConcreteFlyweight();
        }
        return m_mpFlywidghts[key];
    }
    //���ص�ǰ�ж��ٸ��ɹ������ģ��
    map<string,Flyweight*>::size_type countN(){
        return m_mpFlywidghts.size();
    }
private:
    map<string,Flyweight*> m_mpFlywidghts;      //ģ�������
};