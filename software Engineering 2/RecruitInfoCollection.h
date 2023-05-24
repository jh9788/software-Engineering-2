#pragma once
#include "RecruitInfo.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

/*
Ŭ���� �̸� : RecruitInfoCollection
��� : ä�� ���� ����Ʈ�� ���� �Ʒ� ����� ������
	   ä�� ���� ��� �� ��ȸ�� �����Ѵ�.
*/
class RecruitInfoCollection
{
private:
	vector <RecruitInfo*> ownedRecruitInfo;

public:
	void getAllRecruitInfoCollection(); /* ���� �� ������ �Լ� !! */ // ���� ��ϵ� ȸ�� ��� ��� ��ȸ
	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);	// ä�� ���� ��� ��, ���ο� ä�� ������ recruitInfoCollection�� �߰�
	string getRecruitInfo(string currentLoginId); // �α��� �� ����� ����� ��� ä�� ������ ��� ��ȯ
	string getRecruitInfoWithoutSign(string currentLoginId); // ">" ��ȣ�� ���� ä�� ������ ��ȯ
	RecruitInfo* findByCompanyId(string companyId);
	RecruitInfo* findRecruitInfoById(string companyId);
	string findWorkById(string companyId);
	~RecruitInfoCollection();	// �Ҹ���
};