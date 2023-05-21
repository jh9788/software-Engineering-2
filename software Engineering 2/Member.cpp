#include <iostream>
#include <string>
#include "Member.h"

/*
�Լ� �̸�: Member
���: ������
�Ű�����: const char* inputName -> ȸ����, const char* inputId -> ȸ��ID, const char* inputPassword -> ȸ��Password,
		  int inputMemberType -> ȸ�� Type
��ȯ��: X
*/
Member::Member(const char* inputName, const char* inputId, const char* inputPassword, int inputMemberType)
{
	int nameLen = strlen(inputName) + 1;	// ���� ���� ���ڿ��� ���� ���� ���ϱ�
	name = new char[nameLen];				// ���� ���� ���ڿ��� ���� �迭 ���� Ȯ���ϱ�
	strcpy_s(name, nameLen, inputName);		// ���ڿ� �����ؼ� �ֱ�

	int idLen = strlen(inputId) + 1;
	id = new char[idLen];
	strcpy_s(id, idLen, inputId);

	int passwordLen = strlen(inputPassword) + 1;
	password = new char[passwordLen];
	strcpy_s(password, passwordLen, inputPassword);

	memberType = inputMemberType;		// ��� Ÿ���� int type �̹Ƿ� �״�� �ֱ�

	//cout << "inpntName : " << inputName << ", name : " << name << endl;
	//cout << "inpntId : " << inputId << ", id : " << id << endl;
	//cout << "inpntPassword : " << inputPassword << ", password : " << password << endl;
	//cout << "inputMemberType : " << inputMemberType << ", memberType : " << memberType << endl;
}



/*
�Լ� �̸�: getName
���: ȸ�� �̸� ��ȯ
�Ű�����: X
��ȯ��: char*
*/
char* Member::getName() {
	return name;
}


/*
�Լ� �̸�: getId
���: ȸ�� ID ��ȯ
�Ű�����: X
��ȯ��: char*
*/
char* Member::getId() {
	return id;
}


/*
�Լ� �̸�: getPassword
���: ȸ�� Password ��ȯ
�Ű�����: X
��ȯ��: char*
*/
char* Member::getPassword() {
	return password;
}


/*
�Լ� �̸�: getMemberType
���: ȸ�� Member Type ��ȯ
�Ű�����: X
��ȯ��: int
*/
int Member::getMemberType() {
	return memberType;
}

/*
�Լ� �̸�: isIdPwdSame
���: ������� driverAge�� ���� 1 ������Ų��.
�Ű�����:
��ȯ��:

�ۼ���¥: 2021/03/31

*/
//bool Member::isIdPwdSame();
//{
//	driverAge++;
//}



/*
�Լ� �̸�: deleteMember
���: ������� driverExp�� ���� 3 ������Ų��.
�Ű�����:
��ȯ��:

�ۼ���¥: 2021/03/31

*/
//void Member::deleteMember()
//{
//
//}

