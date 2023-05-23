#pragma once
#include <string>
#include "RecruitInfo.h"
using namespace std;

class ApplicationInfo {

private: 

	RecruitInfo* recruitInfo;
	string generalId;


public:
	ApplicationInfo(RecruitInfo* inputRecruitInfo, string inputGeneralId);
	string getGeneralId();
	RecruitInfo* getRecruitInfo();
};


