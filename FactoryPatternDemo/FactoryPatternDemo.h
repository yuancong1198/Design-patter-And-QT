#pragma once

/*工厂模式：为解决简单工厂模式所违背开闭原则，而实现的一种工厂模式。*/
#include <stdio.h>

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

//工厂基类：定义了工厂创建产品的接口，但是没有实现，具体创建工作由其继承类实现。
class AbstractFactory{
public:
    AbstractFactory(){}
    virtual ~AbstractFactory(){}
public:
    virtual AbstractProduct* createProduct() = 0;    
};

//具体工厂类：工厂基类的具体实现，由此类决定创建具体产品	
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


//调用描述：客户程序通过工厂基类的方法调用工厂实现类用来创建所需要的具体产品。从而实现产品功能的访问。
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