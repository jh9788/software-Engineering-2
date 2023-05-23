#pragma once
#include <vector>
#include <map>
#include <string>
#include "ApplicationInfo.h"
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"

using namespace std;

/*
클래스 이름 : ApplicationInfoCollection
기능 : 
*/
class ApplicationInfoCollection {
private:
	vector<ApplicationInfo*> applicationInfoCollection;
	MemberCollection* memberCollection;
	RecruitInfoCollection* recruitInfoCollection;
public:
	ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitCollection);
	void addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId);	// 회원 가입 시, 회원 추가
	void removeApplicationInfo(string currentLoginId); // 회원 탈퇴 시, 회원 삭제
	string getApplicationInfo(string currentLoginId);
};