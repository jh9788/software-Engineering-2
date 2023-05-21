
/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void LogoutUI::startInterface() {
    fout << "2.2. 로그아웃" << endl;  // 유저가 입력한 내용 화면에 띄우기
}

/*
    함수 이름 : requestLogout
    기능: 로그아웃 Boundary의 함수로써, 로그아웃의 Control에 로그아웃을 요청하는 역할
    매개변수: string& loginId -> 현재 login한 ID를 ""로 돌려놓기 위한 매개변수
              int memberType -> memberType을 0으로 돌려놓기 위한 매개변수
    반환값: X
*/
void LogoutUI::requestLogout(string& loginId, int& memberType) {
    Logout logout = Logout();   // logout 객체 생성

    logout.logoutMember(loginId, memberType);   // logoutMember 함수 호출
}

/*
    함수 이름 : showLogoutId
    기능: 로그아웃 성공 시 파일에 내용 저장 역할
    매개변수: string logoutId -> 파일에 저장할 id를 위한 매개변수
    반환값: X
*/
void LogoutUI::showLogoutId(string logoutId) {
    fout << "> " << logoutId << endl << endl;    // 파일에 내용 기입.
}
