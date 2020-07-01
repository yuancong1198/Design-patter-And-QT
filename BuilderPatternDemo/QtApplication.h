#pragma once

#include <iostream>
#include <string>
using namespace std;


class CenterWidget
{
public:
	void setupUi(const string& x){
		Ui = x;
	}
	void setupAnimation(const string& x){
		Animation = x;
	}
	void setupSlot(const string& x){
		Slot = x;
	}
	void show(){
		cout<<"Ui = "<<Ui<<" Animation = "<<Animation<<" Slot = "<<Slot<<endl;
	}
private:
	string Ui;
	string Animation;
	string Slot;
};


class CenterWidgetBuilder
{
public:
	virtual void initUi() = 0;
	virtual void initAnimation() = 0;
	virtual void initSlot() = 0;
	virtual CenterWidget* getResult() = 0;
};

class CenterWidgetBuilderA : public CenterWidgetBuilder
{
public:
	CenterWidgetBuilderA():m_curWidget(new CenterWidget){}
	virtual ~CenterWidgetBuilderA(){
		delete m_curWidget;
	}
	virtual void initUi(){
		m_curWidget->setupUi("Q Ui");
	}
	virtual void initAnimation(){
		m_curWidget->setupAnimation("Biu~Biu~Biu~");
	}
	virtual void initSlot(){
		m_curWidget->setupSlot("connected to your heart ");
	}
	CenterWidget* getResult(){
		return m_curWidget;
	}
private:
	CenterWidget* m_curWidget;
};


class CenterWidgetBuilderB : public CenterWidgetBuilder
{
public:
	CenterWidgetBuilderB():m_curWidget(new CenterWidget){}
	virtual ~CenterWidgetBuilderB(){
		delete m_curWidget;
	}
	virtual void initUi(){
		m_curWidget->setupUi("Q Ui");
	}
	virtual void initAnimation(){
		m_curWidget->setupAnimation("Boom~Boom~Boom~");
	}
	virtual void initSlot(){
		m_curWidget->setupSlot("connected to your heart ");
	}
	CenterWidget* getResult(){
		return m_curWidget;
	}
private:
	CenterWidget* m_curWidget;
};

class Dirctor
{
public:
	void Construct(CenterWidgetBuilder* builder){
		builder->initUi();
		builder->initAnimation();
		builder->initSlot();
	}
};

void testBuilder()
{
	CenterWidgetBuilder* builderA = new CenterWidgetBuilderA();
	Dirctor* directorA = new Dirctor();
	directorA->Construct(builderA);
	builderA->getResult()->show();

	CenterWidgetBuilder* builderB = new CenterWidgetBuilderB();
	Dirctor* directorB = new Dirctor();
	directorB->Construct(builderB);
	builderB->getResult()->show();
}

/*

建造者模式的主要优点：
	将产品本身和产品的创建过程解耦，使得不同的创建过程创建出不同的实例可以很方便的增加新的创建者，实现新的产品实例的创建，符合开闭原则。

建造者模式的主要缺点：
	建造者模式只能创建具有许多共同点的产品，组成成分相似如果产品内部组成复杂多变，将需要定义大量的建造者类，使得系统复杂化。

*/