#pragma once
#include <iostream>
#include <string>
#include "RecruitInfoCollection.h"

using namespace std;

class AddRecruitInfoUI;

 //채용 정보 추가 Control
class AddRecruitInfo {
private:
	AddRecruitInfoUI* boundary;
	RecruitInfoCollection* recruitInfoCollection;

public:
	AddRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection);
	AddRecruitInfoUI* getAddRecruitInfoUI();

	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);
};