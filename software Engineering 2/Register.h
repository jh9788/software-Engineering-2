#pragma once
#include <iostream>
#include <string>

using namespace std;

class RegisterUI;

// 회원가입 Control
class Register {
private:
	RegisterUI* boundary;
public:
	// 회사 회원 생성
	void registerCompanyMember(MemberCollection& memberCollection,
		const char* name, const char* num, const char* id, const char* pwd, int memberType);
	// 일반 회원 생성
	void registerGeneralMember(MemberCollection& memberCollection,
		const char* name, const char* num, const char* id, const char* pwd, int memberType);
};