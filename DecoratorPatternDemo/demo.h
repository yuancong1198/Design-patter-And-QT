#pragma once

#include <iostream>


//Component是定义一个对象接口，可以给这些对象动态地添加职责。
class Component
{
public:
	virtual void Operator()=0;
};

//ConcreteComponent是定义了 一个具体的对象，也可以给这个对象添加一些职责。
class ConcreteComponent : public Component
{
public:
	virtual void Operator(){
		std::cout<<"basic function in ConcreteCompoent class!"<<std::endl;
	}
};

//Decorator装饰抽象类，继承了Component，从外类来扩展Component类的功能，但对于Comonent来说，是无需知道Decortor的存在的。
class Decorator : public Component
{
public:
	Decorator(Component* a_sComponent):m_pComponent(a_sComponent){}
	virtual void Operator(){
		m_pComponent->Operator();
	}
private:
	Component* m_pComponent;
};

//ConcreteDecorator就是具有的装饰对象，起到给Component添加职责的功能。
class ConcreteDecorator : public Decorator
{
public:
	ConcreteDecorator(Component* a_sComponent):Decorator(a_sComponent){}
	void addBehavior(){
		std::cout<<"ConcreteDecorator addBehavior function!"<<std::endl;
	}
};

void DecoratorDemo()
{
	Component* pConcreateComponent = new ConcreteComponent();
	Component* pComcreateDecorator = new ConcreteDecorator(pConcreateComponent);
	pComcreateDecorator->Operator();
	dynamic_cast<ConcreteDecorator*>(pComcreateDecorator)->addBehavior();
}