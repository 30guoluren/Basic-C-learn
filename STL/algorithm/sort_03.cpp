// merge 俩个容器元素合并，并存储到另一容器中

// merge(iterator_beg1, iterator_end1, iterator_beg2, iterator_end2, iterator_dest);
// 两个容器必须是有序的
// 合并之后仍然为有序序列

#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

void print01(int val){
    cout << val << " ";
}

void test01(){
    vector<int> v1;
    vector<int> v2;

    for (int i=0; i<10; i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }

    vector<int> vTarget;

    vTarget.resize(v1.size() + v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), print01);
    cout << endl;
}


int main(){
    test01();
    return 0;
}