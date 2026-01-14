// struct 和 class 的区别
#include<iostream>
using namespace std;
// struct 默认权限是 public
// class 默认权限是 private

class C1{
    int m_A; // 默认权限是 私有
};

struct C2{
    int m_A; // 默认权限是 共有
};


int main(){
    C1 c1;
    // c1.m_A = 100; // m_A 默认是私有成员
    C2 c2;
    c2.m_A = 100; // 在 struct 中，默认是公共权限
    cout << c2.m_A << endl;

    return 0;
}