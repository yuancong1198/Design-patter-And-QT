#pragma once
#include<string>
#include<iostream>
using namespace std;


class Monostate
{
public:
	Monostate(){}
	void setData(string a_sString){
		m_sString = a_sString;
	}
	string data()const{
		return m_sString;
	}
private:
	static string m_sString;
};
string Monostate::m_sString = "";