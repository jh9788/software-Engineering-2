#pragma once
#include <iostream>
#include <string>
#include "RecruitInfoCollection.h"

using namespace std;

class AddRecruitInfoUI;

/*
Ŭ���� �̸� : AddRecruitInfo
��� : ä�� ���� �߰� Control
*/
class AddRecruitInfo {
private:
	AddRecruitInfoUI* boundary;
	RecruitInfoCollection* recruitInfoCollection;

public:
	AddRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection);	// ������
	AddRecruitInfoUI* getAddRecruitInfoUI();	// Boundary�� ȣ���ϱ� ���� �Լ�

	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);		// ä�� ���� ����� ���� �Լ�
};