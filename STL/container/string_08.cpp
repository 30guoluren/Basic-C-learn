// string 子串

// string substr(int pos = 0, int n = npos) const; // 返回由 pos 开始的 n 个字符组成的字符串

#include<iostream>
#include <sstream>

using namespace std;

void test01(){
    string str = "abcdef";

    string subStr = str.substr(1, 3);

    cout << subStr << endl;
}

void test02(){
    string email = "hello@sina.com";

    int pos = email.find("@");

    string userName = email.substr(0, pos);
    cout << userName << endl;
}


int main(){
    // test01();
    test02();
    return 0;
}