// 常见的查找函数

// find // 查找指定元素，找到返回指定元素迭代器，找不到返回迭代器end()
// find_if // 按照条件查找元素
// adjacent_find // 查找相邻重复的元素
// binary_search // 二分查找法
// count // 统计元素的个数
// count_if // 按条件统计元素的个数

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 查找内置的数据类型
void test01(){
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }

    // 查找 5
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos != v.end()){
        cout << "success find" << endl;
    }else {
        cout << "not find" <<endl;
    }
}

// 查找自定义的数据类型
class Person{
    public:

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    // 重载 == ,让底层 find 知道如何对比 person 数据类型
    bool operator==(const Person &p){
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age){
            return true;
        }
        else {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

void test02(){
    vector<Person> v;
    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);
    Person p4("d", 4);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
    if (pos != v.end()){
        cout << "success find" << endl;
    }else {
        cout << "not find" <<endl;
    }
    
}

int main(){
    // test01();
    test02();
    return 0;
}