#include <iostream>
#include <string>
using namespace std;

struct Hero {
    int    age;
    string name;
    string sex;
};

void bubbleSortHero(struct Hero heroArray[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (heroArray[j].age > heroArray[j + 1].age) {
                struct Hero temp = heroArray[j];
                heroArray[j]     = heroArray[j + 1];
                heroArray[j + 1] = temp;
            }
        }
    }
}

void printHero(struct Hero heroArray[], int len) {
    for (int i = 0; i < len; i++) {
        cout << heroArray[i].age << heroArray[i].name << heroArray[i].sex << endl;
    }
}

int main() {
    struct Hero heroArray[5] = {
        {23, "刘备", "男"}, {19, "貂蝉", "女"},

        {21, "关羽", "男"}, {22, "张飞", "男"},

        {20, "曹操", "男"},

    };

    cout << "排序前结果为: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << heroArray[i].age << heroArray[i].name << heroArray[i].sex << endl;
    }

    bubbleSortHero(heroArray, 5);

    printHero(heroArray, 5);

    return 0;
}