#include "LoginUI.h"
#include "Login.h"
#include <string>
using namespace std;

/*
	�Լ� �̸� : LoginUI
	���: ������
	�Ű�����: Login* inputControl -> ��Ʈ�� ������
	��ȯ��: X
*/
LoginUI::LoginUI(Login* inputControl)
{
    control = inputControl;
}

/*
    �Լ� �̸� : init
    ���: 
    �Ű�����: 
    ��ȯ��: X
*/
void LoginUI::init(ofstream* inputFout)
{
    fout = inputFout;
}


/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void LoginUI::startInterface() {
    string loginStr = "2.1. �α���";
    *fout << loginStr << endl;  // ������ �Է��� ���� ȭ�鿡 ����

    
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
bool LoginUI::requestLogin(string inputEvent, string& loginId, int& memberType) {
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