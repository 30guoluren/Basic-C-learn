#include<iostream>
using namespace std;

int main(){
    int arr[5] = {200, 100, 200, 3000, 40000};
    int num_max = 0;

    for (int i=0; i<5; i++){
        num_max = max(arr[i], num_max);
    }
    cout << "最大的数字为：" << num_max << endl;
    return 0;
}