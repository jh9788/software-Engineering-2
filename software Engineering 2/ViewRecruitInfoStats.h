#pragma once
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"
#include <iostream>
#include <string>

using namespace std;

class ViewRecruitInfoStatsUI;

/*
Ŭ���� �̸�: ViewRecruitInfoStats
���: ä�� ���� ��� Control
*/
class ViewRecruitInfoStats{
private:
	ViewRecruitInfoStatsUI* boundary;  //ä�� ���� ��� Boundary Ŭ���� ���� ��
	
	RecruitInfoCollection* recruitInfoCollection; //ä�� ���� Collection Ŭ���� ���� ��
	ApplicationInfoCollection* applicationInfoCollection; //���� ���� Collection Ŭ���� ���� ��

public:
	ViewRecruitInfoStats(RecruitInfoCollection* recruitInfoCollection, ApplicationInfoCollection* applicationInfoCollection); //������

	ViewRecruitInfoStatsUI* getViewRecruitInfoStatsUI();  //ä�� ���� ��� Boundary Ŭ���� ��ȯ

	//boundary -> 2.1 -> control
	string getAddedRecruitInfoStats(string currentLoginId); //ȸ��ȸ���� ����� ä�� ���� ��� ��ȯ
	//boundary -> 3.1 -> control
	string getAppliedRecruitInfoStats(string currentLoginId); //�Ϲ�ȸ���� ������ ä�� ���� ��� ��ȯ
};
