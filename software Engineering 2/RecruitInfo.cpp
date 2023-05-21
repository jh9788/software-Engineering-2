#include <iostream>
#include <string>
#include "RecruitInfo.h"

/*
�Լ� �̸�: RecruitInfo
���: ������
�Ű�����: const char* inputWork -> ����, const char* inputDeadline -> ��û ������, const char* inputTargetNum -> �ο� ��
��ȯ��: X
*/
RecruitInfo::RecruitInfo(const char* inputWork, const char* inputDeadline, const char* inputTargetNum, const char* inputNowLogin)
{
	int workLen = strlen(inputWork) + 1;	// ���� ���� ���ڿ��� ���� ���� ���ϱ�
	work = new char[workLen];				// ���� ���� ���ڿ��� ���� �迭 ���� Ȯ���ϱ�
	strcpy_s(work, workLen, inputWork);		// ���ڿ� �����ؼ� �ֱ�

	int deadlineLen = strlen(inputDeadline) + 1;
	deadline = new char[deadlineLen];
	strcpy_s(deadline, deadlineLen, inputDeadline);

	int targetNumLen = strlen(inputTargetNum) + 1;
	targetNum = new char[targetNumLen];
	strcpy_s(targetNum, targetNumLen, inputTargetNum);

	int nowLoginLen = strlen(inputNowLogin) + 1;
	nowLogin = new char[nowLoginLen];
	strcpy_s(nowLogin, nowLoginLen, inputNowLogin);

	//cout << "inputWork : " << inputWork << ", work : " << work << endl;
	//cout << "inputDeadline : " << inputDeadline << ", deadline : " << deadline << endl;
	//cout << "inputTargetNum : " << inputTargetNum << ", targetNum : " << targetNum << endl;
	//cout << "inputNowLogin : " << inputNowLogin << ", nowLogin : " << nowLogin << endl;
}



/*
�Լ� �̸�: getWork
���: ���� ��ȯ
�Ű�����: X
��ȯ��: char*
*/
char* RecruitInfo::getWork() {
	return work;
}


/*
�Լ� �̸�: getId
���: ��û ������ ��ȯ
�Ű�����: X
��ȯ��: char*
*/
char* RecruitInfo::getDeadline() {
	return deadline;
}


/*
�Լ� �̸�: getTargetNum
���: �ο� �� ��ȯ
�Ű�����: X
��ȯ��: char*
*/
char* RecruitInfo::getTargetNum() {
	return targetNum;
}


/*
�Լ� �̸�: getTargetNum
���: �ο� �� ��ȯ
�Ű�����: X
��ȯ��: char*
*/
char* RecruitInfo::getNowLogin() {
	return nowLogin;
}


/* ���� �� ������ �Լ�!! */
void RecruitInfo::showRecruitInfo()
{
	cout << "����: " << getWork() << ", �ο� ��: " << getTargetNum() << ", ��û ������: " << getDeadline() << endl;
}