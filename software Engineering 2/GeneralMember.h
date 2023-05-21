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

	char* socialSecurityNum;
	//RecruitInfoCollection applicationInfoList;

public:

	GeneralMember(const char* inputName, const char* inputSocialSecurityNum, const char* inputId, const char* inputPassword, int inputMemberType);
	char* getSocialSecurityNum();	// socialSecurityNum ���� �����´�.
	virtual void showMemberInfo();	/* ���� �� ������ �Լ�!! */
	//int getApplicationCountByWork();
	//void addApplicationInfo();
	//void getApplicationInfoList();
	//void cancelSelectedApplicationInfo();
	~GeneralMember();
};