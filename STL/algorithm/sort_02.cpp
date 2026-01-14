// random_shuffle // 指定范围内的元素随即调整次序
// random_shuffle(iterator_beg, iterator_end);

#include <cstdlib>
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

void print01(int val){
    cout << val << " ";
}

void test01(){
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }

    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    // for_each(v.begin(), v.end(), print01);
}

int main(){

    srand((unsigned int)time(NULL));

    test01();
    return 0;
}