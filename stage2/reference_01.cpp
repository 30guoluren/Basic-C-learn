// 引用：给变量起别名
// 语法：数据类型 &别名 = 原名

#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int &b = a;
    cout << a << endl;
    b = 20;
    cout << b << endl;
    cout << a << endl;
    return 0;
}