#pragma once
#include <iostream>
using namespace std;

//Strategy����������֧�ֵ��㷨�Ĺ����ӿڡ�Contextʹ������ӿ�������ĳConcreteStrategy������㷨��
class StrategyObject
{
public:
	virtual void AlgorithmInterface() = 0;
};

//ConcreteStrategy��ʵ��Strategy�ӿڵľ����㷨��
class ConcreteStrategyObjectA : public StrategyObject
{
public:
	void AlgorithmInterface()
	{
		cout<<"I am from ConcreteStrategyA."<<endl;
	}
};

class ConcreteStrategyObjectB : public StrategyObject
{
public:
	void AlgorithmInterface()
	{
		cout<<"I am from ConcreteStrategyB."<<endl;
	}
};

class ConcreteStrategyObjectC : public StrategyObject
{
public:
	void AlgorithmInterface()
	{
		cout<<"I am from ConcreteStrategyC."<<endl;
	}
};

//Context��ʹ��һ��ConcreteStrategy���������ã�ά��һ����Stategy��������ã�ͬʱ�����Զ���һ���ӿ�����Stategy�����������ݡ�
class ContextObject
{
public:
	ContextObject(StrategyObject *pStrategyArg) : pStrategy(pStrategyArg)
	{
	}
	void ContextInterface()
	{
		pStrategy->AlgorithmInterface();
	}
private:
	StrategyObject *pStrategy;
};