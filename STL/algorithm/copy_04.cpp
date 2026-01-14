// swap 互换两个容器内的元素

// swap(container c1, container c2);

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print01(int val){
    cout << val << " ";
}

void test01(){
    vector<int> v1;
    vector<int> v2;

    for(int i=0; i<10; i++){
        v1.push_back(i);
        v2.push_back(i+100);
    }

    swap(v1, v2);

    for_each(v1.begin(), v1.end(), print01);
    cout << endl;

}

int main(){
    test01();
    return 0;
}