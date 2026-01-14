// map 查找和统计

// find(key);
// count(key);

#include<iostream>
#include<map>

using namespace std;

void test01(){
    map<int, int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));

    map<int,int>::iterator pos = m.find(3);
    if (pos != m.end()){
        cout << "find success" << endl;
        cout << "key: " << pos->first << " value: " << (*pos).second << endl;
    }else {
        cout << "fail find" << endl;
    }

    // 统计
    int num = m.count(3);
    cout << "num = " << num << endl;

}

int main(){
    test01();
    return 0;
}