// 菱形继承

// 概念：
// - 两个派生类继承同一个基类
// - 又有某个类同时继承着两个派生类
// - 这种继承被称为菱形继承，或者钻石继承

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 利用 虚继承，解决菱形继承的问题
// 在继承之前，加上关键字 virtual 变为虚继承
// Animal 称为虚基类

class Animal{
public:
    int m_Age;
};

class Sheep:virtual public Animal{

};

class Tuo:virtual public Animal{
    
};

class SheepTuo:public Sheep, public Tuo{

};


void test01(){
    SheepTuo st;
    // 当出现菱形继承的时候，两个父类拥有相同的数据，需要加对应的作用域进行区分
    st.Sheep::m_Age = 19;
    st.Tuo:: m_Age = 28;
    st.m_Age = 383;

    cout << st.Sheep::m_Age << endl;
    cout << st.Tuo::m_Age << endl;
    cout << st.m_Age << endl;

    // 菱形继承导致了数据有两份，导致了资源的浪费
}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}