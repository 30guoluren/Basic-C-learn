// 继承中构造和析构顺序

// 子类继承父类后，当创建子类对象，也会调用父类的构造函数
// 问题：父类和子类的构造和析构顺序，谁先谁后？

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Base{
    public:
    Base(){
        cout << "Base 的构造函数" << endl;
    }

    ~Base(){
        cout << "Base 的析构函数" << endl;
    }
};

class Son: public Base{
public:
    Son(){
        cout << "Son 的构造函数" << endl;
    }
    ~Son(){
        cout << "Son 的析构函数" << endl;
    }
};

void test01(){
    // Base b1;

    // 继承中的构造和析构顺序如下
    // 先构造父类，在构造子类；析构的顺序与构造的顺序相反
    Son s1;

}


int main(){
    system("chcp 65001");
    test01();
    return 0;
}