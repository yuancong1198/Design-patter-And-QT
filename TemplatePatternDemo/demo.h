#pragma once
#include <iostream>
using namespace std;

//AbstractClass�ǳ����࣬���岢ʵ����һ��ģ�巽�������ģ�巽��һ����һ�����巽������������һ�������߼��ĹǼܣ����߼�����ɲ�������Ӧ�ĳ��������
//���Ƴٵ�����ʵ�֡������߼�Ҳ���ܵ���һЩ���巽����
class AbstractClass
{
public:
	~AbstractClass(){}
	//�����ģ�巽�����������߼��ĹǼܣ����߼��������һЩ��Ӧ�ĳ�����������Ƕ��Ƴٵ�������ʵ��
	void TemplateMethod(){
		PrimitiveOperation1();
		PrimitiveOperation2();
	}
	//һЩ������Ϊ���ŵ�������ȥʵ��
	virtual void PrimitiveOperation1()=0;
	virtual void PrimitiveOperation2()=0;
protected:
	AbstractClass(){}

};

 //ʵ�ָ����������һ���������󷽷���ÿһ��AbstractClass��������������ConcreteClass��֮��Ӧ����ÿ��ConcreteClass�����Ը�����Щ���󷽷���Ҳ����
//�����߼�����ɲ��裩�Ĳ�ͬʵ�֣��Ӷ�ʹ�ö����߼���ʵ�ָ�����ͬ��
class ConcreteClassA : public AbstractClass
{
public:
	ConcreteClassA(){}
	~ConcreteClassA(){}
	//ʵ�ֻ��ඨ��ĳ�����Ϊ
	virtual void PrimitiveOperation1(){
		cout << "ConcreteClassA::PrimitiveOperation1" << endl;
	}
	virtual void PrimitiveOperation2(){
		cout << "ConcreteClassA::PrimitiveOperation2" << endl;
	}
};

//ʵ�ֻ���������ĳ��󷽷�
class ConcreteClassB : public AbstractClass
{
public:
	ConcreteClassB(){}
	~ConcreteClassB(){}
	//ʵ�ֻ��ඨ��ĳ�����Ϊ
	virtual void PrimitiveOperation1(){
		cout << "ConcreteClassB::PrimitiveOperation1" << endl;
	}
	virtual void PrimitiveOperation2(){
		cout << "ConcreteClassB::PrimitiveOperation2" << endl;
	}

};