// IteratorPatternDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "demo.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	Aggregate<int> * aggr =new ConcreteAggregate<int>();  
    Iterator<int> *it=aggr->createIterator();  
  
    for(it->first();!it->isDone();it->next())  
    {  
        cout<<*(it->currentItem())<<endl;  
    }  
    delete it;  
    delete aggr; 
	getchar();
	return 0;
}

