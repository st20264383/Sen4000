#include "MainFrame.h"
#include "Dimensions.h"
// Backend includes here.

#include "iostream"
#include <string>
#include "fstream"
std::fstream fs;

#include <wx/wx.h>
#include "MainFrame.h"

bool isOpen;

BEGIN_EVENT_TABLE (MainFrame, wxFrame)
	EVT_MENU(MENU_Quit, MainFrame::OnExit)
	EVT_MENU(MENU_Open, MainFrame::OpenFile)
	EVT_MENU(MENU_Close, MainFrame::CloseFile)
END_EVENT_TABLE() 

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
: wxFrame((wxFrame *) NULL, -1, title, pos, size) 
{
	CreateStatusBar(); // Creates a status bar at the bottom of the window

	mainMenu = new wxMenuBar(); // Creates a menu bar
	wxMenu *fileMenu = new wxMenu(); // Creates a menu

	fileMenu->Append(MENU_Open, wxT("&Open"), wxT("Open an existing file"));
	fileMenu->Append(MENU_Close, wxT("&Close"), wxT("Close the current file"));
	fileMenu->Append(MENU_Quit, wxT("&Quit"), wxT("Quit the editor"));

	mainMenu->Append(fileMenu, wxT("&File")); // Adds the fileMenu to the menu bar
	SetMenuBar(mainMenu); // Adds the menu bar to the frame

//	mainEditBox = new wxTextCtrl();
//	mainEditBox->Create(this, TEXT_Main, wxT("Hello World"), 
//	wxPoint(0,0), wxSize(200,100), wxTE_MULTILINE);

	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_textCtrl1, 0, wxALL|wxEXPAND, 5 );

	m_listCtrl1 = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );

	// Add first column       
	wxListItem col0;
	col0.SetId(0);
	col0.SetText( _("Name") );
	col0.SetWidth(50);
	m_listCtrl1->InsertColumn(0, col0);
	
	// Add second column
	wxListItem col1;
	col1.SetId(1);
	col1.SetText( _("Pos X") );
	m_listCtrl1->InsertColumn(1, col1);

	// Add third column
	wxListItem col2;
	col2.SetId(2);
	col2.SetText(_("Pos Y"));
	m_listCtrl1->InsertColumn(2, col2);

	// Add fourth column
	wxListItem col3;
	col3.SetId(3);
	col3.SetText(_("Pos Z"));
	m_listCtrl1->InsertColumn(3, col3);


	bSizer1->Add( m_listCtrl1, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	//Create file manager

	if (fs) 
	{
		wxMenu* editMenu = new wxMenu(); // Creates a menu

		editMenu->Append(EDIT_Create, wxT("&Create"), wxT("Create an object in the scene"));
		editMenu->Append(EDIT_Search, wxT("&Search"), wxT("Search for an object in the scene"));

		mainMenu->Append(editMenu, wxT("&Edit")); // Adds the editMenu to the menu bar
		SetMenuBar(mainMenu); // Adds the menu bar to the frame

	}


}

void MainFrame::blank()
{
	// Clear the box text
	//mainEditBox->Clear();
	m_textCtrl1->Clear();

	m_listCtrl1->DeleteAllItems();

	// Clear the current document path
	currentDocPath = wxEmptyString;
	// Set the title to "Edit - Untitled"
	SetTitle(wxT("No document"));
}

void MainFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog *openDialog = new wxFileDialog(this, 
				wxT("Choose a file to open"), 
				wxEmptyString, wxEmptyString, 
				wxT("Scene Sdf Files (*.sdf)|*.sdf"),
				wxFD_OPEN, wxDefaultPosition);

	if(openDialog->ShowModal() == wxID_OK)
	{
		currentDocPath = openDialog->GetPath();

		std::string filepath = openDialog->GetFilename().ToStdString();
		std::string fileDirectory = openDialog->GetDirectory().ToStdString();

		fs.open(openDialog->GetDirectory().ToStdString(), std::fstream::app);
		if (fs) 
		{
			fs.seekg(0, fs.end); //Sets the pointer position to the end of the file
			int length = fs.tellg(); //Reads the index of the pointer position to know the number of characters in a file
			fs.seekg(0, fs.beg); //Resets the pointer position to the start of the file

			char* buffer = new char[length]; //Creates a location for data to be stored before reading.

			std::cout << "Reading" << length << "characters." << std::flush;

			fs.read(buffer, length); //Reads buffer for n=length many characters
		}

		SetTitle(wxString("Edit - ") << openDialog->GetFilename());

	}

	openDialog->Destroy();
}

void MainFrame::CloseFile(wxCommandEvent& WXUNUSED(event))
{
	fs.close();
	SetTitle(wxT("No document"));
}

void MainFrame::OnExit(wxCommandEvent& event)
{
	// clean up file manager here!

	Close(TRUE); // Tells the OS to quit running this process
}
