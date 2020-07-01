#pragma once
#include "ccomponent.h"

//叶子节点类
class CLeft : public CComponent
{
public:
    CLeft(void);
    ~CLeft(void);
    CLeft(string a_sName);
    void Add(CComponent*);
    void Remove(CComponent*);
    void Display(int a_iDepth);
};

