// string 插入和删除

// string& insert(int pos, const char* s);      // 插入字符串
// string& insert(int pos, const string& str);  // 插入字符串
// string& insert(int pos, int n, char c);      // 在指定位置插入 n 个字符 c
// string& erase(int pos, int n = npos);        // 删除从 pos 开始的 n个字符

#include<iostream>

using namespace std;

void test01(){
    string str = "hello";
    str.insert(5, "world");
    cout << str << endl;

    str.erase(5, 5);
    cout << str << endl;
}


int main(){
    test01();
    return 0;
}