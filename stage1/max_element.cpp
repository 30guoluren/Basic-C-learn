#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums = {1, 3, -1, -3, 5};
    int i=1, k=3;
    int maxVal = *max_element(nums.begin()+i, nums.begin()+i+k);
    cout << maxVal << endl;

    return 0;
}
/*
nums.begin() + i  →  指向下标为 i 的元素
nums.begin() + i + k  →  指向下标为 i+k 的位置（不包括这个位置）

max_element 返回的是迭代器，' * ' 代表解引用。
*/