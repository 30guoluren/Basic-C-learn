// 拷贝构造函数的时机
// C++ 拷贝构造函数调用时机通常有三种情况
// 1、使用一个已经创建完毕的对象来初始化一个新对象
// 2、值传递的方式给函数参数传值
// 3、以值方式返回局部对象

#include<iostream>
using namespace std;
// 1:
class Person{
public:
    Person(){
        cout << "Person 的默认构造函数调用" << endl;
    }

    Person(int age){
        m_Age = age;
        cout << "Person 的有参构造函数调用" << endl;
    }

    Person(const Person &p){
        m_Age = p.m_Age;
        cout << "Person 的拷贝构造函数调用" << endl;
    }

    ~Person(){
        cout << "Person 析构函数的调用" << endl;
    }

    int m_Age;
};

void test01(){
    Person p1(20);
    Person p2(p1);
    cout << "p2 的年龄为多少：" << p2.m_Age << endl;
}

// 2、值传递的方式给函数参数传值

void doWork(Person p){

}

void test02(){
    Person p;
    doWork(p);
}

// 3、值方式返回局部对象
Person doWork2(){
    Person p1;
    cout << (int*)&p1 << endl;
    return p1; 
    // 注：此处输出的地址是相同的。因为编译器做了“返回值优化”（Return Value Optimization, RVO 
    // 或 
    // “命名返回值优化” （Named Return Value Optimization, NRVO）
    // RVO：是一种编译器优化技术，用来消除临时对象的创建与拷贝
    // retrun p1;
    // 此处返回局部对象时，
    // 直接在调用者的栈上构造这个对象（也就是 p 的那块内存）
    // 这样 p1 实际上一开始“就放在调用者的栈上”
    // 所以返回时不需要拷贝，也不需要移动
    // return std :: move(p1);
}

void test03(){
    Person p = doWork2();
    cout << (int*)&p << endl;
}

int main(){
    // test01();
    // test02();
    test03();
    return 0;
}