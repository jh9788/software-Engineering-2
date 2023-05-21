#pragma once
using namespace std;

/*
클래스 이름 : RecruitInfo
기능 : RecruitInfo를 생성한다.
	   work, deadline, targetNum의 값을 가져온다.
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
	void showRecruitInfo();		/* 제출 시 삭제할 함수 !! */
};
