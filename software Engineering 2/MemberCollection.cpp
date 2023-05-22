#include <iostream>
#include "Member.h"
#include "CompanyMember.h"
#include "GeneralMember.h"
#include "MemberCollection.h"


/* 제출 시 삭제할 함수 !! 현재 등록된 모든 회원 조회 */
void MemberCollection::getAllMemberCollection()
{
    for (int i = 0; i < memberCollection.size(); i++) {
        memberCollection[i]->showMemberInfo();
    }
}

/*
함수 이름: addMember
기능: Member 객체를 매개변수로 받아서 벡터에 순차적으로 넣는다.
매개변수: Member* member -> Member 객체 포인터값
반환값: X
*/
void MemberCollection::addMember(string name, string number, string id, string password, int memType)
{
    Member* member;
    if(memType == 1){
        member = new CompanyMember(name, number, id, password, memType);
    }
    else{
        member = new GeneralMember(name, number, id, password, memType);
    }
	memberCollection.push_back(member);
}


/*
함수 이름: removeMember
기능: 회원이 memberCollection 벡터에 존재하는지 확인하고, 만약 존재한다면 해당 객체를 삭제한다.
매개변수: string memberId -> MemberId char 포인터값
반환값: X
*/
void MemberCollection::removeMember(string memberId) {
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애를 삭제
        if ((*it)->getId() == memberId) {
            delete* it;
            memberCollection.erase(it);
            break;
        }
    }
}


 
/*
함수 이름: isMember
기능: 로그인 시, 기존에 등록되어있는 회원인지 확인한다.
매개변수: string memberId -> MemberId char 포인터값, string memberPassword -> MemberPassword char 포인터 값
반환값: bool
*/
bool MemberCollection::isMember(string memberId, string memberPassword) {
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId() == memberId && (*it)->getPassword() == memberPassword) {
            return true;  // 해당 멤버를 찾은 경우, true return
        }
    }
    return false;  // 찾는 멤버가 없는 경우, false return
}



/*
함수 이름: getMemberType
기능: 로그인 시, 현재 로그인 한 사람의 member type을 확인한다.
매개변수: string memberId -> MemberId char 포인터값, string memberPassword -> MemberPassword char 포인터 값
반환값: int
*/
int MemberCollection::getMemberType(string memberId, string memberPassword) {
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId()== memberId  && (*it)->getPassword() == memberPassword) {
            return (*it)->getMemberType();  // 해당 멤버를 찾은 경우, memberType return
        }
    }
    return 0;  // 찾는 멤버가 없는 경우
}



/*
함수 이름: ~MemberCollection
기능: 소멸자
매개변수: X
반환값: X
*/
MemberCollection::~MemberCollection()
{
	for (int i = 0; i < memberCollection.size(); i++)
		memberCollection.pop_back();
}





///*
//함수 이름: getRecruitInfo
//기능: 로그인 한 사람이 등록한 모든 채용 정보를 담아 반환한다.
//매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
//반환값: string
//*/
//string MemberCollection::findMemberByName(string targetName)
//{
//    string returnString = "";
//    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
//    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
//        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
//        if ((*it)->getName() == targetName) {
//            (*it)->
//        }
//
//        return returnString;
//    }

string MemberCollection::findBusinessNumByName(string memberName)
{
    // memberCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // 만약 name이 같은 회원을 찾으면
        if ((*it)->getName() == memberName) {
            CompanyMember* companyMember = static_cast<CompanyMember*>(*it);
            return companyMember->getBusinessNum();
            }
    }
}

string MemberCollection::findIdByName(string memberName)
{
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // 만약 name이 같은 회원을 찾으면
        if ((*it)->getName() == memberName) {
            Member* member = (*it);
            return member->getId();
        }
    }
}

