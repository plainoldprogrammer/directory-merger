/***************************************************************
 * Name:      directory_mergerMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-10-05
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef DIRECTORY_MERGERMAIN_H
#define DIRECTORY_MERGERMAIN_H

//(*Headers(directory_mergerFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

#include <string>
#include <vector>

class directory_mergerFrame: public wxFrame
{
    public:

        directory_mergerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~directory_mergerFrame();
		void attachConsoleForDebug();
		void getFilesFromDirectory(std::string);
		static bool compareNaturalOrder(const std::string& , const std::string&);
		static std::string toUpper(std::string);
		static void logDirectoryContent(std::vector<std::string>);

    private:
        //(*Handlers(directory_mergerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButtonFirstDirectoryClick(wxCommandEvent& event);
        void OnButtonSecondDirectoryToggle(wxCommandEvent& event);
        void OnButtonOutputDirectoryToggle(wxCommandEvent& event);
        //*)

        //(*Identifiers(directory_mergerFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_TOGGLEBUTTON1;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_TOGGLEBUTTON2;
        static const long ID_TOGGLEBUTTON3;
        static const long ID_STATICLINE1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(directory_mergerFrame)
        wxButton* buttonFirstDirectory;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* textFirstDirectory;
        wxTextCtrl* textOutputDirectory;
        wxTextCtrl* textSecondDirectory;
        wxToggleButton* ToggleButton3;
        wxToggleButton* buttonOutputDirectory;
        wxToggleButton* buttonSecondDirectory;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DIRECTORY_MERGERMAIN_H
