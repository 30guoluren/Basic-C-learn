// map 排序

#include<iostream>
#include<map>
#include <system_error>
#include <utility>

using namespace std;

class MyComapre{
    public:
    bool operator()(int v1, int v2){
        // 降序
        return v1 > v2;
    }
};

void test01(){
    map<int, int, MyComapre> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));

    for (map<int, int, MyComapre>::iterator it=m.begin(); it!=m.end(); it++){
        cout << "key: " << it->first << " value: " << (*it).second <<endl;
    }
}

int main(){
    test01();
    return 0;
}