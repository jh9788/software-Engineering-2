#include <iostream>
#include <string>
#include "GeneralMember.h"

/*
�Լ� �̸�: GeneralMember
���: GeneralMember Ŭ������ �����ڷ� ����Ѵ�.
�Ű�����: string inputName -> �̸�, string inputSocialSecurityNum -> �ֹι�ȣ, string inputId -> ID,
		  string inputPassword -> ��й�ȣ, int inputMemberType -> ��� Ÿ��
��ȯ��: X
*/
GeneralMember::GeneralMember(string inputName, string inputSocialSecurityNum, string inputId, string inputPassword, int inputMemberType)
			   : Member(inputName, inputId, inputPassword, inputMemberType)
{
	socialSecurityNum = inputSocialSecurityNum;	// ���ڿ� �����ؼ� �ֱ�

	//cout << "inputSocialSecurityNum : " << inputSocialSecurityNum << ", socialSecurityNum : " << socialSecurityNum << endl;
}


/*
�Լ� �̸�: getSocialSecurityNum
���: socialSecurityNum ���� �����´�.
�Ű�����: X
��ȯ��: string
*/
string GeneralMember::getSocialSecurityNum() {
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