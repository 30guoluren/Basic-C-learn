// count_if

// count_if(iterator_beg, iterator_end, _Pred);
// 按条件统计元素出现的次数
// _Pred 谓词

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

// 统计内置的数据类型
class GreaterTwenty{
    public:
    bool operator()(int val){
        return val > 20;
    }
};

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(40);

    int num = count_if(v.begin(), v.end(), GreaterTwenty());

    cout << "Greater twenty: " << num << endl;
}


// 统计自定义的数据类型
class Person{
    public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class GreaterAge20{
    public:
    bool operator()(const Person &p){
        return p.m_Age >20;
    }
};

void test02(){
    vector<Person> v;
    Person p1("a",1);
    Person p2("b",12);
    Person p3("c",13);
    Person p4("d",12);
    Person p5("e",12);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    int num = count_if(v.begin(), v.end(), GreaterAge20());

    cout << "Person age greater 20: " << num << endl;
}


int main(){
    // test01();
    test02();
    return 0;
}