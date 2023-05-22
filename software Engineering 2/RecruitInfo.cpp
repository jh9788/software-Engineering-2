#include <iostream>
#include <string>
#include "RecruitInfo.h"

/*
함수 이름: RecruitInfo
기능: 생성자
매개변수: string inputWork -> 업무, string inputDeadline -> 신청 마감일, string inputTargetNum -> 인원 수
반환값: X
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
함수 이름: getWork
기능: 업무 반환
매개변수: X
반환값: string
*/
string RecruitInfo::getWork() {
	return work;
}


/*
함수 이름: getId
기능: 신청 마감일 반환
매개변수: X
반환값: string
*/
string RecruitInfo::getDeadline() {
	return deadline;
}


/*
함수 이름: getTargetNum
기능: 인원 수 반환
매개변수: X
반환값: string
*/
string RecruitInfo::getTargetNum() {
	return targetNum;
}


/*
함수 이름: getCompanyId
기능: Company ID 반환
매개변수: X
반환값: string
*/
string RecruitInfo::getCompanyId() {
	return companyId;
}


/* 제출 시 삭제할 함수!! */
void RecruitInfo::showRecruitInfo()
{
	cout << "업무: " << getWork() << ", 인원 수: " << getTargetNum() << ", 신청 마감일: " << getDeadline() << endl;
}