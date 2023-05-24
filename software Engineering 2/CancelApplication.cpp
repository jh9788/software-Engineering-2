#include "CancelApplication.h"
#include "CancelApplicationUI.h"

CancelApplication::CancelApplication(ApplicationInfoCollection* inputApplicationInfoCollection) {

	applicationInfoCollection = inputApplicationInfoCollection;

	CancelApplicationUI* boundary = new CancelApplicationUI(this);
	this->boundary = boundary;

}

CancelApplicationUI* CancelApplication::getCancelApplicationUI() {
	return boundary;
}


string CancelApplication::viewCancelApplication(string currentLoginId, string inputBusinessNum) {
	string returnString;

	returnString = applicationInfoCollection->removeApplicationInfo(currentLoginId, inputBusinessNum);

	return returnString;
}