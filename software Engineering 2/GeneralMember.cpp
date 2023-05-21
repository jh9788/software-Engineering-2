#include <iostream>
#include "GeneralMember.h"

/*
함수 이름: GeneralMember
기능: GeneralMember 클래스의 생성자로 기능한다.
매개변수: const char* inputName -> 이름, const char* inputSocialSecurityNum -> 주민번호, const char* inputId -> ID,
		  const char* inputPassword -> 비밀번호, int inputMemberType -> 멤버 타입
반환값: X
*/
GeneralMember::GeneralMember(const char* inputName, const char* inputSocialSecurityNum, const char* inputId, const char* inputPassword, int inputMemberType)
			   : Member(inputName, inputId, inputPassword, inputMemberType)
{
	int len = strlen(inputSocialSecurityNum) + 1;				// 새로 만들 문자열을 위한 길이 구하기
	socialSecurityNum = new char[len];							// 새로 만들 문자열을 위한 배열 공간 확보하기
	strcpy_s(socialSecurityNum, len, inputSocialSecurityNum);	// 문자열 복사해서 넣기

	//cout << "inputSocialSecurityNum : " << inputSocialSecurityNum << ", socialSecurityNum : " << socialSecurityNum << endl;
}


/*
함수 이름: getSocialSecurityNum
기능: socialSecurityNum 값을 가져온다.
매개변수: X
반환값: char*
*/
char* GeneralMember::getSocialSecurityNum() {
	return socialSecurityNum;
}


/* 제출 시 삭제할 함수!! */
void GeneralMember::showMemberInfo()
{
	cout << "이름: " << getName() << ", SSN: " << getSocialSecurityNum() << ", ID: " << getId() << ", PWD: " << getPassword() << ", MemberType: " << getMemberType() << endl;
}


/*
함수 이름: ~GeneralMember
기능: 소멸자
매개변수: X
반환값: X
*/
GeneralMember::~GeneralMember() {

}