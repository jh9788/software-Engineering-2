#pragma once
#include <string>
using namespace std;

/*
Ŭ���� �̸� : RecruitInfo
��� : RecruitInfo�� �����Ѵ�.
	   work, deadline, targetNum�� ���� �����´�.
*/
class RecruitInfo
{
private:
	string work; //����
	string deadline; //������
	string targetNum; //�ο� ��
	string companyId; //ä�� ������ ����� ȸ��ȸ�� ID

public:
	RecruitInfo(string inputWork, string inputDeadline, string inputTargetNum, string inputNowLogin);
	string getWork();
	string getDeadline();
	string getTargetNum();
	string getCompanyId();
	void showRecruitInfo();		/* ���� �� ������ �Լ� !! */
};
