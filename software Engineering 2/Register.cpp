#include "Register.h"
#include "RegisterUI.h"

/*
	�Լ� �̸� : Register
	���: ������
	�Ű�����: MemberCollection* inputMemberCollection -> MemberCollection ������ �迭
	��ȯ��: X
*/
Register::Register(MemberCollection* inputMemberCollection) 
{
    memberCollection = inputMemberCollection;

    RegisterUI* boundary = new RegisterUI(this);
    this->boundary = boundary;
}


/*
	�Լ� �̸� : getRegisterUI
	���: �ٿ���� ��ȯ
	�Ű�����: X
	��ȯ��: RegisterUI* Ÿ���� �ٿ����
*/
RegisterUI* Register::getRegisterUI()
{
    return boundary;
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
void Register::registerCompanyMember(
    string name, string num, string id, string pwd, int memberType)
{
    memberCollection->addMember(name, num, id, pwd, memberType);  // memberCollection class�� ���� �ִ� addMember�Լ� ȣ���Ͽ� Member �߰�
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
void Register::registerGeneralMember(
   string name, string num, string id, string pwd, int memberType)
{
     // �� ��ü�� GeneralMember ������ ����� �ֱ�
    memberCollection->addMember(name, num, id, pwd, memberType);  // memberCollection class�� ���� �ִ� addMember�Լ� ȣ���Ͽ� Member �߰�
}