#include <iostream>
#include <cstring>
#include "CompanyMember.h"

/*
함수 이름: CompanyMember
기능: CompanyMember 클래스의 생성자로 기능한다.
매개변수: const char* inputName -> 이름, const char* inputBusinessNum -> 사업자번호, const char* inputId -> ID,
		  const char* inputPassword -> 비밀번호, int inputMemberType -> 멤버 타입
반환값: X
*/
CompanyMember::CompanyMember(const char* inputName, const char* inputBusinessNum, const char* inputId, const char* inputPassword, int inputMemberType)
			   : Member(inputName, inputId, inputPassword, inputMemberType)
{
	int len = strlen(inputBusinessNum) + 1;			// 새로 만들 문자열을 위한 길이 구하기
	businessNum = new char[len];					// 새로 만들 문자열을 위한 배열 공간 확보하기
	strcpy_s(businessNum, len, inputBusinessNum);	// 문자열 복사해서 넣기

	//cout << "inputBusinessNum : " << inputBusinessNum << ", businessNum : " << businessNum << endl;
}



/*
함수 이름: getBusinessNum
기능: businessNum 값을 가져온다.
매개변수: X
반환값: char*
*/
char* CompanyMember::getBusinessNum() {
	return businessNum;
}



/* 제출 시 삭제할 함수!! */
void CompanyMember::showMemberInfo()
{
	cout << "이름: " << getName() << ", SSN: " << getBusinessNum() << ", ID: " << getId() << ", PWD: " << getPassword() << ", MemberType: " << getMemberType() << endl;
}


/*
함수 이름: ~CompanyMember
기능: 소멸자
매개변수: X
반환값: X
*/
CompanyMember::~CompanyMember() {

}