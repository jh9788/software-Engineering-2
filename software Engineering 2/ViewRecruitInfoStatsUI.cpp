#include "ViewRecruitInfoStatsUI.h"
#include "ViewRecruitInfoStats.h"

ViewRecruitInfoStatsUI::ViewRecruitInfoStatsUI(ViewRecruitInfoStats* inputControl)
{
    control = inputControl;
}

void ViewRecruitInfoStatsUI::init(ofstream* inputFout) {
    fout = inputFout;
}

void ViewRecruitInfoStatsUI::startInterface() {
    *fout << "5.1 지원 정보 통계" << endl;
}

void ViewRecruitInfoStatsUI::requestAddedRecruitInfoStats(string currentLoginId)
{   
    map<string, int> recruitInfoStats = control->getAddedRecruitInfoStats(currentLoginId);
    showRecruitInfoStatsInterface(recruitInfoStats);
}

void ViewRecruitInfoStatsUI::requestAppliedRecruitInfoStats(string currentLoginId) {
    map<string, int> recruitInfoStats = control->getAppliedRecruitInfoStats(currentLoginId);
    showRecruitInfoStatsInterface(recruitInfoStats);
}

//control에서 받아온 채용정보 통계 출력
void ViewRecruitInfoStatsUI::showRecruitInfoStatsInterface(map<string, int> recruitInfoStats)
{   
    for (auto it = recruitInfoStats.begin(); it != recruitInfoStats.end(); ++it) {
        *fout << it->first << " " << it->second << endl; 
    }
    *fout << endl;
}
