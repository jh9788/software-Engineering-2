#include "ViewRecruitInfoStats.h"
#include "ViewRecruitInfoStatsUI.h"

/*
	�Լ� �̸� : ViewRecruitInfoStats
	���: ������
	�Ű�����: RecruitInfoCollection* inputRecruitInfoCollection -> ä�� ���� Collection Ŭ���� ���� ��
            ApplicationInfoCollection* inputApplicationInfoCollection -> ���� ���� Collection Ŭ���� ���� ��
	��ȯ��: X
*/
ViewRecruitInfoStats::ViewRecruitInfoStats(RecruitInfoCollection* inputRecruitInfoCollection, ApplicationInfoCollection* inputApplicationInfoCollection)
{
    ViewRecruitInfoStatsUI* boundary = new ViewRecruitInfoStatsUI(this); //Boundary Ŭ���� ����
    this->boundary = boundary; //Boundary Ŭ���� ���� �� ����

    recruitInfoCollection = inputRecruitInfoCollection;
    applicationInfoCollection = inputApplicationInfoCollection;
}

/*
	�Լ� �̸� : getViewRecruitInfoStatsUI
	���: ä�� ���� ��� Boundary Ŭ���� ��ȯ
	�Ű�����: X
	��ȯ��: ViewRecruitInfoStatsUI* -> ä�� ���� ��� Boundary Ŭ���� ���� ��
*/
ViewRecruitInfoStatsUI* ViewRecruitInfoStats::getViewRecruitInfoStatsUI() 
{
    return boundary;
}

/*
	�Լ� �̸� : getAddedRecruitInfoStats
	���: ȸ�� ȸ���� ����� ä�� ���� ��� ��ȯ
	�Ű�����: string currentLoginId -> ���� �α����� ȸ�� ȸ�� ���̵�
	��ȯ��: string -> ä�� ���� ��� ����
*/
string ViewRecruitInfoStats::getAddedRecruitInfoStats(string currentLoginId)
{
    return recruitInfoCollection-> calcAddedRecruitInfoStats(currentLoginId);
}

/*
	�Լ� �̸� : getAppliedRecruitInfoStats
	���: ȸ��ȸ���� ����� ä�� ���� ��� ��ȯ
	�Ű�����: string currentLoginId -> ���� �α����� �Ϲ� ȸ�� ���̵�
	��ȯ��:string -> ä�� ���� ��� ����
*/
string ViewRecruitInfoStats::getAppliedRecruitInfoStats(string currentLoginId)
{
    return applicationInfoCollection->calcAppliedRecruitInfoStats(currentLoginId);
}


