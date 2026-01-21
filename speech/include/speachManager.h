#pragma once
#include<iostream>
#include<vector>
#include<map>
#include "speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>

using namespace std;

// 设计管理类
class SpeachManager{
    public:

    SpeachManager();

    // 展示菜单
    void show_Menu();

    // 退出系统
    void exitSystem();

    // 创建选手
    void createSpeaker();

    // 开始比赛
    void startSpeech();

    // 抽签
    void speechDraw();

    // 比赛
    void speechContest();

    ~SpeachManager();

    // 初始化容器和属性
    void initSpeech();

    // 显示分数
    void showScore();

    // 保存记录
    void saveRecord();

    // 读取记录
    void loadRecord();

    // 判断文件是否为空
    bool fileIsEmpty;
    
    // 存放往届记录的容器
    map<int, vector<string>> m_Record;

    // 显示记录
    void showRecord();

    // 清空记录
    void clearRecord(); 

    // 成员属性
    vector<int> v1;

    vector<int> v2;

    vector<int> vVictory;

    // 存放编号和具体的选手

    map<int, Speaker> m_Speaker;

    // 记录轮次
    int m_index;
};