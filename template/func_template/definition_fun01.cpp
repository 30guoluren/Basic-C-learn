// 模板使用注意事项
// 自动类型推倒。必须推导出一致的数据类型 T ,才可以使用
// 模板必须要确定出 T 的数据类型，才可以使用。

#include<iostream>

using namespace std;


// 自动类型推倒。必须推导出一致的数据类型 T ,才可以使用
template<class T> // typename 可以替换为u class
void mySwap(T &a, T&b){
    T temp = a;
    a = b;
    b = temp;
}

void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';
    // mySwap(a, c); 错误，推倒不出一致的 T 类型.
    mySwap(a, b);
    cout << a << endl;
    cout << b << endl;
}

// 模板必须要确定出 T 的数据类型，才可以使用。
template<typename T>
void func(){
    cout << "这是 func 的调用" << endl;
}
void test02(){
    func<int>();
}

int main(){
    test02();
    return 0;
}