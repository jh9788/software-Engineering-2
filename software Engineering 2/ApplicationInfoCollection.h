#pragma once
#include <vector>
#include <map>
#include <string>
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
	vector<ApplicationInfo*> applicationInfoCollection;
	MemberCollection* memberCollection;
	RecruitInfoCollection* recruitInfoCollection;
public:
	void getAllApplicationInfoCollection(); /* ���� �� ������ �Լ� !! */ // ���� ��ϵ� ȸ�� ��� ��� ��ȸ
	ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitCollection);
	void addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId);	// ȸ�� ���� ��, ȸ�� �߰�
	string removeApplicationInfo(string currentLoginId, string inputBusinessNum); // ȸ�� Ż�� ��, ȸ�� ����
	string getApplicationInfo(string currentLoginId);
};