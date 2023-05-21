#include <iostream>
#include <string>
#include "GeneralMember.h"

/*
함수 이름: GeneralMember
기능: GeneralMember 클래스의 생성자로 기능한다.
매개변수: string inputName -> 이름, string inputSocialSecurityNum -> 주민번호, string inputId -> ID,
		  string inputPassword -> 비밀번호, int inputMemberType -> 멤버 타입
반환값: X
*/
GeneralMember::GeneralMember(string inputName, string inputSocialSecurityNum, string inputId, string inputPassword, int inputMemberType)
			   : Member(inputName, inputId, inputPassword, inputMemberType)
{
	socialSecurityNum = inputSocialSecurityNum;	// 문자열 복사해서 넣기

	//cout << "inputSocialSecurityNum : " << inputSocialSecurityNum << ", socialSecurityNum : " << socialSecurityNum << endl;
}


/*
함수 이름: getSocialSecurityNum
기능: socialSecurityNum 값을 가져온다.
매개변수: X
반환값: string
*/
string GeneralMember::getSocialSecurityNum() {
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