// string 查找与替换

// int find(const string& str, int pos = 0) const;          // 查找 str 第一次出现的位置，从 pos 开始查找
// int find(const char* s, int pos = 0) const;              // 找 s 第一次出现的位置，从 pos 开始查找
// int find(const char* s, int pos, int n) const;           // 从 pos 位置查找 s 的前 n 个字符第一次位置
// int find(const char c, int pos = 0) const;               // 查找字符 c 第一次出现的位置
// int rfind(const string& str, int pos = npos) const;      // 查找 str 最后一次位置，从 pos 开始查找
// int rfind(const char* s, int pos = npos) const;          // 查找 s 最后一次出现位置，从 pos 开始查找
// int rfind(const char* s, int pos, int n) const;          // 从 pos 查找 s 的前 n 个字符最后一次位置
// int rfind(const char c, int pos = 0) const;              // 查找字符 c 最后一次出现位置
// string& replace(int pos, int n, const string& str);      // 替换从 pos 开始 n 个字符为字符串 str
// string& replace(int pos, int n, const char* s);          // 替换从 pos 开始 n 个字符为字符串 s

#include<iostream>

using namespace std;

void test01(){
    string str1 = "abcdefg";
    int pos = str1.find("e");

    if (pos == -1){
        cout << "not found" << endl;
    }else {
        cout << pos << endl;
    }

    // rfind
    // rfind 从右往左查找
    // find 从左往右查找
    pos = str1.rfind("de");
    cout << pos << endl;

}


void test02(){
    string str1 = "abcdefg";
    str1.replace(1, 3, "116661");
    cout << str1 << endl;
}



int main(){
    // test01();
    test02();
    return 0;
}