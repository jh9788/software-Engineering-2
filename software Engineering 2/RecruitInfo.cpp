#include <iostream>
#include <string>
#include "RecruitInfo.h"

/*
함수 이름: RecruitInfo
기능: 생성자
매개변수: const char* inputWork -> 업무, const char* inputDeadline -> 신청 마감일, const char* inputTargetNum -> 인원 수
반환값: X
*/
RecruitInfo::RecruitInfo(const char* inputWork, const char* inputDeadline, const char* inputTargetNum, const char* inputNowLogin)
{
	int workLen = strlen(inputWork) + 1;	// 새로 만들 문자열을 위한 길이 구하기
	work = new char[workLen];				// 새로 만들 문자열을 위한 배열 공간 확보하기
	strcpy_s(work, workLen, inputWork);		// 문자열 복사해서 넣기

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
함수 이름: getWork
기능: 업무 반환
매개변수: X
반환값: char*
*/
char* RecruitInfo::getWork() {
	return work;
}


/*
함수 이름: getId
기능: 신청 마감일 반환
매개변수: X
반환값: char*
*/
char* RecruitInfo::getDeadline() {
	return deadline;
}


/*
함수 이름: getTargetNum
기능: 인원 수 반환
매개변수: X
반환값: char*
*/
char* RecruitInfo::getTargetNum() {
	return targetNum;
}


/*
함수 이름: getTargetNum
기능: 인원 수 반환
매개변수: X
반환값: char*
*/
char* RecruitInfo::getNowLogin() {
	return nowLogin;
}


/* 제출 시 삭제할 함수!! */
void RecruitInfo::showRecruitInfo()
{
	cout << "업무: " << getWork() << ", 인원 수: " << getTargetNum() << ", 신청 마감일: " << getDeadline() << endl;
}