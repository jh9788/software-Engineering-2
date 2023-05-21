#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include <iostream>
#include <string>

using namespace std;

class LoginUI;

// ·Î±×ÀÎ Control
class Login {
private:
	LoginUI* boundary;
	MemberCollection* memberCollection;
public:
	Login(MemberCollection* memberCollection);
	LoginUI* getLoginUI();
	bool verifyLogin(string id, string pwd, string& loginId, int& memberType);
};
