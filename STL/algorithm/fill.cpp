// fill 

// fill(iterator_beg, iterator_end, value);
// value 填充的值

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

void print01(int val){
    cout << val << " ";
}

void test01(){
    vector<int> v;
    v.resize(10);

    // 后期重新填充
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), print01);
    cout << endl;
}

int main(){
    test01();
    return 0;
}