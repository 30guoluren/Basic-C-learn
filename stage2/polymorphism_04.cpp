// case2

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class AbstractDrinking{
    public:

    virtual ~AbstractDrinking() = default; // 虚析构

    virtual void Boil() = 0;

    virtual void Brew() = 0;

    virtual void PourInCup() = 0;

    virtual void PutSomething() = 0;

    void makeDrink(){
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

// 制作咖啡
class Coffee : public AbstractDrinking{
    public:
    
    virtual void Boil(){
        cout << "煮矿泉水" << endl;
    };

    virtual void Brew(){
        cout << "冲泡咖啡" << endl;
    };

    virtual void PourInCup(){
        cout << "加水" << endl;
    };

    virtual void PutSomething(){
        cout << "加入咖啡和牛奶" << endl;
    };
};

// 泡茶
class Tea : public AbstractDrinking{
    public:
    
    virtual void Boil(){
        cout << "煮矿泉水" << endl;
    };

    virtual void Brew(){
        cout << "冲泡茶叶" << endl;
    };

    virtual void PourInCup(){
        cout << "加水" << endl;
    };

    virtual void PutSomething(){
        cout << "加入其他" << endl;
    };  
};

void doWork(AbstractDrinking * abs){
    abs->makeDrink();
    delete abs;
}

void test01(){
    doWork(new Coffee);

    doWork(new Tea);
}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}