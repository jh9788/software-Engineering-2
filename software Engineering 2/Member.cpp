#include <iostream>
#include <string>
#include "Member.h"

/*
함수 이름: Member
기능: 생성자
매개변수: const char* inputName -> 회원명, const char* inputId -> 회원ID, const char* inputPassword -> 회원Password,
		  int inputMemberType -> 회원 Type
반환값: X
*/
Member::Member(const char* inputName, const char* inputId, const char* inputPassword, int inputMemberType)
{
	int nameLen = strlen(inputName) + 1;	// 새로 만들 문자열을 위한 길이 구하기
	name = new char[nameLen];				// 새로 만들 문자열을 위한 배열 공간 확보하기
	strcpy_s(name, nameLen, inputName);		// 문자열 복사해서 넣기

	int idLen = strlen(inputId) + 1;
	id = new char[idLen];
	strcpy_s(id, idLen, inputId);

	int passwordLen = strlen(inputPassword) + 1;
	password = new char[passwordLen];
	strcpy_s(password, passwordLen, inputPassword);

	memberType = inputMemberType;		// 멤버 타입은 int type 이므로 그대로 넣기

	//cout << "inpntName : " << inputName << ", name : " << name << endl;
	//cout << "inpntId : " << inputId << ", id : " << id << endl;
	//cout << "inpntPassword : " << inputPassword << ", password : " << password << endl;
	//cout << "inputMemberType : " << inputMemberType << ", memberType : " << memberType << endl;
}



/*
함수 이름: getName
기능: 회원 이름 반환
매개변수: X
반환값: char*
*/
char* Member::getName() {
	return name;
}


/*
함수 이름: getId
기능: 회원 ID 반환
매개변수: X
반환값: char*
*/
char* Member::getId() {
	return id;
}


/*
함수 이름: getPassword
기능: 회원 Password 반환
매개변수: X
반환값: char*
*/
char* Member::getPassword() {
	return password;
}


/*
함수 이름: getMemberType
기능: 회원 Member Type 반환
매개변수: X
반환값: int
*/
int Member::getMemberType() {
	return memberType;
}

/*
함수 이름: isIdPwdSame
기능: 멤버변수 driverAge의 값을 1 증가시킨다.
매개변수:
반환값:

작성날짜: 2021/03/31

*/
//bool Member::isIdPwdSame();
//{
//	driverAge++;
//}



/*
함수 이름: deleteMember
기능: 멤버변수 driverExp의 값을 3 증가시킨다.
매개변수:
반환값:

작성날짜: 2021/03/31

*/
//void Member::deleteMember()
//{
//
//}

