// set 排序

#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

void printSet(set<int> &s){
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

class MyCompare{
    public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void test01(){
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);

    printSet(s1);
    

    // 指定排序规则
    set<int, MyCompare> s2;
    s2.insert(1);
    s2.insert(2);
    s2.insert(3);
    for (set<int, MyCompare>::iterator it=s2.begin(); it!=s2.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


int main(){
    test01();
    return 0;
}