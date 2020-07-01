#pragma once

/*
	抽象工厂模式：提供一个创建一系列相关或相互依赖对象的接口，二无需指定他们具体的类。
*/

#include <stdio.h>


//产品基类：这里包含产品基类A和产品基类B，实际上在示例代码中，这两个产品都从共同的基类继承而来，
//但是这个继承关系却是在这个模式之外的部分，而本身这个模式关心的是这两个产品基类的差异部分。
class AbstractProductA{

 public:
     AbstractProductA(){}
     virtual ~AbstractProductA(){}
     
 public:
     virtual void operationA() = 0;
 };
 
 class ProductA_1:public AbstractProductA{
 
 public:
     ProductA_1(){}
     virtual ~ProductA_1(){}
     
 public:
     void operationA(){
		 fprintf(stderr,"productA_1 operation!\n");
	 }
 };
 
 class ProductA_2:public AbstractProductA{
 
 public:
     ProductA_2(){}
     ~ProductA_2(){}
     
 public:
     void operationA(){
		 fprintf(stderr,"productA_2 operation!\n");
	 }
 };


class AbstractProductB{

 public:
     AbstractProductB(){}
     virtual ~AbstractProductB(){}
     
 public:
     virtual void operationB() = 0;
 };
 
 class ProductB_1:public AbstractProductB{
 
 public:
     ProductB_1(){}
     virtual ~ProductB_1(){}
     
 public:
     void operationB(){
		 fprintf(stderr,"productB_1 operation!\n");
	 }
 };
 
 class ProductB_2:public AbstractProductB{
 
 public:
     ProductB_2(){}
     ~ProductB_2(){}
     
 public:
     void operationB(){
		 fprintf(stderr,"productB_2 operation!\n");
	 }
 };

//工厂抽象接口：定义了创建产品的接口，这里返回参数是返回的产品A，产品B，而本身产品A和B的共同基类
class AbstractFactory{
 
 public:
     AbstractFactory(){}
     virtual ~AbstractFactory(){}
     
 public:
     virtual AbstractProductA* createProductA() = 0;    
     virtual AbstractProductB* createProductB() = 0;    
 };
 
 
 class Factory1:public AbstractFactory{
 
 public:
     Factory1(){}
     ~Factory1(){}
     
 public:
     AbstractProductA* createProductA(){
		 AbstractProductA* temp = NULL;
		 temp = new ProductA_1();
		 return temp;
	 }
     AbstractProductB* createProductB(){
		 AbstractProductB* temp = NULL;
		 temp = new ProductB_1();
		 return temp;
	 }
 };
 
 
 class Factory2:public AbstractFactory{
 
 public:
     Factory2(){}
     ~Factory2(){}
     
 public:
     AbstractProductA* createProductA(){
		 AbstractProductA* temp = NULL;
		 temp = new ProductA_2();
		 return temp;
	 }
     AbstractProductB* createProductB(){
		 AbstractProductB* temp = NULL;
		 temp = new ProductB_2();
		 return temp;
	 }
 };

//通过抽象工厂的指针访问具体工厂实现来创建对应系列的产品，然后通过产品基类指针访问产品功能。
 void AbstractFactoryPattternDemo()
 {
	 AbstractFactory* factory = new Factory1();
	 AbstractProductA* productA = factory->createProductA();
	 AbstractProductB* productB = factory->createProductB();
	 productA->operationA();
	 productB->operationB();

	 delete factory;
	 factory = NULL;
	 delete productA;
	 productA = NULL;
	 delete productB;
	 productB = NULL;

	 factory = new Factory2();
	 productA = factory->createProductA();
	 productB = factory->createProductB();
	 productA->operationA();
	 productB->operationB();

	 delete factory;
	 factory = NULL;
	 delete productA;
	 productA = NULL;
	 delete productB;
	 productB = NULL;
 }