#pragma once
#include <string>
using namespace std;

/*
클래스 이름 : RecruitInfo
기능 : RecruitInfo를 생성한다.
	   work, deadline, targetNum의 값을 가져온다.
*/
class RecruitInfo
{
private:
	string work; //업무
	string deadline; //마감일
	string targetNum; //인원 수
	string companyId; //채용 정보를 등록한 회사회원 ID

public:
	RecruitInfo(string inputWork, string inputDeadline, string inputTargetNum, string inputNowLogin);
	string getWork();
	string getDeadline();
	string getTargetNum();
	string getCompanyId();
	void showRecruitInfo();		/* 제출 시 삭제할 함수 !! */
};
