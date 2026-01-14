// reverse() 将容器内的元素反转

// reverse(iterator_beg, iterator_end);

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
    for (int i=0; i<10; i++){
        v.push_back(i);
    }

    reverse(v.begin(), v.end());

    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

int main(){
    test01();
    return 0;
}