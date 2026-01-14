// 继承方式
// 继承语法： class 子类 : 继承方式 父类

// 继承方式一共有三种
// - 公共继承
// - 保护继承
// - 私有继承

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 公共继承
class Base1{
    public:
    int m_A;
    protected:
    int m_B;
    private:
    int m_C;
};

class Son1: public Base1{
    public:
    void func(){
        m_A = 10; // 父类中公共权限内容，到子类依然是公共权限
        m_B = 20; // 父类中的保护权限，到子类依然是保护权限
        // m_C = 20; // 父类的私有成员，无法访问
    }
};

void test01(){
    Son1 s1;
    s1.m_A = 20;
    // s1.m_B = 200; // 保护权限，类内可以访问；类外不可以访问
}


// 保护继承
class Base2{
    public:
    int m_A;
    protected:
    int m_B;
    private:
    int m_C;
};

class Son2: protected Base2{
    public:
    void func(){
        m_A = 100; // 父类中公共权限，变为保护权限
        m_B = 299;
    }
};

void test02(){
    Son2 s1;
    // s1.m_A = 199; // 保护权限，类外无法访问
}


// 私有继承
class Base3{
    public:
    int m_A;
    protected:
    int m_B;
    private:
    int m_C;
};

class Son3: private Base3{
    public:
    void func(){
        m_A = 100; // 父类的公共成员，到子类中变为，私有成员
        m_B = 288; // 父类的保护成员，到子类中变为，私有成员
        // m_C = 77; 父类中的私有成员，子类访问不到。
    }
};

void test03(){
    Son3 s1;
    // s1.m_A = 0; 在 Son3 中都为私有成员。
}

class GrandSon3: public Son3{
    public:
    void func(){
        // m_A = 1000; // 到了 Son3 中，都已经变为私有成员，其 public 子类，无法使用
    }
};


int main(){
    system("chcp 65001");
    
    return 0;
}