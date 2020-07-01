#pragma once

/*
应用：图形界面构件库的设计
	Sunny软件公司基于面向对象技术开发了一套图形界面构件库Visual Component，该构件库提供了大量基本构件，如窗体、文本框、列表框等，
	由于在使用该构件库时，用户经常要求定制一些特殊的显示效果，列如带滚动条的窗体、带黑色边框的文本框、既带滚动条又带黑色边框的列表框等，
	因此经常需要对该构件库进行扩展以增强其功能。
*/

#include <iostream>  
using namespace std;

//抽象界面构件类：抽象构件类  
class Component{  
public:  
	virtual void display()=0;  
};

//窗体类:具体构件类  
class Window :public Component{  
public:  
	void display(){  
		cout<<"显示窗体！"<<endl;  
	}  
}; 

//文本框类:具体构件类  
class TextField:public Component{  
public:  
	void display(){  
		cout<<"显示文本框"<<endl;  
	}  
}; 

//列表框类：具体构件类  
class ListBox : public Component{  
public:  
	void display(){  
		cout<<"显示文本框"<<endl;  
	}  
};

//构件装饰类:抽象装饰者类  
  
class Decorator : public Component{  
private:  
    Component *component;   //维持对抽象构件类型的引用  
public:  
    //通过构造函数注入抽象构件类型的对象  
    Decorator(Component *com):component(com){  
    }  
  
    /** 
    *在Decorator类中并未真正实现display()方法，只是调用原有component的display()方法， 
    它没有真正实施装饰，而是提供一个统一的接口，将具体装饰过程交给其子类处理。 
    */  
    void display(){  
        component->display();    //调用原有对象的业务方法  
    }  
};

//滚动条装饰类:具体装饰者类  
class ScrollBarDecorator : public Decorator{  
public:  
	ScrollBarDecorator(Component *com):Decorator(com){  
	}  
	void adderScrollBar(){  
		cout<<"增加滚动条"<<endl;  
	}  
	void display(){  
		adderScrollBar();  
		Decorator::display();  
	}  
};  

//黑色边框装饰类:具体装饰者类  
class BlackBorderDecorator : public Decorator{  
public:  
	BlackBorderDecorator(Component *com):Decorator(com){  
	}  
	void addBlackBorder(){  
		cout<<"增加黑色边框"<<endl;  
	}  
	void display(){  
		addBlackBorder();  
		Decorator::display();  
	}  
};

//客户端测试代码  
int DecoratorDemoEx()  
{  
	Component *origin,*oriScroll,*oriScrollBlack; //全部使用抽象构件定义  
	origin=new Window(); //定义具体构件  
	oriScroll=new ScrollBarDecorator(origin); //定义装饰后的构件  
	oriScrollBlack=new BlackBorderDecorator(oriScroll); //将装饰了一次之后的对象继续注入到另一个类中，进行第2次装饰  
	oriScrollBlack->display();  
	return 0;  
} 