#pragma once
#include <iostream>
using namespace std;

//Strategy：定义所有支持的算法的公共接口。Context使用这个接口来调用某ConcreteStrategy定义的算法；
class StrategyObject
{
public:
	virtual void AlgorithmInterface() = 0;
};

//ConcreteStrategy：实现Strategy接口的具体算法；
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

//Context：使用一个ConcreteStrategy对象来配置；维护一个对Stategy对象的引用，同时，可以定义一个接口来让Stategy访问它的数据。
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