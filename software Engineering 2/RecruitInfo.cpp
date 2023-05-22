#include <iostream>
#include <string>
#include "RecruitInfo.h"

/*
�Լ� �̸�: RecruitInfo
���: ������
�Ű�����: string inputWork -> ����, string inputDeadline -> ��û ������, string inputTargetNum -> �ο� ��
��ȯ��: X
*/
RecruitInfo::RecruitInfo(string inputWork, string inputTargetNum, string inputDeadline, string inputCompanyId)
{
	work = inputWork;
	targetNum = inputTargetNum;
	deadline = inputDeadline;
	companyId = inputCompanyId;
	
	//cout << "inputWork : " << inputWork << ", work : " << work << endl;
	//cout << "inputTargetNum : " << inputTargetNum << ", targetNum : " << targetNum << endl;
	//cout << "inputDeadline : " << inputDeadline << ", deadline : " << deadline << endl;
	//cout << "inputNowLogin : " << inputNowLogin << ", nowLogin : " << nowLogin << endl;
}



/*
�Լ� �̸�: getWork
���: ���� ��ȯ
�Ű�����: X
��ȯ��: string
*/
string RecruitInfo::getWork() {
	return work;
}


/*
�Լ� �̸�: getId
���: ��û ������ ��ȯ
�Ű�����: X
��ȯ��: string
*/
string RecruitInfo::getDeadline() {
	return deadline;
}


/*
�Լ� �̸�: getTargetNum
���: �ο� �� ��ȯ
�Ű�����: X
��ȯ��: string
*/
string RecruitInfo::getTargetNum() {
	return targetNum;
}


/*
�Լ� �̸�: getCompanyId
���: Company ID ��ȯ
�Ű�����: X
��ȯ��: string
*/
string RecruitInfo::getCompanyId() {
	return companyId;
}


/* ���� �� ������ �Լ�!! */
void RecruitInfo::showRecruitInfo()
{
	cout << "����: " << getWork() << ", �ο� ��: " << getTargetNum() << ", ��û ������: " << getDeadline() << endl;
}