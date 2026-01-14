#include <iostream>
using namespace std;

// 全局变量
int g_a = 10;
int g_b = 10;

// const 修饰额全局变量 --> 全局常量
const int c_g_a = 10;

int main() {
    // 全局区

    // 全局变量，静态变量，常量

    // 创建普通的局部变量
    int a = 10;
    int b = 10;

    cout << "局部变量 a 的地址为：" << &a << endl;
    cout << "局部变量 b 的地址为：" << &b << endl;

    cout << "全局变量 g_a 的地址为：" << &g_a << endl;
    cout << "全局变量 g_b 的地址为：" << &g_b << endl;

    // 静态变量
    static int s_a = 10;
    static int s_b = 10;

    cout << "静态变量 s_a 的地址为：" << &s_a << endl;
    cout << "静态变量 s_b 的地址为：" << &s_b << endl;

    // 常量
    // 字符串常量
    cout << "字符串常量的地址为：" << &"hello world" << endl;
    // const 常量
    // const 修饰的全局变量
    cout << "const 修饰的全局常量地址为：" << &c_g_a << endl;
    // const 修饰的 局部变量

    const int c_l_a = 10;
    const int c_l_b = 10;

    cout << "const 修饰的局部常量地址为：" << &c_l_a << endl;
    cout << "const 修饰的局部常量地址为：" << &c_l_b << endl;

    return 0;
}