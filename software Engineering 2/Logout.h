#pragma once
#include <string>
using namespace std;

class LogoutUI;
// �α׾ƿ� Control
class Logout {
private:
	LogoutUI* boundary;
public:
	LogoutUI* getLogoutUI();
	void init(LogoutUI* inputBoundary);
	void logoutMember(string& loginId, int& memberType);  	// �α׾ƿ� ����, loginId�� ""�� �������, memberType�� 0���� ��������
};