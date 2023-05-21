#include "Run.h"
#include "MemberCollection.h"
#include "Member.h"
#include "RecruitInfoCollection.h"
#include "RecruitInfo.h"
#include "CompanyMember.h"
#include "GeneralMember.h"
#include <string>
#include <fstream>
#include <sstream>

#define endl '\n'
#define INPUT_FILE "example.txt"
#define OUTPUT_FILE "output.txt"


ifstream fin(INPUT_FILE); // 텍스트 파일 열기
ofstream fout(OUTPUT_FILE); // 텍스트 파일로 추출하기


/*
    함수 이름 : run
    기능: 파일을 입력 받고, 입력 받은 내용에 맞게 각 함수를 실행함. Actor의 역할
    매개변수: X
    반환값: X
*/
void run() {
    if (!fin || !fout) {
        cout << "파일을 열 수 없습니다." << endl;
        return;
    }

    string inputEvent;  // 읽은 파일에서 현재 보고 있는 한 줄
    int keepGoing = 1;  // keepGoing이 1이면 계속해서 파일을 읽고, 0이 되는 순간 while문 탈출
    MemberCollection memberCollection = MemberCollection();     // MemberCollection 생성
    RecruitInfoCollection recruitInfoCollection = RecruitInfoCollection();      // RecruitInfoCollection 생성
    string nowLogin = "";       // 현재 로그인 중인 ID를 nowLogin에 저장

    int memberType = 0;         // 1이면 회사 회원, 2면 일반 회원
    // memberType이 1일 때에는 회사 회원 관련 시스템이 작동하고, 일반 회원 관련 시스템에 접근 시 아무 행동도 하지 않으며,
    // memberType이 2일 때에는 일반 회원 관련 시스템이 작동하고, 회사 회원 관련 시스템에 접근 시 아무 행동도 하지 않는다.


    RegisterUI registerUI = RegisterUI();   // 회원 가입을 위한 바운더리 객체 생성
    WithdrawUI withdrawUI = WithdrawUI();   // 회원 탈퇴를 위한 바운더리 객체 생성
    LoginUI loginUI = LoginUI();            // 로그인을 위한 바운더리 객체 생성
    LogoutUI logoutUI = LogoutUI();         // 로그아웃을 위한 바운더리 객체 생성
    AddRecruitInfoUI addRecruitInfoUI = AddRecruitInfoUI();     // 채용 정보 등록을 위한 객체 생성
    ViewAddedRecruitListUI viewAddedRecruitListUI = ViewAddedRecruitListUI();   // 등록한 채용 정보 리스트 조회를 위한 객체 생성


    while (keepGoing) { // 한 줄씩 읽어오기
        getline(fin, inputEvent);

        int firstEvent = inputEvent[0] - '0';       // 1. 1. 1에서 맨 앞의 1
        int secondEvent = inputEvent[2] - '0';      // 1. 1. 1에서 중간의 1
        string tempId = nowLogin;     // 로그아웃 하면 파일에 nowLogin 내용을 작성해야 하는데, 아래 함수 실행 시 nowLogin이 사라지므로, 잠시 담아 둠
                                      // 회원 탈퇴할 때에도 마찬가지

        switch (firstEvent) {
        case 1:
            switch (secondEvent) {
            // 회원 가입
            case 1:
                registerUI.startInterface();    // 인터페이스 시작

                memberType = registerUI.selectMemberType(inputEvent);       // 1. 1. 1에서 맨 뒤의 1이 memberType에 저장됨
                registerUI.requestRegister(memberCollection, inputEvent, memberType);   // Boundary에 있는 requestRegister 함수 호출
                registerUI.showRegisterSuccessInterface(inputEvent, memberType);        // 회원가입 시 내용을 파일에 저장
                break;
            // 회원 탈퇴
            case 2:
                withdrawUI.startInterface();    // 인터페이스 시작

                if (nowLogin == "") // 로그인 하지 않은 상태라면 nowLogin은 ""이고, 회원 탈퇴할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;
                else {              // 로그인 되었을 때에만 회원 탈퇴
                    withdrawUI.requestWithdraw(memberCollection, nowLogin, memberType);     // Boundary에 있는 requestWithdraw 함수 호출
                    withdrawUI.showWithdrawId(tempId);           // 회원탈퇴 시 내용을 파일에 저장
                    //cout << "after withdraw memberType : " << memberType << endl;
                    break;
                }
            }
            break;
        case 2:
            switch (secondEvent) {
            // 로그인
            case 1:
                loginUI.startInterface();   // 인터페이스 시작

                if (nowLogin != "")                 // 누군가 로그인 중이면 로그인 할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;

                else {
                    if (loginUI.requestLogin(memberCollection, inputEvent, nowLogin, memberType))   // Boundary에 있는 requestLogin 함수 호출
                        loginUI.showLoginSuccessInterface(inputEvent);      // 로그인 성공 시 파일에 저장할 내용 작성
                    else
                        loginUI.showLoginFailInterface();           // 로그인 실패 시 파일에 저장할 내용 작성
                    
                    //cout << "nowLogin : " << nowLogin << endl;      // 지금 로그인하고 있는 사람이 누구인지 Console 창에 찍어본 것
                    //cout << "after login memberType : " << memberType << endl;
                    break;
                }
                break;
            // 로그아웃
            case 2:
                logoutUI.startInterface();  // 인터페이스 시작

                if (nowLogin == "")               // 로그인 하지 않은 상태라면 로그아웃할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;
                else {              // 로그인 한 상태에서만 로그아웃 진행 가능!
                    logoutUI.requestLogout(nowLogin, memberType);       // 로그인 한 상태라면 로그아웃 진행 가능. Boundary에 있는 requestLogout 함수 호출
                    logoutUI.showLogoutId(tempId);        // 로그아웃 시 파일에 저장할 내용 작성
                    //cout << "nowLogin : " << nowLogin << endl;      // 로그아웃이 잘 되었는지 확인하기 위해 Console 창에 찍어본 것
                    //cout << "after logout memberType : " << memberType << endl;
                    break;
                }
                break;
            }
            break;
        case 3:
            switch (secondEvent) {
            // 채용 정보 등록
            case 1:
                addRecruitInfoUI.startInterface();  // 인터페이스 시작

                if (memberType == 2)        // 일반 회원은 이 작업 수행 불가능
                    break;
                else {
                    addRecruitInfoUI.requestRecruitInfo(recruitInfoCollection, inputEvent, nowLogin);     // recruitInfoCollection 벡터에 recruitInfo를 추가하기 위한 함수 호출
                    addRecruitInfoUI.showAddedRecruitInfo(inputEvent);
                }
                break;
            // 채용 정보 조회
            case 2:
                viewAddedRecruitListUI.startInterface();    // 인터페이스 시작

                if (memberType == 2)        // 일반 회원은 이 작업 수행 불가능
                    break;
                else {
                    viewAddedRecruitListUI.showRecruitInfo(recruitInfoCollection, nowLogin);     // recruitInfoCollection 벡터를 조회하기 위한 함수 호출
                }
                break;
            }
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            switch (secondEvent) {
            case 1:
                program_exit();     // 프로그램 종료하기 위한 함수 호출
                keepGoing = 0;      // keepGoing을 0으로 설정함으로써 while문 탈출
                break;
            }
            break;
        }
    }

    //memberCollection.getAllMemberCollection(); // 현재 멤버가 누구누구 있는지 확인하기 위한 애
    recruitInfoCollection.getAllRecruitInfoCollection(); // 현재 등록된 채용 정보가 누구누구 있는지 확인하기 위한 애

    fin.close(); // 파일 닫기
    fout.close(); // 파일 닫기
}


/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void RegisterUI::startInterface() {
    fout << "1.1. 회원가입" << endl;  // 유저가 입력한 내용 화면에 띄우기. 이에 대한 응답은 boundary에서 실현
}

/*
    함수 이름 : selectMemberType
    기능: 파일의 한 줄을 읽고, 회원의 Type에 맞게 값을 반환
    매개변수: string inputEvent -> 파일에서 방금 읽어들인 한 줄의 내용
    반환값: 회사 회원이면 1, 일반 회원이면 2를 반환
*/
int RegisterUI::selectMemberType(string inputEvent) {
    int thirdEvent = inputEvent[4] - '0';

    if (thirdEvent == 1)
        return 1;
    else if (thirdEvent == 2)
        return 2;
}

/*
    함수 이름 : requestRegister
    기능: 회원가입 Boundary의 함수로써, 회원 가입 Control에게 회원 가입을 요청하는 역할
    매개변수: MemberCollection& memberCollection -> 회원 가입 완료 시, memberCollection에 저장
              string inputEvent -> 파일에서 방금 읽어들인 한 줄의 내용
              int memberType -> 1: 회사 회원, 2: 일반 회원
    반환값: X
*/
void RegisterUI::requestRegister(MemberCollection& memberCollection, string inputEvent, int memberType) {
    // 다음에 사용될 함수의 매개변수에 char* type을 넣기 위해 string 자르기
    stringstream input(inputEvent);     // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, num3, name, num, id, pwd;    // 공백을 기준으로 잘라진 애들을 넣을 string 변수 생성

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // 공백을 기준으로 각 변수에 string이 넣어짐

    const char* cname = name.c_str();   // string type을 const char* type으로 변환
    const char* cnum = num.c_str();
    const char* cid = id.c_str();
    const char* cpwd = pwd.c_str();

    Register regist;            // Control class에서 regist 객체 생성 (register는 예약어이므로 regist라는 변수 명으로 대체)

    // 1.1.1인지 1.1.2인지는 이 switch case문에서 결정
    switch (memberType) {
    case 1:             // 회사 회원인 경우
        regist.registerCompanyMember(memberCollection, cname, cnum, cid, cpwd, 1);     // Control의 함수인 registerCompanyMember 호출
        break;
    case 2:             // 일반 회원인 경우
        regist.registerGeneralMember(memberCollection, cname, cnum, cid, cpwd, 2);     // Control의 함수인 registerGeneralMember 호출
        break;
    }
}

/*
    함수 이름 : showRegisterSuccessInterface
    기능: 회원 가입 완료 시 파일에 내용 저장 역할
    매개변수: string inputEvent -> 파일에 저장할 name, num, id, pwd를 파싱하기 위한 매개변수
              memberType -> 회사 회원, 일반 회원에 맞는 번호를 파일에 저장하기 위한 매개변수
    반환값: X
*/
void RegisterUI::showRegisterSuccessInterface(string inputEvent, int memberType) {
    // 파일에 내용을 기입하기 위해 string 자르기
    stringstream input(inputEvent);     // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, num3, name, num, id, pwd;    // 공백을 기준으로 잘라진 애들을 넣을 string 변수 생성

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // 공백을 기준으로 각 변수에 string이 넣어짐

    fout << "> " << memberType << " " << name << " " << num << " " << id << " " << pwd << endl << endl;    // 파일에 회원 가입 정보 기입
}

/*
    함수 이름 : registerCompanyMember
    기능: 회사 회원을 새로 등록함
    매개변수: MemberCollection& memberCollection -> 회원 가입 완료 시, memberCollection에 저장
              const char* name -> 이름
              const char* num -> 사업자 번호
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 1 (회사 회원)
    반환값: X
*/
void Register::registerCompanyMember(MemberCollection& memberCollection,
                                     const char* name, const char* num, const char* id, const char* pwd, int memberType)
{
    Member* newMember = NULL;       // Member Type의 새로운 객체 생성
    newMember = new CompanyMember(name, num, id, pwd, memberType);  // 그 객체에 CompanyMember 생성자 만들어 넣기
    memberCollection.addMember(newMember);  // memberCollection class가 갖고 있는 addMember함수 호출하여 Member 추가
}

/*
    함수 이름 : registerGeneralMember
    기능: 일반 회원을 새로 등록함
    매개변수: MemberCollection& memberCollection -> 회원 가입 완료 시, memberCollection에 저장
              const char* name -> 이름
              const char* num -> 주민등록번호
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 2 (일반 회원)
    반환값: X
*/
void Register::registerGeneralMember(MemberCollection& memberCollection,
                                     const char* name, const char* num, const char* id, const char* pwd, int memberType)
{
    Member* newMember = NULL;       // Member Type의 새로운 객체 생성
    newMember = new CompanyMember(name, num, id, pwd, memberType);  // 그 객체에 GeneralMember 생성자 만들어 넣기
    memberCollection.addMember(newMember);  // memberCollection class가 갖고 있는 addMember함수 호출하여 Member 추가
}

/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void LoginUI::startInterface() {
    fout << "2.1. 로그인" << endl;  // 유저가 입력한 내용 화면에 띄우기
}

/*
    함수 이름 : requestLogin
    기능: 로그인 Boundary의 함수로써, 로그인의 Control에 로그인을 요청하는 역할
    매개변수: MemberCollection& memberCollection -> memberCollection에 저장되어있는 애인지 확인하기 위해 보내는 argument
              const char* name -> 이름
              const char* num -> 주민등록번호
              const char* id -> ID
              const char* pwd -> Password
              string& loginId -> 현재 login한 ID를 저장해 오기 위한 변수
              int memberType -> 회사 회원, 일반 회원에 따라 memberType값을 저장해 오기 위한 변수
    반환값: bool
*/
bool LoginUI::requestLogin(MemberCollection& memberCollection, string inputEvent, string& loginId, int& memberType) {
    // 다음에 호출할 함수의 매개변수에 const char* type을 넣기 위한 작업
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, id, pwd;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> id >> pwd;     // 공백을 기준으로 각각의 string을 변수에 담기

    const char* cid = id.c_str();       // string을 char* 형식으로 변환
    const char* cpwd = pwd.c_str();

    Login login = Login();          // Login 객체 생성

    if (login.verifyLogin(memberCollection, cid, cpwd, loginId, memberType))
        return true;
    else
        return false;

}

/*
    함수 이름 : showLoginSuccessInterface
    기능: 로그인 성공 시 파일에 내용 저장 역할
    매개변수: string inputEvent -> 파일에 저장할 id와 pwd를 파싱하기 위한 매개변수
    반환값: X
*/
void LoginUI::showLoginSuccessInterface(string inputEvent) {
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, id, pwd;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> id >> pwd;     // 공백을 기준으로 각각의 string을 변수에 담기

    fout << "> " << id << " " << pwd << endl << endl;       // 로그인 성공 시, 나머지 내용 (id, pwd)을 파일에 저장
}

/*
    함수 이름 : showLoginFailInterface
    기능: 로그인 실패 시 파일에 내용 저장 역할
    매개변수: X
    반환값: X
*/
void LoginUI::showLoginFailInterface() {
    fout << endl << endl;        // 로그인 실패 시, 개행만 두 번 실행한 결과를 파일에 저장
}

/*
    함수 이름 : verifyLogin
    기능: 로그인 할 수 있는 자격을 갖추었는지 확인하는 함수
    매개변수: MemberCollection& memberCollection -> memberCollection에 저장되어있는 애인지 확인하기 위해 보내는 argument
              const char* name -> 이름
              const char* num -> 주민등록번호
              const char* id -> ID
              const char* pwd -> Password
              string& loginId -> 현재 login한 ID를 저장해 오기 위한 변수
              int memberType -> 회사 회원, 일반 회원에 따라 memberType값을 저장해 오기 위한 변수
    반환값: bool
*/
bool Login::verifyLogin(MemberCollection& memberCollection, const char* id, const char* pwd, string& loginId, int& memberType) {
    // 회원이 맞는 경우
    if (memberCollection.isMember(id, pwd)) {
        loginId = id;           // loginId에 방금 로그인을 시도했던 id를 저장
        memberType = memberCollection.getMemberType(id, pwd);       // memberType에 현재 로그인 한 member의 type을 저장
        return true;
    }
    // 회원이 아닌 경우
    else
        return false;
}

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

/*
    함수 이름 : logoutMember
    기능: 로그아웃을 실제로 진행하는 역할
    매개변수: string& loginId -> 현재 login한 ID를 ""로 돌려놓기 위한 매개 변수
              int memberType -> memberType을 0으로 돌려놓기 위한 매개변수
    반환값: X
*/
void Logout::logoutMember(string& loginId, int& memberType) {
    loginId = "";   // 로그아웃 시 nowLogin = ""로 되돌려주기
    memberType = 0; // 로그아웃 시 memberType은 회사 회원도 일반 회원도 아니므로 0으로 바꿔주기
}

/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void WithdrawUI::startInterface() {
    fout << "1.2. 회원탈퇴" << endl;     // 유저가 입력한 내용 화면에 띄우기
}

/*
    함수 이름 : requestWithdraw
    기능: 회원탈퇴 Boundary의 함수로써, 회원탈퇴의 Control에 회원탈퇴를 요청하는 역할
    매개변수: MemberCollection& memberCollection -> 회원 탈퇴를 요청한 회원을 찾고, 정보를 삭제하기 위해 매개변수로 전달
              string& loginId -> 현재 login한 ID를 ""로 돌려놓기 위한 매개변수
              int memberType -> memberType을 0으로 돌려놓기 위한 매개변수
    반환값: X
*/
void WithdrawUI::requestWithdraw(MemberCollection& memberCollection, string& loginId, int& memberType) {
    Withdraw withdraw = Withdraw();     // withdraw 객체 생성
    withdraw.withdrawMember(memberCollection, loginId, memberType);     // 회원 탈퇴를 위한 함수 호출
}

/*
    함수 이름 : showWithdrawId
    기능: 회원 탈퇴 성공 시 파일에 내용 저장 역할
    매개변수: string withdrawId -> 파일에 저장할 id를 위한 매개변수
    반환값: X
*/
void WithdrawUI::showWithdrawId(string withdrawId) {
    fout << "> " << withdrawId << endl << endl;        // 파일에 내용 기입
}

/*
    함수 이름 : withdrawMember
    기능: 회원탈퇴를 실제로 진행하는 역할
    매개변수: MemberCollection& memberCollection -> 회원 탈퇴를 요청한 회원을 찾고, 정보를 삭제하기 위해 매개변수로 전달
              string& loginId -> 현재 login한 ID를 ""로 돌려놓기 위한 매개변수
              int memberType -> memberType을 0으로 돌려놓기 위한 매개변수
    반환값: X
*/
void Withdraw::withdrawMember(MemberCollection& memberCollection, string& loginId, int& memberType) {
    const char* id = loginId.c_str();       // const char*로 type 변환

    memberCollection.removeMember(id);      // 해당 id 제거

    loginId = "";           // 회원 탈퇴 시 로그아웃 상태로 되돌리기
    memberType = 0;         // 회원 탈퇴 시 회사 회원도 일반 회원도 아니므로 memberType = 0
}


/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void AddRecruitInfoUI::startInterface() {
    fout << "3.1. 채용 정보 등록" << endl;     // 유저가 입력한 내용 화면에 띄우기
}

void AddRecruitInfoUI::requestRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string inputEvent, string nowLogin) {
    // 다음에 사용될 함수의 매개변수에 char* type을 넣기 위해 string 자르기
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, work, targetNum, deadline;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // 공백을 기준으로 각각의 string을 변수에 담기

    const char* cwork = work.c_str();   // string type을 const char* type으로 변환
    const char* ctargetnum = targetNum.c_str();
    const char* cdeadline = deadline.c_str();
    const char* cnowlogin = nowLogin.c_str();

    AddRecruitInfo addRecruitInfor;            // Control class에서 addRecruitInfo 객체 생성
    addRecruitInfor.addRecruitInfo(recruitInfoCollection, cwork, ctargetnum, cdeadline, cnowlogin);
}

void AddRecruitInfoUI::showAddedRecruitInfo(string inputEvent) {
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, work, targetNum, deadline;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // 공백을 기준으로 각각의 string을 변수에 담기

    cout << "work : " << work << endl;
    cout << "targetNum : " << targetNum << endl;
    cout << "deadline : " << deadline << endl;

    fout << "> " << work << " " << targetNum << " " << deadline << endl << endl;       // 채용 정보 등록 성공 시, 파일에 저장
}

void AddRecruitInfo::addRecruitInfo(RecruitInfoCollection& recruitInfoCollection,
                                    const char* work, const char* targetNum, const char* deadline, const char* nowLogin) {
    RecruitInfo* newRecruitInfo = NULL;       // RecruitInfo Type의 새로운 객체 생성
    newRecruitInfo = new RecruitInfo(work, targetNum, deadline, nowLogin);  // 그 객체에 RecruitInfo 생성자 만들어 넣기
    recruitInfoCollection.addRecruitInfo(newRecruitInfo);  // recruitInfoCollection class가 갖고 있는 addRecruitInfo함수 호출하여 RecruitInfo 추가
}

/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void ViewAddedRecruitListUI::startInterface() {
    fout << "3.2. 등록된 채용 정보 조회" << endl;     // 유저가 입력한 내용 화면에 띄우기
}

void ViewAddedRecruitListUI::showRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string nowLogin) {
    const char* cnowlogin = nowLogin.c_str();

    ViewAddedRecruitList viewAddedRecruitList = ViewAddedRecruitList();


    // 컨트롤로 보내고, 컨트롤이 대답할 객체를 생성해야 할텐데..
    for (int i = 0; i < recruitInfoCollection.getRecruitInfoCollectionSize(); i++) {
        if (recruitInfoCollection.isMemberInRecruitInfoCollection(cnowlogin)) {
            fout << "> " << recruitInfoCollection.getRecruitAllInfo(i);
        }
    }
}


void program_exit() {
    fout << "6.1. 종료" << endl;  // 파일에 종료 내용 입력
}