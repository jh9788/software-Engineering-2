#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"
using namespace std;

class RegisterUI;

// 회원가입 Control
class Register 
{
private:
	RegisterUI* boundary;
	MemberCollection* memberCollection;

public:
	Register(MemberCollection* inputMemberCollection);
	RegisterUI* getRegisterUI();

	// 회사 회원 생성
	void registerCompanyMember(string name, string num, string id, string pwd, int memberType);
	// 일반 회원 생성
	void registerGeneralMember(string name, string num, string id, string pwd, int memberType);
};