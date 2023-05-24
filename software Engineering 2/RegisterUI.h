#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Register;

/*
Ŭ���� �̸� : RegisterUI
��� : ȸ������ Boundary
*/
class RegisterUI 
{
private:
	Register* control;
	ofstream* fout;

	void _showRegisterSuccessInterface(string inputEvent, int memberType);		// ȸ�� ���� ���� ȭ�� ���Ͽ� ����
public:
	RegisterUI(Register* inputControl);		// ������
	void init(ofstream* inputFout); 		// ���� ������� ���� �Լ�

	void startInterface();		// �������̽� ����
	int selectMemberType(string inputEvent);		// ȸ�� ȸ������, �Ϲ� ȸ������ member type ����
	void requestRegister(string inputEvent, int memberType);		// ȸ�� ���� ��û
};