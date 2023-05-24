#pragma once
#include <string>
#include <fstream>
using namespace std;

class Withdraw;


/*
Ŭ���� �̸� : WithdrawUI
��� : ȸ��Ż�� Boundary
*/
class WithdrawUI 
{
private:
	Withdraw* control;
	ofstream* fout;

	void _showWithdrawId(string withdrawId); // ȸ�� Ż���� ID ���
public:
	WithdrawUI(Withdraw* inputControl);	// ������
	void init(ofstream* inputFout);		// ���� ������� ���� �Լ�

	void startInterface(); // �������̽� ����
	void requestWithdraw(string& loginId, string tempId, int& memberType); // ȸ�� ���� ��û
};