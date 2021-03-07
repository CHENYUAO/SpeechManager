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

	//��ʼ���������������
	void initSpeech();

	//����ѡ��
	void createSpeaker();

	//��ʼ����
	void startSpeech();

	//��ǩ
	void speechDraw();

	//��ʽ����
	void speechContest();

	//��ʾ����ѡ����Ϣ
	void showScore();

	void exitSystem();

	//12������
	vector<int> v1;

	//��2�ֽ���ѡ��
	vector<int> v2;

	//ʤ��ѡ��
	vector<int> victory;

	//��ű�������ѡ������
	map<int, Speaker> m_Speaker;

	//�����ִ�
	int m_Turn;
};