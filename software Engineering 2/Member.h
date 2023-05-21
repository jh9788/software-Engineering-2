#pragma once
using namespace std;

/*
클래스 이름 : Member
기능 : Member를 생성한다.
	   Name, Id, Password, MemberType의 값을 가져온다.
*/
class Member
{
private:
	char* name;
	char* id;
	char* password;
	int memberType;

public:
	Member(const char* inputName, const char* inputId, const char* inputPassword, int inputMemberType);
	char* getName();
	char* getId();
	char* getPassword();
	int getMemberType();
	virtual void showMemberInfo() = 0;	/* 제출 시 삭제할 함수 !! 현재 등록된 모든 회원 조회 */
	//bool isIdPwdSame();
	//void deleteMember();	// 필요 없는듯? 어차피 MemberCollection에서 해당 개체 지우면 되니까!
};
