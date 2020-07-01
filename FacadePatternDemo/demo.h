#pragma once

#include <iostream>
using namespace std;

/*
Camera/Light/Screen子系统类，用于实现子系统的功能。
*/
class Camera
{
public:
	Camera(){}
	~Camera(){}
	void TrunOn(){
		cout << "摄像机打开!" << endl;
	}
	void TrunOff(){
		cout << "摄像机关闭!" << endl;
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
		cout << "灯光打开!" << endl;
	}
	void TrunOff(){
		cout << "灯光关闭!" << endl;
	}
};

class Screen
{
public:
	Screen(){}
	~Screen(){}
	void TrunOn(){
		cout << "显示器打开!" << endl;
	}
	void TrunOff(){
		cout << "显示器关闭!" << endl;
	}
};


/*
门面类（外观类）：它需要了解所有的子系统的方法或属性，进行组合，以备外界调用
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
		cout<< "激活设备开始直播!"<<endl;
		m_camera->TrunOn();
		m_camera->Rotate(90);
		m_lights->TrunOn();
		m_Screen->TrunOn();

	}
	void Deactivate(){
		cout << "关闭设备!" << endl;
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