#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class AddRecruitInfo;
 //채용 정보 추가 UI
class AddRecruitInfoUI {
private:
	AddRecruitInfo* control;
	ofstream* fout;
public:
	AddRecruitInfoUI(AddRecruitInfo* inputControl);
	void init(ofstream* inputFout);

	void startInterface();		// 인터페이스 시작
	void requestRecruitInfo(string inputEvent, string currentLoginId);		// recruitInfoCollection에 recruitInfo를 추가하는 함수 호출
	void showAddedRecruitInfo(string inputEvent);		// 추가가 완료되면 파일에 기록
};