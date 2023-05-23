#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CancelApplication;

// 등록한 채용 정보 조회 UI
class CancelApplicationUI {
private:
	CancelApplication* control;
	ofstream* fout;
public:
	CancelApplicationUI(CancelApplication* inputControl);		// 생성자
	void init(ofstream* inputFout);									// 파일 입출력을 위한 함수

	void startInterface();		// 인터페이스 시작
	void showCancelApplication(string currentLoginId, string inputEvent);		
};