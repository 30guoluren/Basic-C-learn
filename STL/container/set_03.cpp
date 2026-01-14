// set 插入和删除

// insert(elem);
// clear();
// erase(pos);
// erase(beg, end);
// erase(elem);

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
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    printSet(s1);

    s1.erase(s1.begin());
    printSet(s1);

    s1.insert(12);
    // s1.erase(s1.begin(), s1.end());
    s1.erase(12);
    printSet(s1);

    s1.clear();
    printSet(s1);
}

int main(){
    test01();
    return 0;
}