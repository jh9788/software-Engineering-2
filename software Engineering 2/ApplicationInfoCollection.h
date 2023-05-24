#pragma once
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "ApplicationInfo.h"
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"

using namespace std;

/*
Ŭ���� �̸� : ApplicationInfoCollection
��� : 
*/
class ApplicationInfoCollection {
private:
	vector<ApplicationInfo*> ownedApplicationInfo;

	MemberCollection* memberCollection;
	RecruitInfoCollection* recruitInfoCollection;
public:
	void getAllApplicationInfoCollection(); /* ���� �� ������ �Լ� !! */ // ���� ��ϵ� ȸ�� ��� ��� ��ȸ
	ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitCollection);

	void addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId);	// ȸ�� ���� ��, ȸ�� �߰�
	string removeApplicationInfo(string currentLoginId, string inputBusinessNum); // ���� ���
	void removeAllApplicationInfo(string currentLoginId); //ȸ�� Ż��� ���� ���� ����
	string getApplicationInfo(string currentLoginId);

	//control -> 3.1.1 -> applicationinfo collection
	map<string, int> calcAppliedRecruitInfoStats(string currentLoginId);
};