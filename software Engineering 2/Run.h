#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include <iostream>
#include <string>

using namespace std;

void run();
void program_exit();

// 객체에 대한 주석 제대로 추가해야함!!
// 회원가입 UI
class RegisterUI {
private:
public:
	void startInterface();		// 인터페이스 시작
	int selectMemberType(string inputEvent);		// 회사 회원인지, 일반 회원인지 member type 고르기
	void requestRegister(MemberCollection& memberCollection, string inputEvent, int memberType);		// 회원 가입 요청
	void showRegisterSuccessInterface(string inputEvent, int memberType);		// 회원 가입 성공 화면 파일에 저장
};

// 회원가입 Control
class Register {
private:
public:
	// 회사 회원 생성
	void registerCompanyMember(MemberCollection& memberCollection,
							   const char* name, const char* num, const char* id, const char* pwd, int memberType);
	// 일반 회원 생성
	void registerGeneralMember(MemberCollection& memberCollection,
							   const char* name, const char* num, const char* id, const char* pwd, int memberType);
};

// 로그인 UI
class LoginUI {
private:
public:
	void startInterface();		// 인터페이스 시작
	bool requestLogin(MemberCollection& memberCollection, string inputEvent, string& loginId, int& memberType);	// 로그인 요청, ID와 PW가 일치한다면 true 반환
	void showLoginSuccessInterface(string inputEvent);		// 로그인 성공 화면 파일에 저장
	void showLoginFailInterface();		// 로그인 실패 화면 파일에 저장
};

// 로그인 Control
class Login {
private:
public:
	bool verifyLogin(MemberCollection& memberCollection, const char* id, const char* pwd, string& loginId, int& memberType);
};

// 로그아웃 UI
class LogoutUI {
private:
public:
	void startInterface();		// 인터페이스 시작
	void requestLogout(string& loginId, int& memberType);	// 로그아웃 요청
	void showLogoutId(string logoutId);		// 로그아웃 성공 화면 파일에 저장
};

// 로그아웃 Control
class Logout {
private:
public:
	void logoutMember(string& loginId, int& memberType);  	// 로그아웃 진행, loginId를 ""로 비워놓고, memberType은 0으로 돌려놓음
};

// 회원탈퇴 UI
class WithdrawUI {
private:
public:
	void startInterface();		// 인터페이스 시작
	void requestWithdraw(MemberCollection& memberCollection, string& loginId, int& memberType);		// 회원 삭제 요청
	void showWithdrawId(string withdrawId);		// 회원 탈퇴한 ID 기록
};

// 회원탈퇴 Control
class Withdraw {
private:
public:
	void withdrawMember(MemberCollection& memberCollection, string& loginId, int& memberType);			// 회원 삭제
};

// 채용 정보 추가 UI
class AddRecruitInfoUI {
private:
public:
	void startInterface();		// 인터페이스 시작
	void requestRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string inputEvent, string nowLogin);		// recruitInfoCollection에 recruitInfo를 추가하는 함수 호출
	void showAddedRecruitInfo(string inputEvent);		// 추가가 완료되면 파일에 기록
};

// 채용 정보 추가 Control
class AddRecruitInfo {
private:
public:
	void addRecruitInfo(RecruitInfoCollection& recruitInfoCollection,
						const char* work, const char* targetNum, const char* deadline, const char* nowLogin);
};

// 채용 정보 추가 UI
class ViewAddedRecruitListUI {
private:
public:
	void startInterface();		// 인터페이스 시작
	void showRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string nowLogin);		// 추가가 완료되면 파일에 기록
};

// 채용 정보 추가 Control
class ViewAddedRecruitList {
private:
public:
};