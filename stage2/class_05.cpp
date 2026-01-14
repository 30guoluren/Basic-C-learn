// 成员属性设置为私有
#include<iostream>
#include <string>
using namespace std;

// 1、可以自己控制读写的权限
// 2、对于写可以检测数据的有效性


class Person{
public:
    void setName(string name){
        m_Name = name;
    }

    string getName(){
        return m_Name;
    }

    int getAge(){
        return m_Age;
    }

    void setAge(int age){
        if (age>=0 && age<=120){
            m_Age = age;
        }else{
            cout << "年龄输出有误" << endl;
            return;
        }
    }

    void setIdol(string Idol){
        m_Idol = Idol;
    }

private:
    string m_Name; // 可读可写

    int m_Age = 18; // 只读，也可以写，但是设定范围：0~120

    string m_Idol; // 只写
};

int main(){
    Person p1;
    p1.setName("张三");
    cout << p1.getName() << endl;
    p1.setAge(190);
    cout << p1.getAge() << endl; // 只读

    p1.setIdol("小明"); // 只写
    
    return 0;
}