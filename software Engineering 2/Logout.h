#pragma once
#include <string>
using namespace std;

class LogoutUI;
// 로그아웃 Control
class Logout {
private:
	LogoutUI* boundary;
public:
	LogoutUI* getLogoutUI();
	void init(LogoutUI* inputBoundary);
	void logoutMember(string& loginId, int& memberType);  	// 로그아웃 진행, loginId를 ""로 비워놓고, memberType은 0으로 돌려놓음
};