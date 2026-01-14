// 浅拷贝与深拷贝

#include<iostream>
using namespace std;

class Person{
public:
    Person(){
        cout << "Person 的默认构造调用" << endl;
    }

    Person(int age, int height){
        m_Height = new int(height);
        m_Age = age;
        cout << "Person 的有参构造调用" << endl;
    }

    // 自己实现拷贝构造函数 解决浅拷贝带来的问题
    Person(const Person &p){
        m_Age = p.m_Age;

        // m_Height = p.m_Height; // 编译器默认实现就是这行代码

        // 深拷贝操作
        m_Height = new int(*p.m_Height);

        cout << "Person 的拷贝构造调用" << endl;
    }

    ~Person(){
        // 将我们在堆区开辟的数据做释放操作
        if (m_Height != NULL){
            delete m_Height;
            m_Height = NULL;
        }

        cout << "Person 的析构构造调用" << endl;
    }

    int m_Age;
    int *m_Height;
};

void test01(){
    Person p1(18, 180);
    cout << "p1 的年龄为：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;

    Person p2(p1); // 默认执行了浅拷贝（只拷贝）
    cout << "p2 的年龄为：" << p2.m_Age << "身高为：" << *p2.m_Height << endl;
}

int main(){
    test01();
    return 0;
}