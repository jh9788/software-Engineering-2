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
	~ApplicationInfoCollection();
};