#include "Composite.h"


CComposite::CComposite(void)
{
}

CComposite::CComposite(string a_sName):CComponent(a_sName)
{

}


CComposite::~CComposite(void)
{
}

void CComposite::Add(CComponent* a_pComponent)
{
    m_child.push_back(a_pComponent);
}

void CComposite::Remove(CComponent* a_pComponent)
{
    m_child.remove(a_pComponent);
}

void CComposite::Display(int a_iDepth)
{
    cout<<string(a_iDepth,'-')<<m_sName<<endl;
    list<CComponent*>::iterator iter = m_child.begin();
    while(iter!=m_child.end()){
        (*iter)->Display(a_iDepth+1);
        iter++;
    }
}
