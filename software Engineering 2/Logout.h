#pragma once
#include <string>
using namespace std;

class LogoutUI;
// �α׾ƿ� Control
class Logout 
{
private:
	LogoutUI* boundary;
	
public:
	Logout();
	LogoutUI* getLogoutUI();
	void logoutMember(string& loginId, int& memberType);  	// �α׾ƿ� ����, loginId�� ""�� �������, memberType�� 0���� ��������
};