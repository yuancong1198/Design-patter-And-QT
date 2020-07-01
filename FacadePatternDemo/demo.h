#pragma once

#include <iostream>
using namespace std;

/*
Camera/Light/Screen��ϵͳ�࣬����ʵ����ϵͳ�Ĺ��ܡ�
*/
class Camera
{
public:
	Camera(){}
	~Camera(){}
	void TrunOn(){
		cout << "�������!" << endl;
	}
	void TrunOff(){
		cout << "������ر�!" << endl;
	}
	void Rotate(int degrees){
		cout << "Rotate the camera by "<<degrees<< "degrees!" <<endl;
	}
};

class Light
{
public:
	Light(){}
	~Light(){}
	void TrunOn(){
		cout << "�ƹ��!" << endl;
	}
	void TrunOff(){
		cout << "�ƹ�ر�!" << endl;
	}
};

class Screen
{
public:
	Screen(){}
	~Screen(){}
	void TrunOn(){
		cout << "��ʾ����!" << endl;
	}
	void TrunOff(){
		cout << "��ʾ���ر�!" << endl;
	}
};


/*
�����ࣨ����ࣩ������Ҫ�˽����е���ϵͳ�ķ��������ԣ�������ϣ��Ա�������
*/
class Facade
{
public:
	Facade(){
		m_camera = new Camera();
		m_lights = new Light();
		m_Screen = new Screen();
	}
	~Facade(){
		delete m_camera;
		delete m_lights;
		delete m_Screen;
	}
	void Activate(){
		cout<< "�����豸��ʼֱ��!"<<endl;
		m_camera->TrunOn();
		m_camera->Rotate(90);
		m_lights->TrunOn();
		m_Screen->TrunOn();

	}
	void Deactivate(){
		cout << "�ر��豸!" << endl;
		m_camera->TrunOff();
		m_camera->Rotate(0);
		m_lights->TrunOff();
		m_Screen->TrunOff();
	}

private:
	Camera *m_camera;
	Light *m_lights;
	Screen *m_Screen;
};