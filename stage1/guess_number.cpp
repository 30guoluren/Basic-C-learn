#include<iostream>
#include<ctime>
using namespace std;

int main(){

    // 添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都一样
    srand((unsigned int)time(NULL));

    int num = rand() % 100; // 生成一个 0-99 的随机数
    int val = 0;
    while (1){
        cin >> val;
        if (val>num){
            cout << "猜大了" << endl;
        }else if (val<num){
            cout << "猜小了" << endl;
        }else{
            cout << "恭喜猜对了" << endl;
            break;
        }
    }
    return 0;
}