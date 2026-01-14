#include<iostream>

using namespace std;

// 实现一个通用的对数组进行排序的函数，从大到小，选择排序

template<class T>
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}


template<class T>
void mySort(T arr[], int len){
    for (int i=0; i<len; i++){
        int max = i; // 认定最大值下表
        for (int j=i+1; j<len; j++){
            if (arr[max] < arr[j]){
                max = j;
            }
        }
        if (max != i){
            mySwap(arr[max], arr[i]);
        }
    }
}

// 提供打印数组模板
template<class T>
void printArr(T arr[], int len){
    for (int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


void test01(){
    char charArr[] = "badcfe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArr(charArr, num);
}

void test02(){
    int intArr[] = {2,3,455,6,77,6};
    int num = sizeof(intArr) / sizeof(int);

    mySort(intArr, num);
    printArr(intArr, num);
}

int main(){
    // test01();
    test02();
    return 0;
}