#pragma once
#include "Member.h"

using namespace std;

/*
클래스 이름 : CompanyMember
기능 : CompanyMember를 생성한다.
	   businessNum을 가져오는 함수를 호출한다.
*/
class CompanyMember : public Member
{
private:
	string businessNum;

public:
	CompanyMember(string inputName, string businessNum, string inputId, string inputPassword, int inputMemberType);
	virtual string getBusinessNum();		// businessNum 값을 가져온다.
	virtual void showMemberInfo();	/* 제출 시 삭제할 함수!! */
	~CompanyMember();
};