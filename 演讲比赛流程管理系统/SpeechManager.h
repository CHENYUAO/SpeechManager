#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
using namespace std;

class SpeechManager {
public:
	//constructor
	SpeechManager();
	//destructor
	~SpeechManager();


	void showMenu();

	//初始化比赛，容器清空
	void initSpeech();

	//创建选手
	void createSpeaker();

	//开始比赛
	void startSpeech();

	//抽签
	void speechDraw();

	//正式比赛
	void speechContest();

	//显示晋级选手信息
	void showScore();

	void exitSystem();

	//12人容器
	vector<int> v1;

	//第2轮晋级选手
	vector<int> v2;

	//胜出选手
	vector<int> victory;

	//存放编号与具体选手容器
	map<int, Speaker> m_Speaker;

	//比赛轮次
	int m_Turn;
};