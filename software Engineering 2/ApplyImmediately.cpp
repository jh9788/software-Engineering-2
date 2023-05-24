#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

/*
	�Լ� �̸� : ApplyImmediately
	���: ������
	�Ű�����: ApplyImmediately* inputControl
			 RecruitInfoCollection* inputRecruitInfoCollection 
			 MemberCollection* inputMemberCollection 
	��ȯ��: X
*/
ApplyImmediately::ApplyImmediately(ApplicationInfoCollection* inputApplicationInfoCollection,
								   RecruitInfoCollection* inputRecruitInfoCollection,MemberCollection* inputMemberCollection)
{
	applicationInfoCollection = inputApplicationInfoCollection;
	recruitInfoCollection = inputRecruitInfoCollection;
	memberCollection = inputMemberCollection;
	ApplyImmediatelyUI* boundary = new ApplyImmediatelyUI(this);
	this->boundary = boundary;
}

/*
    �Լ� �̸� : getApplyImmediatelyUI
    ���: Boundary�� ȣ���ϱ� ���� �Լ�
    �Ű�����: X
    ��ȯ��: ApplyImmediately* Ÿ���� Boundary
*/
ApplyImmediatelyUI* ApplyImmediately::getApplyImmediatelyUI()
{
	return boundary;
}

/*
    �Լ� �̸� : applyImmediately
    ���: ä�� ������ ���� �Լ�
    �Ű�����: string businessNum -> ����� ��ȣ, string currentLoginId -> ���� �α����� ID�� �Ű������� ����
    ��ȯ��: ä�� ������ �Ϸ��� ä�� ������ returnSTring�� ����
*/
string ApplyImmediately::applyImmediately(string businessNum, string currentLoginId)
{
	string companyId = memberCollection->findIdByBusinessNum(businessNum);
	string companyName = memberCollection->findNameById(companyId);
	RecruitInfo* companyRecruitInfo = recruitInfoCollection->findByCompanyId(companyId);

	applicationInfoCollection->addApplicationInfo(companyRecruitInfo,currentLoginId);
	string companyWork = recruitInfoCollection->findWorkById(companyId);
	string returnString= "> " + companyName + " " + businessNum + " " + companyWork;
	
	return returnString;
}