#include<iostream>
#include "speachManager.h"
#include "speaker.h"

using namespace std;

int main(){

    // 随机数种子
    srand((unsigned int)time(NULL));

    // 创建管理类对象
    SpeachManager sm;

    // 测试创建12名选手
    // for (map<int, Speaker>::iterator it=sm.m_Speaker.begin(); it!=sm.m_Speaker.end(); it++){
    //     cout << "编号：" << it->first << "姓名：" << (*it).second.m_Name << "成绩：" << it->second.m_Score[0] << endl;
    // }

    int choice = 0;

    while(true){
        sm.show_Menu();

        cout << "请输入您的选择" << endl;
        cin >> choice;

        switch(choice){
            // 退出系统
            case 0:
                sm.exitSystem();
                break;
            // 开始比赛
            case 1:
                sm.startSpeech();
                break;
            // 查看往届比赛记录
            case 2:
                sm.showRecord();
                break;
            // 清空比赛记录
            case 3:
                sm.clearRecord();
                break;
            default:
                break;
        }
    }

    return 0;
}