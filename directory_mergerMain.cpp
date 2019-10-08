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
const long directory_mergerFrame::ID_STATICTEXT3 = wxNewId();
const long directory_mergerFrame::ID_TEXTCTRL3 = wxNewId();
const long directory_mergerFrame::ID_STATICLINE1 = wxNewId();
const long directory_mergerFrame::ID_BUTTON2 = wxNewId();
const long directory_mergerFrame::ID_BUTTON3 = wxNewId();
const long directory_mergerFrame::ID_BUTTON4 = wxNewId();
const long directory_mergerFrame::ID_STATICBOX1 = wxNewId();
const long directory_mergerFrame::ID_STATICLINE2 = wxNewId();
const long directory_mergerFrame::ID_RADIOBUTTON1 = wxNewId();
const long directory_mergerFrame::ID_RADIOBUTTON2 = wxNewId();
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
    SetClientSize(wxSize(506,518));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Directory 1:"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextFirstDirectory = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,40), wxSize(432,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    ButtonFirstDirectory = new wxButton(this, ID_BUTTON1, _("..."), wxPoint(456,40), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Directory 2:"), wxPoint(16,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TextSecondDirectory = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(16,120), wxSize(432,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextSecondDirectory->SetMaxSize(wxSize(-1,-1));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Output Directory:"), wxPoint(16,192), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextOutputDirectory = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(16,216), wxSize(432,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(16,176), wxSize(464,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    ButtonSecondDirectory = new wxButton(this, ID_BUTTON2, _("..."), wxPoint(456,120), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    ButtonOutputDirectory = new wxButton(this, ID_BUTTON3, _("..."), wxPoint(456,216), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    ButtonMergeDirectories = new wxButton(this, ID_BUTTON4, _("Merge Directories"), wxPoint(184,420), wxSize(144,44), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Settings"), wxPoint(16,296), wxSize(464,80), 0, _T("ID_STATICBOX1"));
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(16,264), wxSize(464,2), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    CopyRadioButton = new wxRadioButton(this, ID_RADIOBUTTON1, _("Copy"), wxPoint(32,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    MoveRadioButton = new wxRadioButton(this, ID_RADIOBUTTON2, _("Move"), wxPoint(104,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnAbout);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&directory_mergerFrame::OnButtonFirstDirectoryClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&directory_mergerFrame::OnButtonSecondDirectoryClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&directory_mergerFrame::OnButtonOutputDirectoryClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&directory_mergerFrame::OnButtonMergeDirectoriesClick);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnCopyRadioButtonSelect);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnMoveRadioButtonSelect);
    //*)

	SetMinClientSize(wxSize(506, 518));
	SetMaxClientSize(wxSize(506, 518));

	moveOperation = false;
	CopyRadioButton->SetValue(true);
	MoveRadioButton->SetValue(false);
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
	firstDirectoryPath = dlg.GetPath().ToStdString();
	TextFirstDirectory->SetLabel(firstDirectoryPath);
	contentOnFirstDirectory = getFilesFromDirectory(firstDirectoryPath);

	std::cout << "DIR " << firstDirectoryPath << ":" << std::endl;
	logDirectoryContent(contentOnFirstDirectory);
}

void directory_mergerFrame::OnButtonSecondDirectoryClick(wxCommandEvent& event)
{
	wxDirDialog dlg(NULL, "Choose second directory", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	dlg.ShowModal();
	secondDirectoryPath = dlg.GetPath().ToStdString();
	TextSecondDirectory->SetLabel(secondDirectoryPath);
	contentOnSecondDirectory = getFilesFromDirectory(secondDirectoryPath);

	std::cout << "DIR " << secondDirectoryPath << ":" << std::endl;
	logDirectoryContent(contentOnSecondDirectory);
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
	std::cout << "**Merging Files**" << std::endl;
	std::cout << "First Directory:" << std::endl;
	for (unsigned int i = 0; i < contentOnFirstDirectory.size(); i++)
	{
		std::string src = firstDirectoryPath + "\\" + contentOnFirstDirectory.at(i);
		std::string dest = outputDirectoryPath + "\\" + contentOnFirstDirectory.at(i);
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

	std::cout << std::endl;
	std::cout << "Second Directory:" << std::endl;
	for (unsigned int i = 0; i < contentOnSecondDirectory.size(); i++)
	{
		std::string src = secondDirectoryPath + "\\" + contentOnSecondDirectory.at(i);
		std::string dest = outputDirectoryPath + "\\" + contentOnSecondDirectory.at(i);
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
	std::cout << "Console has been attached" << std::endl;
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
