// 继承中的对象类型

// 问题：从父类继承过来的成员，哪些属于子类对象中？

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Base1{
    public:
    int m_A;
    protected:
    int m_B;
    private:
    int m_C;
};

class Son: public Base1{
    public:
    int m_D;
};

// 利用 visual studio 开发人员命令提示工具，查看对象模型
// 1、跳转盘符
// 2、cl /dl reportSingleClassSingle类名 "文件名"


void test01(){
    // 父类中所有非静态成员属性，都会被子类继承下去
    // 父类中的私有成员属性，是被编译器隐藏了，因此是访问不到，但是确实被继承下去了
    cout << sizeof(Son) << endl; // 16
}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}