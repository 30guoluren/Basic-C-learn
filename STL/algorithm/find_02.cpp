// find_if
// find_if(iterator beg, iterator end, _Pred);
// _Pred 函数或者谓词（返回 bool 类型的方函数）

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 查找内置的数据类型

class Greater{
    public:
    bool operator()(int val){
        return val >5;
    }
};

void test01(){
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }

    vector<int>:: iterator pos = find_if(v.begin(), v.end(), Greater());
    if (pos == v.end()){
        cout << "not find" << endl;
    }else {
        cout << "success find " << *pos << endl;
    }
}

// 自定义数据类型
class Person{
    public:

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};


class GreaterTwenty{
    public:
    bool operator()(Person &p){
        return p.m_Age > 20;
    }
};

void test02(){
    vector<Person> v;
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    Person p4("d", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator pos = find_if(v.begin(), v.end(), GreaterTwenty());\
    if (pos == v.end()){
        cout << "not found" << endl;
    }else {
        cout << "success find " <<  (*pos).m_Age << endl;
    }
}

int main(){
    // test01();
    test02();
    return 0;
}