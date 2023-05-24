#include "CancelApplicationUI.h"
#include "CancelApplication.h"

CancelApplicationUI::CancelApplicationUI(CancelApplication* inputControl) 
{
	control = inputControl;
}

void CancelApplicationUI::init(ofstream* inputFout) 
{
	fout = inputFout;
}

void CancelApplicationUI::startInterface() 
{
	*fout << "4.4. 지원 취소" << endl;
}

void CancelApplicationUI::showCancelApplication(string currentLoginId, string inputEvent) 
{
	
	stringstream input(inputEvent);
	string num1, num2, businessNum;

	input >> num1 >> num2 >> businessNum;

	string returnString = control->viewCancelApplication(currentLoginId, businessNum);

	*fout << returnString << endl;

}

