#pragma once
#include <string>
#include <fstream>

using namespace std;


class Logout;
// �α׾ƿ� UI
class LogoutUI {
private:
	Logout* control;
	ofstream* fout;
public:
	LogoutUI(Logout* inputControl);
	void init(ofstream* inputFout);

	void startInterface();		// �������̽� ����
	void requestLogout(string& loginId, int& memberType);	// �α׾ƿ� ��û
	void showLogoutId(string logoutId);		// �α׾ƿ� ���� ȭ�� ���Ͽ� ����
};