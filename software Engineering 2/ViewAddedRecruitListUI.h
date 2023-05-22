#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ViewAddedRecruitList;

// ����� ä�� ���� ��ȸ UI
class ViewAddedRecruitListUI {
private:
	ViewAddedRecruitList* control;
	ofstream* fout;
public:
	ViewAddedRecruitListUI(ViewAddedRecruitList* inputControl);		// ������
	void init(ofstream* inputFout);									// ���� ������� ���� �Լ�

	void startInterface();		// �������̽� ����
	void showRecruitInfo(string currentLoginId);		// ��ȸ�� �����ϰ�, ��ȸ �Ϸ�� �ֵ��� ���Ͽ� ���
};