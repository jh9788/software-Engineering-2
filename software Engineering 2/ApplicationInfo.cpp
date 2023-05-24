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

/* 제출 시 삭제할 함수!! */
void ApplicationInfo::showApplicationInfo()
{
	cout << "채용 정보\n" << "회사명 : " << getRecruitInfo()->getCompanyId() << ", 업무: " << getRecruitInfo()->getWork() <<
		", : 모집 인원 수: " << getRecruitInfo()->getTargetNum() << ", 마감일: " << getRecruitInfo()->getDeadline() << ", 지원자 ID: " << getGeneralId() << endl;
}
}



