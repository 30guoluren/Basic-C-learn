// 纯虚函数和抽象类

// 在多态中，通常父类虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 纯虚函数语法：virtual 返回值类型 函数名 (参数列表) = 0;
// 当类中有了纯虚函数，这个类也被称为 抽象类。

// 抽象类的特点：
// - 无法实例化对象
// - 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Base{
    public:
    // 纯虚函数
    // 无法实例化对象
    // 抽象类的子类，必须要重写父类的中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};


class Son : public Base{
    public:

    virtual void func(){
        cout << "func 的调用" << endl;
    }

};

void test01(){
    // Base b;
    // new Base;
    // 抽象类无法实例化对象

    // Son s; // 子类必须重写父类中的纯虚函数

    Base * base = new Son;
    base->func();
}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}