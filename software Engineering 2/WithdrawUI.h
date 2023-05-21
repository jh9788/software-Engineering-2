#pragma once
#include <string>
#include <fstream>
using namespace std;

class Withdraw;
// ȸ��Ż�� UI
class WithdrawUI {
private:
	Withdraw* control;
	ofstream* fout;
public:
	WithdrawUI(Withdraw* inputControl);
	void init(ofstream* inputFout);

	void startInterface(); // �������̽� ����
	void requestWithdraw(string& loginId, int& memberType); // ȸ�� ���� ��û
	void showWithdrawId(string withdrawId); // ȸ�� Ż���� ID ���
};