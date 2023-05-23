#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Entity ���
#include "MemberCollection.h"
#include "Member.h"
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"
#include "CompanyMember.h"
#include "GeneralMember.h"

// ȸ������ ����ý��� ���
#include "LoginUI.h"
#include "Login.h"
#include "LogoutUI.h"
#include "Logout.h"
#include "RegisterUI.h"
#include "Register.h"
#include "WithdrawUI.h"
#include "Withdraw.h"

// ä���������� ����ý��� ���
#include "AddRecruitInfoUI.h"
#include "AddRecruitInfo.h"
#include "ViewAddedRecruitListUI.h"
#include "ViewAddedRecruitList.h"

// ä������ ����ý��� ���
#include "SearchRecruitInfoUI.h"
#include "SearchRecruitInfo.h"
#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

using namespace std;

//��� ����
#define endl '\n'
#define INPUT_FILE "example.txt"
#define OUTPUT_FILE "output.txt"

ifstream fin; // �ؽ�Ʈ ���� ����
ofstream fout; // �ؽ�Ʈ ���Ϸ� �����ϱ�

//�Լ� ����
void run();
void program_exit();

int main() {
	fin.open(INPUT_FILE);
	fout.open(OUTPUT_FILE);

    run();

    return 0;
}

/*
    �Լ� �̸� : run
    ���: ������ �Է� �ް�, �Է� ���� ���뿡 �°� �� �Լ��� ������. Actor�� ����
    �Ű�����: X
    ��ȯ��: X
*/
void run() {
    if (!fin || !fout) {
        cout << "������ �� �� �����ϴ�." << endl;
        return;
    }

    string inputEvent;  // ���� ���Ͽ��� ���� ���� �ִ� �� ��
    bool keepGoing = 1;  // keepGoing�� 1�̸� ����ؼ� ������ �а�, 0�� �Ǵ� ���� while�� Ż��

    MemberCollection memberCollection = MemberCollection(); // MemberCollection ����
    RecruitInfoCollection recruitInfoCollection = RecruitInfoCollection(); // RecruitInfoCollection ����
    ApplicationInfoCollection applicationInfoCollection = ApplicationInfoCollection(&memberCollection, &recruitInfoCollection); // ApplicationInfoCollection ����

    string currentLoginId = "";       // ���� �α��� ���� ID�� currentLoginId�� ����
    int currentMemberType = 0;         // 1�̸� ȸ�� ȸ��, 2�� �Ϲ� ȸ��
    // currentMemberType�� 1�� ������ ȸ�� ȸ�� ���� �ý����� �۵��ϰ�, �Ϲ� ȸ�� ���� �ý��ۿ� ���� �� �ƹ� �ൿ�� ���� ������,
    // currentMemberType�� 2�� ������ �Ϲ� ȸ�� ���� �ý����� �۵��ϰ�, ȸ�� ȸ�� ���� �ý��ۿ� ���� �� �ƹ� �ൿ�� ���� �ʴ´�.

    /*
    RegisterUI registerUI = RegisterUI(&fout);   // ȸ�� ������ ���� �ٿ���� ��ü ����
    WithdrawUI withdrawUI = WithdrawUI(&fout);   // ȸ�� Ż�� ���� �ٿ���� ��ü ����
    LoginUI loginUI = LoginUI(&fout);            // �α����� ���� �ٿ���� ��ü ����
    LogoutUI logoutUI = LogoutUI(&fout);         // �α׾ƿ��� ���� �ٿ���� ��ü ����
    AddRecruitInfoUI addRecruitInfoUI = AddRecruitInfoUI(&fout);     // ä�� ���� ����� ���� ��ü ����
    ViewAddedRecruitListUI viewAddedRecruitListUI = ViewAddedRecruitListUI(&fout);   // ����� ä�� ���� ����Ʈ ��ȸ�� ���� ��ü ����
    */


    while (keepGoing) { // �� �پ� �о����
        getline(fin, inputEvent);

        int firstEvent = inputEvent[0] - '0';       // 1. 1. 1���� �� ���� 1
        int secondEvent = inputEvent[2] - '0';      // 1. 1. 1���� �߰��� 1

        string tempId = currentLoginId;     // �α׾ƿ� �ϸ� ���Ͽ� currentLoginId ������ �ۼ��ؾ� �ϴµ�, �Ʒ� �Լ� ���� �� currentLoginId�� ������Ƿ�, ��� ��� ��
        // ȸ�� Ż���� ������ ��������

        switch (firstEvent) {
        case 1:
        {
            switch (secondEvent) {
            // ȸ�� ����
            case 1:
            {
                Register regist = Register(&memberCollection);
                regist.getRegisterUI()->init(&fout);
                regist.getRegisterUI()->startInterface();

                currentMemberType = regist.getRegisterUI()->selectMemberType(inputEvent); // 1. 1. 1���� �� ���� 1�� currentMemberType�� ����� 
                regist.getRegisterUI()->requestRegister(inputEvent, currentMemberType);   // Boundary�� �ִ� requestRegister �Լ� ȣ��
                regist.getRegisterUI()->showRegisterSuccessInterface(inputEvent, currentMemberType);        // ȸ������ �� ������ ���Ͽ� ����
            }
            break;
            // ȸ�� Ż��
            case 2:
            {
                Withdraw withdraw = Withdraw(&memberCollection);
                withdraw.getWithdrawUI()->init(&fout);
                withdraw.getWithdrawUI()->startInterface();    // �������̽� ����

                if (currentLoginId == "") // �α��� ���� ���� ���¶�� currentLoginId�� ""�̰�, ȸ�� Ż���� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;
                else {              // �α��� �Ǿ��� ������ ȸ�� Ż��
                    withdraw.getWithdrawUI()->requestWithdraw(currentLoginId, currentMemberType);     // Boundary�� �ִ� requestWithdraw �Լ� ȣ��
                    withdraw.getWithdrawUI()->showWithdrawId(tempId);           // ȸ��Ż�� �� ������ ���Ͽ� ����
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
            // �α���
            case 1:
            {
                Login login = Login(&memberCollection);
                login.getLoginUI()->init(&fout);
                login.getLoginUI()->startInterface();    // �������̽� ����

                if (currentLoginId != "")                 // ������ �α��� ���̸� �α��� �� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;

                else {
                    if (login.getLoginUI()->requestLogin(inputEvent, currentLoginId, currentMemberType))   // Boundary�� �ִ� requestLogin �Լ� ȣ��
                        login.getLoginUI()->showLoginSuccessInterface(inputEvent);      // �α��� ���� �� ���Ͽ� ������ ���� �ۼ�
                    else
                        login.getLoginUI()->showLoginFailInterface();           // �α��� ���� �� ���Ͽ� ������ ���� �ۼ�

                    //cout << "currentLoginId : " << currentLoginId << endl;      // ���� �α����ϰ� �ִ� ����� �������� Console â�� �� ��
                    //cout << "after login currentMemberType : " << currentMemberType << endl;
                    break;
                }
            }
            break;
            // �α׾ƿ�
            case 2:
            {
                Logout logout = Logout();
                logout.getLogoutUI()->init(&fout);
                logout.getLogoutUI()->startInterface();    // �������̽� ����

                if (currentLoginId == "")               // �α��� ���� ���� ���¶�� �α׾ƿ��� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;
                else {              // �α��� �� ���¿����� �α׾ƿ� ���� ����!
                    logout.getLogoutUI()->requestLogout(currentLoginId, currentMemberType);       // �α��� �� ���¶�� �α׾ƿ� ���� ����. Boundary�� �ִ� requestLogout �Լ� ȣ��
                    logout.getLogoutUI()->showLogoutId(tempId);        // �α׾ƿ� �� ���Ͽ� ������ ���� �ۼ�
                    //cout << "currentLoginId : " << currentLoginId << endl;      // �α׾ƿ��� �� �Ǿ����� Ȯ���ϱ� ���� Console â�� �� ��
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
            // ä�� ���� ���
            case 1:
            {
                AddRecruitInfo addRecruitInfo = AddRecruitInfo(&recruitInfoCollection);
                addRecruitInfo.getAddRecruitInfoUI()->init(&fout);
                addRecruitInfo.getAddRecruitInfoUI()->startInterface();    // �������̽� ����

                if (currentMemberType == 2)        // �Ϲ� ȸ���� �� �۾� ���� �Ұ���
                    break;
                else {
                	addRecruitInfo.getAddRecruitInfoUI()->requestRecruitInfo(inputEvent, currentLoginId);     // recruitInfoCollection ���Ϳ� recruitInfo�� �߰��ϱ� ���� �Լ� ȣ��
                	addRecruitInfo.getAddRecruitInfoUI()->showAddedRecruitInfo(inputEvent);         // ����� ä�� ������ ���Ͽ� ����
                    //recruitInfoCollection.getAllRecruitInfoCollection(); // ���� ��ϵ� ä�� ������ �������� �ִ��� Ȯ���ϱ� ���� ��
                }
                break;
            }
            // ä�� ���� ��ȸ
            case 2:
            {
                ViewAddedRecruitList viewAddedRecruitList = ViewAddedRecruitList(&recruitInfoCollection);
                viewAddedRecruitList.getViewAddedRecruitListUI()->init(&fout);
                viewAddedRecruitList.getViewAddedRecruitListUI()->startInterface();     // �������̽� ����

                if (currentMemberType == 2)
                    break;
                else {
                    viewAddedRecruitList.getViewAddedRecruitListUI()->showRecruitInfo(currentLoginId);      // ����� ä�� ���� ��� ��ȸ
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
            // ä�� ���� �˻�
            case 1:
            {
                SearchRecruitInfo searchRecruitInfo = SearchRecruitInfo(&recruitInfoCollection,&memberCollection);
                searchRecruitInfo.getSearchRecruitInfoUI()->init(&fout);
                searchRecruitInfo.getSearchRecruitInfoUI()->startInterface(); // �������̽� ����
                
                if (currentMemberType == 1) // ȸ�� ȸ���� �� �۾� ���� �Ұ���
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
                program_exit();     // ���α׷� �����ϱ� ���� �Լ� ȣ��
                keepGoing = 0;      // keepGoing�� 0���� ���������ν� while�� Ż��
                break;
            }
            break;
            }
			break;
        }
        break;
        }

        //memberCollection.getAllMemberCollection(); // ���� ����� �������� �ִ��� Ȯ���ϱ� ���� ��
        
        }
    }
	fin.close(); // ���� �ݱ�
	fout.close(); // ���� �ݱ�
}

    void program_exit() {
        fout << "6.1. ����" << endl;  // ���Ͽ� ���� ���� �Է�
    }
