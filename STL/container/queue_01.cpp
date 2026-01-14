// queue 

// 构造函数
// queue<T> que;
// queue(const queue &que);

// 赋值操作
// queue& operator=(const queue &que);

// 数据存取
// push(elem);
// pop()
// back();
// front();

// 大小操作
// empty();
// size();

#include<iostream>
#include<queue>


using namespace std;

class Person{
    public:

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};


void test01(){
    queue<Person> q;
    Person p1("a", 10);
    Person p2("b", 11);
    Person p3("c", 3);
    Person p4("d", 4);

    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    // 队列不空。查看队头队尾
    while (!q.empty()){
        cout << "queue front " << q.front().m_Name << " " << q.front().m_Age << endl;
        cout << "queue back" << "年龄" << q.back().m_Name << " " << q.back().m_Age << endl;

        // 出对
        q.pop();
    }

    cout << "q size " << q.size() << endl;
    
}

int main(){
    test01();
    return 0;
}