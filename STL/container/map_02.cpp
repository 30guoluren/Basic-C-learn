// map 大小和交换

// size();
// empty();
// swap(st);

#include<iostream>
#include <iterator>
#include<map>

using namespace std;

void printMap(map<int, int> &mp){
    for (map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        cout << "key: " << it->first << " value: " << it->second << endl;
    }
}

void test01(){
    map<int, int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));

    if (m.empty()){
        cout << "m is empty" << endl;
    }else {
        cout << "m is not empty" << endl;
        cout << "m size is " << m.size() << endl;
    }

}

void test02(){
    map<int, int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));

    map<int, int> m1;
    m1.insert(pair<int,int>(12, 20));
    m1.insert(pair<int,int>(13, 30));
    m1.insert(pair<int,int>(14, 40));

    m.swap(m1);
    printMap(m);
    printMap(m1);
    
}

int main(){
    // test01();
    test02();
    return 0;
}