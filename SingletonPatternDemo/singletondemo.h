#pragma once

//����ģʽ �� ��ָ����ʵ���ڳ�������ʱ������ִ�г�ʼ��
class Singleton1
{
public:
	static Singleton1* createInstance(){
		return m_pInstance;
	}
private:
	Singleton1(){}
	Singleton1(const Singleton1&){}
private:
	static Singleton1* m_pInstance;
};
Singleton1* Singleton1::m_pInstance = new Singleton1();

//����ģʽ �� ��ָ����ʵ���ڳ����һ��ʹ��ʱ�ű���ʼ��
class Singleton2
{
public:
	static Singleton2* createInstance(){
		static Singleton2* s_pInstance = new Singleton2();
		return s_pInstance;
	}
private:
	Singleton2(){}
	Singleton2(const Singleton2&){}
	Singleton2& operator=(const Singleton2&){}
};