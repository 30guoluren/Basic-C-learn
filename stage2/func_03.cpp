// 函数重载 :函数名可以相同，提高复用性
// 条件
// 1、同一个作用域下
// 2、函数名称相同
// 3、函数参数类型不同，或者个数不同，或者顺序不同

// 注意：函数的返回值不可以作为函数重载的条件

#include<iostream>
using namespace std;

// 条件：同一个作用域、函数名称相同、函数参数类型不同，或者个数不同，顺序不同
void func(){
    cout << "this is a function" << endl;
}

void func(int a){
    cout << "a function int a" << endl;
}

void func(double a){
    cout << "a function int a" << endl;
}

void func(int a, double b){
    cout << "this is a func int a and double b" << endl;
}


// 注意：函数的返回值不可以作为函数重载的条件

// int func(int a, double b){
//     cout << "this is a func int a and double b" << endl;
// }

int main(){

    // func(10);
    func(10,3.14);
    return 0;
}