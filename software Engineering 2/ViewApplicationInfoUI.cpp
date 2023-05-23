#include "ViewApplicationInfoUI.h"
#include "ViewApplicationInfo.h"

ViewApplicationInfoUI::ViewApplicationInfoUI(ViewApplicationInfo* inputControl) {
	control = inputControl;
}

void ViewApplicationInfoUI::init(ofstream* inputFout) {
	fout = inputFout;
}

void ViewApplicationInfoUI::startInterface() {
	*fout << "4.3. 지원 정보 조회" << endl;
}

void ViewApplicationInfoUI::showApplicationInfo(string currentLoginId) {

	string returnString = control->viewApplicationList(currentLoginId);

	*fout << returnString << endl;

}