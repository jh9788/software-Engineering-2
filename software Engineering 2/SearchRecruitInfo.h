#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "RecruitInfoCollection.h"
#include "MemberCollection.h"

using namespace std;

class SearchRecruitInfoUI;

/*
Ŭ���� �̸� : SearchRecruitInfo
��� : ä�� ���� �˻� Control
*/
class SearchRecruitInfo {
private:
	SearchRecruitInfoUI* boundary;
	RecruitInfoCollection* recruitInfoCollection;
	MemberCollection* memberCollection;
public:
	SearchRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection, MemberCollection* inputMemberCollection); // ������
	SearchRecruitInfoUI* getSearchRecruitInfoUI(); // Boundary�� ȣ���ϱ� ���� �Լ�

	string searchRecruitInfo(string name); // ä�� ���� �˻��� ���� �Լ�
	
};