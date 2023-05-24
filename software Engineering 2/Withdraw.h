#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"
#include "ApplicationInfoCollection.h"

using namespace std;

class WithdrawUI;

// È¸¿øÅ»Åð Control
class Withdraw 
{
private:
	WithdrawUI* boundary;
	MemberCollection* memberCollection;
	ApplicationInfoCollection* applicationInfoCollection;

public:
	Withdraw(MemberCollection* inputMemberCollection, ApplicationInfoCollection* inputApplicationInfoCollection);
	WithdrawUI* getWithdrawUI();
	void withdrawMember(string& loginId, int& memberType);// È¸¿ø »èÁ¦
};