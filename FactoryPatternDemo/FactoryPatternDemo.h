#pragma once

/*����ģʽ��Ϊ����򵥹���ģʽ��Υ������ԭ�򣬶�ʵ�ֵ�һ�ֹ���ģʽ��*/
#include <stdio.h>

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
		 fprintf(stderr,"productA operation!\n");
	 }
 };

class ProductB:public AbstractProduct{
public:
    ProductB(){}
    ~ProductB(){}  
public:
    void operation(){
		fprintf(stderr,"productB operation!\n");
	}
};

//�������ࣺ�����˹���������Ʒ�Ľӿڣ�����û��ʵ�֣����崴����������̳���ʵ�֡�
class AbstractFactory{
public:
    AbstractFactory(){}
    virtual ~AbstractFactory(){}
public:
    virtual AbstractProduct* createProduct() = 0;    
};

//���幤���ࣺ��������ľ���ʵ�֣��ɴ���������������Ʒ	
class FactoryA:public AbstractFactory{
public:
    FactoryA(){}
    ~FactoryA(){}
public:
    AbstractProduct* createProduct(){
		AbstractProduct* temp = NULL;
		temp = new ProductA();
		return temp;
	}
};


class FactoryB:public AbstractFactory{
public:
    FactoryB(){}
    ~FactoryB(){}
public:
	AbstractProduct* createProduct(){
		AbstractProduct* temp = NULL;
		temp = new ProductB();
		return temp;
	}
};


//�����������ͻ�����ͨ����������ķ������ù���ʵ����������������Ҫ�ľ����Ʒ���Ӷ�ʵ�ֲ�Ʒ���ܵķ��ʡ�
void FactorPatternDemo()
{
   AbstractFactory* factory = new FactoryA();
   AbstractProduct* product = factory->createProduct();
   product->operation();
   delete product;
   product = NULL;
    delete factory;
    factory = NULL;
    
    factory = new FactoryB();
    product = factory->createProduct();
    product->operation();
    delete product;
    product = NULL;
    delete factory;
    factory = NULL;
}