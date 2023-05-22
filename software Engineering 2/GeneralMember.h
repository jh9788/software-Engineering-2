#pragma once
#include "Member.h"
//#include "RecruitInfoCollection.h"

using namespace std;

/*
Ŭ���� �̸� : GeneralMember
��� : GeneralMember�� �����Ѵ�.
	   socialSecurityNum�� �������� �Լ��� ȣ���Ѵ�.
*/
class GeneralMember : public Member
{
private:

	string socialSecurityNum;
	//RecruitInfoCollection applicationInfoList;

public:

	GeneralMember(string inputName, string inputSocialSecurityNum, string inputId, string inputPassword, int inputMemberType);
	string getSocialSecurityNum();	// socialSecurityNum ���� �����´�.
	virtual void showMemberInfo();	/* ���� �� ������ �Լ�!! */
	//int getApplicationCountByWork();
	//void addApplicationInfo();
	//void getApplicationInfoList();
	//void cancelSelectedApplicationInfo();
	~GeneralMember();
};