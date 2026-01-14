// replace 将容器内指定范围的旧元素修改为新元素

// replace(iterator_beg, iterator_end, oldvalue, newvalue);

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MyPrint{
    public:
    void operator()(int val){
        cout << val << " ";
    }
};

void test01(){
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);

    replace(v.begin(), v.end(), 20, 10);

    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

int main(){
    test01();
    return 0;
}