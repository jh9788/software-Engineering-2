#include "ApplicationInfo.h"


ApplicationInfo::ApplicationInfo(RecruitInfo* inputRecruitInfo, string inputGeneralId){
	recruitInfo = inputRecruitInfo;
	generalId = inputGeneralId;
}

string ApplicationInfo::getGeneralId()
{
	return generalId;
}

string ApplicationInfo::getRecruitInfoWork()
{
	return recruitInfo->getWork();
}
