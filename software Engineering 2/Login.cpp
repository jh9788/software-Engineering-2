#include "Login.h"
#include "LoginUI.h"

Login::Login(MemberCollection* inputMemberCollection){
    LoginUI* boundary = new LoginUI(this);
    this->boundary = boundary;
    memberCollection = inputMemberCollection;

}

LoginUI* Login::getLoginUI(){
    return boundary;
}

/*
    함수 이름 : verifyLogin
    기능: 로그인 할 수 있는 자격을 갖추었는지 확인하는 함수
    매개변수: MemberCollection& memberCollection -> memberCollection에 저장되어있는 애인지 확인하기 위해 보내는 argument
              string name -> 이름
              string num -> 주민등록번호
              string* id -> ID
              string pwd -> Password
              string& loginId -> 현재 login한 ID를 저장해 오기 위한 변수
              int memberType -> 회사 회원, 일반 회원에 따라 memberType값을 저장해 오기 위한 변수
    반환값: bool
*/
bool Login::verifyLogin(string id, string pwd, string& currentLoginId, int& currentMemberType) {
    // 회원이 맞는 경우
    if (memberCollection.isMember(id, pwd)) {
		currentLoginId = id;           // loginId에 방금 로그인을 시도했던 id를 저장
		currentMemberType = memberCollection.getMemberType(id, pwd);       // memberType에 현재 로그인 한 member의 type을 저장
        return true;
    }
    // 회원이 아닌 경우
    else
        return false;
}