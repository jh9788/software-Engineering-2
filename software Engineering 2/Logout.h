#pragma once
#include <string>

using namespace std;

class LogoutUI;
// �α׾ƿ� Control
class Logout {
private:
	LogoutUI* boundary;
public:
	void logoutMember(string& loginId, int& memberType);  	// �α׾ƿ� ����, loginId�� ""�� �������, memberType�� 0���� ��������
};