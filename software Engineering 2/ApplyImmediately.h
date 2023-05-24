#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"
#include "RecruitInfoCollection.h"
#include "MemberCollection.h"

using namespace std;

class ApplyImmediatelyUI;

/*
Ŭ���� �̸� : ApplyImmediately
��� : ä�� ���� Control
*/
class ApplyImmediately
{
private:
	ApplyImmediatelyUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
	RecruitInfoCollection* recruitInfoCollection;
	MemberCollection* memberCollection;
public:
	ApplyImmediately(ApplicationInfoCollection* inputApplicationInfoCollection,
					 RecruitInfoCollection* inputRecruitInfoCollection,MemberCollection* inputMemberCollection); // ������

	ApplyImmediatelyUI* getApplyImmediatelyUI(); // Boundary�� ȣ���ϱ� ���� �Լ�

	string applyImmediately(string businessNum, string currentLoginId); // ä�� ������ �Ϸ��ϱ� ���� �Լ�
};

