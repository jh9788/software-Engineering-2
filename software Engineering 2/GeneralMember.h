#pragma once
#include "Member.h"
//#include "RecruitInfoCollection.h"

using namespace std;

/*
클래스 이름 : GeneralMember
기능 : GeneralMember를 생성한다.
	   socialSecurityNum을 가져오는 함수를 호출한다.
*/
class GeneralMember : public Member
{
private:

	char* socialSecurityNum;
	//RecruitInfoCollection applicationInfoList;

public:

	GeneralMember(const char* inputName, const char* inputSocialSecurityNum, const char* inputId, const char* inputPassword, int inputMemberType);
	char* getSocialSecurityNum();	// socialSecurityNum 값을 가져온다.
	virtual void showMemberInfo();	/* 제출 시 삭제할 함수!! */
	//int getApplicationCountByWork();
	//void addApplicationInfo();
	//void getApplicationInfoList();
	//void cancelSelectedApplicationInfo();
	~GeneralMember();
};