// 函数重载注意事项

#include<iostream>
using namespace std;

// 1、引用作为重载的条件
void func(int &a){
    cout << "function 的调用" << endl;
}

void func(const int &a){
    cout << "function const int &a 的调用" << endl;
}


// 2、函数重载配到默认参数
void func2(int a, int b=0){
    cout << "func2 (int a, int b)" << endl;
}

void func2(int a){
    cout << "func2 (int a)" << endl;
}

int main(){
    int a = 10;
    // func(a);
    // func(10);

    // func2(10); 此处既可以调用func2(int a, int b=0) 和 func2(int a)，出现歧义报错
    return 0;
}