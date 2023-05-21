#include "Withdraw.h"
#include "WithdrawUI.h"

/*
    함수 이름 : Withdraw
    기능 : 생성자
    매개변수 : 
    반환값 : X
*/
Withdraw::Withdraw(MemberCollection* inputMemberCollection){
    memberCollection = inputMemberCollection;
	WithdrawUI* boundary = new WithdrawUI(this);
    this->boundary = boundary;
}

/*
	함수 이름 : getWithdrawUI
	기능 : 
	매개변수 : X
	반환값 : boundary
*/
WithdrawUI* Withdraw::getWithdrawUI() {
	return boundary;
}

/*
    함수 이름 : withdrawMember
    기능: 회원탈퇴를 실제로 진행하는 역할
    매개변수: MemberCollection& memberCollection -> 회원 탈퇴를 요청한 회원을 찾고, 정보를 삭제하기 위해 매개변수로 전달
              string& loginId -> 현재 login한 ID를 ""로 돌려놓기 위한 매개변수
              int memberType -> memberType을 0으로 돌려놓기 위한 매개변수
    반환값: X
*/
void Withdraw::withdrawMember(string& currentLoginId, int& currentMemberType) {
    memberCollection->removeMember(currentLoginId);      // 해당 id 제거

    currentLoginId = "";           // 회원 탈퇴 시 로그아웃 상태로 되돌리기
    currentMemberType = 0;         // 회원 탈퇴 시 회사 회원도 일반 회원도 아니므로 memberType = 0
}
