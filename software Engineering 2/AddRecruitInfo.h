#pragma once
#include <string>
// ä�� ���� �߰� Control
class AddRecruitInfo {
private:
public:
	void addRecruitInfo(RecruitInfoCollection& recruitInfoCollection,
		const char* work, const char* targetNum, const char* deadline, const char* nowLogin);
};