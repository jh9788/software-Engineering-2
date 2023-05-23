#pragma once
#include "RecruitInfo.h"
#include <vector>
#include <string>

using namespace std;

/*
Ŭ���� �̸� : RecruitInfoCollection
��� : ä�� ���� ����Ʈ�� ���� �Ʒ� ����� ������
	   ä�� ���� ��� �� ��ȸ�� �����Ѵ�.
*/
class RecruitInfoCollection
{
private:
	vector <RecruitInfo*> recruitInfoCollection;

public:
	void getAllRecruitInfoCollection(); /* ���� �� ������ �Լ� !! */ // ���� ��ϵ� ȸ�� ��� ��� ��ȸ

	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);	// ä�� ���� ��� ��, ���ο� ä�� ������ recruitInfoCollection�� �߰�
	string getRecruitInfo(string currentLoginId); // �α��� �� ����� ����� ��� ä�� ������ ��� ��ȯ
	string getRecruitInfoWithoutSign(string currentLoginId); // ">" ��ȣ�� ���� ä�� ������ ��ȯ
	~RecruitInfoCollection();	// �Ҹ���
};