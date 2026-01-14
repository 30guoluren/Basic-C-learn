#include <cstdlib>
#include<iostream>
using namespace std;

// 对象的初始化和清理

class Person{
    // 1 构造函数 
    // 没有返回值，不用写 void
    // 函数名与类名相同
    // 构造函数可以有参数，可以发生重载
    // 创建对象时，构造函数函数会自动调用，且只会调用一次
public:
    Person(){
        cout << "构造函数的调用" << endl;
    }

    // 2、析构函数 进行清理操作
    // 没有返回值，不写 void 操作
    // 函数名与类名相同，在名称前加 ~
    // 析构函数不可以有参数，即不可以发生重载
    // 对象在销毁前，会自动调用析构函数，而且只会调用一次
    ~Person(){
        cout << "Person 的析构函数调用" << endl;
    }
};


// 构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01(){
    Person p1; //这是在栈上的数据，test01 执行完毕后，编译器会自动释放这个对象
}

int main(){
    // test01();
    Person p1;
    system("pause");
    return 0;
}