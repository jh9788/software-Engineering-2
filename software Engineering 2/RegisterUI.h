#pragma once
#include <iostream>
#include <string>

using namespace std;

class Register;
// ��ü�� ���� �ּ� ����� �߰��ؾ���!!
// ȸ������ UI
class RegisterUI {
private:

	Register* control;
public:
	void startInterface();		// �������̽� ����
	int selectMemberType(string inputEvent);		// ȸ�� ȸ������, �Ϲ� ȸ������ member type ����
	void requestRegister(MemberCollection& memberCollection, string inputEvent, int memberType);		// ȸ�� ���� ��û
	void showRegisterSuccessInterface(string inputEvent, int memberType);		// ȸ�� ���� ���� ȭ�� ���Ͽ� ����
};