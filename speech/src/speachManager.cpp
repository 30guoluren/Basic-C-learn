#include "speachManager.h"
#include <cstdlib>

// 构造函数
SpeachManager :: SpeachManager(){
    this->initSpeech();

    // 创建 12 名选手
    this->createSpeaker();
}

// 析构函数

SpeachManager :: ~SpeachManager(){

}

// 菜单功能
void SpeachManager :: show_Menu(){
    cout << "******************" << endl;
    cout << "***欢迎参加比赛*****" << endl;
    cout << "1 开始比赛" << endl;
    cout << "2 查看往届记录" << endl;
    cout << "3 清空比赛记录" << endl;
    cout << "0 退出比赛程序" << endl;
    cout << endl;
}

// 退出系统
void SpeachManager :: exitSystem(){
    cout << "欢迎下次使用" << endl;
    exit(0);
}

// 初始化属性
void SpeachManager :: initSpeech(){
    // 容器都置空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    this->m_index = 1;
}

// 创建选手
void SpeachManager :: createSpeaker(){
    string nameSeed = "ABCDEFGHIJKL";

    for (int i=0; i<nameSeed.size(); i++){
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;

        for (int j=0; j<2; j++){
            sp.m_Score[j] = 0;
        }

        // 创建选手的编号
        this->v1.push_back(i+100001);

        // 选手编号以及对应选手放入到map容器中
        this->m_Speaker.insert(make_pair(i+100001, sp));
    }
}