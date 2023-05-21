#pragma once
#include <iostream>
#include <string>

using namespace std;

class Register;
// 객체에 대한 주석 제대로 추가해야함!!
// 회원가입 UI
class RegisterUI {
private:

	Register* control;
public:
	void startInterface();		// 인터페이스 시작
	int selectMemberType(string inputEvent);		// 회사 회원인지, 일반 회원인지 member type 고르기
	void requestRegister(MemberCollection& memberCollection, string inputEvent, int memberType);		// 회원 가입 요청
	void showRegisterSuccessInterface(string inputEvent, int memberType);		// 회원 가입 성공 화면 파일에 저장
};