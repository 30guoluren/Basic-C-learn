// string 字符存取

// char& operator[](int n);  // 通过 [] 方式取字符
// char& at(int n);          // 通过 at 方法获取字符

#include<iostream>

using namespace std;

void test01(){
    string str = "hello";
    cout << str << endl;

    // 1、[]
    for (int i=0; i<str.size(); i++){
        cout << str[i] << " ";
    }
    cout << endl;
    // 2、at
    for (int i=0; i<str.size(); i++){
        cout << str.at(i) << " ";
    }
    cout << endl;


    // 修改字符
    str[0] = 'x';
    cout << str << endl;

    str.at(2) = 'd';
    cout << str << endl;
}


int main(){
    test01();
    return 0;
}