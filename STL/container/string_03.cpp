// string 字符串拼接

// string& operator+=(const char* str);                 // 重载 += 操作符
// string& operator+=(const char c);                    // 重载 += 操作符
// string& operator+=(const string& str);               // 重载 += 操作符
// string& append(const char *s);                       // 把字符串 s 连接到当前字符串结尾
// string& append(const char *s, int n);                // 把字符串 s 的前 n 个字符连接到当前字符串结尾
// string& append(const string &s);                     // 同 operator+=(const string& str);
// string& append(const string &s, int pos, int n);     // 字符串 s 中从 pos 开始的 n 个字符连接到字符串结尾

#include<iostream>
#include <string>

using namespace std;

void test01(){
    string str1 = "me";
    str1 += "is me";
    cout << str1 << endl;

    str1 += ':';
    cout << str1 << endl;

    string str2 = "LOL DNF";
    str1 += str2;
    cout << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << str3 << endl;

    str3.append("game abs", 4);
    cout << str3 << endl;

    str3.append(str2);
    cout << str3 << endl;

    str3.append(str2, 0, 3);
    cout << str3 << endl;
}



int main(){
    test01();
    return 0;
}