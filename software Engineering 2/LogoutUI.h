#pragma once
#include <string>

using namespace std;

class Logout;
// �α׾ƿ� UI
class LogoutUI {
private:
	Logout* control;
public:
	void startInterface();		// �������̽� ����
	void requestLogout(string& loginId, int& memberType);	// �α׾ƿ� ��û
	void showLogoutId(string logoutId);		// �α׾ƿ� ���� ȭ�� ���Ͽ� ����
};