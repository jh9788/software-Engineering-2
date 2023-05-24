#include "ApplicationInfo.h"


ApplicationInfo::ApplicationInfo(RecruitInfo* inputRecruitInfo, string inputGeneralId){
	recruitInfo = inputRecruitInfo;
	generalId = inputGeneralId;
}

string ApplicationInfo::getGeneralId() {
	return generalId;
}


RecruitInfo* ApplicationInfo::getRecruitInfo() {
	return recruitInfo;
}

string ApplicationInfo::getRecruitInfoWork()
{
	return recruitInfo->getWork();
}

/* ���� �� ������ �Լ�!! */
void ApplicationInfo::showApplicationInfo()
{
	cout << "ä�� ����\n" << "ȸ��� : " << getRecruitInfo()->getCompanyId() << ", ����: " << getRecruitInfo()->getWork() <<
		", : ���� �ο� ��: " << getRecruitInfo()->getTargetNum() << ", ������: " << getRecruitInfo()->getDeadline() << ", ������ ID: " << getGeneralId() << endl;
}
}



