#include "SpeechManager.h"

SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
}


SpeechManager::~SpeechManager() {


}

void SpeechManager::showMenu() {
	cout << "************************************" << endl;
	cout << "********* 欢迎参加演讲比赛 *********" << endl;
	cout << "********* 1. 开始演讲比赛 **********" << endl;
	cout << "********* 2. 查看往届记录 **********" << endl;
	cout << "********* 3. 清空比赛记录 **********" << endl;
	cout << "********* 4. 退出比赛程序 **********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void SpeechManager::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_Speaker.clear();
	this->m_Turn = 1;
}

void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); ++i) {
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		sp.m_Score[0] = 0;
		sp.m_Score[1] = 0;

		this->v1.push_back(i+10001);

		this->m_Speaker.insert(pair<int, Speaker>(i + 10001, sp));
	}
}


void SpeechManager::startSpeech() {
	//第一轮比赛
		//抽签
	this->speechDraw();
		//比赛
	this->speechContest();
		//显示晋级结果
	this->showScore();
	//第二轮比赛
	this->m_Turn++;
		//抽签
	this->speechDraw();
		//比赛
	this->speechContest();
		//显示晋级结果
	this->showScore();
		//保存结果

}


void SpeechManager::speechDraw() {
	cout << "第 <" << this->m_Turn << "> 轮比赛正在进行抽签" << endl;
	cout << "----------------" << endl;
	if (this->m_Turn == 1) {
		random_shuffle(v1.begin(), v1.end());
		cout << "抽签后演讲顺序如下：" << endl;
		for (auto v: v1) {
			cout << v << endl;
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		cout << "抽签后演讲顺序如下：" << endl;
		for (auto v : v2) {
			cout << v << endl;
		}
	}
	cout << "----------------" << endl;
	system("pause");
}

void SpeechManager::speechContest() {
	cout << "----- 第" << this->m_Turn << "轮比赛正式开始 -----" << endl;
	cout << endl;
	//准备临时容器存放小组成绩
	multimap<double, int, greater<double>> groupScore;
	//统计人员个数，6个一组
	int num = 0;

	vector<int> vSrc;//比赛选手容器
	if (this->m_Turn == 1) {
		vSrc = v1;
	}
	else vSrc = v2;


	//遍历选手进行比赛
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); ++it) {
		++num;
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 400 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(),greater<double>());
		d.pop_back();
		d.pop_front();
		double avg = accumulate(d.begin(), d.end(), 0.0f) / (double)d.size(); //平均分

		//test   
		//cout << "比赛成绩： "<< endl << *it << ": " << avg << endl;
		//将平均分放入容器中
		this->m_Speaker[*it].m_Score[this->m_Turn - 1] = avg;

		//打分数据放入小组容器中
		groupScore.insert(pair<double, int>(avg, *it));
		//每6人取出前三名
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "小组比赛名次如下： " << endl;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end(); ++it) {
				cout << "编号： " << it->second << "\t姓名： " << this->m_Speaker[it->second].m_Name
					<< "\t成绩： " << it->first << endl;
			}
			cout << endl;
			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; ++count,++it) {
				if (this->m_Turn == 1) {
					v2.push_back(it->second);
				}
				else victory.push_back(it->second);
			}


			groupScore.clear();
		}
	}
	cout << "----- 第 <" << this->m_Turn <<">轮比赛结束 -----" << endl;
	system("pause");
}


void SpeechManager::showScore() {
	cout << "第<" << this->m_Turn << ">轮晋级选手如下： " << endl;
	vector<int> vSrc;
	if (this->m_Turn == 1) {
		vSrc = v2;
	}
	else  vSrc = victory;
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); ++it) {
		cout << "选手编号： " << *it << "\t姓名： " <<  this->m_Speaker[*it].m_Name << "\t选手成绩： " << this->m_Speaker[*it].m_Score[this->m_Turn - 1] << endl;
	}

	cout << endl;
	
	system("pause");
	system("cls");

}











void SpeechManager::exitSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}