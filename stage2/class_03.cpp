// 访问权限

#include <iostream>
using namespace std;

// 3 种访问权限
// 公共权限、public     成员 类内可以访问，类外也可以访问
// 保护权限、protected  成员 类内可以访问，类外不可以访问 （继承：儿子也可以访问父类之中的内容）
// 私有权限、private    成员 类内可以访问，类外不可以访问 （儿子不可以访问父亲的私有内容）

class Person {
    // public
public:
    string m_Name;

    // protected
protected:
    string m_Car;

private:
    int m_Password;

public:
    void func() {
        m_Name     = "张三";
        m_Car      = "拖拉机";
        m_Password = 123456;
    }
};

int main() {
    Person p1;
    p1.m_Name = "李四";
    // p1.m_Car = "奔驰"; // 保护权限的内容，在类外无法访问
    // p1.m_Password = 123; // 私有权限的内容，类外页无法访问

    p1.func();
    cout << p1.m_Name << endl;
    return 0;
}