#include "ApplicationInfoCollection.h"

map<string, int> ApplicationInfoCollection::calcAppliedRecruitInfoStats(string currentLoginId)
{
    map<string, int> recruitInfoStats;

    for (auto it = applicationInfoVec.begin(); it != applicationInfoVec.end(); ++it) {
        if ((*it)->getGeneralId() == currentLoginId) {
            string work = (*it)->getRecruitInfoWork();

            if (recruitInfoStats.find(work) == recruitInfoStats.end()) {
                recruitInfoStats[work] = 1;
            }
            else {
                recruitInfoStats[work] += 1;
            }
        }
    }

    return recruitInfoStats;
}
