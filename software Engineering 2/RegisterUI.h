#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Register;

// 회원가입 UI
class RegisterUI 
{
private:
	Register* control;
	ofstream* fout;
public:
	RegisterUI(Register* inputControl);
	void init(ofstream* inputFout); 

	void startInterface();		// 인터페이스 시작
	int selectMemberType(string inputEvent);		// 회사 회원인지, 일반 회원인지 member type 고르기
	void requestRegister(string inputEvent, int memberType);		// 회원 가입 요청
	void showRegisterSuccessInterface(string inputEvent, int memberType);		// 회원 가입 성공 화면 파일에 저장
};