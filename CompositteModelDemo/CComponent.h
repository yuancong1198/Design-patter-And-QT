#pragma once
#include <iostream>
#include <string>
using namespace std;


//�����࣬�û�ͨ���ýӿ����������Ӳ���
class CComponent
{
public:
    CComponent(){}
    CComponent(string a_sName):m_sName(a_sName){}
    virtual void Add(CComponent*) = 0;
    virtual void Remove(CComponent*) = 0;
    virtual void Display(int a_iDepth) = 0;
protected:
    string m_sName;
};