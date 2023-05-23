#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"

using namespace std;

class ApplyImmediatelyUI;

// ä�� ���� Control
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

