#include <string>
#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

using namespace std;

ApplyImmediatelyUI::ApplyImmediatelyUI(ApplyImmediately* inputControl)
{
	control = inputControl;
}

void ApplyImmediatelyUI::init(ofstream* inputFout)
{
	fout = inputFout;
}

void ApplyImmediatelyUI::startInterface()
{
	*fout << "4.2. 채용 지원" << endl;
}



void ApplyImmediatelyUI::showApplyImmediately(string inputEvent)
{
	stringstream input(inputEvent);
	string num1, num2, businessNum;

	input >> num1 >> num2 >> businessNum;

	string returnString = control->applyImmediately(businessNum);

	*fout <<  returnString << endl << endl;
}

