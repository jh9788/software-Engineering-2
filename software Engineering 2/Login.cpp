#include "Login.h"
#include "LoginUI.h"

Login::Login(MemberCollection* inputMemberCollection){
    LoginUI* boundary = new LoginUI(this);
    this->boundary = boundary;
    memberCollection = inputMemberCollection;

}

LoginUI* Login::getLoginUI(){
    return boundary;
}

/*
    �Լ� �̸� : verifyLogin
    ���: �α��� �� �� �ִ� �ڰ��� ���߾����� Ȯ���ϴ� �Լ�
    �Ű�����: MemberCollection& memberCollection -> memberCollection�� ����Ǿ��ִ� ������ Ȯ���ϱ� ���� ������ argument
              string name -> �̸�
              string num -> �ֹε�Ϲ�ȣ
              string* id -> ID
              string pwd -> Password
              string& loginId -> ���� login�� ID�� ������ ���� ���� ����
              int memberType -> ȸ�� ȸ��, �Ϲ� ȸ���� ���� memberType���� ������ ���� ���� ����
    ��ȯ��: bool
*/
bool Login::verifyLogin(string id, string pwd, string& currentLoginId, int& currentMemberType) {
    // ȸ���� �´� ���
    if (memberCollection.isMember(id, pwd)) {
		currentLoginId = id;           // loginId�� ��� �α����� �õ��ߴ� id�� ����
		currentMemberType = memberCollection.getMemberType(id, pwd);       // memberType�� ���� �α��� �� member�� type�� ����
        return true;
    }
    // ȸ���� �ƴ� ���
    else
        return false;
}