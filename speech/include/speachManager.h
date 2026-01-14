#pragma once
#include<iostream>
#include<vector>
#include<map>
#include "speaker.h"

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

    ~SpeachManager();

    // 初始化容器和属性
    void initSpeech();

    // 成员属性
    vector<int> v1;

    vector<int> v2;

    vector<int> vVictory;

    // 存放编号和具体的选手

    map<int, Speaker> m_Speaker;

    // 记录轮次
    int m_index;
};