#include <iostream>
#include "GeneralMember.h"

/*
�Լ� �̸�: GeneralMember
���: GeneralMember Ŭ������ �����ڷ� ����Ѵ�.
�Ű�����: const char* inputName -> �̸�, const char* inputSocialSecurityNum -> �ֹι�ȣ, const char* inputId -> ID,
		  const char* inputPassword -> ��й�ȣ, int inputMemberType -> ��� Ÿ��
��ȯ��: X
*/
GeneralMember::GeneralMember(const char* inputName, const char* inputSocialSecurityNum, const char* inputId, const char* inputPassword, int inputMemberType)
			   : Member(inputName, inputId, inputPassword, inputMemberType)
{
	int len = strlen(inputSocialSecurityNum) + 1;				// ���� ���� ���ڿ��� ���� ���� ���ϱ�
	socialSecurityNum = new char[len];							// ���� ���� ���ڿ��� ���� �迭 ���� Ȯ���ϱ�
	strcpy_s(socialSecurityNum, len, inputSocialSecurityNum);	// ���ڿ� �����ؼ� �ֱ�

	//cout << "inputSocialSecurityNum : " << inputSocialSecurityNum << ", socialSecurityNum : " << socialSecurityNum << endl;
}


/*
�Լ� �̸�: getSocialSecurityNum
���: socialSecurityNum ���� �����´�.
�Ű�����: X
��ȯ��: char*
*/
char* GeneralMember::getSocialSecurityNum() {
	return socialSecurityNum;
}


/* ���� �� ������ �Լ�!! */
void GeneralMember::showMemberInfo()
{
	cout << "�̸�: " << getName() << ", SSN: " << getSocialSecurityNum() << ", ID: " << getId() << ", PWD: " << getPassword() << ", MemberType: " << getMemberType() << endl;
}


/*
�Լ� �̸�: ~GeneralMember
���: �Ҹ���
�Ű�����: X
��ȯ��: X
*/
GeneralMember::~GeneralMember() {

}