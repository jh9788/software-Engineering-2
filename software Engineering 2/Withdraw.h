#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"

using namespace std;

class WithdrawUI;

// È¸¿øÅ»Åð Control
class Withdraw {
private:
	WithdrawUI* boundary;
	MemberCollection* memberCollection;
public:
	Withdraw(MemberCollection* inputMemberCollection);
	WithdrawUI* getWithdrawUI();
	void withdrawMember(string& loginId, int& memberType);// È¸¿ø »èÁ¦
};