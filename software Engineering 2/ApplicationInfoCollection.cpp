#include "ApplicationInfoCollection.h"

ApplicationInfoCollection::ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection) {
	memberCollection = inputMemberCollection;
	recruitInfoCollection = inputRecruitInfoCollection;
}

string ApplicationInfoCollection::getApplicationInfo(string currentLoginId){
	/*for (int i = 0; i < applicationInfoCollection.size(); i++)
	{
		applicationInfoCollection[i]->showApplicationInfo();
	}*/
	return 0;
}


void ApplicationInfoCollection::addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId) {
	ApplicationInfo* applicationInfo = new ApplicationInfo(inputRecruitInfo, currentLoginId);
	applicationInfoCollection.push_back(applicationInfo);
}


void ApplicationInfoCollection::removeApplicationInfo(string currentLoginId) {


}