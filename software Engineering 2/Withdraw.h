#pragma once
#include <string>
using namespace std;

class WithdrawUI;
// ȸ��Ż�� Control
class Withdraw {
private:
	WithdrawUI* boundary;
public:
	void withdrawMember(string& loginId, int& memberType);// ȸ�� ����
};