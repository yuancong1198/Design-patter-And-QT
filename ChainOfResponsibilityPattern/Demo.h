#pragma once
#include <iostream>
using namespace std;

/*
��������ã�
	����ÿ����ɫ�����Ƕ������ǵ�ְ�𣻵����ύ���ݼ�����ʱ����Ŀ������Ҫ�жϣ������Լ��ܷ�������ݼٳ�����2��Сʱ��
��ô��Ŀ����Ͳ��ܴ����ˣ���Ŀ������������ύ����Ŀ���ܣ���Ŀ�����жϲ��ž����ڲ��ڣ�������ž����ڣ���Ŀ���ܾͲ��ܴ����ˣ�
����ҵ��ݼ�����͵��˲��ž��������ˣ������������������Ժ����ԵĿ�������Ŀ������Ŀ���ܺͲ��ž����п��ܴ����ҵ��ݼ����룬
�ҵ���������������һֱ����ȥ��ֱ�����˴������ҵ�����

*/

class HolidayRequest
{
public:
	HolidayRequest(int hour) : m_iHour(hour){}
	int GetHour() { return m_iHour; }
private:
	int m_iHour;
};

// ����ӿ�
//Handler��������һ����������Ľӿڣ������������Ҫ������ͬ�����󣬿���ʵ�ָýӿھͺ��ˣ�
class Manager
{
public:
	virtual bool HandleRequest(HolidayRequest *pRequest) = 0;
};

// ��Ŀ����
//ConcreteHandler�����������������������ɴ�������󣬾ʹ����������󣻷��򽫸�����ת����������һ�����Դ��������Ķ���
//�����������ܷ���������һ�����Դ���ͬ������Ķ���
class PM : public Manager
{
public:
	PM(Manager *handler) : m_pHandler(handler){}
	bool HandleRequest(HolidayRequest *pRequest)
	{
		if (pRequest->GetHour() <= 2 || m_pHandler == nullptr)
		{
			cout << "PM said:OK." << endl;
			return true;
		}
		return m_pHandler->HandleRequest(pRequest);
	}
private:
	Manager *m_pHandler;
};

// ���ž���
class DM : public Manager
{
public:
	DM(Manager *handler) : m_pHandler(handler){}
	bool HandleRequest(HolidayRequest *pRequest)
	{
		cout << "DM said:OK." << endl;
		return true;
	}

	// The department manager is in?
	bool IsIn()
	{
		return true;
	}
private:
	Manager *m_pHandler;
};

// ��Ŀ����
class PS : public Manager
{
public:
	PS(Manager *handler) : m_pHandler(handler){}
	bool HandleRequest(HolidayRequest *pRequest)
	{
		//����̬������base��ת����derived�࣬�������dynamic_cast
		DM *pDM = dynamic_cast<DM *>(m_pHandler);
		//������ž����ڣ���ת�����ž�����
		if (pDM != nullptr)
		{
			if (pDM->IsIn())
			{
				return pDM->HandleRequest(pRequest);
			}
		}
		//���ž����ڣ��Լ�����
		cout << "PS said:OK." << endl;
		return true;
	}
private:
	Manager *m_pHandler;
};

