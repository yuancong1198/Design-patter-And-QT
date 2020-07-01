#pragma once

/*
Ӧ�ã�ͼ�ν��湹��������
	Sunny�����˾�������������������һ��ͼ�ν��湹����Visual Component���ù������ṩ�˴��������������細�塢�ı����б��ȣ�
	������ʹ�øù�����ʱ���û�����Ҫ����һЩ�������ʾЧ����������������Ĵ��塢����ɫ�߿���ı��򡢼ȴ��������ִ���ɫ�߿���б��ȣ�
	��˾�����Ҫ�Ըù����������չ����ǿ�书�ܡ�
*/

#include <iostream>  
using namespace std;

//������湹���ࣺ���󹹼���  
class Component{  
public:  
	virtual void display()=0;  
};

//������:���幹����  
class Window :public Component{  
public:  
	void display(){  
		cout<<"��ʾ���壡"<<endl;  
	}  
}; 

//�ı�����:���幹����  
class TextField:public Component{  
public:  
	void display(){  
		cout<<"��ʾ�ı���"<<endl;  
	}  
}; 

//�б���ࣺ���幹����  
class ListBox : public Component{  
public:  
	void display(){  
		cout<<"��ʾ�ı���"<<endl;  
	}  
};

//����װ����:����װ������  
  
class Decorator : public Component{  
private:  
    Component *component;   //ά�ֶԳ��󹹼����͵�����  
public:  
    //ͨ�����캯��ע����󹹼����͵Ķ���  
    Decorator(Component *com):component(com){  
    }  
  
    /** 
    *��Decorator���в�δ����ʵ��display()������ֻ�ǵ���ԭ��component��display()������ 
    ��û������ʵʩװ�Σ������ṩһ��ͳһ�Ľӿڣ�������װ�ι��̽��������ദ�� 
    */  
    void display(){  
        component->display();    //����ԭ�ж����ҵ�񷽷�  
    }  
};

//������װ����:����װ������  
class ScrollBarDecorator : public Decorator{  
public:  
	ScrollBarDecorator(Component *com):Decorator(com){  
	}  
	void adderScrollBar(){  
		cout<<"���ӹ�����"<<endl;  
	}  
	void display(){  
		adderScrollBar();  
		Decorator::display();  
	}  
};  

//��ɫ�߿�װ����:����װ������  
class BlackBorderDecorator : public Decorator{  
public:  
	BlackBorderDecorator(Component *com):Decorator(com){  
	}  
	void addBlackBorder(){  
		cout<<"���Ӻ�ɫ�߿�"<<endl;  
	}  
	void display(){  
		addBlackBorder();  
		Decorator::display();  
	}  
};

//�ͻ��˲��Դ���  
int DecoratorDemoEx()  
{  
	Component *origin,*oriScroll,*oriScrollBlack; //ȫ��ʹ�ó��󹹼�����  
	origin=new Window(); //������幹��  
	oriScroll=new ScrollBarDecorator(origin); //����װ�κ�Ĺ���  
	oriScrollBlack=new BlackBorderDecorator(oriScroll); //��װ����һ��֮��Ķ������ע�뵽��һ�����У����е�2��װ��  
	oriScrollBlack->display();  
	return 0;  
} 