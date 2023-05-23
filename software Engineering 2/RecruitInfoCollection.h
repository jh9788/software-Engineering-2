#pragma once
#include "RecruitInfo.h"
#include <vector>
#include <string>

using namespace std;

/*
클래스 이름 : RecruitInfoCollection
기능 : 채용 정보 리스트에 대한 아래 기능을 구현함
	   채용 정보 등록 및 조회를 진행한다.
*/
class RecruitInfoCollection
{
private:
	vector <RecruitInfo*> recruitInfoCollection;

public:
	void getAllRecruitInfoCollection(); /* 제출 시 삭제할 함수 !! */ // 현재 등록된 회원 목록 모두 조회

	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);	// 채용 정보 등록 시, 새로운 채용 정보를 recruitInfoCollection에 추가
	string getRecruitInfo(string currentLoginId); // 로그인 한 사람이 등록한 모든 채용 정보를 담아 반환
	string getRecruitInfoWithoutSign(string currentLoginId); // ">" 기호를 빼고 채용 정보를 반환
	~RecruitInfoCollection();	// 소멸자
};