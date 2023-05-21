#pragma once
using namespace std;

/*
Ŭ���� �̸� : RecruitInfo
��� : RecruitInfo�� �����Ѵ�.
	   work, deadline, targetNum�� ���� �����´�.
*/
class RecruitInfo
{
private:
	char* work;
	char* deadline;
	char* targetNum;
	char* nowLogin;

public:
	RecruitInfo(const char* inputWork, const char* inputDeadline, const char* inputTargetNum, const char* inputNowLogin);
	char* getWork();
	char* getDeadline();
	char* getTargetNum();
	char* getNowLogin();
	void showRecruitInfo();		/* ���� �� ������ �Լ� !! */
};
