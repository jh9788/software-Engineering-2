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

	int getRecruitInfoCollectionSize();	// recruitInfoCollection�� ������ size�� ��ȯ
	bool isMemberInRecruitInfoCollection(const char* nowLogin);		// ȸ�� ȸ���� �ø� �Խù��� recruitInfoCollectin �ȿ� �ִ��� Ȯ��
	void addRecruitInfo(RecruitInfo* recruitInfo);	// ä�� ���� ��� ��, ���ο� ä�� ������ ���Ϳ� �߰�
	string getRecruitAllInfo(int index); // Ư�� ä�� ������ ����, ��� �� ��������

	~RecruitInfoCollection();	// �Ҹ���
};