#include "speachManager.h"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <ios>
#include <iterator>
#include <numeric>
#include <utility>

// 构造函数
SpeachManager ::SpeachManager() {
  this->initSpeech();

  // 创建 12 名选手
  this->createSpeaker();

  // 加载往届记录
  this->loadRecord();
}

// 析构函数

SpeachManager ::~SpeachManager() {}

// 菜单功能
void SpeachManager ::show_Menu() {
  cout << "******************" << endl;
  cout << "***欢迎参加比赛*****" << endl;
  cout << "1 开始比赛" << endl;
  cout << "2 查看往届记录" << endl;
  cout << "3 清空比赛记录" << endl;
  cout << "0 退出比赛程序" << endl;
  cout << endl;
}

// 退出系统
void SpeachManager ::exitSystem() {
  cout << "欢迎下次使用" << endl;
  exit(0);
}

// 初始化属性
void SpeachManager ::initSpeech() {
  // 容器都置空
  this->v1.clear();
  this->v2.clear();
  this->vVictory.clear();
  this->m_Speaker.clear();

  this->m_index = 1;

  // 将记录的容器清空
  this->m_Record.clear();
}

// 创建选手
void SpeachManager ::createSpeaker() {
  string nameSeed = "ABCDEFGHIJKL";

  for (int i = 0; i < nameSeed.size(); i++) {
    string name = "选手";
    name += nameSeed[i];

    Speaker sp;
    sp.m_Name = name;

    for (int j = 0; j < 2; j++) {
      sp.m_Score[j] = 0;
    }

    // 创建选手的编号
    this->v1.push_back(i + 100001);

    // 选手编号以及对应选手放入到map容器中
    this->m_Speaker.insert(make_pair(i + 100001, sp));
  }
}

// 开始比赛
void SpeachManager ::startSpeech() {
  // 第一轮比赛

  // 1、抽签
  this->speechDraw();

  // 2、比赛
  this->speechContest();

  // 3、显示晋级结果
  this->showScore();

  // 第二轮
  this->m_index++;

  // 1、抽签
  this->speechDraw();

  // 2、比赛
  this->speechContest();

  // 3、显示晋级结果
  this->showScore();

  // 4、保存分数到文件
  this->saveRecord();

  // 重置比赛，获取记录
  // 初始化容器和属性
  this->initSpeech();

  // 创建 12 名选手
  this->createSpeaker();

  // 加载往届记录
  this->loadRecord();

  cout << "本届比赛完毕" << endl;
}

void SpeachManager ::speechDraw() {
  cout << "第" << this->m_index << ">> 轮比赛选手正在抽签" << endl;
  cout << "--------------------------" << endl;
  cout << "抽签后顺序如下" << endl;

  if (this->m_index == 1) {
    // 第一轮比赛
    random_shuffle(v1.begin(), v1.end());
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
      cout << *it << endl;
    }
    cout << endl;
  } else {
    // 第二轮比赛
    random_shuffle(v2.begin(), v2.end());
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
      cout << *it << endl;
    }
    cout << endl;
  }
  cout << "--------------------------" << endl;
  cout << endl;
}

// 比赛
void SpeachManager ::speechContest() {
  cout << "第" << this->m_index << "轮比赛正式开始" << endl;

  // 准备一个临时的容器来存放小组的成绩
  multimap<double, int, greater<double>> groupScore;
  int num = 0; // 记录人员的个数，6人一组

  vector<int> v_Src; // 比赛人员容器
  if (this->m_index == 1) {
    v_Src = v1;
  } else {
    v_Src = v2;
  }

  // 遍历所有的选手
  for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
    num++;
    // 评为打分
    deque<double> d;
    for (int i = 0; i < 10; i++) {
      double score = (rand() % 401 + 600) / 10.f;
      // cout << score << " " << endl;
      d.push_back(score);
    }

    sort(d.begin(), d.end(), greater<double>());
    d.pop_front(); //去除最高分
    d.pop_back();  // 去除最低分

    double sum = accumulate(d.begin(), d.end(), 0.0f);
    double avg = sum / (double)d.size();

    // 打印平均分
    // cout << "编号: " << *it << " 姓名: " << this->m_Speaker[*it].m_Name << "
    // 获取平均分: " << avg << endl;

    // 将平均分放到 map 容器中
    this->m_Speaker[*it].m_Score[this->m_index - 1] = avg;

    // 将打分的数据放到临时小组中
    groupScore.insert(make_pair(avg, *it)); // key 是的分， value是具体的分

    // 每6人取出前3名
    if (num % 6 == 0) {
      cout << "第" << num / 6 << "小组比赛名次" << endl;
      for (multimap<double, int, greater<double>>::iterator it =
               groupScore.begin();
           it != groupScore.end(); it++) {
        cout << "编号: " << it->second
             << "姓名: " << this->m_Speaker[it->second].m_Name << "平均成绩: "
             << this->m_Speaker[it->second].m_Score[this->m_index - 1] << endl;
      }

      // 取走前 3 名
      int count = 0;
      for (multimap<double, int>::iterator it = groupScore.begin();
           it != groupScore.end() && count != 3; it++, count++) {
        if (this->m_index == 1) {
          v2.push_back((*it).second);
        } else {
          vVictory.push_back((*it).second);
        }
      }

      groupScore.clear();
      cout << endl;
    }
  }
  cout << "第" << this->m_index << " 轮，比赛完毕" << endl;
}

// 显示的分
void SpeachManager ::showScore() {
  cout << "--------------第" << this->m_index << " 轮晋级选手信息如下" << endl;
  vector<int> v;
  if (this->m_index == 1) {
    v = v2;
  } else {
    v = vVictory;
  }
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << "选手编号" << *it << "姓名" << this->m_Speaker[*it].m_Name << "得分"
         << this->m_Speaker[*it].m_Score[this->m_index - 1] << endl;
  }
  cout << endl;
}

// 保存记录
void SpeachManager ::saveRecord() {
  ofstream ofs;
  ofs.open("apeech.csv", ios::out | ios::app);

  // 将每个人的数据，写入到文件中
  for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end();
       it++) {
    ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
  }
  ofs << endl;

  // 关闭
  ofs.close();
  cout << "记录已经保存完" << endl;
  this->fileIsEmpty = false;
}

void SpeachManager ::loadRecord() {
  ifstream ifs("apeech.csv", ios::in);
  if (!ifs.is_open()) {
    this->fileIsEmpty = true;
    // cout << "文件不存在" << endl;
    ifs.close();
    return;
  }

  // 文件清空
  char c;
  ifs >> c;
  if (ifs.eof()) {
    // cout << "文件为空" << endl;
    this->fileIsEmpty = true;
    ifs.close();
    return;
  }

  // 文件不为空
  this->fileIsEmpty = false;
  ifs.putback(c); // 将上面读取的但个字符再放回
  string data;

  int index = 0;

  while (ifs >> data) {

    vector<string> v; // 存放6个string的字符窜

    int pos = -1; // 查到逗号的位置变量
    int start = 0;

    while (true) {
      pos = data.find(",", start);

      if (pos == -1) {
        // 没有找到
        break;
      }
      string temp = data.substr(start, pos - start);
      v.push_back(temp);
      start = pos + 1;
    }
    this->m_Record.insert(make_pair(index, v));
    index++;
  }
  ifs.close();

  // for (map<int, vector<string>>::iterator it=m_Record.begin();
  // it!=m_Record.end(); it++){
  //     cout << it->first << "冠军编号: " << it->second[0] << "\t分数: " <<
  //     it->second[1] << endl;
  // }
}

// 显示往届记录
void SpeachManager ::showRecord() {

  if (this->fileIsEmpty) {
    cout << "文件为空或不存在" << endl;
  } else {
    for (int i = 0; i < this->m_Record.size(); i++) {
      cout << "第" << i + 1 << "届"
           << "冠军编号" << this->m_Record[i][0]
           << "得分: " << this->m_Record[i][1] << " "
           << "亚军编号" << this->m_Record[i][2]
           << "得分: " << this->m_Record[i][3] << " "
           << "季军编号" << this->m_Record[i][4]
           << "得分: " << this->m_Record[i][5] << " " << endl;
    }
  }
}

// 清空数据
void SpeachManager :: clearRecord(){
    cout << "是否清空文件" << endl;
    cout << "1 : 是" << endl;
    cout << "2 : 否" << endl;
    
    int select = 0;
    cin >> select;

    if (select == 1){
        ofstream ofs("apeech.csv", ios::trunc);
        ofs.close();

        // 初始化容器和属性
        this->initSpeech();

        // 创建 12 名选手
        this->createSpeaker();

        // 加载往届记录
        this->loadRecord();
    }
}