#pragma once
#include "ccomponent.h"
#include <list>
using std::list;


//分支节点类（非叶子节点）
class CComposite : public CComponent
{
public:
    CComposite(void);
    ~CComposite(void);
    CComposite(string a_sName);
    void Add(CComponent* a_pComponent);
    void Remove(CComponent* a_pComponent);
    void Display(int a_iDepth);
private:
    list<CComponent*> m_child;  //分支节点的容器
};

