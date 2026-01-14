#include<iostream>
using namespace std;

int main(){
    cout << "请给电影打分" << endl;
    int score = 0;
    cin >> score;
    cout << "您给该电影打的分数为：" << score << endl;

    switch(score){ // 此处的判断，只能为 整型 或者 字符型，不能为区间，而if则可以为区间
        case 10:
            cout << "您认为该电影非常好" << endl;
            break;
        case 9:
            cout << "您认为该电影很好" << endl;
            break;
        default:
            cout << "您认为该电影是烂片" << endl;
    }
    return 0;
}