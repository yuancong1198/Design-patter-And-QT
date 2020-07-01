#pragma once

#include <vector>  
#include <string>  
#include <iostream>  
using namespace std; 

/*
   �Ҵ������������Ƚϸ��ӣ��Ҹö�������ĳ�Ա�����ò�ͬ��ʵ������ʾ��ͬ��ʵ�������仰˵����ͬ���Ķ��󹹽����̿����в�ͬ�ı�ʾ��
   ����������ȥ�Թ������ߣ������в�ͬ���ײͣ��ײ��������������һ���ģ�����һ�����ߣ�һ�����ˣ�һ�����ϡ����ǲ�ͬ���ײ�����3���ֶ�����ȫ��һ���ġ�
   ��ʱ���ǾͿ����ý�����ģʽ��
*/

/*  //product 
    ��Ʒ��Product����ɫ����Ʒ���ǽ����еĸ��Ӷ��󡣾��������ײͣ����ж����ŵ�һ��˹���.
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
	�����ߣ�Builder����ɫ������һ������ӿڣ��Թ淶��Ʒ����ĸ�����ɳɷֵĽ��졣һ����ԣ��˽ӿڶ�����Ӧ�ó������ҵ�߼���
	ģʽ��ֱ�Ӵ�����Ʒ������Ǿ��彨���ߣ�Concrete Builder����ɫ�����彨���������ʵ������ӿ���Ҫ��ķ�����һ���ǽ��췽������һ���ǽ������������
	��ʱ�������ߵ��Ա������������Ա��Ҫ���ȥ׼��������ײͣ������ʵ������ߣ����˺����ϡ�
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
	���彨���ߣ�Concrete Builder����ɫ�����������ɫ������Ӧ�ó��������ص��࣬������Ӧ�ó�������´�����Ʒʵ����
	�����ɫ��Ҫ��ɵ����������ʵ��Builder��ɫ�ṩ�Ľӿڣ�һ��һ����ɴ�����Ʒʵ���Ĺ��̡��ڽ��������ɺ��ṩ��Ʒ��ʵ����
	�Ǿ������ĳ���ײ͵�Ա����
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
	ָ���ߣ�Director����ɫ�����������ɫ������þ��彨���߽�ɫ�Դ�����Ʒ����
	�����߲�û�в�Ʒ��ľ���֪ʶ������ӵ�в�Ʒ��ľ���֪ʶ���Ǿ��彨���߶���
	������Ա����֪������Ҫʲô�ײͣ����������������ߵ�Ա��ȥ׼��ʲô�ײ͡�
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
	//������ģʽ�������Ӷ���Ĺ������ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
	//food��Ϊ���Ӷ���
	FoodManager *foodManager= new FoodManager();  

	Builder * builder;  
	// the following code can use simple factory;  
	char ch;  
	cout<<"input your food Type (A or B):";  
	cin>>ch;  
	//���Ӷ���Ĺ�������Builder���캯���й�����
	if(ch=='A')  
	{  
		builder = new BuilderA();  
	}else if(ch=='B')  
	{  
		builder = new BuilderB();  
	}  
	//���Ӷ���Ĺ������̡�
	foodManager->Construct(builder);  
	Food * food = builder->getFood();  
	//��������ı�ʾ
	food->show();  
	

	getchar();
}