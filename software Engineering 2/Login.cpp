#include "Login.h"
#include "LoginUI.h"

/*
	�Լ� �̸� : Login
	���: ������
	�Ű�����: MemberCollection* inputMemberCollection -> MemberCollection ������ �迭
	��ȯ��: X
*/
Login::Login(MemberCollection* inputMemberCollection)
{
    LoginUI* boundary = new LoginUI(this);
    this->boundary = boundary;
    memberCollection = inputMemberCollection;

}


/*
	�Լ� �̸� : getLoginUI
	���: boundary ��ȯ
	�Ű�����: X
	��ȯ��: LoginUI* Ÿ���� Boundary
*/
LoginUI* Login::getLoginUI(){
    return boundary;
}

/*
    �Լ� �̸� : isLoginVerified
    ���: �α��� �� �� �ִ� �ڰ��� ���߾����� Ȯ���ϴ� �Լ�
    �Ű�����: MemberCollection& memberCollection -> memberCollection�� ����Ǿ��ִ� ������ Ȯ���ϱ� ���� ������ argument
              string name -> �̸�
              string num -> �ֹε�Ϲ�ȣ
              string* id -> ID
              string pwd -> Password
              string& loginId -> ���� login�� ID�� ������ ���� ���� ����
              int memberType -> ȸ�� ȸ��, �Ϲ� ȸ���� ���� memberType���� ������ ���� ���� ����
    ��ȯ��: bool Ÿ���� true �Ǵ� false
*/
bool Login::isLoginVerified(string id, string pwd, string& currentLoginId, int& currentMemberType) 
{
    // ȸ���� �´� ���
    if (memberCollection->isMember(id, pwd)) {
		currentLoginId = id;           // loginId�� ��� �α����� �õ��ߴ� id�� ����
		currentMemberType = memberCollection->getMemberType(id, pwd);       // memberType�� ���� �α��� �� member�� type�� ����
        return true;
    }
    // ȸ���� �ƴ� ���
    else
        return false;
}