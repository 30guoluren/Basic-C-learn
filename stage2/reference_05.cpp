// 引用的本质，在C++ 内部实现是一个 **指针常量**

#include<iostream>
using namespace std;

// 发现是引用，自动转换为：int * const ref = &a;
void func(int& ref){
    ref = 100;
}

int main(){
    int a = 0;
    
    // 自动转换为 int * const ref = &a；指针常量是指针的指向不可改，也说明为什么引用不可改
    int& ref = a;
    ref = 20; // 内部发现是引用，自动完成转换：*ref = 20

    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;

    func(a);

    return 0;
}