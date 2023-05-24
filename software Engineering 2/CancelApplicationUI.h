#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CancelApplication;

// ����� ä�� ���� ��ȸ UI
class CancelApplicationUI {
private:
	CancelApplication* control;
	ofstream* fout;
public:
	CancelApplicationUI(CancelApplication* inputControl);		// ������
	void init(ofstream* inputFout);									// ���� ������� ���� �Լ�

	void startInterface();		// �������̽� ����
	void showCancelApplication(string currentLoginId, string inputEvent);		
};