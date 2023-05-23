#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Entity 헤더
#include "MemberCollection.h"
#include "Member.h"
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"
#include "CompanyMember.h"
#include "GeneralMember.h"

// 회원관리 서브시스템 헤더
#include "LoginUI.h"
#include "Login.h"
#include "LogoutUI.h"
#include "Logout.h"
#include "RegisterUI.h"
#include "Register.h"
#include "WithdrawUI.h"
#include "Withdraw.h"

// 채용정보관리 서브시스템 헤더
#include "AddRecruitInfoUI.h"
#include "AddRecruitInfo.h"
#include "ViewAddedRecruitListUI.h"
#include "ViewAddedRecruitList.h"

// 채용지원 서브시스템 헤더
#include "SearchRecruitInfoUI.h"
#include "SearchRecruitInfo.h"
#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

using namespace std;

//상수 선언
#define endl '\n'
#define INPUT_FILE "example.txt"
#define OUTPUT_FILE "output.txt"

ifstream fin; // 텍스트 파일 열기
ofstream fout; // 텍스트 파일로 추출하기

//함수 선언
void run();
void program_exit();

int main() {
	fin.open(INPUT_FILE);
	fout.open(OUTPUT_FILE);

    run();

    return 0;
}

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
    bool keepGoing = 1;  // keepGoing이 1이면 계속해서 파일을 읽고, 0이 되는 순간 while문 탈출

    MemberCollection memberCollection = MemberCollection(); // MemberCollection 생성
    RecruitInfoCollection recruitInfoCollection = RecruitInfoCollection(); // RecruitInfoCollection 생성
    ApplicationInfoCollection applicationInfoCollection = ApplicationInfoCollection(&memberCollection, &recruitInfoCollection); // ApplicationInfoCollection 생성

    string currentLoginId = "";       // 현재 로그인 중인 ID를 currentLoginId에 저장
    int currentMemberType = 0;         // 1이면 회사 회원, 2면 일반 회원
    // currentMemberType이 1일 때에는 회사 회원 관련 시스템이 작동하고, 일반 회원 관련 시스템에 접근 시 아무 행동도 하지 않으며,
    // currentMemberType이 2일 때에는 일반 회원 관련 시스템이 작동하고, 회사 회원 관련 시스템에 접근 시 아무 행동도 하지 않는다.

    /*
    RegisterUI registerUI = RegisterUI(&fout);   // 회원 가입을 위한 바운더리 객체 생성
    WithdrawUI withdrawUI = WithdrawUI(&fout);   // 회원 탈퇴를 위한 바운더리 객체 생성
    LoginUI loginUI = LoginUI(&fout);            // 로그인을 위한 바운더리 객체 생성
    LogoutUI logoutUI = LogoutUI(&fout);         // 로그아웃을 위한 바운더리 객체 생성
    AddRecruitInfoUI addRecruitInfoUI = AddRecruitInfoUI(&fout);     // 채용 정보 등록을 위한 객체 생성
    ViewAddedRecruitListUI viewAddedRecruitListUI = ViewAddedRecruitListUI(&fout);   // 등록한 채용 정보 리스트 조회를 위한 객체 생성
    */


    while (keepGoing) { // 한 줄씩 읽어오기
        getline(fin, inputEvent);

        int firstEvent = inputEvent[0] - '0';       // 1. 1. 1에서 맨 앞의 1
        int secondEvent = inputEvent[2] - '0';      // 1. 1. 1에서 중간의 1

        string tempId = currentLoginId;     // 로그아웃 하면 파일에 currentLoginId 내용을 작성해야 하는데, 아래 함수 실행 시 currentLoginId이 사라지므로, 잠시 담아 둠
        // 회원 탈퇴할 때에도 마찬가지

        switch (firstEvent) {
        case 1:
        {
            switch (secondEvent) {
            // 회원 가입
            case 1:
            {
                Register regist = Register(&memberCollection);
                regist.getRegisterUI()->init(&fout);
                regist.getRegisterUI()->startInterface();

                currentMemberType = regist.getRegisterUI()->selectMemberType(inputEvent); // 1. 1. 1에서 맨 뒤의 1이 currentMemberType에 저장됨 
                regist.getRegisterUI()->requestRegister(inputEvent, currentMemberType);   // Boundary에 있는 requestRegister 함수 호출
                regist.getRegisterUI()->showRegisterSuccessInterface(inputEvent, currentMemberType);        // 회원가입 시 내용을 파일에 저장
            }
            break;
            // 회원 탈퇴
            case 2:
            {
                Withdraw withdraw = Withdraw(&memberCollection);
                withdraw.getWithdrawUI()->init(&fout);
                withdraw.getWithdrawUI()->startInterface();    // 인터페이스 시작

                if (currentLoginId == "") // 로그인 하지 않은 상태라면 currentLoginId은 ""이고, 회원 탈퇴할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;
                else {              // 로그인 되었을 때에만 회원 탈퇴
                    withdraw.getWithdrawUI()->requestWithdraw(currentLoginId, currentMemberType);     // Boundary에 있는 requestWithdraw 함수 호출
                    withdraw.getWithdrawUI()->showWithdrawId(tempId);           // 회원탈퇴 시 내용을 파일에 저장
                    //cout << "after withdraw memberType : " << memberType << endl;
                    break;
                }
            }
            break;
            }
        }
        break;
        case 2:
        {
            switch (secondEvent) {
            // 로그인
            case 1:
            {
                Login login = Login(&memberCollection);
                login.getLoginUI()->init(&fout);
                login.getLoginUI()->startInterface();    // 인터페이스 시작

                if (currentLoginId != "")                 // 누군가 로그인 중이면 로그인 할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;

                else {
                    if (login.getLoginUI()->requestLogin(inputEvent, currentLoginId, currentMemberType))   // Boundary에 있는 requestLogin 함수 호출
                        login.getLoginUI()->showLoginSuccessInterface(inputEvent);      // 로그인 성공 시 파일에 저장할 내용 작성
                    else
                        login.getLoginUI()->showLoginFailInterface();           // 로그인 실패 시 파일에 저장할 내용 작성

                    //cout << "currentLoginId : " << currentLoginId << endl;      // 지금 로그인하고 있는 사람이 누구인지 Console 창에 찍어본 것
                    //cout << "after login currentMemberType : " << currentMemberType << endl;
                    break;
                }
            }
            break;
            // 로그아웃
            case 2:
            {
                Logout logout = Logout();
                logout.getLogoutUI()->init(&fout);
                logout.getLogoutUI()->startInterface();    // 인터페이스 시작

                if (currentLoginId == "")               // 로그인 하지 않은 상태라면 로그아웃할 수 없으므로, 아무 것도 하지 않고 건너뜀
                    break;
                else {              // 로그인 한 상태에서만 로그아웃 진행 가능!
                    logout.getLogoutUI()->requestLogout(currentLoginId, currentMemberType);       // 로그인 한 상태라면 로그아웃 진행 가능. Boundary에 있는 requestLogout 함수 호출
                    logout.getLogoutUI()->showLogoutId(tempId);        // 로그아웃 시 파일에 저장할 내용 작성
                    //cout << "currentLoginId : " << currentLoginId << endl;      // 로그아웃이 잘 되었는지 확인하기 위해 Console 창에 찍어본 것
                    //cout << "after logout currentMemberType : " << currentMemberType << endl;
                    break;
                }
            }
            break;
            }
        break;
        case 3:
        {
            switch (secondEvent) {
            // 채용 정보 등록
            case 1:
            {
                AddRecruitInfo addRecruitInfo = AddRecruitInfo(&recruitInfoCollection);
                addRecruitInfo.getAddRecruitInfoUI()->init(&fout);
                addRecruitInfo.getAddRecruitInfoUI()->startInterface();    // 인터페이스 시작

                if (currentMemberType == 2)        // 일반 회원은 이 작업 수행 불가능
                    break;
                else {
                	addRecruitInfo.getAddRecruitInfoUI()->requestRecruitInfo(inputEvent, currentLoginId);     // recruitInfoCollection 벡터에 recruitInfo를 추가하기 위한 함수 호출
                	addRecruitInfo.getAddRecruitInfoUI()->showAddedRecruitInfo(inputEvent);         // 등록한 채용 정보를 파일에 쓰기
                    //recruitInfoCollection.getAllRecruitInfoCollection(); // 현재 등록된 채용 정보가 누구누구 있는지 확인하기 위한 애
                }
                break;
            }
            // 채용 정보 조회
            case 2:
            {
                ViewAddedRecruitList viewAddedRecruitList = ViewAddedRecruitList(&recruitInfoCollection);
                viewAddedRecruitList.getViewAddedRecruitListUI()->init(&fout);
                viewAddedRecruitList.getViewAddedRecruitListUI()->startInterface();     // 인터페이스 시작

                if (currentMemberType == 2)
                    break;
                else {
                    viewAddedRecruitList.getViewAddedRecruitListUI()->showRecruitInfo(currentLoginId);      // 등록한 채용 정보 모두 조회
                    break;
                }
            }
			break;
            }
        break;
        }
        case 4:
        {
            switch (secondEvent) {
            // 채용 정보 검색
            case 1:
            {
                SearchRecruitInfo searchRecruitInfo = SearchRecruitInfo(&recruitInfoCollection,&memberCollection);
                searchRecruitInfo.getSearchRecruitInfoUI()->init(&fout);
                searchRecruitInfo.getSearchRecruitInfoUI()->startInterface(); // 인터페이스 시작
                
                if (currentMemberType == 1) // 회사 회원은 이 작업 수행 불가능
                    break;
                else {
                    searchRecruitInfo.getSearchRecruitInfoUI()->showSearchRecruitInfo(inputEvent);
                    break;
                }
            }
            case 2:
            {
                break;
            }

            }
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            switch (secondEvent) {
            case 1:
            {
                program_exit();     // 프로그램 종료하기 위한 함수 호출
                keepGoing = 0;      // keepGoing을 0으로 설정함으로써 while문 탈출
                break;
            }
            break;
            }
			break;
        }
        break;
        }

        //memberCollection.getAllMemberCollection(); // 현재 멤버가 누구누구 있는지 확인하기 위한 애
        
        }
    }
	fin.close(); // 파일 닫기
	fout.close(); // 파일 닫기
}

    void program_exit() {
        fout << "6.1. 종료" << endl;  // 파일에 종료 내용 입력
    }
