#pragma once
#include "RecruitInfo.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

/*
클래스 이름 : RecruitInfoCollection
기능 : 채용 정보 리스트에 대한 아래 기능을 구현함
	   채용 정보 등록 및 조회를 진행한다.
*/
class RecruitInfoCollection
{
private:
	vector <RecruitInfo*> ownedRecruitInfo;

public:
	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);	// 채용 정보 등록 시, 새로운 채용 정보를 recruitInfoCollection에 추가
	string getRecruitInfo(string currentLoginId); // 로그인 한 사람이 등록한 모든 채용 정보를 담아 반환
	string getRecruitInfoWithoutSign(string currentLoginId); // ">" 기호를 빼고 채용 정보를 반환
	RecruitInfo* findByCompanyId(string companyId);
	RecruitInfo* findRecruitInfoById(string companyId);
	string findWorkById(string companyId);

	//control -> 2.1.1 -> recruitinfo collection
	map<string, int> calcAddedRecruitInfoStats(string currentLoginId);

	~RecruitInfoCollection();	// 소멸자
};