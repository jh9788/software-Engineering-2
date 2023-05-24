#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "RecruitInfoCollection.h"

using namespace std;

class SearchRecruitInfo;

/*
Ŭ���� �̸� : SearchRecruitInfoUI
��� : ä�� ���� �˻� Boundary
*/
class SearchRecruitInfoUI {
private:
	SearchRecruitInfo* control;
	ofstream* fout;
public:
	SearchRecruitInfoUI(SearchRecruitInfo* inputControl); // ������
	void init(ofstream* inputFout); //���� ������� ���� �Լ�

	void startInterface(); // �������̽� ����
	void showSearchRecruitInfo(string inputEvent); // ä�� ���� �˻��� �����ϴ� �Լ�
};