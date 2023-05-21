#pragma once
#include <string>
#include <fstream>

using namespace std;


class Logout;
// 로그아웃 UI
class LogoutUI {
private:
	Logout* control;
	ofstream* fout;
public:
	LogoutUI(Logout* inputControl);
	void init(ofstream* inputFout);

	void startInterface();		// 인터페이스 시작
	void requestLogout(string& loginId, int& memberType);	// 로그아웃 요청
	void showLogoutId(string logoutId);		// 로그아웃 성공 화면 파일에 저장
};