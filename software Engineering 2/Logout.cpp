#include "Logout.h"
#include "LogoutUI.h"
using namespace std;

Logout::Logout()
{
    LogoutUI* boundary = new LogoutUI(this);
    this->boundary = boundary;
}

LogoutUI* Logout::getLogoutUI()
{
    return boundary;
}

/*
    함수 이름 : logoutMember
    기능: 로그아웃을 실제로 진행하는 역할
    매개변수: string& loginId -> 현재 login한 ID를 ""로 돌려놓기 위한 매개 변수
              int memberType -> memberType을 0으로 돌려놓기 위한 매개변수
    반환값: X
*/
void Logout::logoutMember(string& loginId, int& memberType) 
{
    loginId = "";   // 로그아웃 시 nowLogin = ""로 되돌려주기
    memberType = 0; // 로그아웃 시 memberType은 회사 회원도 일반 회원도 아니므로 0으로 바꿔주기
}