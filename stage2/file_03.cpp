// 二进制文件 写操作

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Person{
    public:

    char m_Namw[64]; // 对字符进行写的时候，最好用 C 语言的字符数组，不用 C++ 的字符串
    int m_Age; // 年龄

};


void test01(){
    // 1、包含头文件

    // 2、创建流对象
    // 也可以在这一步指定路径和打开方式，直接省略第三步
    // ofstream ofs("person.txt". ios::out|ios::binary);
    ofstream ofs;

    // 3、打开文件
    ofs.open("person.txt", ios::out|ios::binary);
    // 4、写文件
    Person p = {"张三",18};
    ofs.write((const char *)&p, sizeof(Person));
    // 5、关闭
    ofs.close();
}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}