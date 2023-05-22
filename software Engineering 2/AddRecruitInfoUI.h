#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class AddRecruitInfo;

 //ä�� ���� �߰� UI
class AddRecruitInfoUI {
private:
	AddRecruitInfo* control;
	ofstream* fout;
public:
	AddRecruitInfoUI(AddRecruitInfo* inputControl);		// ������
	void init(ofstream* inputFout);						// ���� ������� ���� �Լ�

	void startInterface();		// �������̽� ����
	void requestRecruitInfo(string inputEvent, string currentLoginId);		// recruitInfoCollection�� recruitInfo�� �߰��ϴ� �Լ� ȣ��
	void showAddedRecruitInfo(string inputEvent);		// �߰��� �Ϸ�Ǹ� ���Ͽ� ���
};