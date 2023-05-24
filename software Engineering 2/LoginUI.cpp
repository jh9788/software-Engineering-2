#include "LoginUI.h"
#include "Login.h"
#include <string>
using namespace std;

/*
	�Լ� �̸� : LoginUI
	���: ������
	�Ű�����: Login* inputControl -> Control ������
	��ȯ��: X
*/
LoginUI::LoginUI(Login* inputControl)
{
    control = inputControl;
}

/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
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
    *fout << "2.1. �α���" << endl;  // ������ �Է��� ���� ȭ�鿡 ����
}

/*
    �Լ� �̸� : isLoginValid
    ���: �α��� Boundary�� �Լ��ν�, �α����� Control�� �α����� ��û�ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> memberCollection�� ����Ǿ��ִ� ������ Ȯ���ϱ� ���� ������ argument
              const char* name -> �̸�
              const char* num -> �ֹε�Ϲ�ȣ
              const char* id -> ID
              const char* pwd -> Password
              string& loginId -> ���� login�� ID�� ������ ���� ���� ����
              int memberType -> ȸ�� ȸ��, �Ϲ� ȸ���� ���� memberType���� ������ ���� ���� ����
    ��ȯ��: X
*/
void LoginUI::verifyLogin(string inputEvent, string& currentLoginId, int& currentMemberType) 
{
    // ������ ȣ���� �Լ��� �Ű������� const char* type�� �ֱ� ���� �۾�
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, id, pwd;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> id >> pwd;     // ������ �������� ������ string�� ������ ���

    if (control->isLoginVerified(id, pwd, currentLoginId, currentMemberType)){
        _showLoginSuccessInterface(inputEvent); 
    }
    else{
        _showLoginFailInterface(); 
    }
    return;
}

/*
    �Լ� �̸� : showLoginSuccessInterface
    ���: �α��� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: string inputEvent -> ���Ͽ� ������ id�� pwd�� �Ľ��ϱ� ���� �Ű�����
    ��ȯ��: X
*/

void LoginUI::_showLoginSuccessInterface(string inputEvent) 
{
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, id, pwd;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> id >> pwd;     // ������ �������� ������ string�� ������ ���


    *fout << "> " << id << " " << pwd << endl << endl;       // �α��� ���� ��, ������ ���� (id, pwd)�� ���Ͽ� ����
}


/*
    �Լ� �̸� : showLoginFailInterface
    ���: �α��� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: X
    ��ȯ��: X
*/
void LoginUI::_showLoginFailInterface() 
{
    *fout << endl;        // �α��� ���� ��, ���ุ �� �� ������ ����� ���Ͽ� ����
}