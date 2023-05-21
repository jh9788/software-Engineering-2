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


ifstream fin(INPUT_FILE); // �ؽ�Ʈ ���� ����
ofstream fout(OUTPUT_FILE); // �ؽ�Ʈ ���Ϸ� �����ϱ�


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


/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void RegisterUI::startInterface() {
    fout << "1.1. ȸ������" << endl;  // ������ �Է��� ���� ȭ�鿡 ����. �̿� ���� ������ boundary���� ����
}

/*
    �Լ� �̸� : selectMemberType
    ���: ������ �� ���� �а�, ȸ���� Type�� �°� ���� ��ȯ
    �Ű�����: string inputEvent -> ���Ͽ��� ��� �о���� �� ���� ����
    ��ȯ��: ȸ�� ȸ���̸� 1, �Ϲ� ȸ���̸� 2�� ��ȯ
*/
int RegisterUI::selectMemberType(string inputEvent) {
    int thirdEvent = inputEvent[4] - '0';

    if (thirdEvent == 1)
        return 1;
    else if (thirdEvent == 2)
        return 2;
}

/*
    �Լ� �̸� : requestRegister
    ���: ȸ������ Boundary�� �Լ��ν�, ȸ�� ���� Control���� ȸ�� ������ ��û�ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� ���� �Ϸ� ��, memberCollection�� ����
              string inputEvent -> ���Ͽ��� ��� �о���� �� ���� ����
              int memberType -> 1: ȸ�� ȸ��, 2: �Ϲ� ȸ��
    ��ȯ��: X
*/
void RegisterUI::requestRegister(MemberCollection& memberCollection, string inputEvent, int memberType) {
    // ������ ���� �Լ��� �Ű������� char* type�� �ֱ� ���� string �ڸ���
    stringstream input(inputEvent);     // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, num3, name, num, id, pwd;    // ������ �������� �߶��� �ֵ��� ���� string ���� ����

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // ������ �������� �� ������ string�� �־���

    const char* cname = name.c_str();   // string type�� const char* type���� ��ȯ
    const char* cnum = num.c_str();
    const char* cid = id.c_str();
    const char* cpwd = pwd.c_str();

    Register regist;            // Control class���� regist ��ü ���� (register�� ������̹Ƿ� regist��� ���� ������ ��ü)

    // 1.1.1���� 1.1.2������ �� switch case������ ����
    switch (memberType) {
    case 1:             // ȸ�� ȸ���� ���
        regist.registerCompanyMember(memberCollection, cname, cnum, cid, cpwd, 1);     // Control�� �Լ��� registerCompanyMember ȣ��
        break;
    case 2:             // �Ϲ� ȸ���� ���
        regist.registerGeneralMember(memberCollection, cname, cnum, cid, cpwd, 2);     // Control�� �Լ��� registerGeneralMember ȣ��
        break;
    }
}

/*
    �Լ� �̸� : showRegisterSuccessInterface
    ���: ȸ�� ���� �Ϸ� �� ���Ͽ� ���� ���� ����
    �Ű�����: string inputEvent -> ���Ͽ� ������ name, num, id, pwd�� �Ľ��ϱ� ���� �Ű�����
              memberType -> ȸ�� ȸ��, �Ϲ� ȸ���� �´� ��ȣ�� ���Ͽ� �����ϱ� ���� �Ű�����
    ��ȯ��: X
*/
void RegisterUI::showRegisterSuccessInterface(string inputEvent, int memberType) {
    // ���Ͽ� ������ �����ϱ� ���� string �ڸ���
    stringstream input(inputEvent);     // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, num3, name, num, id, pwd;    // ������ �������� �߶��� �ֵ��� ���� string ���� ����

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // ������ �������� �� ������ string�� �־���

    fout << "> " << memberType << " " << name << " " << num << " " << id << " " << pwd << endl << endl;    // ���Ͽ� ȸ�� ���� ���� ����
}

/*
    �Լ� �̸� : registerCompanyMember
    ���: ȸ�� ȸ���� ���� �����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� ���� �Ϸ� ��, memberCollection�� ����
              const char* name -> �̸�
              const char* num -> ����� ��ȣ
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 1 (ȸ�� ȸ��)
    ��ȯ��: X
*/
void Register::registerCompanyMember(MemberCollection& memberCollection,
                                     const char* name, const char* num, const char* id, const char* pwd, int memberType)
{
    Member* newMember = NULL;       // Member Type�� ���ο� ��ü ����
    newMember = new CompanyMember(name, num, id, pwd, memberType);  // �� ��ü�� CompanyMember ������ ����� �ֱ�
    memberCollection.addMember(newMember);  // memberCollection class�� ���� �ִ� addMember�Լ� ȣ���Ͽ� Member �߰�
}

/*
    �Լ� �̸� : registerGeneralMember
    ���: �Ϲ� ȸ���� ���� �����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� ���� �Ϸ� ��, memberCollection�� ����
              const char* name -> �̸�
              const char* num -> �ֹε�Ϲ�ȣ
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 2 (�Ϲ� ȸ��)
    ��ȯ��: X
*/
void Register::registerGeneralMember(MemberCollection& memberCollection,
                                     const char* name, const char* num, const char* id, const char* pwd, int memberType)
{
    Member* newMember = NULL;       // Member Type�� ���ο� ��ü ����
    newMember = new CompanyMember(name, num, id, pwd, memberType);  // �� ��ü�� GeneralMember ������ ����� �ֱ�
    memberCollection.addMember(newMember);  // memberCollection class�� ���� �ִ� addMember�Լ� ȣ���Ͽ� Member �߰�
}

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void LoginUI::startInterface() {
    fout << "2.1. �α���" << endl;  // ������ �Է��� ���� ȭ�鿡 ����
}

/*
    �Լ� �̸� : requestLogin
    ���: �α��� Boundary�� �Լ��ν�, �α����� Control�� �α����� ��û�ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> memberCollection�� ����Ǿ��ִ� ������ Ȯ���ϱ� ���� ������ argument
              const char* name -> �̸�
              const char* num -> �ֹε�Ϲ�ȣ
              const char* id -> ID
              const char* pwd -> Password
              string& loginId -> ���� login�� ID�� ������ ���� ���� ����
              int memberType -> ȸ�� ȸ��, �Ϲ� ȸ���� ���� memberType���� ������ ���� ���� ����
    ��ȯ��: bool
*/
bool LoginUI::requestLogin(MemberCollection& memberCollection, string inputEvent, string& loginId, int& memberType) {
    // ������ ȣ���� �Լ��� �Ű������� const char* type�� �ֱ� ���� �۾�
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, id, pwd;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> id >> pwd;     // ������ �������� ������ string�� ������ ���

    const char* cid = id.c_str();       // string�� char* �������� ��ȯ
    const char* cpwd = pwd.c_str();

    Login login = Login();          // Login ��ü ����

    if (login.verifyLogin(memberCollection, cid, cpwd, loginId, memberType))
        return true;
    else
        return false;

}

/*
    �Լ� �̸� : showLoginSuccessInterface
    ���: �α��� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: string inputEvent -> ���Ͽ� ������ id�� pwd�� �Ľ��ϱ� ���� �Ű�����
    ��ȯ��: X
*/
void LoginUI::showLoginSuccessInterface(string inputEvent) {
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, id, pwd;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> id >> pwd;     // ������ �������� ������ string�� ������ ���

    fout << "> " << id << " " << pwd << endl << endl;       // �α��� ���� ��, ������ ���� (id, pwd)�� ���Ͽ� ����
}

/*
    �Լ� �̸� : showLoginFailInterface
    ���: �α��� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: X
    ��ȯ��: X
*/
void LoginUI::showLoginFailInterface() {
    fout << endl << endl;        // �α��� ���� ��, ���ุ �� �� ������ ����� ���Ͽ� ����
}

/*
    �Լ� �̸� : verifyLogin
    ���: �α��� �� �� �ִ� �ڰ��� ���߾����� Ȯ���ϴ� �Լ�
    �Ű�����: MemberCollection& memberCollection -> memberCollection�� ����Ǿ��ִ� ������ Ȯ���ϱ� ���� ������ argument
              const char* name -> �̸�
              const char* num -> �ֹε�Ϲ�ȣ
              const char* id -> ID
              const char* pwd -> Password
              string& loginId -> ���� login�� ID�� ������ ���� ���� ����
              int memberType -> ȸ�� ȸ��, �Ϲ� ȸ���� ���� memberType���� ������ ���� ���� ����
    ��ȯ��: bool
*/
bool Login::verifyLogin(MemberCollection& memberCollection, const char* id, const char* pwd, string& loginId, int& memberType) {
    // ȸ���� �´� ���
    if (memberCollection.isMember(id, pwd)) {
        loginId = id;           // loginId�� ��� �α����� �õ��ߴ� id�� ����
        memberType = memberCollection.getMemberType(id, pwd);       // memberType�� ���� �α��� �� member�� type�� ����
        return true;
    }
    // ȸ���� �ƴ� ���
    else
        return false;
}

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void LogoutUI::startInterface() {
    fout << "2.2. �α׾ƿ�" << endl;  // ������ �Է��� ���� ȭ�鿡 ����
}

/*
    �Լ� �̸� : requestLogout
    ���: �α׾ƿ� Boundary�� �Լ��ν�, �α׾ƿ��� Control�� �α׾ƿ��� ��û�ϴ� ����
    �Ű�����: string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void LogoutUI::requestLogout(string& loginId, int& memberType) {
    Logout logout = Logout();   // logout ��ü ����

    logout.logoutMember(loginId, memberType);   // logoutMember �Լ� ȣ��
}

/*
    �Լ� �̸� : showLogoutId
    ���: �α׾ƿ� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: string logoutId -> ���Ͽ� ������ id�� ���� �Ű�����
    ��ȯ��: X
*/
void LogoutUI::showLogoutId(string logoutId) {
    fout << "> " << logoutId << endl << endl;    // ���Ͽ� ���� ����.
}

/*
    �Լ� �̸� : logoutMember
    ���: �α׾ƿ��� ������ �����ϴ� ����
    �Ű�����: string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű� ����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void Logout::logoutMember(string& loginId, int& memberType) {
    loginId = "";   // �α׾ƿ� �� nowLogin = ""�� �ǵ����ֱ�
    memberType = 0; // �α׾ƿ� �� memberType�� ȸ�� ȸ���� �Ϲ� ȸ���� �ƴϹǷ� 0���� �ٲ��ֱ�
}

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void WithdrawUI::startInterface() {
    fout << "1.2. ȸ��Ż��" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}

/*
    �Լ� �̸� : requestWithdraw
    ���: ȸ��Ż�� Boundary�� �Լ��ν�, ȸ��Ż���� Control�� ȸ��Ż�� ��û�ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� Ż�� ��û�� ȸ���� ã��, ������ �����ϱ� ���� �Ű������� ����
              string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void WithdrawUI::requestWithdraw(MemberCollection& memberCollection, string& loginId, int& memberType) {
    Withdraw withdraw = Withdraw();     // withdraw ��ü ����
    withdraw.withdrawMember(memberCollection, loginId, memberType);     // ȸ�� Ż�� ���� �Լ� ȣ��
}

/*
    �Լ� �̸� : showWithdrawId
    ���: ȸ�� Ż�� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: string withdrawId -> ���Ͽ� ������ id�� ���� �Ű�����
    ��ȯ��: X
*/
void WithdrawUI::showWithdrawId(string withdrawId) {
    fout << "> " << withdrawId << endl << endl;        // ���Ͽ� ���� ����
}

/*
    �Լ� �̸� : withdrawMember
    ���: ȸ��Ż�� ������ �����ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� Ż�� ��û�� ȸ���� ã��, ������ �����ϱ� ���� �Ű������� ����
              string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void Withdraw::withdrawMember(MemberCollection& memberCollection, string& loginId, int& memberType) {
    const char* id = loginId.c_str();       // const char*�� type ��ȯ

    memberCollection.removeMember(id);      // �ش� id ����

    loginId = "";           // ȸ�� Ż�� �� �α׾ƿ� ���·� �ǵ�����
    memberType = 0;         // ȸ�� Ż�� �� ȸ�� ȸ���� �Ϲ� ȸ���� �ƴϹǷ� memberType = 0
}


/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void AddRecruitInfoUI::startInterface() {
    fout << "3.1. ä�� ���� ���" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}

void AddRecruitInfoUI::requestRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string inputEvent, string nowLogin) {
    // ������ ���� �Լ��� �Ű������� char* type�� �ֱ� ���� string �ڸ���
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, work, targetNum, deadline;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // ������ �������� ������ string�� ������ ���

    const char* cwork = work.c_str();   // string type�� const char* type���� ��ȯ
    const char* ctargetnum = targetNum.c_str();
    const char* cdeadline = deadline.c_str();
    const char* cnowlogin = nowLogin.c_str();

    AddRecruitInfo addRecruitInfor;            // Control class���� addRecruitInfo ��ü ����
    addRecruitInfor.addRecruitInfo(recruitInfoCollection, cwork, ctargetnum, cdeadline, cnowlogin);
}

void AddRecruitInfoUI::showAddedRecruitInfo(string inputEvent) {
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, work, targetNum, deadline;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // ������ �������� ������ string�� ������ ���

    cout << "work : " << work << endl;
    cout << "targetNum : " << targetNum << endl;
    cout << "deadline : " << deadline << endl;

    fout << "> " << work << " " << targetNum << " " << deadline << endl << endl;       // ä�� ���� ��� ���� ��, ���Ͽ� ����
}

void AddRecruitInfo::addRecruitInfo(RecruitInfoCollection& recruitInfoCollection,
                                    const char* work, const char* targetNum, const char* deadline, const char* nowLogin) {
    RecruitInfo* newRecruitInfo = NULL;       // RecruitInfo Type�� ���ο� ��ü ����
    newRecruitInfo = new RecruitInfo(work, targetNum, deadline, nowLogin);  // �� ��ü�� RecruitInfo ������ ����� �ֱ�
    recruitInfoCollection.addRecruitInfo(newRecruitInfo);  // recruitInfoCollection class�� ���� �ִ� addRecruitInfo�Լ� ȣ���Ͽ� RecruitInfo �߰�
}

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void ViewAddedRecruitListUI::startInterface() {
    fout << "3.2. ��ϵ� ä�� ���� ��ȸ" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}

void ViewAddedRecruitListUI::showRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string nowLogin) {
    const char* cnowlogin = nowLogin.c_str();

    ViewAddedRecruitList viewAddedRecruitList = ViewAddedRecruitList();


    // ��Ʈ�ѷ� ������, ��Ʈ���� ����� ��ü�� �����ؾ� ���ٵ�..
    for (int i = 0; i < recruitInfoCollection.getRecruitInfoCollectionSize(); i++) {
        if (recruitInfoCollection.isMemberInRecruitInfoCollection(cnowlogin)) {
            fout << "> " << recruitInfoCollection.getRecruitAllInfo(i);
        }
    }
}


void program_exit() {
    fout << "6.1. ����" << endl;  // ���Ͽ� ���� ���� �Է�
}