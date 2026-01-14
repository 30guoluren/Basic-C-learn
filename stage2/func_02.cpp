// 函数占位参数

#include<iostream>

using namespace std;

// 占位参数， 还可以有默认参数 
void func(int a, int = 10){
    cout << "this a function" << endl;
}

int main(){
    func(10,20);
    return 0;
}