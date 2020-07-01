#pragma once

#include <stdio.h>
	
/*
	简单工厂模式：简单工厂模式是工厂模式中最简单的一种，他可以用比较简单的方式隐藏创建对象的细节，一般只需要告诉工厂类所需要的类型，
工厂类就会返回需要的产品类，但客户端看到的只是产品的抽象对象，无需关心到底是返回了哪个子类。
*/

//产品基类： 工厂创建的所有产品的基类, 它负责描述所有实例所共有的公共接口。它用来作为工厂方法的返回参数。
class AbstractProduct{
public:
	AbstractProduct(){}
	virtual ~AbstractProduct(){}

public:
	virtual void operation() = 0;
};

//具体产品类：产品1和产品2，这个角色实现了抽象产品角色所定义的接口。
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

//工厂类的抽象基类，定义了创建产品的接口，该接口为纯虚函数。
class AbstractFactory{
public:
    AbstractFactory(){}
    virtual ~AbstractFactory(){}
    
public:
    virtual AbstractProduct* createProduct(int type) = 0;    
};

//工厂类：负责具体产品的创建，创建不同产品用相同的方法，然后通过传递参数实现不同产品的创建。
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