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
	char* businessNum;
	//RecruitInfoCollection recruitList;

public:
	CompanyMember(const char* inputName, const char* businessNum, const char* inputId, const char* inputPassword, int inputMemberType);
	char* getBusinessNum();		// businessNum 값을 가져온다.
	virtual void showMemberInfo();	/* 제출 시 삭제할 함수!! */
	//void getRecruitList();
	//void addRecruitInfo();
	//bool isCompanyNameSame();
	~CompanyMember();
};