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
클래스 이름 : ApplicationInfoCollection
기능 : 
*/
class ApplicationInfoCollection {
private:
	vector<ApplicationInfo*> ownedApplicationinfo;

	MemberCollection* memberCollection;
	RecruitInfoCollection* recruitInfoCollection;
public:
	bool cmp(ApplicationInfo& a, ApplicationInfo& b);
	void getAllApplicationInfoCollection(); /* 제출 시 삭제할 함수 !! */ // 현재 등록된 회원 목록 모두 조회
	ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitCollection);
	void addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId);	// 회원 가입 시, 회원 추가
	string removeApplicationInfo(string currentLoginId, string inputBusinessNum); // 회원 탈퇴 시, 회원 삭제
	string getApplicationInfo(string currentLoginId);
};