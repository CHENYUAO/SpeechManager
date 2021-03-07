#include <iostream>
#include "SpeechManager.h"
using namespace std;

int main() {
	SpeechManager sm;
	

	//测试代码
	//for (int i = 0; i < sm.v1.size(); ++i) {
	//	cout << sm.v1[i] << "\t" << endl;
	//}
	while (true) {
		sm.showMenu();
		
		int choice;
		cout << "请输入您的选择:" << endl;
		cin >> choice;

		switch (choice) {
		case 4:
			sm.exitSystem();
			break;
		case 1:
			sm.startSpeech();
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}

	//system("pause");
}
