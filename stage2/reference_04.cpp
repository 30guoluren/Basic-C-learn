// 引用做函数返回值


#include<iostream>
using namespace std;

// 不要返回局部变量的引用
int& test01(){
    int a = 10;
    return a;
}

// 函数的调用可以作为左值
int& test02(){
    static int a = 0; // 静态变量，存放在全局区，由系统进行释放在程序结束后
    return a;
}
int main(){

    // int &ref = test01();
    // cout << "ref = " << ref << endl;
    
    int &ref2 = test02();
    cout << "ref = " << ref2 << endl;
    cout << "ref = " << ref2 << endl;

    test02() = 1000;    // 如果函数的返回值是引用，这个函数调用可以作为左值

    cout << "ref = " << ref2 << endl;
    cout << "ref = " << ref2 << endl;

    return 0;
}