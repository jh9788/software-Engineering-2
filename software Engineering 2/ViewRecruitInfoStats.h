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
	map<string, int> getAddedRecruitInfoStats(string currentLoginId); //회사회원이 등록한 채용 정보 통계 반환
	//boundary -> 3.1 -> control
	map<string, int> getAppliedRecruitInfoStats(string currentLoginId); //일반회원이 지원한 채용 정보 통계 반환
};
