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

	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);	// 채용 정보 등록 시, 새로운 채용 정보를 벡터에 추가
	int getRecruitInfoCollectionSize();	// recruitInfoCollection의 벡터의 size를 반환
	bool isMemberInRecruitInfoCollection(string companyId);		// 회사 회원이 올린 게시물이 recruitInfoCollectin 안에 있는지 확인
	string getRecruitAllInfo(int index); // 특정 채용 정보에 대해, 모든 값 가져오기

	~RecruitInfoCollection();	// 소멸자
};