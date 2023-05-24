#pragma once
#include <vector>
#include <map>
#include <string>
#include "ApplicationInfo.h"

using namespace std;

/*
Ŭ���� �̸� : ApplicationInfoCollection
��� : 
*/
class ApplicationInfoCollection {
private:
	vector<ApplicationInfo*> applicationInfoVec;
public:

	//control -> 3.1.1 -> applicationinfo collection
	map<string, int> calcAppliedRecruitInfoStats(string currentLoginId);
};