#pragma once
#include <string>
using namespace std;

class LogoutUI;

/*
Ŭ���� �̸� : LoginUI
��� : �α׾ƿ� Control
*/
class Logout 
{
private:
	LogoutUI* boundary;
	
public:
	Logout();	// ������
	LogoutUI* getLogoutUI();	// Boundary ȣ��
	void logoutMember(string& loginId, int& memberType);  	// �α׾ƿ� ����, loginId�� ""�� �������, memberType�� 0���� ��������
};