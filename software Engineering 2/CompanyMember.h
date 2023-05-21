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
	string businessNum;
	//RecruitInfoCollection recruitList;

public:
	CompanyMember(string inputName, string businessNum, string inputId, string inputPassword, int inputMemberType);
	string getBusinessNum();		// businessNum ���� �����´�.
	virtual void showMemberInfo();	/* ���� �� ������ �Լ�!! */
	//void getRecruitList();
	//void addRecruitInfo();
	//bool isCompanyNameSame();
	~CompanyMember();
};