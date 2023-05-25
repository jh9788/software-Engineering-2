#include "ViewRecruitInfoStatsUI.h"
#include "ViewRecruitInfoStats.h"

/*
	�Լ� �̸� : ViewRecruitInfoStatsUI
	���: ������
	�Ű�����: ViewRecruitInfoStats* inputControl -> ä�� ���� ��� Control Ŭ���� ���� ��
	��ȯ��: X
*/
ViewRecruitInfoStatsUI::ViewRecruitInfoStatsUI(ViewRecruitInfoStats* inputControl)
{
    control = inputControl;
}

/*
	�Լ� �̸� : init
	���: ���� ����� ofstream ���� �� ����
	�Ű�����: ofstream* inputFout -> ofstream ���� ��
	��ȯ��: X
*/
void ViewRecruitInfoStatsUI::init(ofstream* inputFout) {
    fout = inputFout;
}

/*
	�Լ� �̸� : startInterface
	���: ����ڰ� ������ �޴� output.txt�� ���
	�Ű�����: X
	��ȯ��: X
*/
void ViewRecruitInfoStatsUI::startInterface() {
    *fout << "5.1 ���� ���� ���" << endl;
}

/*
	�Լ� �̸� : requestAddedRecruitInfoStats
	���: ȸ�� ȸ���� ����� ä�� ���� ��� Control Ŭ�������� ��û
	�Ű�����: string currentLoginId -> ���� �α����� ȸ�� ȸ�� ���̵� 
	��ȯ��: X
*/
void ViewRecruitInfoStatsUI::requestAddedRecruitInfoStats(string currentLoginId)
{   
    string recruitInfoStats = control->getAddedRecruitInfoStats(currentLoginId);
    _showRecruitInfoStatsInterface(recruitInfoStats);
}

/*
	�Լ� �̸� : requestAppliedRecruitInfoStats
	���: �Ϲ� ȸ���� ������ ä�� ���� ��� Control Ŭ�������� ��û
	�Ű�����: string currentLoginId -> ���� �α����� �Ϲ� ȸ�� ���̵� 
	��ȯ��: X
*/
void ViewRecruitInfoStatsUI::requestAppliedRecruitInfoStats(string currentLoginId) {
    string recruitInfoStats = control->getAppliedRecruitInfoStats(currentLoginId);
    _showRecruitInfoStatsInterface(recruitInfoStats);
}

/*
	�Լ� �̸� : requestAppliedRecruitInfoStats
	���: Control Ŭ�������� �޾ƿ� ä�� ���� ��� output.txt�� ���
	�Ű�����: string recruitInfoStats -> ä�� ���� ��� ����
	��ȯ��: X
*/
void ViewRecruitInfoStatsUI::_showRecruitInfoStatsInterface(string recruitInfoStats)
{   
        *fout << recruitInfoStats << endl;
}
