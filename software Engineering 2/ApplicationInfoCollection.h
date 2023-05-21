#pragma once
#include <vector>
#include <map>
#include <string>
#include "ApplicationInfo.h"

using namespace std;

/*
클래스 이름 : ApplicationInfoCollection
기능 : 
*/
class ApplicationInfoCollection {
private:
	vector<ApplicationInfo*> applicationInfoVec;
public:
	~ApplicationInfoCollection();
};