#include "Left.h"


CLeft::CLeft(void)
{
}

CLeft::CLeft(string a_sName):CComponent(a_sName)
{
    
}


CLeft::~CLeft(void)
{
}

void CLeft::Add(CComponent*)
{
    cout<<"不能向叶子节点添加部件"<<endl;
}

void CLeft::Remove(CComponent*)
{
    cout<<"不能从叶子节点删除部件"<<endl;
}

void CLeft::Display(int a_iDepth)
{
    cout<<string(a_iDepth,'-')<<m_sName<<endl;
}
