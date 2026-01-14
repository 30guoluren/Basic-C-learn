// 递增重载运算符：通过重载递增运算符，实现自己的整型数据

// 前置递增返回 引用；后置递增返回 值。

#include <iostream>
#include <ostream>
using namespace std;

// 自定义整型
class MyInteger {
    friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
    MyInteger() { m_Num = 0; }

    // 重载前置 ++ 运算符
    MyInteger& operator++(){ // 此处 MyInteger 须为引用，返回操作的是一个对象
        // 先进行 ++ 的运算
        m_Num ++;
        return *this;
    }


    // 重载后置 ++ 运算符
    // void operator++(int) // int 代表占位参数，可以用于区分前置和后置递增
    // 后置递增返回的是值，因为重载后置我们返回的是局部变量，运行玩就释放了，不能饭hi引用
    MyInteger operator++(int){
        // 先记录当时的结果
        MyInteger temp = *this;
        // 后递增
        m_Num ++;
        // 最后将记录结果返回
        return temp;
    }

private:
    int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger myint) {
    cout << myint.m_Num << endl;
    return cout;
}

void test01() {
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}

void test02(){
    MyInteger myint;
    cout << myint++ << endl;
    cout << myint;
}

int main() {
    // test01();
    test02();
    return 0;
}