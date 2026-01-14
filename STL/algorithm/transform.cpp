// transform

// transform(iterator beg1, iterator end1, iterator beg2, _func);
// _func 函数或则函数对象

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Transform{
    public:
    int operator()(int v){
        return v+100;
    }
};

class MyPrint{
    public:
    void operator()(int val){
        cout << val << " ";
    }
};

void test01(){
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }

    vector<int> vTarget;
    vTarget.resize(v.size());
    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << endl;
}

int main(){
    test01();
    return 0;
}