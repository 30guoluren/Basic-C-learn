#include<iostream>
using namespace std;

int main(){
    for (int i=0; i<5; i++){
        if (i == 3){
            cout << "break" << endl;
            // break;
            // continue;
        }
        cout << i << endl;
    }
    return 0;
}