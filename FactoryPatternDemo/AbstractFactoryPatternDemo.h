#pragma once

/*
	���󹤳�ģʽ���ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ�����ࡣ
*/

#include <stdio.h>


//��Ʒ���ࣺ���������Ʒ����A�Ͳ�Ʒ����B��ʵ������ʾ�������У���������Ʒ���ӹ�ͬ�Ļ���̳ж�����
//��������̳й�ϵȴ�������ģʽ֮��Ĳ��֣����������ģʽ���ĵ�����������Ʒ����Ĳ��첿�֡�
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

//��������ӿڣ������˴�����Ʒ�Ľӿڣ����ﷵ�ز����Ƿ��صĲ�ƷA����ƷB���������ƷA��B�Ĺ�ͬ����
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

//ͨ�����󹤳���ָ����ʾ��幤��ʵ����������Ӧϵ�еĲ�Ʒ��Ȼ��ͨ����Ʒ����ָ����ʲ�Ʒ���ܡ�
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