#pragma once
#include <iostream>
#include <vector>
/*烤肉师傅类，只负责烤串工作*/
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

//抽象命令类：是执行具体操作的接口。
class Command
{
public:
    Command(void){}
    Command(Receiver* a_pReceiver){}
    ~Command(void){}
public:
    virtual void ExecuteCommand() = 0;  //纯虚函数，执行命令
protected:
    Receiver* m_pReceiver;
};

/*  具体命令类：烤羊肉串命令  */
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

/*  具体命令类：烤鸡翅串命令  */
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

/*  服务员类  */
class Waiter
{
public:
    Waiter(void){}
    void setOrder(Command* a_pCommand){
        if(a_pCommand)
            m_vctCommandList.push_back(a_pCommand);
        std::cout<<"增加烤肉命令"<<std::endl;
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
    std::vector<Command*> m_vctCommandList; //类似于一个命令对象队列
};

