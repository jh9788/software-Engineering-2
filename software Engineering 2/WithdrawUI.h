#pragma once
#include <string>
using namespace std;

class Withdraw;
// ȸ��Ż�� UI
class WithdrawUI {
private:
	Withdraw* control;
public:
	void startInterface();// �������̽� ����
	void requestWithdraw(string& loginId, int& memberType);// ȸ�� ���� ��û
	void showWithdrawId(string withdrawId);// ȸ�� Ż���� ID ���
};