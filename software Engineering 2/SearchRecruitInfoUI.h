#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "RecruitInfoCollection.h"

using namespace std;

class SearchRecruitInfo;

// 채용 정보 검색 UI
class SearchRecruitInfoUI {
private:
	SearchRecruitInfo* control;
	ofstream* fout;
public:
	SearchRecruitInfoUI(SearchRecruitInfo* inputControl); // 생성자
	void init(ofstream* inputFout); //파일 입출력을 위한 함수

	void startInterface(); // 인터페이스 시작
	void showSearchRecruitInfo(string inputEvent); // 채용 정보 검색을 recruitInfoCollection 
};