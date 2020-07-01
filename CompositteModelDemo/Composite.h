#pragma once
#include "ccomponent.h"
#include <list>
using std::list;


//��֧�ڵ��ࣨ��Ҷ�ӽڵ㣩
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
    list<CComponent*> m_child;  //��֧�ڵ������
};

