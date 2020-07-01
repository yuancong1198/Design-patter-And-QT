#pragma once

#include <iostream>


//Component�Ƕ���һ������ӿڣ����Ը���Щ����̬�����ְ��
class Component
{
public:
	virtual void Operator()=0;
};

//ConcreteComponent�Ƕ����� һ������Ķ���Ҳ���Ը�����������һЩְ��
class ConcreteComponent : public Component
{
public:
	virtual void Operator(){
		std::cout<<"basic function in ConcreteCompoent class!"<<std::endl;
	}
};

//Decoratorװ�γ����࣬�̳���Component������������չComponent��Ĺ��ܣ�������Comonent��˵��������֪��Decortor�Ĵ��ڵġ�
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

//ConcreteDecorator���Ǿ��е�װ�ζ����𵽸�Component���ְ��Ĺ��ܡ�
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