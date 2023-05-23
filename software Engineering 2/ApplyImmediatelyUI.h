#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class ApplyImmediately;

// 채용 지원 UI
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