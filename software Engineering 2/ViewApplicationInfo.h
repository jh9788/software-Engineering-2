#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"

using namespace std;

class ViewApplicationInfoUI;

// 등록한 채용 정보 조회 Control
class ViewApplicationInfo {
private:
	ViewApplicationInfoUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
public:
	ViewApplicationInfo(ApplicationInfoCollection* inputApplicationInfoCollection);	// 생성자
	ViewApplicationInfoUI* getViewApplicationInfoUI();	// Boundary를 호출하기 위한 함수

	string viewApplicationList(string currentLoginId);		// 등록된 채용 정보를 모두 확인하는 함수
};