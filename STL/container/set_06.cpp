// pair 对组

// 创建方式
// pair<type, type> p (value1, value2);
// pair<type, type> p = make_pair(value1, value2);

#include<iostream>
#include<set>
#include <utility>

using namespace std;

void test01(){
    pair<string, int> p("abc", 11);
    cout << "first" << p.first << " second" << p.second << endl;

    // 第二种方式
    pair<string, int> p2 = make_pair("jerry", 12);
    cout << p2.first << p2.second << endl;
}


int main(){
    test01();
    return 0;
}