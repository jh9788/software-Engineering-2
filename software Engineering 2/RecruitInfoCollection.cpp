#include <iostream>
#include <string>
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"


/* 제출 시 삭제할 함수 !! 현재 등록된 모든 회원 조회 */
void RecruitInfoCollection::getAllRecruitInfoCollection()
{
    for (int i = 0; i < ownedRecruitInfo.size(); i++) {
        ownedRecruitInfo[i]->showRecruitInfo();
    }
}


/*
함수 이름: addRecruitInfo
기능: recruitInfo 객체를 매개변수로 받아서 벡터에 순차적으로 넣는다.
매개변수: string work -> 업무, string targetNum -> 인원 수, string deadline -> 신청 마감일, string currentLoginId -> 현재 로그인한 ID
반환값: X
*/
void RecruitInfoCollection::addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId)
{
    RecruitInfo* recruitInfo = new RecruitInfo(work, targetNum, deadline, currentLoginId);
    ownedRecruitInfo.push_back(recruitInfo);
}


/*
함수 이름: getRecruitInfo
기능: 로그인 한 사람이 등록한 모든 채용 정보를 담아 반환한다.
매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
반환값: string
*/
string RecruitInfoCollection::getRecruitInfo(string currentLoginId)
{
    string returnString = "";
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
        if ((*it)->getCompanyId() == currentLoginId) {
            returnString = returnString + "> " + (*it)->getWork() + " ";
            returnString = returnString + (*it)->getTargetNum() + " ";
            returnString = returnString + (*it)->getDeadline() + "\n";
        }
    }
    
    return returnString;
}

/*
함수 이름: getRecruitInfoWithoutSign
기능: 로그인 한 사람이 등록한 모든 채용 정보를 담아 ">" 기호를 제외하고 반환한다.
매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
반환값: string
*/
string RecruitInfoCollection::getRecruitInfoWithoutSign(string currentLoginId)
{
	string returnString = "";

	// 현재 시간을 받아옵니다.
	auto now = chrono::system_clock::now();
	time_t now_time_t = chrono::system_clock::to_time_t(now);
	tm now_tm = {};
	localtime_s(&now_tm, &now_time_t);

	// memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
	for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
		// 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
		if ((*it)->getCompanyId() == currentLoginId) {
			// 입력된 문자열을 시간으로 변환합니다.
			istringstream dateDeadline(((*it)->getDeadline()));
			tm input_tm = {};
			dateDeadline >> get_time(&input_tm, "%Y/%m/%d"); // 형식은 "YYYY/MM/DD"
			// 입력된 날짜가 현재보다 이후인지 확인합니다.
			if (input_tm.tm_year > now_tm.tm_year) {
				returnString = returnString + (*it)->getWork() + " ";
				returnString = returnString + (*it)->getTargetNum() + " ";
				returnString = returnString + (*it)->getDeadline() + "\n";
				return returnString;
			}
			else if (input_tm.tm_year == now_tm.tm_year) {
				if (input_tm.tm_mon > now_tm.tm_mon) {
					returnString = returnString + (*it)->getWork() + " ";
					returnString = returnString + (*it)->getTargetNum() + " ";
					returnString = returnString + (*it)->getDeadline() + "\n";
					return returnString;
				}
				else if (input_tm.tm_mon == now_tm.tm_mon) {
					if (input_tm.tm_mday >= now_tm.tm_mday) {
						returnString = returnString + (*it)->getWork() + " ";
						returnString = returnString + (*it)->getTargetNum() + " ";
						returnString = returnString + (*it)->getDeadline() + "\n";
						return returnString;
					}
				}
			}
		}
	}

	return returnString;

}

RecruitInfo* RecruitInfoCollection::findRecruitInfoById(string companyId)
{
    for (auto& recruitInfo : ownedRecruitInfo) {
        if (recruitInfo->getCompanyId() == companyId) {
            return recruitInfo;
        }
    }
    return nullptr;
}

string RecruitInfoCollection::findWorkById(string companyId)
{
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
        if ((*it)->getCompanyId() == companyId) {
            return (*it)->getWork();
        }
    }

    return "";
}

RecruitInfo* RecruitInfoCollection::findByCompanyId(string companyId) {
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
        if ((*it)->getCompanyId() == companyId) {
            return *it;
        }
    }

    return NULL; //발견하지 못했을때
}

/*
함수 이름: ~RecruitInfoCollection
기능: 소멸자
매개변수: X
반환값: X
*/
RecruitInfoCollection::~RecruitInfoCollection()
{
    for (int i = 0; i < ownedRecruitInfo.size(); i++)
        ownedRecruitInfo.pop_back();
}
