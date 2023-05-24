#pragma once
#include <string>
#include <fstream>

using namespace std;


class Logout;

/*
Ŭ���� �̸� : LoginUI
��� : �α׾ƿ� Boundary
*/
class LogoutUI
{
private:
	Logout* control;
	ofstream* fout;

	void _showLogoutId(string logoutId);		// �α׾ƿ� ���� ȭ�� ���Ͽ� ����
public:
	LogoutUI(Logout* inputControl);		// ������
	void init(ofstream* inputFout);		// ���� ������� ���� �Լ�

	void startInterface();		// �������̽� ����
	void requestLogout(string& loginId, string tempId, int& memberType);	// �α׾ƿ� ��û
};