#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"

using namespace std;

class CancelApplicationUI;

// 등록한 채용 정보 조회 Control
class CancelApplication {
private:
	CancelApplicationUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
public:
	CancelApplication(ApplicationInfoCollection* inputApplicationInfoCollection);	// 생성자
	CancelApplicationUI* getCancelApplicationUI();	// Boundary를 호출하기 위한 함수

	string viewCancelApplication(string currentLoginId, string inputBusinessNum);		// 등록된 채용 정보를 모두 확인하는 함수
};