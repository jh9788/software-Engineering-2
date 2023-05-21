#pragma once
#include "Member.h"
#include <vector>

using namespace std;

/*
클래스 이름 : MemberCollection
기능 : 멤버 리스트에 대한 아래 기능을 구현함
	   멤버의 회원 가입, 로그인, 로그아웃, 회원 탈퇴를 진행한다.
	   멤버의 타입을 확인한다.
*/
class MemberCollection
{
private:
	vector <Member*> memberCollection;

public:
	void getAllMemberCollection(); /* 제출 시 삭제할 함수 !! */ // 현재 등록된 회원 목록 모두 조회

	void addMember(Member* member);	// 회원 가입 시, 회원 추가
	void removeMember(const char* memberId); // 회원 탈퇴 시, 회원 삭제
	bool isMember(const char* memberId, const char* memberPassword); // 등록된 회원인지 확인 (로그인)
	int getMemberType(const char* memberId, const char* memberPassword);	// 회사 회원인지, 일반 회원인지 구분할 수 있는 memberType을 가져오기
	//void removeMember();
	//void findMemberByName();
	~MemberCollection();
};