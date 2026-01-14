// 类模板与继承

// 当类模板碰到继承时，需要注意以下几点
// - 当子类继承的父类是一个模板的时候，子类在声明的时候。要指定出父类中 T 的类型
// - 如果不指定，编译器无法给子类分配内存
// - 如果想灵活指定出父类中 T 的类型，子类也需要变为类模板

#include<iostream>

using namespace std;

template<class T>
class Base{
    public:

    T m;
};

// 1、
class Son : public Base<int>{ // 必须要知道父类中的数据类型，才能继承给子类
    public:

};

// 2、
template<class T1, class T2>
class Son2 : public Base<T2>{
    public:

    Son2(){
        cout << "T1 的类型为: " << typeid(T1).name() << endl;
        cout << "T2 的类型为: " << typeid(T2).name() << endl;

    }

    T1 s;
};


void test02(){
    Son2<int, char> s2;
    s2.s = 10;
    s2.m = 'c';
}


void test01(){
    Son s1;
}


int main(){
    test02();
    return 0;
}