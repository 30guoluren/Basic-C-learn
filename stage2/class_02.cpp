// #include<iostream>
// using namespace std;

// class Student{
//     public:
//     string name;
//     int stu_id;

//     void printStu(string name, int stu_id){
//         cout << "Student name:" <<  name << "\t" << "stu_id:" << stu_id << endl;
//     }
// };

// int main(){

//     Student s1;
//     s1.name = "liming";
//     s1.stu_id = 123;
//     s1.printStu(s1.name, s1.stu_id);
//     return 0;
// }


#include<iostream>

using namespace std;

class Student{
public:

    // 类中的属性和行为，统一称为成员
    // 属性 成员属性 成员变量
    // 行为 成员函数 成员方法
    
    string m_name;
    int m_id;

    void showStudent(){
        cout << "姓名：" << m_name << "学号" << m_id << endl;
    }

    // 给姓名赋值
    void setName(string name){
        m_name = name;
    }

    void setStu_id(int id){
        m_id = id;
    }
};

int main(){
    Student stu1;
    // stu1.m_id = 233;
    stu1.setStu_id(123);
    stu1.setName("zhanfsan");
    stu1.showStudent();

    Student s2;
    s2.m_id = 2222;
    s2.m_name = "lisi";
    s2.showStudent();
    return 0;
}