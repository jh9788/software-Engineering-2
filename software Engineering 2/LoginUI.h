#pragma once

#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include <iostream>
#include <string>

using namespace std;



class Login;

// 로그인 UI
class LoginUI {
private:
	Login* control;
public:
	void startInterface();		// 인터페이스 시작
	bool requestLogin(MemberCollection& memberCollection, string inputEvent, string& loginId, int& memberType);	// 로그인 요청, ID와 PW가 일치한다면 true 반환
	void showLoginSuccessInterface(string inputEvent);		// 로그인 성공 화면 파일에 저장
	void showLoginFailInterface();		// 로그인 실패 화면 파일에 저장
};