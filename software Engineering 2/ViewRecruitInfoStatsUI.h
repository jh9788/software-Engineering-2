#pragma once
#include <fstream>
#include<map>
#include <string>
using namespace std;

class ViewRecruitInfoStats;
class ViewRecruitInfoStatsUI
{
private:
	ViewRecruitInfoStats* control;
	ofstream* fout;

	void _showRecruitInfoStatsInterface(map<string, int> recruitInfoStats);

public:
	ViewRecruitInfoStatsUI(ViewRecruitInfoStats* inputControl);
	void init(ofstream* inputFout);

	//control -> 1 -> boundary
	void startInterface(); //인터페이스 시작
	
	//actor -> 2 [currentMemberType == 1] -> boundary
	void requestAddedRecruitInfoStats(string currentLoginId); //회사회원의 등록한 채용 정보 통계 요청 
	//actor -> 3 [currentMemberType == 2] -> boundary
	void requestAppliedRecruitInfoStats(string currentLoginId); //일반회원의 지원한 채용 정보 통계 요청
};

