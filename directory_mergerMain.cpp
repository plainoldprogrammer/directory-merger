/***************************************************************
 * Name:      directory_mergerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-10-05
 * Copyright:  ()
 * License:
 **************************************************************/

#include "directory_mergerMain.h"
#include <wx/msgdlg.h>
#include <wx/dirdlg.h>
#include <vector>
#include <dirent.h>
#include <sstream>
#include <string>
#include <fstream>

//(*InternalHeaders(directory_mergerFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(directory_mergerFrame)
const long directory_mergerFrame::ID_STATICTEXT1 = wxNewId();
const long directory_mergerFrame::ID_TEXTCTRL1 = wxNewId();
const long directory_mergerFrame::ID_BUTTON1 = wxNewId();
const long directory_mergerFrame::ID_STATICTEXT2 = wxNewId();
const long directory_mergerFrame::ID_TEXTCTRL2 = wxNewId();
const long directory_mergerFrame::ID_BUTTON2 = wxNewId();
const long directory_mergerFrame::ID_STATICLINE1 = wxNewId();
const long directory_mergerFrame::ID_STATICTEXT3 = wxNewId();
const long directory_mergerFrame::ID_TEXTCTRL3 = wxNewId();
const long directory_mergerFrame::ID_BUTTON3 = wxNewId();
const long directory_mergerFrame::ID_STATICLINE2 = wxNewId();
const long directory_mergerFrame::ID_BUTTON4 = wxNewId();
const long directory_mergerFrame::ID_STATICBOX1 = wxNewId();
const long directory_mergerFrame::ID_RADIOBUTTON1 = wxNewId();
const long directory_mergerFrame::ID_RADIOBUTTON2 = wxNewId();
const long directory_mergerFrame::ID_PANEL2 = wxNewId();
const long directory_mergerFrame::ID_STATICBOX2 = wxNewId();
const long directory_mergerFrame::ID_RADIOBUTTON3 = wxNewId();
const long directory_mergerFrame::ID_RADIOBUTTON4 = wxNewId();
const long directory_mergerFrame::ID_PANEL3 = wxNewId();
const long directory_mergerFrame::ID_PANEL1 = wxNewId();
const long directory_mergerFrame::idMenuQuit = wxNewId();
const long directory_mergerFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(directory_mergerFrame,wxFrame)
    //(*EventTable(directory_mergerFrame)
    //*)
END_EVENT_TABLE()

directory_mergerFrame::directory_mergerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(directory_mergerFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Directory Merger"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(514,518));
    MainPanel = new wxPanel(this, ID_PANEL1, wxPoint(504,8), wxSize(496,464), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(MainPanel, ID_STATICTEXT1, _("Directory 1:"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextFirstDirectory = new wxTextCtrl(MainPanel, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,40), wxSize(462,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    ButtonFirstDirectory = new wxButton(MainPanel, ID_BUTTON1, _("..."), wxPoint(478,40), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText2 = new wxStaticText(MainPanel, ID_STATICTEXT2, _("Directory 2:"), wxPoint(8,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TextSecondDirectory = new wxTextCtrl(MainPanel, ID_TEXTCTRL2, wxEmptyString, wxPoint(8,120), wxSize(462,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextSecondDirectory->SetMaxSize(wxSize(-1,-1));
    ButtonSecondDirectory = new wxButton(MainPanel, ID_BUTTON2, _("..."), wxPoint(478,120), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticLine1 = new wxStaticLine(MainPanel, ID_STATICLINE1, wxPoint(8,160), wxSize(494,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    StaticText3 = new wxStaticText(MainPanel, ID_STATICTEXT3, _("Output Directory:"), wxPoint(8,192), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextOutputDirectory = new wxTextCtrl(MainPanel, ID_TEXTCTRL3, wxEmptyString, wxPoint(8,216), wxSize(462,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    ButtonOutputDirectory = new wxButton(MainPanel, ID_BUTTON3, _("..."), wxPoint(478,216), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticLine2 = new wxStaticLine(MainPanel, ID_STATICLINE2, wxPoint(8,264), wxSize(494,2), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    ButtonMergeDirectories = new wxButton(MainPanel, ID_BUTTON4, _("Merge Directories"), wxPoint(196,424), wxSize(144,44), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    PanelOperation = new wxPanel(MainPanel, ID_PANEL2, wxPoint(8,276), wxSize(126,118), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticBoxOperation = new wxStaticBox(PanelOperation, ID_STATICBOX1, _("Operation"), wxPoint(8,8), wxSize(112,98), 0, _T("ID_STATICBOX1"));
    RadioButtonCopy = new wxRadioButton(PanelOperation, ID_RADIOBUTTON1, _("Copy"), wxPoint(24,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButtonMove = new wxRadioButton(PanelOperation, ID_RADIOBUTTON2, _("Move"), wxPoint(24,72), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    PanelBehavior = new wxPanel(MainPanel, ID_PANEL3, wxPoint(140,276), wxSize(362,118), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticBoxBehavior = new wxStaticBox(PanelBehavior, ID_STATICBOX2, _("Behavior"), wxPoint(8,8), wxSize(344,98), 0, _T("ID_STATICBOX2"));
    RadioButtonReplaceAInB = new wxRadioButton(PanelBehavior, ID_RADIOBUTTON3, _("Replace Files From Directory 1 In Directory 2"), wxPoint(24,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    RadioButtonReplaceBInA = new wxRadioButton(PanelBehavior, ID_RADIOBUTTON4, _("Replace Files From Directory 2 In Directory 1"), wxPoint(24,72), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&directory_mergerFrame::OnButtonFirstDirectoryClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&directory_mergerFrame::OnButtonSecondDirectoryClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&directory_mergerFrame::OnButtonOutputDirectoryClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&directory_mergerFrame::OnButtonMergeDirectoriesClick);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnCopyRadioButtonSelect);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnMoveRadioButtonSelect);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnAbout);
    //*)

	SetMinClientSize(wxSize(509, 518));
	SetMaxClientSize(wxSize(509, 518));

	moveOperation = false;
	RadioButtonCopy->SetValue(true);
	RadioButtonMove->SetValue(false);

	ButtonFirstDirectory->SetCursor(wxCursor(wxCURSOR_HAND));
	ButtonSecondDirectory->SetCursor(wxCursor(wxCURSOR_HAND));
	ButtonOutputDirectory->SetCursor(wxCursor(wxCURSOR_HAND));
	ButtonMergeDirectories->SetCursor(wxCursor(wxCURSOR_HAND));

	TextFirstDirectory->SetToolTip(_("Full path to the first source directory"));
	TextSecondDirectory->SetToolTip(_("Full path to the second source directory"));
	TextOutputDirectory->SetToolTip(_("Full path to the output directory"));

	attachConsoleForDebug();
}

directory_mergerFrame::~directory_mergerFrame()
{
	FreeConsole();
}

void directory_mergerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void directory_mergerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Directory Merger (Under Development) \n(No Warranty)\n\nDeveloped by PlainOldProgrammer\n\nResources:\nGNU MinGW g++ (tdm-1) 5.1.0\n" + wxbuildinfo(long_f);
    wxMessageBox(msg, _("Directory Merger"));
}

void directory_mergerFrame::OnButtonFirstDirectoryClick(wxCommandEvent& event)
{
	wxDirDialog dlg(NULL, "Choose first directory", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	dlg.ShowModal();
	// firstDirectoryPath = dlg.GetPath().ToStdString();
	TextFirstDirectory->SetLabel(dlg.GetPath().ToStdString());
	std::cout << "DIR " << TextFirstDirectory->GetLabel() << ":" << std::endl;
}

void directory_mergerFrame::OnButtonSecondDirectoryClick(wxCommandEvent& event)
{
	wxDirDialog dlg(NULL, "Choose second directory", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	dlg.ShowModal();
	// secondDirectoryPath = dlg.GetPath().ToStdString();
	TextSecondDirectory->SetLabel(dlg.GetPath().ToStdString());
	std::cout << "DIR " << TextSecondDirectory->GetLabel() << ":" << std::endl;

}

void directory_mergerFrame::OnButtonOutputDirectoryClick(wxCommandEvent& event)
{
	wxDirDialog dlg(NULL, "Choose output directory", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	dlg.ShowModal();
	outputDirectoryPath = dlg.GetPath().ToStdString();
	TextOutputDirectory->SetLabel(outputDirectoryPath);

	std::cout << "OUTPUT DIR: " << outputDirectoryPath <<std::endl;
}

void directory_mergerFrame::OnButtonMergeDirectoriesClick(wxCommandEvent& event)
{
	std::string firstDirectoryPath = std::string(TextFirstDirectory->GetValue().mb_str());
	contentOnFirstDirectory = getFilesFromDirectory(firstDirectoryPath);
	std::cout << "Logging the content of first directory:" << std::endl;
	logDirectoryContent(contentOnFirstDirectory);

	std::string secondDirectoryPath = std::string(TextSecondDirectory->GetValue().mb_str());
	contentOnSecondDirectory = getFilesFromDirectory(secondDirectoryPath);
	std::cout << "Logging the content of second directory:";
	logDirectoryContent(contentOnSecondDirectory);

	std::cout << std::endl;
	std::cout << "**Merging Files**" << std::endl;
	std::cout << "First directory: " << firstDirectoryPath << std::endl;
	std::cout << "Second directory: " << secondDirectoryPath << std::endl;
	std::cout << std::endl;

	/*
	 *	Move files from first directory to the output directory.
	 */
	std::cout << "First Directory:" << std::endl;
	for (unsigned int i = 0; i < contentOnFirstDirectory.size(); i++)
	{
		std::string src = firstDirectoryPath + "\\" + contentOnFirstDirectory.at(i);
		std::string dest = std::string(TextOutputDirectory->GetValue().mb_str()) + "\\" + contentOnFirstDirectory.at(i);
		std::cout << src << "\t=>\t" << dest << std::endl;


		if (moveOperation == true)
		{
			rename(src.c_str(), dest.c_str());
		}
		else
		{
			std::ifstream srcFile(src.c_str(), std::ios::binary);
			std::ofstream destFile(dest.c_str(), std::ios::binary);
			destFile << srcFile.rdbuf();
		}
	}

	/*
	 *	Move files from second directory to the output directory.
	 */
	std::cout << std::endl;
	std::cout << "Second Directory:" << std::endl;
	for (unsigned int i = 0; i < contentOnSecondDirectory.size(); i++)
	{
		std::string src = secondDirectoryPath + "\\" + contentOnSecondDirectory.at(i);
		std::string dest = std::string(TextOutputDirectory->GetValue().mb_str()) + "\\" + contentOnSecondDirectory.at(i);
		std::cout << src << "\t=>\t" << dest << std::endl;

		if (moveOperation == true)
		{
			rename(src.c_str(), dest.c_str());
		}
		else
		{
			std::ifstream srcFile(src.c_str(), std::ios::binary);
			std::ofstream destFile(dest.c_str(), std::ios::binary);
			destFile << srcFile.rdbuf();
		}
	}

	wxMessageBox(wxT("Operation Completed!"), wxString("Info"), wxICON_INFORMATION);
}

void directory_mergerFrame::attachConsoleForDebug()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	std::cout << "Console has been attached" << std::endl << std::endl;
}

std::vector<std::string> directory_mergerFrame::getFilesFromDirectory(std::string path)
{
	DIR *directory;
	struct dirent *entry;

	std::vector<std::string> files;
	std::string fileName = "";

	if ((directory = opendir(path.c_str())) != NULL)
	{
		while ((entry = readdir(directory)) != NULL)
		{
			fileName = entry->d_name;

			if (!(fileName.compare(".") == 0) && !(fileName.compare("..") == 0))
			{
				files.push_back(fileName);
			}
		}

		closedir(directory);

		std::sort(files.begin(), files.end(), compareNaturalOrder);
	}
	else
	{
		std::cout << "Can't open directory " << path << std::endl;
	}

	return files;
}

bool directory_mergerFrame::compareNaturalOrder(const std::string& a, const std::string& b)
{
    if (a.empty())
	{
        return true;
	}
    if (b.empty())
	{
        return false;
	}
    if (std::isdigit(a[0]) && !std::isdigit(b[0]))
	{
        return true;
	}
    if (!std::isdigit(a[0]) && std::isdigit(b[0]))
	{
        return false;
	}
    if (!std::isdigit(a[0]) && !std::isdigit(b[0]))
    {
        if (a[0] == b[0])
		{
            return compareNaturalOrder(a.substr(1), b.substr(1));
		}

        return (toUpper(a) < toUpper(b));
    }

    // Both strings begin with digit. Parse both numbers
    std::istringstream issa(a);
    std::istringstream issb(b);
    int ia;
	int ib;
    issa >> ia;
    issb >> ib;

    if (ia != ib)
	{
        return ia < ib;
}

    // Numbers are the same. Remove numbers and recurse
    std::string anew;
	std::string bnew;
    std::getline(issa, anew);
    std::getline(issb, bnew);

    return (compareNaturalOrder(anew, bnew));
}

std::string directory_mergerFrame::toUpper(std::string s)
{
    for(int i=0;i<(int)s.length();i++){s[i]=toupper(s[i]);}
    return s;
}

void directory_mergerFrame::logDirectoryContent(std::vector<std::string> dirContent)
{
	for (unsigned int i = 0; i < dirContent.size(); i++)
	{
		std::cout << dirContent.at(i) << std::endl;
	}

	std::cout << std::endl;
}

void directory_mergerFrame::OnCopyRadioButtonSelect(wxCommandEvent& event)
{
	moveOperation = false;
}

void directory_mergerFrame::OnMoveRadioButtonSelect(wxCommandEvent& event)
{
	moveOperation = true;
}
