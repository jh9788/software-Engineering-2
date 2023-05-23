#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

ApplyImmediately::ApplyImmediately(ApplicationInfoCollection* inputApplicationInfoCollection)
{
	applicationInfoCollection = inputApplicationInfoCollection;

	ApplyImmediatelyUI* boundary = new ApplyImmediatelyUI(this);
	this->boundary = boundary;
}

ApplyImmediatelyUI* ApplyImmediately::getApplyImmediatelyUI()
{
	return boundary;
}

void ApplyImmediately::applyImmediately(string businessNum)
{
	RecruitInfo* a;
	applicationInfoCollection->addApplicationInfo(a,businessNum);
}