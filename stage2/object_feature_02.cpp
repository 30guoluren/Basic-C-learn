// this 指针的概念

#include<iostream>
using namespace std;





class Person{
    public:
    Person(int age){
        // m_Age = age;

        // this 指针指向被调用的成员函数所属的对象
        this->age = age;
    }

    // int m_Age;
    int age;

    Person& PersonAddage(Person &p){ // 注：此处是以引用的方式返回，不能是以值得方式返回，因为以值得方式返回返回的不是对象本身，而是创建了一个新对象。
        this->age += p.age;
        return *this;
    }
};

// 解决名称冲突
void test01(){
    Person p(18);
    // cout << p.m_Age << endl;
    cout << p.age << endl;
}

// 返回对象本身用 *this
void test02(){
    Person p1(10);
    Person p2(10);

    // 链式编程思想
    p2.PersonAddage(p1).PersonAddage(p1);
    cout << "p2 的年龄" << p2.age << endl;
}

int main(){
    // test01();
    test02();
    return 0;
}