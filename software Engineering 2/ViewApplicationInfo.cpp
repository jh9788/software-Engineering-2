#include "ViewApplicationInfo.h"
#include "ViewApplicationInfoUI.h"


ViewApplicationInfo::ViewApplicationInfo(ApplicationInfoCollection* inputApplicationInfoCollection) {

	applicationInfoCollection = inputApplicationInfoCollection;

	ViewApplicationInfoUI* boundary = new ViewApplicationInfoUI(this);
	this->boundary = boundary;
}


ViewApplicationInfoUI* ViewApplicationInfo::getViewApplicationInfoUI() {
	return boundary;
}

string ViewApplicationInfo::viewApplicationList(string currentLoginId) {
	string retrunString = applicationInfoCollection->getApplicationInfo(currentLoginId);
	return retrunString;
}