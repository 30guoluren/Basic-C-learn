#include<iostream>
using namespace std;

// 交换函数
// 1、值传递
void mySwap01(int a, int b){
    int temp = a;
    a = b;
    b = temp;

}
// 2、地址传递
void mySwap02(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 3、引用传递
void mySwap03(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 10;
    int b = 20;
    mySwap01(a,b); // 值传递，只修饰形参，不修饰实参
    cout << a << endl;
    cout << b << endl;

    mySwap02(&a, &b);
    cout << a << endl;
    cout << b << endl;

    mySwap03(a, b);
    cout << a << endl;
    cout << b << endl;
    return 0;
}