#pragma once
#include <string>
using namespace std;

/*
Ŭ���� �̸� : Member
��� : Member�� �����Ѵ�.
	   Name, Id, Password, MemberType�� ���� �����´�.
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
