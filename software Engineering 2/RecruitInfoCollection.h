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

	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);	// ä�� ���� ��� ��, ���ο� ä�� ������ ���Ϳ� �߰�
	int getRecruitInfoCollectionSize();	// recruitInfoCollection�� ������ size�� ��ȯ
	bool isMemberInRecruitInfoCollection(string companyId);		// ȸ�� ȸ���� �ø� �Խù��� recruitInfoCollectin �ȿ� �ִ��� Ȯ��
	string getRecruitAllInfo(int index); // Ư�� ä�� ������ ����, ��� �� ��������

	~RecruitInfoCollection();	// �Ҹ���
};