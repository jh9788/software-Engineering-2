#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"

using namespace std;

class ApplyImmediatelyUI;

// 채용 지원 Control
class ApplyImmediately
{
private:
	ApplyImmediatelyUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
public:
	ApplyImmediately(ApplicationInfoCollection* inputApplicationInfoCollection);
	ApplyImmediatelyUI* getApplyImmediatelyUI();

	void applyImmediately(string businessNum);
};

