// map 

#include<iostream>
#include<map>

using namespace std;

void printMap(map<int, int> &mp){
    for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++){
        cout << "key: " << (*it).first << " value: " << it->second << endl;
    }
}


void test01(){
    map<int, int> mp;
    mp.insert(pair<int, int>(1,12));
    mp.insert(pair<int, int>(2,122));
    mp.insert(pair<int, int>(3,112));
    mp.insert(pair<int, int>(4,11112));
    printMap(mp);

    // 拷贝构造
    map<int, int> mp2(mp);
    printMap(mp2);

    // 赋值
    map<int, int> mp3 = mp2;
    printMap(mp3);
}

int main(){
    test01();
    return 0;
}