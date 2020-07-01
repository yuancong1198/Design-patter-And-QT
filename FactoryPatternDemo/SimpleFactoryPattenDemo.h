#pragma once

#include <stdio.h>
	
/*
	�򵥹���ģʽ���򵥹���ģʽ�ǹ���ģʽ����򵥵�һ�֣��������ñȽϼ򵥵ķ�ʽ���ش��������ϸ�ڣ�һ��ֻ��Ҫ���߹���������Ҫ�����ͣ�
������ͻ᷵����Ҫ�Ĳ�Ʒ�࣬���ͻ��˿�����ֻ�ǲ�Ʒ�ĳ������������ĵ����Ƿ������ĸ����ࡣ
*/

//��Ʒ���ࣺ �������������в�Ʒ�Ļ���, ��������������ʵ�������еĹ����ӿڡ���������Ϊ���������ķ��ز�����
class AbstractProduct{
public:
	AbstractProduct(){}
	virtual ~AbstractProduct(){}

public:
	virtual void operation() = 0;
};

//�����Ʒ�ࣺ��Ʒ1�Ͳ�Ʒ2�������ɫʵ���˳����Ʒ��ɫ������Ľӿڡ�
class ProductA:public AbstractProduct{

public:
    ProductA(){}
    virtual ~ProductA(){}
    
public:
    void operation(){
		printf("product1 operation!\n");
	}
};

class ProductB:public AbstractProduct{

public:
    ProductB(){}
    ~ProductB(){}
    
public:
    void operation(){
		printf("product2 operation!\n");
	}
};

//������ĳ�����࣬�����˴�����Ʒ�Ľӿڣ��ýӿ�Ϊ���麯����
class AbstractFactory{
public:
    AbstractFactory(){}
    virtual ~AbstractFactory(){}
    
public:
    virtual AbstractProduct* createProduct(int type) = 0;    
};

//�����ࣺ��������Ʒ�Ĵ�����������ͬ��Ʒ����ͬ�ķ�����Ȼ��ͨ�����ݲ���ʵ�ֲ�ͬ��Ʒ�Ĵ�����
class SimpleFactory:public AbstractFactory{

public:
    SimpleFactory(){}
    ~SimpleFactory(){}
    
public:
    AbstractProduct* createProduct(int type){
		AbstractProduct* temp = NULL;
		switch(type)
		{
		case 1:
			temp = new ProductA();
			break;
		case 2:
			temp = new ProductB();
			break;
		default:
			break;
		}
		return temp;
	}
};

void SimpleFactoryClient()
{
	AbstractFactory* factory = new SimpleFactory();
	AbstractProduct* product = factory->createProduct(1);
	product->operation();
	delete product;
	product = NULL;

	product = factory->createProduct(2);
	product->operation();
	delete product;
	product = NULL;
}