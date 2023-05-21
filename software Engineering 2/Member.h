#pragma once
using namespace std;

/*
Ŭ���� �̸� : Member
��� : Member�� �����Ѵ�.
	   Name, Id, Password, MemberType�� ���� �����´�.
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
	virtual void showMemberInfo() = 0;	/* ���� �� ������ �Լ� !! ���� ��ϵ� ��� ȸ�� ��ȸ */
	//bool isIdPwdSame();
	//void deleteMember();	// �ʿ� ���µ�? ������ MemberCollection���� �ش� ��ü ����� �Ǵϱ�!
};
