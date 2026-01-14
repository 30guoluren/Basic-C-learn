// set 不允许有重复元素
// multiset 允许有重复元素

#include<iostream>
#include<set>

using namespace std;

void printSet(set<int> &s){
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    set<int> s1;
    s1.insert(12); // 插入数据只有 insert 方式
    s1.insert(2);
    s1.insert(3);
    s1.insert(2);
    s1.insert(22);
    printSet(s1);

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3 = s2;
    printSet(s3);
}

int main(){
    test01();    
    return 0;
}