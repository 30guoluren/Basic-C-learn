#include<iostream>
using namespace std;

const double PI = 3.14;

class Circle{
    // 访问权限
public:
    // 属性
    int m_r;
    // 行为
    // 获取圆的周长
    double calculateZC(){
        return 2 * PI * m_r;
    }
};

int main(){
    Circle cl;
    cl.m_r = 20;
    double ZC = cl.calculateZC();
    cout << "圆的周长: "<< ZC << endl;

    return 0;
}