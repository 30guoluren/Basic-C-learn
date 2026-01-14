// case 评委打分

#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    Person(string name, int score) {
        this->m_Name  = name;
        this->m_Score = score;
    }

    string m_Name;
    int    m_Score;
};

void createPerson(vector<Person> &v) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++) {
        string name = "Player";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person> &v) {
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        // 将评委的分数放到 deque 中
        deque<int> d;
        for (int i = 0; i < 10; i++) {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        // cout << "play score" << (*it).m_Name << endl;
        // for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++){
        //     cout << *dit << " ";
        // }
        // cout << endl;

        // sort
        sort(d.begin(), d.end());

        // 去除最高最低
        d.pop_back();
        d.pop_front();

        // 求平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
            sum += *dit;
        }

        int avg = sum / d.size();

        it->m_Score = avg;
    }
}

void showScore(vector<Person> &v) {
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "Name: " << (*it).m_Name << " Avg score: " << (*it).m_Score << endl;
    }
}

int main() {
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 1、创建 5 ，名选手
    vector<Person> v;
    createPerson(v);

    // for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
    //     cout << (*it).m_Name << (*it).m_Score << endl;
    // }

    // 2、打分
    setScore(v);

    // 3、显示最后的得分
    showScore(v);
    return 0;
}