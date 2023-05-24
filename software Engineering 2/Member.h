#pragma once
#include <string>
using namespace std;

/*
클래스 이름 : Member
기능 : Member를 생성한다.
	   Name, Id, Password, MemberType의 값을 가져온다.
*/
class Member
{
private:
	string name;
	string id;
	string password;
	int memberType;

public:
	Member(string inputName, string inputId, string inputPassword, int inputMemberType);
	string getName();	
	string getId();
	string getPassword();
	
	int getMemberType();

	virtual string getBusinessNum();
};
