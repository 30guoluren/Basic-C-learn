// count // 统计元素的个数
// count(iterator_beg, iterator_end, value);
// value 统计的元素

// 统计自定义的数据类型的时候，需要配合重载 operator== 


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

// 统计内置的数据类型
void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(40);
    
    int num = count(v.begin(), v.end(), 40);

    cout << "40 times : " << num << endl;
}

// 自定义数据类型

class Person{
    public:

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    bool operator==(const Person &p){
        if (this->m_Age == p.m_Age){
            return true;
        }else {
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
    Person p3("c", 1);
    Person p4("d", 1);
    Person p5("e", 5);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("g", 1);

    int num = count(v.begin(), v.end(), p);

    cout << num << endl;
}

int main(){
    // test01();
    test02();
    return 0;
}