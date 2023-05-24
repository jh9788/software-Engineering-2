#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ViewApplicationInfo;

// ����� ä�� ���� ��ȸ UI
class ViewApplicationInfoUI {
private:
	ViewApplicationInfo* control;
	ofstream* fout;
public:
	ViewApplicationInfoUI(ViewApplicationInfo* inputControl);		// ������
	void init(ofstream* inputFout);									// ���� ������� ���� �Լ�

	void startInterface();		// �������̽� ����
	void showApplicationInfo(string currentLoginId);		// ��ȸ�� �����ϰ�, ��ȸ �Ϸ�� �ֵ��� ���Ͽ� ���
};