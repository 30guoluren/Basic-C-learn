// set 大小和交换

// empty();
// size();
// swap(st);

#include<iostream>
#include<set>

using namespace std;

void printSet(set<int> &s){
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


// 交换
void test01(){
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    printSet(s1);

    if (s1.empty()){
        cout << "s1 is empty" << endl;
    }
    else {
        cout << "not empty " << s1.size() << endl;
    }

    set<int> s2;
    s2.insert(11111);
    s2.insert(3434);
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}
// 大小

int main(){
    test01();
    return 0;
}