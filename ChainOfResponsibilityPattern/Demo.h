#pragma once
#include <iostream>
using namespace std;

/*
程序的作用：
	对于每个角色，他们都有他们的职责；当我提交了休假申请时，项目经理需要判断，看看自己能否处理，如果休假超过了2个小时，
那么项目经理就不能处理了；项目经理将这个请求提交到项目主管，项目主管判断部门经理在不在，如果部门经理在，项目主管就不能处理了；
最后，我的休假申请就到了部门经理那里了，由他亲自审批。可以很明显的看到，项目经理、项目主管和部门经理都有可能处理我的休假申请，
我的请求沿着这条链一直走下去，直到有人处理了我的请求

*/

class HolidayRequest
{
public:
	HolidayRequest(int hour) : m_iHour(hour){}
	int GetHour() { return m_iHour; }
private:
	int m_iHour;
};

// 定义接口
//Handler：定义了一个处理请求的接口；其它类如果需要处理相同的请求，可以实现该接口就好了；
class Manager
{
public:
	virtual bool HandleRequest(HolidayRequest *pRequest) = 0;
};

// 项目经理
//ConcreteHandler：处理它所负责的请求，如果可处理该请求，就处理掉这个请求；否则将该请求转发给它的下一个可以处理该请求的对象，
//所以它必须能访问它的下一个可以处理同样请求的对象；
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

// 部门经理
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

// 项目主管
class PS : public Manager
{
public:
	PS(Manager *handler) : m_pHandler(handler){}
	bool HandleRequest(HolidayRequest *pRequest)
	{
		//将静态类型由base类转换到derived类，因此适用dynamic_cast
		DM *pDM = dynamic_cast<DM *>(m_pHandler);
		//如果部门经理在，则转交部门经理处理
		if (pDM != nullptr)
		{
			if (pDM->IsIn())
			{
				return pDM->HandleRequest(pRequest);
			}
		}
		//部门经理不在，自己处理
		cout << "PS said:OK." << endl;
		return true;
	}
private:
	Manager *m_pHandler;
};

