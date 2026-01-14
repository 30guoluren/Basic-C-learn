// set 查找和统计

// find(key); 查找 key 是否存在，若存在，返回该键的元素的迭代器；若不存在，返回 set.end();
// count(key); 统计 key 元素的个数

#include<iostream>
#include<set>

using namespace std;
void test01(){
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);

    set<int>::iterator pos = s.find(30);
    if (pos != s.end()){
        cout << "find success" << endl;
    }else {
        cout << "not found" << endl;
    }

    int num = s.count(1); // 对于 set ，结果只有 0 或 1
    cout << "num: " << num << endl;
}


int main(){
    test01();
    return 0;
}