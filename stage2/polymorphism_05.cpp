// 虚构和纯虚构
// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 解决方法：将父类中的析构函数改为 虚析构 或 纯虚析构

// 虚析构 和 纯虚析构 的共性
// - 可以解决父类指针释放子类现象
// - 都需要有具体的函数实现
// 区别
// 如果是纯虚构，该类属于抽象类，无法实例化对象

// 虚析构语法
// virtual ~类名(){}

// 纯虚析构语法
// virtual ~类名(){} = 0;
// 类名 ~类名(){}

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Animal{
    public:

    Animal(){
        cout << "Animal 构造函数的调用" << endl;
    }

    // virtual ~Animal(){
    //     cout << "Animal 析构函数调用" << endl;
    // }

    // 纯虚析构 需要声明，也需要有实现
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;

    virtual void speak() = 0;
};

Animal :: ~Animal(){
    cout << "Animal 纯虚析构函数" << endl;
}


class Cat : public Animal{
    public:

    Cat(string name){
        cout << "Cat 构造函数的调用" << endl;
        m_Name = new string(name);
    }

    virtual void speak(){
        cout << *m_Name <<  "小猫在说话" << endl;
    }

    ~Cat(){
        if (m_Name != NULL){
            cout << "Cat 析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    string *m_Name;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构的时候，不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄漏情况
    delete animal;
}


int main(){
    system("chcp 65001");
    test01();
    return 0;
}

// “无法解析的外部应用”，链接的时候出现的问题


// 总结
// - 虚析构或者纯虚析构就是用来解决通过父类指针释放子类对象
// - 如果子类中没有堆区数据，可以不写虚析构或者纯虚析构
// - 拥有纯虚析构函数的类也属于抽象类