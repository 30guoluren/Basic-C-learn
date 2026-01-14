#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
using namespace std;

struct Student {
    string name;
    int    score;
};

struct Teacher {
    string         Tname;
    struct Student sArray[5];
};

void allocateSpace(struct Teacher tarray[], int len) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++) {
        tarray[i].Tname = "Teacher_";
        tarray[i].Tname += nameSeed[i];

        for (int j = 0; j < 5; j++) {
            tarray[i].sArray[j].name = "Student_";
            tarray[i].sArray[j].name += nameSeed[j];

            int random                = rand() % 60 + 40;
            tarray[i].sArray[j].score = random;
        }
    }
}

void printInfo(struct Teacher tArray[], int len) {
    for (int i = 0; i < len; i++) {
        cout << i << "号老师姓名为: " << tArray[i].Tname << endl;
        for (int j = 0; j < 5; j++) {
            cout << "\t所带的学生为: " << tArray[i].sArray[j].name << " 学生成绩为" << tArray[i].sArray[j].score
                 << endl;
        }
        if (i < len - 1)
            cout << "-----------------------" << endl;
    }
}

int main() {
    // 随机数种子
    srand((unsigned int)time(NULL));

    struct Teacher tArray[3];
    int            len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray, len);

    printInfo(tArray, len);

    return 0;
}