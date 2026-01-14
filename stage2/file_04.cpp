// 二进制读文件

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Person{
    public:

    char m_Name[64];
    int m_Age;
};


void test01(){
    ifstream ifs;

    ifs.open("person.txt", ios::binary|ios::in);

    if (! ifs.is_open()){
        cout << "文件打开失败" << endl;
        return;
    }

    Person p;
    ifs.read((char *)&p, sizeof(p));
    cout << "姓名：" << p.m_Name << "\t" << "年龄：" << p.m_Age << endl;

    ifs.close();

}

int main(){
    system("chcp 65001");
    test01();
    return 0;
}