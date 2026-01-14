// 构造函数的分类和调用

#include <iostream>
using namespace std;

// 分类
// 按照参数分类：无参（默认）构造 和 有参构造
// 按照类型分类：普通构造 和 拷贝构造

class Person {
public:
    Person() { cout << "Person 无参（默认）构造函数的调用" << endl; }

    Person(int a) {
        age = a;
        cout << "Person 有参构造函数的调用" << endl;
    }

    // 拷贝构造函数
    Person(const Person& p) { 
        age = p.age; 
        cout << "Person 拷贝构造函数的调用" << endl;
    }

    ~Person() { cout << "Person 析构函数的调用" << endl; }

    int age;
};

// 调用
void test01() {
    // 1、括号法
    Person p1;      // 默认构造函数调用
    Person p2(10);  // 有参构造函数调用
    Person p3(p2); // 拷贝构造函数的调用

    // 注意事项：
    // 调用默认构造函数的时候，不要加 ()
    // ep: Person p1();
    // 因为这行代码，编译器会认为是一个函数的声明，不会认为在创建对象

    // cout  << "p2 的年龄为：" << p2.age << endl;
    // cout  << "p3 的年龄为：" << p3.age << endl;


    // 2、显示法
    Person P1;
    Person P2 = Person(10); // 有参构造
    Person P3 = Person(P2); // 拷贝构造

    // Person(10); // 匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象

    // 注意事项2：
    // 不要利用拷贝构造函数，初始化匿名对象
    // Person(P2); // 编译器会认为，Person(P2) =====等价===== Person P2; 是一个对象的声明

    // 3、隐式转换法
    Person p4 = 10; // 相当于：Person p4 = Person(10); 有参构造
    Person p5 = p4; // 相当于 Person p5 = Person(p4); 拷贝构造
}

int main() {
    test01();
    // Person p3;
    // system("pause");
    return 0;
}