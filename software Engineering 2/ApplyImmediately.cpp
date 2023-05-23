#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

ApplyImmediately::ApplyImmediately(ApplicationInfoCollection* inputApplicationInfoCollection,
	RecruitInfoCollection* inputRecruitInfoCollection,MemberCollection* inputMemberCollection)
{
	applicationInfoCollection = inputApplicationInfoCollection;
	recruitInfoCollection = inputRecruitInfoCollection;
	memberCollection = inputMemberCollection;
	ApplyImmediatelyUI* boundary = new ApplyImmediatelyUI(this);
	this->boundary = boundary;
}

ApplyImmediatelyUI* ApplyImmediately::getApplyImmediatelyUI()
{
	return boundary;
}

string ApplyImmediately::applyImmediately(string businessNum)
{
	string companyId = memberCollection->findIdByBusinessNum(businessNum);
	string companyName = memberCollection->findNameById(companyId);
	RecruitInfo* companyRecruitInfo = recruitInfoCollection->findRecruitInfoById(companyId);
	applicationInfoCollection->addApplicationInfo(companyRecruitInfo,businessNum);
	string companyWork = recruitInfoCollection->findWorkById(companyId);
	string returnString= "> " + companyName + " " + businessNum + " " + companyWork;
	return returnString;
}