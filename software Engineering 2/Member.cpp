#include <iostream>
#include <string>
#include "Member.h"

/*
�Լ� �̸�: Member
���: ������
�Ű�����: const string inputName -> ȸ����, const string inputId -> ȸ��ID, const string inputPassword -> ȸ��Password,
		  int inputMemberType -> ȸ�� Type
��ȯ��: X
*/
Member::Member(string inputName, string inputId, string inputPassword, int inputMemberType)
{
	name = inputName;
	id = inputId;
	password = inputPassword;
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
string Member::getName() 
{
	return name;
}

/*
�Լ� �̸�: getId
���: ȸ�� ID ��ȯ
�Ű�����: X
��ȯ��: char*
*/
string Member::getId() 
{
	return id;
}

/*
�Լ� �̸�: getPassword
���: ȸ�� Password ��ȯ
�Ű�����: X
��ȯ��: char*
*/
string Member::getPassword() 
{
	return password;
}

/*
�Լ� �̸�: getMemberType
���: ȸ�� Member Type ��ȯ
�Ű�����: X
��ȯ��: int
*/
int Member::getMemberType() 
{
	return memberType;
}

/*
�Լ� �̸�: isIdPwdSame
���: 
�Ű�����:
��ȯ��:


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

string Member::getBusinessNum()
{
	return "";
}