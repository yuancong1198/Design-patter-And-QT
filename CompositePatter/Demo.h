#ifndef _DEMO_H
#define _DEMO_H
#include<string.h>
#include<iostream>
#include<list>
using namespace std;

class Component
{
public:
	Component(string a_sName):m_sName(a_sName){}
	//通常都用Add和Remove方法来提供增加或移除树叶或树枝的功能
	virtual void Add(Component* c) = 0;
	virtual void Remove(Component* c) = 0;
	virtual void Display(int depth) = 0;
public:
	string m_sName;
};

//Leaf在组合中表示叶节点对象，叶节点没有子节点。
class Leaf : public Component
{
public:
	Leaf(string a_sName):Component(a_sName){}
	//由于叶子没有再增加分支和树叶，所以Add和Remove方法实现它没有意义，但是这样做可以消除叶节点和枝节点
	//对象在抽象层次的区别，他们具有完全一致的接口。
	virtual void Add(Component* c){
		cout<<"cannot add to a leaf"<<endl;
	}
	virtual void Remove(Component* c){
		cout<<"cannot reomve from a leaf"<<endl;
	}
	virtual void Display(int depth){
		string s(depth,'-');
		s += m_sName;
		cout<< s.c_str() <<endl;
	}
};

class Composite : public Component
{
public:
	Composite(string a_sName):Component(a_sName){}
	virtual void Add(Component* c){
		m_lstChildren.push_back(c);
	}
	virtual void Remove(Component* c){
		m_lstChildren.remove(c);
	}
	//显示其枝节点名称，并对其下级进行便利
	virtual void Display(int depth){
		string s(depth,'-');
		s += m_sName;
		cout<< s.c_str() <<endl;
		list<Component*>::iterator iter;
		for(iter = m_lstChildren.begin();iter != m_lstChildren.end();iter++){
			(*iter)->Display(depth+2);
		}
	}
private:
	//一个子对象集合用来存储其下属的枝节点和叶节点
	list<Component*> m_lstChildren;
};



#endif