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
    cout<<"������Ҷ�ӽڵ���Ӳ���"<<endl;
}

void CLeft::Remove(CComponent*)
{
    cout<<"���ܴ�Ҷ�ӽڵ�ɾ������"<<endl;
}

void CLeft::Display(int a_iDepth)
{
    cout<<string(a_iDepth,'-')<<m_sName<<endl;
}
