// set 和 multiset

// set 不可以重复插入数据，而 multiset 可以
// set 插入数据的同时会返回插入的结果，表示是否插入成功
// multiset 不会检测数据，因此可以插入重复的数据。

#include<iostream>
#include<set>

using namespace std;

void test01(){
    set<int> s;

    pair<set<int>::iterator, bool> ret = s.insert(10);
    // s.insert(10);
    if (ret.second){
        cout << "success" << endl;
    }else {
        cout << "fail" << endl;
    }

    cout << "----===-----" << endl;

    ret = s.insert(10);
    if (ret.second){
        cout << "success" << endl;
    }else {
        cout << "fail" << endl;
    }

    multiset<int> ms;
    ms.insert(9);
    ms.insert(9);

    for (multiset<int>::iterator it=ms.begin(); it!=ms.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    test01();
    return 0;
}