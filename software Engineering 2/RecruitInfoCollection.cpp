#include <iostream>
#include <string>
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"


/* 제출 시 삭제할 함수 !! 현재 등록된 모든 회원 조회 */
void RecruitInfoCollection::getAllRecruitInfoCollection()
{
    for (int i = 0; i < recruitInfoCollection.size(); i++) {
        recruitInfoCollection[i]->showRecruitInfo();
    }
}


/*
함수 이름: getRecruitInfoCollectionSize
기능: recruitInfoCollection의 벡터의 size를 반환
매개변수: X
반환값: int
*/
int RecruitInfoCollection::getRecruitInfoCollectionSize() {
    return recruitInfoCollection.size();
}


/*
함수 이름: isMemberInRecruitInfoCollection
기능: 회사 회원이 올린 게시물이 recruitInfoCollectin 안에 있는지 확인
매개변수: X
반환값: bool
*/
bool RecruitInfoCollection::isMemberInRecruitInfoCollection(string companyId) {
    for (const auto& recruitInfo : recruitInfoCollection) {
        if (recruitInfo->getCompanyId() == companyId) {
            return true;
        }
    }
    return false;
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
    recruitInfoCollection.push_back(recruitInfo);
}


/*
함수 이름: getRecruitAllInfo
기능: 특정 채용 정보에 대해, 모든 값을 가져온다.
매개변수: RecruitInfo* recruitInfo -> RecruitInfo 객체 포인터값
반환값: X
*/
string RecruitInfoCollection::getRecruitAllInfo(int index)
{
    string work = recruitInfoCollection[index]->getWork();
    string targetNum = recruitInfoCollection[index]->getTargetNum();
    string deadline = recruitInfoCollection[index]->getDeadline();

    return work + " " + targetNum + " " + deadline;
}



/*
함수 이름: removeMember
기능: 회원이 memberCollection 벡터에 존재하는지 확인하고, 만약 존재한다면 해당 객체를 삭제한다.
매개변수: const char* memberId -> MemberId char 포인터값
반환값: X
*/
//void MemberCollection::removeMember(const char* memberId) {
//    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
//    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
//        // 만약 id가 같은 애가 검색되면 그 애를 삭제
//        if (strcmp((*it)->getId(), memberId) == 0) {
//            delete* it;
//            memberCollection.erase(it);
//            break;
//        }
//    }
//}



/*
함수 이름: isMember
기능: 로그인 시, 기존에 등록되어있는 회원인지 확인한다.
매개변수: const char* memberId -> MemberId char 포인터값, const char* memberPassword -> MemberPassword char 포인터 값
반환값: bool
*/
//bool MemberCollection::isMember(const char* memberId, const char* memberPassword) {
//    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
//    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
//        if (strcmp((*it)->getId(), memberId) == 0 && strcmp((*it)->getPassword(), memberPassword) == 0) {
//            return true;  // 해당 멤버를 찾은 경우, true return
//        }
//    }
//    return false;  // 찾는 멤버가 없는 경우, false return
//}



/*
함수 이름: getMemberType
기능: 로그인 시, 현재 로그인 한 사람의 member type을 확인한다.
매개변수: const char* memberId -> MemberId char 포인터값, const char* memberPassword -> MemberPassword char 포인터 값
반환값: int
*/
//int MemberCollection::getMemberType(const char* memberId, const char* memberPassword) {
//    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
//    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
//        if (strcmp((*it)->getId(), memberId) == 0 && strcmp((*it)->getPassword(), memberPassword) == 0) {
//            return (*it)->getMemberType();  // 해당 멤버를 찾은 경우, memberType return
//        }
//    }
//    return 0;  // 찾는 멤버가 없는 경우
//}



/*
함수 이름: ~RecruitInfoCollection
기능: 소멸자
매개변수: X
반환값: X
*/
RecruitInfoCollection::~RecruitInfoCollection()
{
    for (int i = 0; i < recruitInfoCollection.size(); i++)
        recruitInfoCollection.pop_back();
}
