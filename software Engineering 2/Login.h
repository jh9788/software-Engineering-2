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
public:
	bool verifyLogin(MemberCollection& memberCollection, string id, string pwd, string& loginId, int& memberType);
};
