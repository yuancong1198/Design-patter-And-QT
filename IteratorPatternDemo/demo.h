#pragma once
#include <iostream>  
#include <vector>  
using namespace std;  

//迭代器角色（Iterator）：迭代器角色负责定义访问和遍历元素的接口。
template<class Item>  
class Iterator  
{  
public:  
    virtual void first()=0;  
    virtual void next()=0;  
    virtual Item* currentItem()=0;  
    virtual bool isDone()=0;  
    virtual ~Iterator(){}  
}; 

template<class Item>  
class ConcreteAggregate;

//具体迭代器角色（Concrete Iterator）：具体迭代器角色要实现迭代器接口，并要记录遍历中的当前位置。
template<class Item>  
class ConcreteIterator : public Iterator<Item>  
{  
    ConcreteAggregate<Item> * aggr;  
    int cur;  
public:  
    ConcreteIterator(ConcreteAggregate<Item>* a):aggr(a),cur(0){}  
    virtual void first()  
    {  
        cur=0;  
    }  
    virtual void next()  
    {  
        if(cur<aggr->getLen())  
            cur++;  
    }  
    virtual Item* currentItem()  
    {  
        if(cur<aggr->getLen())  
            return &(*aggr)[cur];  
        else  
            return NULL;  
    }  
    virtual bool isDone()  
    {  
        return (cur>=aggr->getLen());  
    }  
}; 

//集合角色（Aggregate）：集合角色负责提供创建具体迭代器角色的接口。
template<class Item>  
class Aggregate  
{  
public:  
    virtual Iterator<Item>* createIterator()=0;  
    virtual ~Aggregate(){}  
}; 

//具体集合角色（Concrete Aggregate）：具体集合角色实现创建具体迭代器角色的接口——这个具体迭代器角色于该集合的结构相关
template<class Item>  
class ConcreteAggregate:public Aggregate<Item>  
{  
    vector<Item >data;  
public:  
    ConcreteAggregate()  
    {  
        data.push_back(1);  
        data.push_back(2);  
        data.push_back(3);  
    }  
    virtual Iterator<Item>* createIterator()  
    {  
        return new ConcreteIterator<Item>(this);  
    }  
    Item& operator[](int index)  
    {  
        return data[index];  
    }  
    int getLen()  
    {  
        return data.size();  
    }  
}; 