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
const long directory_mergerFrame::ID_TOGGLEBUTTON1 = wxNewId();
const long directory_mergerFrame::ID_STATICTEXT3 = wxNewId();
const long directory_mergerFrame::ID_TEXTCTRL3 = wxNewId();
const long directory_mergerFrame::ID_TOGGLEBUTTON2 = wxNewId();
const long directory_mergerFrame::ID_TOGGLEBUTTON3 = wxNewId();
const long directory_mergerFrame::ID_STATICLINE1 = wxNewId();
const long directory_mergerFrame::idMenuQuit = wxNewId();
const long directory_mergerFrame::idMenuAbout = wxNewId();
const long directory_mergerFrame::ID_STATUSBAR1 = wxNewId();
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

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(506,410));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Directory 1:"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,40), wxSize(432,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("..."), wxPoint(456,40), wxSize(24,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Directory 2:"), wxPoint(16,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(16,120), wxSize(432,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("..."), wxPoint(456,120), wxSize(24,24), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Output Directory:"), wxPoint(16,192), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(16,216), wxSize(432,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("..."), wxPoint(456,216), wxSize(24,24), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
    ToggleButton3 = new wxToggleButton(this, ID_TOGGLEBUTTON3, _("Merge Directories"), wxPoint(184,304), wxSize(144,44), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON3"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(16,176), wxSize(464,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
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
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&directory_mergerFrame::OnAbout);
    //*)
}

directory_mergerFrame::~directory_mergerFrame()
{
    //(*Destroy(directory_mergerFrame)
    //*)
}

void directory_mergerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void directory_mergerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
