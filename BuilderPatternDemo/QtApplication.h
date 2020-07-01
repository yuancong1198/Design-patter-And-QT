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

������ģʽ����Ҫ�ŵ㣺
	����Ʒ����Ͳ�Ʒ�Ĵ������̽��ʹ�ò�ͬ�Ĵ������̴�������ͬ��ʵ�����Ժܷ���������µĴ����ߣ�ʵ���µĲ�Ʒʵ���Ĵ��������Ͽ���ԭ��

������ģʽ����Ҫȱ�㣺
	������ģʽֻ�ܴ���������๲ͬ��Ĳ�Ʒ����ɳɷ����������Ʒ�ڲ���ɸ��Ӷ�䣬����Ҫ��������Ľ������࣬ʹ��ϵͳ���ӻ���

*/