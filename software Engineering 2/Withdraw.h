#pragma once
#include <string>
using namespace std;

class WithdrawUI;
// È¸¿øÅ»Åð Control
class Withdraw {
private:
	WithdrawUI* boundary;
public:
	void withdrawMember(string& loginId, int& memberType);// È¸¿ø »èÁ¦
};