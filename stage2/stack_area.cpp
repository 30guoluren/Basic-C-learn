// 栈区的数据由编译器管理开辟和释放
// 栈区数据使用注意事项 -----> 不要返回局部变量的地址

#include<iostream>
using namespace std;

int* func(int b) // 形参数据也会放在栈区
{
    int a = 10; // 局部变量存放在栈区，栈区的数据在函数执行完后，自动释放。
    // return &a; // 返回局部变量的地址
}

int main(){

    int * p = func(1);
    cout << *p << endl;
    return 0;
}