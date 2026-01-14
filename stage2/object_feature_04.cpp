// const 修饰成员函数

// 常函数：
// - 成员函数后加 const 后，我们称为这个函数为常函数
// - 常函数内不可以修改成员属性
// - 成员属性声明时加关键字 mutable，在常函数中依然可以修改

// 常对象：
// - 声明对象前加 const ，称该对象为常对象
// - 常对象只能调常函数

#include<iostream>
using namespace std;

// 常函数
class Person{
    public:

    void func(){

    }

    
    Person(){}
    // const Person * const this;
    // 在成员函数后面加 const ，修饰的是 this 指向，让指针指向的值也不可以修改
    void showPerson() const
    {
        // this 指针的本质是一个指针常量，指针的指向是不可以修改的
        // this->m_Age = 100; // 此处加了const ，因此不能修改成员属性
        // this = NULL; // this 指针不可以修改指针的指向

        this->m_B = 100;
    }

    int m_Age;
    mutable int m_B; // 特殊变量，即使在常函数中，也可以修改这个值，加关键字 mutable .
};

void  test01(){
    Person p;
    p.showPerson();
}


// 常对象
void test02(){
    const Person p; // 此处声明了一个 const 对象，需要提供默认构造函数；在对象前加 const ，变为常对象。
    // p.m_Age = 100;
    p.m_B = 100;

    // 常对象只能调用常函数
    p.showPerson();
    // p.func(); // 常对象不可以调用普通成员函数，因为普通成员函数可以修改属性

}

int main(){
    return 0;
}