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
	//ͨ������Add��Remove�������ṩ���ӻ��Ƴ���Ҷ����֦�Ĺ���
	virtual void Add(Component* c) = 0;
	virtual void Remove(Component* c) = 0;
	virtual void Display(int depth) = 0;
public:
	string m_sName;
};

//Leaf������б�ʾҶ�ڵ����Ҷ�ڵ�û���ӽڵ㡣
class Leaf : public Component
{
public:
	Leaf(string a_sName):Component(a_sName){}
	//����Ҷ��û�������ӷ�֧����Ҷ������Add��Remove����ʵ����û�����壬������������������Ҷ�ڵ��֦�ڵ�
	//�����ڳ����ε��������Ǿ�����ȫһ�µĽӿڡ�
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
	//��ʾ��֦�ڵ����ƣ��������¼����б���
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
	//һ���Ӷ��󼯺������洢��������֦�ڵ��Ҷ�ڵ�
	list<Component*> m_lstChildren;
};



#endif