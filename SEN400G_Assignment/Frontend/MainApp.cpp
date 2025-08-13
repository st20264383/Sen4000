#include "MainApp.h"
#include "MainFrame.h"
#include "wx/wx.h"

// A macro that tells wxWidgets to create an instance of our application
IMPLEMENT_APP(MainApp);

bool MainApp::OnInit() 
{
	// Create an instance of our frame, or window 
	MainFrame *MainWin = new MainFrame(("XXX File Reading Application"), wxDefaultPosition, wxSize(300, 200));
	MainWin->Show(true); // show the window 
	SetTopWindow(MainWin); // and finally, set it as the main window 
	return true;
} 