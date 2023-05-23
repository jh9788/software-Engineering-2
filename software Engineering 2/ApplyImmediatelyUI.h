#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class ApplyImmediately;

// ä�� ���� UI
class ApplyImmediatelyUI
{
private:
	ApplyImmediately* control;
	ofstream* fout;
public:
	ApplyImmediatelyUI(ApplyImmediately* inputControl);
	void init(ofstream* inputFout);

	void startInterface();
	void showApplyImmediately(string inputEvent);
};