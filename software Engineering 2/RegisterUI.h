#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Register;

// ȸ������ UI
class RegisterUI 
{
private:
	Register* control;
	ofstream* fout;
public:
	RegisterUI(Register* inputControl);
	void init(ofstream* inputFout); 

	void startInterface();		// �������̽� ����
	int selectMemberType(string inputEvent);		// ȸ�� ȸ������, �Ϲ� ȸ������ member type ����
	void requestRegister(string inputEvent, int memberType);		// ȸ�� ���� ��û
	void showRegisterSuccessInterface(string inputEvent, int memberType);		// ȸ�� ���� ���� ȭ�� ���Ͽ� ����
};