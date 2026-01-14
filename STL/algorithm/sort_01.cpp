// 常用的排序算法
// sort // 对容器内的元素合并
// random_shuffle // 洗牌，指定范围内的元素随即调整次序
// merge // 容器元素合并，并存储到另一容器中
// reverse // 反转指定范围内的元素


#include<iostream>
#include <iterator>
#include<vector>
#include<algorithm>

// sort(iterator_beg, iterator_end, _Pred);
// _Pred 谓词

using namespace std;

class Greater{
    public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void print01(int val){
    cout << val << " ";
}

void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);

    sort(v.begin(), v.end());
    // for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    for_each(v.begin(), v.end(), print01);
    cout << endl;

    // sort(v.begin(), v.end(), Greater());
    sort(v.begin(), v.end(), greater<int>());
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    test01();
    return 0;
}