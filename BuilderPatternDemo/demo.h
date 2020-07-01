#pragma once

#include <vector>  
#include <string>  
#include <iostream>  
using namespace std; 

/*
   我创建的这个对象比较复杂，且该对象里面的成员函数用不同的实现来表示不同的实例，换句话说就是同样的对象构建过程可以有不同的表示。
   比如我那天去吃过桥米线，他们有不同的套餐，套餐里包含的种类是一样的，都有一碗米线，一份凉菜，一杯饮料。但是不同的套餐里这3样又都不是全部一样的。
   此时我们就可以用建造者模式。
*/

/*  //product 
    产品（Product）角色：产品便是建造中的复杂对象。就是最后的套餐，所有东西放到一起端过来.
*/ 
class Food  
{  
private: 
	vector<string> mFoodName;  
	vector<int> mFoodPrice;  
public:  
	void add(string foodName,int price) {  
		mFoodName.push_back(foodName);        
		mFoodPrice.push_back(price);  
	}  

	void show(){  
		cout<<"Food List" <<endl;  
		cout<<"-------------------"<<endl;  
		for(int i=0;i < mFoodName.size();i++){  
			cout<<mFoodName[i]<<" "<<mFoodPrice[i]<<endl;  
		}  
	}  
}; 

/*  //builder  
	建造者（Builder）角色：给出一个抽象接口，以规范产品对象的各个组成成分的建造。一般而言，此接口独立于应用程序的商业逻辑。
	模式中直接创建产品对象的是具体建造者（Concrete Builder）角色。具体建造者类必须实现这个接口所要求的方法：一个是建造方法，另一个是结果返还方法。
	此时就是米线店的员工，按照收银员的要求的去准备具体的套餐，放入适当的米线，凉菜和饮料。
*/
class Builder  
{  
public:  
	virtual void BuildRiceNoodles() {};  
	virtual void BuildCoolDish(){};  
	virtual void BuildDrink(){};  
	virtual Food * getFood(){return NULL;}  
}; 

/*
	具体建造者（Concrete Builder）角色：担任这个角色的是于应用程序紧密相关的类，它们在应用程序调用下创建产品实例。
	这个角色主要完成的任务包括：实现Builder角色提供的接口，一步一步完成创建产品实例的过程。在建造过程完成后，提供产品的实例。
	是具体的做某个套餐的员工。
*/
//builderA  
class BuilderA:public Builder  
{  
private:  
	Food *food;  

public:  
	BuilderA(){food = new Food();}  
	void BuildRiceNoodles()  
	{  
		food->add("RiceNoodlesA",20);  
	}  
	void BuildCoolDish()  
	{  
		food->add("CoolDishA",20);  
	}  
	void BuildDrink()  
	{  
		food->add("DrinkA",20);  
	}  
	Food * getFood()  
	{  
		return food;  
	}  
};  

//builderB  
class BuilderB:public Builder  
{  
private:  
	Food *food;  
public:  
	BuilderB(){food = new Food();}  
	void BuildRiceNoodles()  
	{  
		food->add("RiceNoodlesB",10);  
	}  
	void BuildCoolDish()  
	{  
		food->add("CoolDishB",10);  
	}  
	void BuildDrink()  
	{  
		food->add("DrinkB",10);  
	}  
	Food * getFood()  
	{  
		return food;  
	}  
};

/* //director  
	指导者（Director）角色：担任这个角色的类调用具体建造者角色以创建产品对象。
	导演者并没有产品类的具体知识，真正拥有产品类的具体知识的是具体建造者对象。
	是收银员，他知道我想要什么套餐，他会告诉里面的米线店员工去准备什么套餐。
*/
class FoodManager  
{  
public:  
	void Construct(Builder * builder)  
	{  
		builder->BuildRiceNoodles();  
		builder->BuildDrink();  
		builder->BuildCoolDish();  
	}  
};

void Client()
{
	//构建者模式：将复杂对象的构建与表示分离，使得同样的构建过程可以创建不同的表示。
	//food则为复杂对象。
	FoodManager *foodManager= new FoodManager();  

	Builder * builder;  
	// the following code can use simple factory;  
	char ch;  
	cout<<"input your food Type (A or B):";  
	cin>>ch;  
	//复杂对象的构建，在Builder构造函数中构建。
	if(ch=='A')  
	{  
		builder = new BuilderA();  
	}else if(ch=='B')  
	{  
		builder = new BuilderB();  
	}  
	//复杂对象的构建过程。
	foodManager->Construct(builder);  
	Food * food = builder->getFood();  
	//辅助对象的表示
	food->show();  
	

	getchar();
}