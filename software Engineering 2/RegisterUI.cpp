#include "RegisterUI.h"
#include "Register.h"
#include <string>
using namespace std;

/*
	�Լ� �̸� : RegisterUI
	���: ������
	�Ű�����: Register* inputControl -> ��Ʈ�� ������
	��ȯ��: X
*/
RegisterUI::RegisterUI(Register* inputControl)
{
    control = inputControl;
}

/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
	��ȯ��: X
*/
void RegisterUI::init(ofstream* inputFout)
{
    fout = inputFout;
}

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void RegisterUI::startInterface() 
{
    *fout << "1.1. ȸ������" << endl;  // ������ �Է��� ���� ȭ�鿡 ����. �̿� ���� ������ boundary���� ����
}

/*
    �Լ� �̸� : selectMemberType
    ���: ������ �� ���� �а�, ȸ���� Type�� �°� ���� ��ȯ
    �Ű�����: string inputEvent -> ���Ͽ��� ��� �о���� �� ���� ����
    ��ȯ��: ȸ�� ȸ���̸� 1, �Ϲ� ȸ���̸� 2�� ��ȯ
*/
int RegisterUI::selectMemberType(string inputEvent) 
{
    return inputEvent[4] - '0';
}

/*
    �Լ� �̸� : requestRegister
    ���: ȸ������ Boundary�� �Լ��ν�, ȸ�� ���� Control���� ȸ�� ������ ��û�ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� ���� �Ϸ� ��, memberCollection�� ����
              string inputEvent -> ���Ͽ��� ��� �о���� �� ���� ����
              int memberType -> 1: ȸ�� ȸ��, 2: �Ϲ� ȸ��
    ��ȯ��: X
*/
void RegisterUI::requestRegister(string inputEvent, int memberType) 
{
    // ������ ���� �Լ��� �Ű������� char* type�� �ֱ� ���� string �ڸ���
    stringstream input(inputEvent);     // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, num3, name, num, id, pwd;    // ������ �������� �߶��� �ֵ��� ���� string ���� ����

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // ������ �������� �� ������ string�� �־���

    // 1.1.1���� 1.1.2������ �� switch case������ ����
    switch (memberType) {
    case 1:             // ȸ�� ȸ���� ���
        control->registerCompanyMember(name, num, id, pwd, 1);     // Control�� �Լ��� registerCompanyMember ȣ��
        _showRegisterSuccessInterface(inputEvent, 1);
        break;
    case 2:             // �Ϲ� ȸ���� ���
        control->registerGeneralMember(name, num, id, pwd, 2);     // Control�� �Լ��� registerGeneralMember ȣ��
        _showRegisterSuccessInterface(inputEvent, 2);
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
void RegisterUI::_showRegisterSuccessInterface(string inputEvent, int memberType) 
{
    // ���Ͽ� ������ �����ϱ� ���� string �ڸ���
    stringstream input(inputEvent);     // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, num3, name, num, id, pwd;    // ������ �������� �߶��� �ֵ��� ���� string ���� ����

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // ������ �������� �� ������ string�� �־���

    *fout << "> " << memberType << " " << name << " " << num << " " << id << " " << pwd << endl << endl;    // ���Ͽ� ȸ�� ���� ���� ����
}
