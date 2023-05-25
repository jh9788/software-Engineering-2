#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class AddRecruitInfo;


/*
Ŭ���� �̸� : AddRecruitInfoUI
��� : ä�� ���� �߰� Boundary
*/
class AddRecruitInfoUI {
private:
	AddRecruitInfo* control;
	ofstream* fout;

	void _showAddedRecruitInfo(string inputEvent);		// �߰��� �Ϸ�Ǹ� ���Ͽ� ���
public:
	AddRecruitInfoUI(AddRecruitInfo* inputControl);		// ������
	void init(ofstream* inputFout);						// ���� ������� ���� �Լ�

	void startInterface();		// �������̽� ����
	void requestAddRecruitInfo(string inputEvent, string currentLoginId);		// recruitInfoCollection�� recruitInfo�� �߰��ϴ� �Լ� ȣ��
};