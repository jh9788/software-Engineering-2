#include <iostream>
#include <cstring>
#include "CompanyMember.h"

/*
�Լ� �̸�: CompanyMember
���: CompanyMember Ŭ������ �����ڷ� ����Ѵ�.
�Ű�����: const char* inputName -> �̸�, const char* inputBusinessNum -> ����ڹ�ȣ, const char* inputId -> ID,
		  const char* inputPassword -> ��й�ȣ, int inputMemberType -> ��� Ÿ��
��ȯ��: X
*/
CompanyMember::CompanyMember(const char* inputName, const char* inputBusinessNum, const char* inputId, const char* inputPassword, int inputMemberType)
			   : Member(inputName, inputId, inputPassword, inputMemberType)
{
	int len = strlen(inputBusinessNum) + 1;			// ���� ���� ���ڿ��� ���� ���� ���ϱ�
	businessNum = new char[len];					// ���� ���� ���ڿ��� ���� �迭 ���� Ȯ���ϱ�
	strcpy_s(businessNum, len, inputBusinessNum);	// ���ڿ� �����ؼ� �ֱ�

	//cout << "inputBusinessNum : " << inputBusinessNum << ", businessNum : " << businessNum << endl;
}



/*
�Լ� �̸�: getBusinessNum
���: businessNum ���� �����´�.
�Ű�����: X
��ȯ��: char*
*/
char* CompanyMember::getBusinessNum() {
	return businessNum;
}



/* ���� �� ������ �Լ�!! */
void CompanyMember::showMemberInfo()
{
	cout << "�̸�: " << getName() << ", SSN: " << getBusinessNum() << ", ID: " << getId() << ", PWD: " << getPassword() << ", MemberType: " << getMemberType() << endl;
}


/*
�Լ� �̸�: ~CompanyMember
���: �Ҹ���
�Ű�����: X
��ȯ��: X
*/
CompanyMember::~CompanyMember() {

}