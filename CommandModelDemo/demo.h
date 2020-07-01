#pragma once
#include <iostream>
#include <vector>
/*����ʦ���ֻ࣬���𿾴�����*/
class Receiver
{
public:
    Receiver(void){}
    ~Receiver(void){}
public:
    void BakeMutton(){
        std::cout<<"Bake Muttton"<<std::endl;
    }
    void BakeChickenWind(){
        std::cout<<"Bake Chicken Wind"<<std::endl;
    }
};

//���������ࣺ��ִ�о�������Ľӿڡ�
class Command
{
public:
    Command(void){}
    Command(Receiver* a_pReceiver){}
    ~Command(void){}
public:
    virtual void ExecuteCommand() = 0;  //���麯����ִ������
protected:
    Receiver* m_pReceiver;
};

/*  ���������ࣺ�����⴮����  */
class BakeMuttonCommand :
    public Command
{
public:
    BakeMuttonCommand(Receiver* a_pReceiver):Command(a_pReceiver){}
    virtual void ExecuteCommand(){
        m_pReceiver->BakeMutton();
    }
    ~BakeMuttonCommand(void){}
};

/*  ���������ࣺ�����ᴮ����  */
class BakeChickenWind :
    public Command
{
public:
    BakeChickenWind(Receiver* a_pReceiver):Command(a_pReceiver){}
    virtual void ExecuteCommand(){
        m_pReceiver->BakeChickenWind();
    }
    ~BakeChickenWind();
};

/*  ����Ա��  */
class Waiter
{
public:
    Waiter(void){}
    void setOrder(Command* a_pCommand){
        if(a_pCommand)
            m_vctCommandList.push_back(a_pCommand);
        std::cout<<"���ӿ�������"<<std::endl;
    }
    void Notify(){
        std::vector<Command*>::iterator iter = m_vctCommandList.begin();
        while(iter != m_vctCommandList.end()){
            (*iter)->ExecuteCommand();
            ++iter;
        }
    }
    ~Waiter(void){}
private:
    std::vector<Command*> m_vctCommandList; //������һ������������
};

