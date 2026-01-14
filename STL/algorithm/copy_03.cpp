// replace_if

// replace_if(iterator_beg, iterator_end, _Pred, newvalue);

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Greater20{
    public:
    bool operator()(int val){
        return val > 20;
    }
};

class Myprint{
    public:
    void operator()(int val){
        cout << val << " ";
    }
};

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(56);

    replace_if(v.begin(), v.end(), Greater20(), 1111);

    for_each(v.begin(), v.end(), Myprint());
    cout << endl;
}

int main(){
    test01();
    return 0;
}