#include "ViewRecruitInfoStats.h"
#include "ViewRecruitInfoStatsUI.h"

ViewRecruitInfoStats::ViewRecruitInfoStats(RecruitInfoCollection* inputRecruitInfoCollection, ApplicationInfoCollection* inputApplicationInfoCollection)
{
    ViewRecruitInfoStatsUI* boundary = new ViewRecruitInfoStatsUI(this);
    this->boundary = boundary;
    recruitInfoCollection = inputRecruitInfoCollection;
    applicationInfoCollection = inputApplicationInfoCollection;
}

ViewRecruitInfoStatsUI* ViewRecruitInfoStats::getViewRecruitInfoStatsUI() {
    return boundary;
}

map<string, int> ViewRecruitInfoStats::getAddedRecruitInfoStats(string currentLoginId)
{
    return recruitInfoCollection-> calcAddedRecruitInfoStats(currentLoginId);
}

map<string, int> ViewRecruitInfoStats::getAppliedRecruitInfoStats(string currentLoginId)
{
    return applicationInfoCollection->calcAppliedRecruitInfoStats(currentLoginId);
}


