#include "cApp.h"
#include "cMain.h"


wxIMPLEMENT_APP(cApp);

cApp::cApp() {

}

bool cApp::OnInit() {
	this->frame1 = new cMain();
	frame1->Show();
	return true;
}