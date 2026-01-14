// 关系仿函数

// template<class T> bool equal_to<T>
// template<class T> bool not_equal<T>
// template<class T> bool greater<T>
// template<class T> bool greater_equal<T>
// template<class T> bool less<T>
// template<class T> bool less_equal<T>

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

class MyCompare{
    public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(2);
    v.push_back(45);
    v.push_back(22);

    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << endl;
    }

    // 降序
    // sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), greater<int>());

    cout << "---------------" << endl;

    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << endl;
    }
}

int main(){
    test01();
    return 0;
}