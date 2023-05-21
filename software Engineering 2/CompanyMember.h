#pragma once
#include "Member.h"

using namespace std;

/*
Ŭ���� �̸� : CompanyMember
��� : CompanyMember�� �����Ѵ�.
	   businessNum�� �������� �Լ��� ȣ���Ѵ�.
*/
class CompanyMember : public Member
{
private:
	char* businessNum;
	//RecruitInfoCollection recruitList;

public:
	CompanyMember(const char* inputName, const char* businessNum, const char* inputId, const char* inputPassword, int inputMemberType);
	char* getBusinessNum();		// businessNum ���� �����´�.
	virtual void showMemberInfo();	/* ���� �� ������ �Լ�!! */
	//void getRecruitList();
	//void addRecruitInfo();
	//bool isCompanyNameSame();
	~CompanyMember();
};