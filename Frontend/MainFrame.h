#ifndef MAIN_FRAME_H_
#define MAIN_FRAME_H_

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

class OgreFileManager;

enum {
	// declare an id for our button
	// one higher than those used by wxWidgets itself. 
	TEXT_Main = wxID_HIGHEST+1, 
	MENU_New,
	MENU_Open,
	MENU_Close,
	MENU_Save, 
	MENU_SaveAs,
	MENU_Quit,
	EDIT_Create,
	EDIT_Search
};

class MainFrame: public wxFrame // MainFrame is the class for our window, 
{
private: 
	wxTextCtrl *mainEditBox;
	wxMenuBar *mainMenu;
	wxString currentDocPath;
	wxTextCtrl* m_textCtrl1;
	wxListCtrl* m_listCtrl1;

	OgreFileManager *ogreFileManager;

	// It contains the window and all objects in it 
public: 
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size); 
	
	void OnExit(wxCommandEvent& event);
	void OpenFile(wxCommandEvent& event);
	void CloseFile(wxCommandEvent& event);
	void NewObject(wxCommandEvent& event);
	void blank();

	DECLARE_EVENT_TABLE();
}; 

#endif