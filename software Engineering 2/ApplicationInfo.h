#pragma once
#include <iostream>
#include <string>
#include <map>
#include "RecruitInfo.h"
using namespace std;

class ApplicationInfo {

private: 
	RecruitInfo* recruitInfo;
	string generalId;

public:
	ApplicationInfo(RecruitInfo* inputRecruitInfo, string inputGeneralId);

	string getGeneralId();

	//RecruitInfo attribute getter
	string getRecruitInfoWork();

	RecruitInfo* getRecruitInfo();
	void showApplicationInfo();		/* 제출 시 삭제할 함수!! */
};


