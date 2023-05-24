#pragma once
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class ViewRecruitInfoStatsUI;
class ViewRecruitInfoStats{
private:
	ViewRecruitInfoStatsUI* boundary;
	
	RecruitInfoCollection* recruitInfoCollection;
	ApplicationInfoCollection* applicationInfoCollection;

public:
	ViewRecruitInfoStats(RecruitInfoCollection* recruitInfoCollection, ApplicationInfoCollection* applicationInfoCollection);

	ViewRecruitInfoStatsUI* getViewRecruitInfoStatsUI();

	//boundary -> 2.1 -> control
	map<string, int> getAddedRecruitInfoStats(string currentLoginId); //ȸ��ȸ���� ����� ä�� ���� ��� ��ȯ
	//boundary -> 3.1 -> control
	map<string, int> getAppliedRecruitInfoStats(string currentLoginId); //�Ϲ�ȸ���� ������ ä�� ���� ��� ��ȯ
};
