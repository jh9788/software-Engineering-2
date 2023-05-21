#pragma once
#include <string>
// 채용 정보 추가 Control
class AddRecruitInfo {
private:
public:
	void addRecruitInfo(RecruitInfoCollection& recruitInfoCollection,
		const char* work, const char* targetNum, const char* deadline, const char* nowLogin);
};