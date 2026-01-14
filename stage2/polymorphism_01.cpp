// 多态的基本概念

// 多态分为两类
// - 静态多态：函数重载 和 运算符重载 属于静态多态，复用函数名
// - 动态多态：派生类和虚函数实现运行时多态

// 静态多态和动态多态的区别：
// - 静态多态的函数地址早绑定 - 编译阶段确定函数地址
// - 动态多态的函数地址晚绑定 - 运行阶段确定函数地址

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Animal{
    public:

    virtual void speak(){
        cout << "动物在说话" << endl;
    }
};

class Cat: public Animal{
    public:

    void speak(){
        cout << "Cat 在说话" << endl;
    }
};


class Dog: public Animal{
    public:
    // 重写：函数返回值类型，函数名，参数列表 完全相同
    void speak(){
        cout << "dog 在说话" << endl;
    }
};


// 地址早绑定，在编译阶段确定函数的地址
// 如果想执行让猫说话，那么这个函数不能提前绑定，需要在运行阶段绑定

// 动态多态满足条件
// 1、有继承关系
// 2、子类重写父类的虚函数

// 动态多态的使用
// 父类的指针或引用，指向子类对象
void doSpeak(Animal &animal) // Animal & animal = cat;
{
    animal.speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02(){
    cout << "Sizeof Animal = " << sizeof(Animal) << endl;
}

int main(){
    system("chcp 65001");
    // test01();
    test02();
    return 0;
}