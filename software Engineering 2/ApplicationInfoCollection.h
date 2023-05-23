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
	RecruitInfoCollection* recruitCollection;
public:
	ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitCollection);
	void addApplicationInfo(string currentLoginId);	// ȸ�� ���� ��, ȸ�� �߰�
	void removeApplicationInfo(string currentLoginId); // ȸ�� Ż�� ��, ȸ�� ����
	string getApplicationInfo(string currentLoginId);

};