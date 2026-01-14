// 类模板案例
#include<iostream>
#include "MyArray.hpp"

using namespace std;

void printIntArray(MyArray<int> &arr){
    for (int i=0; i<arr.getSize(); i++){
        cout << arr[i] << endl;
    }
}


void test01(){
    MyArray<int> arr1(5);
    
    for (int i=0; i<5; i++){
        arr1.Push_Back(i);
    }

    cout << "arr1 的打印输出" << endl;
    printIntArray(arr1);

    cout << "arr1 的容量: " << arr1.getCapacity() << endl;
    cout << arr1.getSize() << endl;

    MyArray<int> arr2(arr1);
    cout << "arr2 的打印输出: " << endl;
    printIntArray(arr2);

    // 尾删
    arr2.Pop_Back();
    cout << "arr2 尾删后大小" << endl;
    cout << arr2.getCapacity() << endl;
    cout << arr2.getSize() << endl;
}


// 测试自定义数据类型
class Person{
    public:

    Person(){

    }

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};


void printPersonArray(MyArray<Person> &arr){
    for (int i=0; i<arr.getSize(); i++){
        cout << arr[i].m_Name << arr[i].m_Age << endl;
    }
}

void test02(){
    MyArray<Person> arr(5);
    Person p1("sungoku", 1000);
    Person p2("doggy", 23);
    Person p3("jerry", 25);
    
    // 插入数据
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);

    printPersonArray(arr);
    cout << arr.getCapacity() << endl;
    cout << arr.getSize() << endl;
}


int main(){
    // test01();
    test02();

    return 0;
}