#include "SpeechManager.h"

SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
}


SpeechManager::~SpeechManager() {


}

void SpeechManager::showMenu() {
	cout << "************************************" << endl;
	cout << "********* ��ӭ�μ��ݽ����� *********" << endl;
	cout << "********* 1. ��ʼ�ݽ����� **********" << endl;
	cout << "********* 2. �鿴�����¼ **********" << endl;
	cout << "********* 3. ��ձ�����¼ **********" << endl;
	cout << "********* 4. �˳��������� **********" << endl;
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
		string name = "ѡ��";
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
	//��һ�ֱ���
		//��ǩ
	this->speechDraw();
		//����
	this->speechContest();
		//��ʾ�������
	this->showScore();
	//�ڶ��ֱ���
	this->m_Turn++;
		//��ǩ
	this->speechDraw();
		//����
	this->speechContest();
		//��ʾ�������
	this->showScore();
		//������

}


void SpeechManager::speechDraw() {
	cout << "�� <" << this->m_Turn << "> �ֱ������ڽ��г�ǩ" << endl;
	cout << "----------------" << endl;
	if (this->m_Turn == 1) {
		random_shuffle(v1.begin(), v1.end());
		cout << "��ǩ���ݽ�˳�����£�" << endl;
		for (auto v: v1) {
			cout << v << endl;
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		cout << "��ǩ���ݽ�˳�����£�" << endl;
		for (auto v : v2) {
			cout << v << endl;
		}
	}
	cout << "----------------" << endl;
	system("pause");
}

void SpeechManager::speechContest() {
	cout << "----- ��" << this->m_Turn << "�ֱ�����ʽ��ʼ -----" << endl;
	cout << endl;
	//׼����ʱ�������С��ɼ�
	multimap<double, int, greater<double>> groupScore;
	//ͳ����Ա������6��һ��
	int num = 0;

	vector<int> vSrc;//����ѡ������
	if (this->m_Turn == 1) {
		vSrc = v1;
	}
	else vSrc = v2;


	//����ѡ�ֽ��б���
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); ++it) {
		++num;
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 400 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(),greater<double>());
		d.pop_back();
		d.pop_front();
		double avg = accumulate(d.begin(), d.end(), 0.0f) / (double)d.size(); //ƽ����

		//test   
		//cout << "�����ɼ��� "<< endl << *it << ": " << avg << endl;
		//��ƽ���ַ���������
		this->m_Speaker[*it].m_Score[this->m_Turn - 1] = avg;

		//������ݷ���С��������
		groupScore.insert(pair<double, int>(avg, *it));
		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С������������£� " << endl;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end(); ++it) {
				cout << "��ţ� " << it->second << "\t������ " << this->m_Speaker[it->second].m_Name
					<< "\t�ɼ��� " << it->first << endl;
			}
			cout << endl;
			//ȡ��ǰ����
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
	cout << "----- �� <" << this->m_Turn <<">�ֱ������� -----" << endl;
	system("pause");
}


void SpeechManager::showScore() {
	cout << "��<" << this->m_Turn << ">�ֽ���ѡ�����£� " << endl;
	vector<int> vSrc;
	if (this->m_Turn == 1) {
		vSrc = v2;
	}
	else  vSrc = victory;
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); ++it) {
		cout << "ѡ�ֱ�ţ� " << *it << "\t������ " <<  this->m_Speaker[*it].m_Name << "\tѡ�ֳɼ��� " << this->m_Speaker[*it].m_Score[this->m_Turn - 1] << endl;
	}

	cout << endl;
	
	system("pause");
	system("cls");

}











void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}