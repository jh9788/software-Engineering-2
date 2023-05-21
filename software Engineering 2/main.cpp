
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Run.h"
#include "MemberCollection.h"
#include "Member.h"
#include "RecruitInfoCollection.h"
#include "RecruitInfo.h"
#include "CompanyMember.h"
#include "GeneralMember.h"

#define endl '\n'
#define INPUT_FILE "example.txt"
#define OUTPUT_FILE "output.txt"


ifstream fin(INPUT_FILE); // �ؽ�Ʈ ���� ����
ofstream fout(OUTPUT_FILE); // �ؽ�Ʈ ���Ϸ� �����ϱ�

void run();
void program_exit();


int main() {

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
    int keepGoing = 1;  // keepGoing�� 1�̸� ����ؼ� ������ �а�, 0�� �Ǵ� ���� while�� Ż��
    MemberCollection memberCollection = MemberCollection();     // MemberCollection ����
    RecruitInfoCollection recruitInfoCollection = RecruitInfoCollection();      // RecruitInfoCollection ����
    string nowLogin = "";       // ���� �α��� ���� ID�� nowLogin�� ����

    int memberType = 0;         // 1�̸� ȸ�� ȸ��, 2�� �Ϲ� ȸ��
    // memberType�� 1�� ������ ȸ�� ȸ�� ���� �ý����� �۵��ϰ�, �Ϲ� ȸ�� ���� �ý��ۿ� ���� �� �ƹ� �ൿ�� ���� ������,
    // memberType�� 2�� ������ �Ϲ� ȸ�� ���� �ý����� �۵��ϰ�, ȸ�� ȸ�� ���� �ý��ۿ� ���� �� �ƹ� �ൿ�� ���� �ʴ´�.


    RegisterUI registerUI = RegisterUI();   // ȸ�� ������ ���� �ٿ���� ��ü ����
    WithdrawUI withdrawUI = WithdrawUI();   // ȸ�� Ż�� ���� �ٿ���� ��ü ����
    LoginUI loginUI = LoginUI();            // �α����� ���� �ٿ���� ��ü ����
    LogoutUI logoutUI = LogoutUI();         // �α׾ƿ��� ���� �ٿ���� ��ü ����
    AddRecruitInfoUI addRecruitInfoUI = AddRecruitInfoUI();     // ä�� ���� ����� ���� ��ü ����
    ViewAddedRecruitListUI viewAddedRecruitListUI = ViewAddedRecruitListUI();   // ����� ä�� ���� ����Ʈ ��ȸ�� ���� ��ü ����


    while (keepGoing) { // �� �پ� �о����
        getline(fin, inputEvent);

        int firstEvent = inputEvent[0] - '0';       // 1. 1. 1���� �� ���� 1
        int secondEvent = inputEvent[2] - '0';      // 1. 1. 1���� �߰��� 1
        string tempId = nowLogin;     // �α׾ƿ� �ϸ� ���Ͽ� nowLogin ������ �ۼ��ؾ� �ϴµ�, �Ʒ� �Լ� ���� �� nowLogin�� ������Ƿ�, ��� ��� ��
        // ȸ�� Ż���� ������ ��������

        switch (firstEvent) {
        case 1:
            switch (secondEvent) {
                // ȸ�� ����
            case 1:
                registerUI.startInterface();    // �������̽� ����

                memberType = registerUI.selectMemberType(inputEvent);       // 1. 1. 1���� �� ���� 1�� memberType�� �����
                registerUI.requestRegister(memberCollection, inputEvent, memberType);   // Boundary�� �ִ� requestRegister �Լ� ȣ��
                registerUI.showRegisterSuccessInterface(inputEvent, memberType);        // ȸ������ �� ������ ���Ͽ� ����
                break;
                // ȸ�� Ż��
            case 2:
                withdrawUI.startInterface();    // �������̽� ����

                if (nowLogin == "") // �α��� ���� ���� ���¶�� nowLogin�� ""�̰�, ȸ�� Ż���� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;
                else {              // �α��� �Ǿ��� ������ ȸ�� Ż��
                    withdrawUI.requestWithdraw(memberCollection, nowLogin, memberType);     // Boundary�� �ִ� requestWithdraw �Լ� ȣ��
                    withdrawUI.showWithdrawId(tempId);           // ȸ��Ż�� �� ������ ���Ͽ� ����
                    //cout << "after withdraw memberType : " << memberType << endl;
                    break;
                }
            }
            break;
        case 2:
            switch (secondEvent) {
                // �α���
            case 1:
                loginUI.startInterface();   // �������̽� ����

                if (nowLogin != "")                 // ������ �α��� ���̸� �α��� �� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;

                else {
                    if (loginUI.requestLogin(memberCollection, inputEvent, nowLogin, memberType))   // Boundary�� �ִ� requestLogin �Լ� ȣ��
                        loginUI.showLoginSuccessInterface(inputEvent);      // �α��� ���� �� ���Ͽ� ������ ���� �ۼ�
                    else
                        loginUI.showLoginFailInterface();           // �α��� ���� �� ���Ͽ� ������ ���� �ۼ�

                    //cout << "nowLogin : " << nowLogin << endl;      // ���� �α����ϰ� �ִ� ����� �������� Console â�� �� ��
                    //cout << "after login memberType : " << memberType << endl;
                    break;
                }
                break;
                // �α׾ƿ�
            case 2:
                logoutUI.startInterface();  // �������̽� ����

                if (nowLogin == "")               // �α��� ���� ���� ���¶�� �α׾ƿ��� �� �����Ƿ�, �ƹ� �͵� ���� �ʰ� �ǳʶ�
                    break;
                else {              // �α��� �� ���¿����� �α׾ƿ� ���� ����!
                    logoutUI.requestLogout(nowLogin, memberType);       // �α��� �� ���¶�� �α׾ƿ� ���� ����. Boundary�� �ִ� requestLogout �Լ� ȣ��
                    logoutUI.showLogoutId(tempId);        // �α׾ƿ� �� ���Ͽ� ������ ���� �ۼ�
                    //cout << "nowLogin : " << nowLogin << endl;      // �α׾ƿ��� �� �Ǿ����� Ȯ���ϱ� ���� Console â�� �� ��
                    //cout << "after logout memberType : " << memberType << endl;
                    break;
                }
                break;
            }
            break;
        case 3:
            switch (secondEvent) {
                // ä�� ���� ���
            case 1:
                addRecruitInfoUI.startInterface();  // �������̽� ����

                if (memberType == 2)        // �Ϲ� ȸ���� �� �۾� ���� �Ұ���
                    break;
                else {
                    addRecruitInfoUI.requestRecruitInfo(recruitInfoCollection, inputEvent, nowLogin);     // recruitInfoCollection ���Ϳ� recruitInfo�� �߰��ϱ� ���� �Լ� ȣ��
                    addRecruitInfoUI.showAddedRecruitInfo(inputEvent);
                }
                break;
                // ä�� ���� ��ȸ
            case 2:
                viewAddedRecruitListUI.startInterface();    // �������̽� ����

                if (memberType == 2)        // �Ϲ� ȸ���� �� �۾� ���� �Ұ���
                    break;
                else {
                    viewAddedRecruitListUI.showRecruitInfo(recruitInfoCollection, nowLogin);     // recruitInfoCollection ���͸� ��ȸ�ϱ� ���� �Լ� ȣ��
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
                program_exit();     // ���α׷� �����ϱ� ���� �Լ� ȣ��
                keepGoing = 0;      // keepGoing�� 0���� ���������ν� while�� Ż��
                break;
            }
            break;
        }
    }

    //memberCollection.getAllMemberCollection(); // ���� ����� �������� �ִ��� Ȯ���ϱ� ���� ��
    recruitInfoCollection.getAllRecruitInfoCollection(); // ���� ��ϵ� ä�� ������ �������� �ִ��� Ȯ���ϱ� ���� ��

    fin.close(); // ���� �ݱ�
    fout.close(); // ���� �ݱ�
}


void program_exit() {
    fout << "6.1. ����" << endl;  // ���Ͽ� ���� ���� �Է�
}