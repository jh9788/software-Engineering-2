#include <iostream>
#include <string>
#include "CompanyMember.h"

/*
�Լ� �̸�: CompanyMember
���: CompanyMember Ŭ������ �����ڷ� ����Ѵ�.
�Ű�����: string inputName -> �̸�, string inputBusinessNum -> ����ڹ�ȣ, string inputId -> ID,
		 string inputPassword -> ��й�ȣ, int inputMemberType -> ��� Ÿ��
��ȯ��: X
*/
CompanyMember::CompanyMember(string inputName, string inputBusinessNum, string inputId, string inputPassword, int inputMemberType)
			   : Member(inputName, inputId, inputPassword, inputMemberType)
{
	businessNum = inputBusinessNum;	// ���ڿ� �����ؼ� �ֱ�

	//cout << "inputBusinessNum : " << inputBusinessNum << ", businessNum : " << businessNum << endl;
}



/*
�Լ� �̸�: getBusinessNum
���: businessNum ���� �����´�.
�Ű�����: X
��ȯ��: string
*/
string CompanyMember::getBusinessNum() {
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