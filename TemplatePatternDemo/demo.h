#pragma once
#include <iostream>
using namespace std;

//AbstractClass是抽象类，定义并实现了一个模板方法。这个模板方法一般是一个具体方法，它给出了一个顶级逻辑的骨架，而逻辑的组成步骤在相应的抽象操作中
//，推迟到子类实现。顶级逻辑也可能调用一些具体方法。
class AbstractClass
{
public:
	~AbstractClass(){}
	//具体的模板方法，给出了逻辑的骨架，而逻辑的组成是一些相应的抽象操作，它们都推迟到子类中实现
	void TemplateMethod(){
		PrimitiveOperation1();
		PrimitiveOperation2();
	}
	//一些抽象行为，放到子类中去实现
	virtual void PrimitiveOperation1()=0;
	virtual void PrimitiveOperation2()=0;
protected:
	AbstractClass(){}

};

 //实现父类所定义的一个或多个抽象方法。每一个AbstractClass都可以有任意多个ConcreteClass与之对应，而每个ConcreteClass都可以给出这些抽象方法（也就是
//顶级逻辑的组成步骤）的不同实现，从而使得顶级逻辑的实现各不相同。
class ConcreteClassA : public AbstractClass
{
public:
	ConcreteClassA(){}
	~ConcreteClassA(){}
	//实现基类定义的抽象行为
	virtual void PrimitiveOperation1(){
		cout << "ConcreteClassA::PrimitiveOperation1" << endl;
	}
	virtual void PrimitiveOperation2(){
		cout << "ConcreteClassA::PrimitiveOperation2" << endl;
	}
};

//实现基类所定义的抽象方法
class ConcreteClassB : public AbstractClass
{
public:
	ConcreteClassB(){}
	~ConcreteClassB(){}
	//实现基类定义的抽象行为
	virtual void PrimitiveOperation1(){
		cout << "ConcreteClassB::PrimitiveOperation1" << endl;
	}
	virtual void PrimitiveOperation2(){
		cout << "ConcreteClassB::PrimitiveOperation2" << endl;
	}

};