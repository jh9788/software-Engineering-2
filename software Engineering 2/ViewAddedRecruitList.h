#pragma once
#include <iostream>
#include <string>
#include "RecruitInfoCollection.h"

using namespace std;

class ViewAddedRecruitListUI;

// ����� ä�� ���� ��ȸ Control
class ViewAddedRecruitList {
private:
	ViewAddedRecruitListUI* boundary;
	RecruitInfoCollection* recruitInfoCollection;
public:
	ViewAddedRecruitList(RecruitInfoCollection* inputRecruitInfoCollection);	// ������
	ViewAddedRecruitListUI* getViewAddedRecruitListUI();	// Boundary�� ȣ���ϱ� ���� �Լ�

	string viewAddedRecruitList(string currentLoginId);		// ��ϵ� ä�� ������ ��� Ȯ���ϴ� �Լ�
};