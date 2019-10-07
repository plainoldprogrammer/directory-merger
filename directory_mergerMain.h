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
//*)

#include <string>
#include <vector>

class directory_mergerFrame: public wxFrame
{
    public:
		directory_mergerFrame(wxWindow* parent,wxWindowID id = -1);
		virtual ~directory_mergerFrame();
		void attachConsoleForDebug();
		std::vector<std::string> getFilesFromDirectory(std::string);
		static bool compareNaturalOrder(const std::string& , const std::string&);
		static std::string toUpper(std::string);
		static void logDirectoryContent(std::vector<std::string>);

    private:
        //(*Handlers(directory_mergerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButtonFirstDirectoryClick(wxCommandEvent& event);
        void OnButtonSecondDirectoryClick(wxCommandEvent& event);
        void OnButtonOutputDirectoryClick(wxCommandEvent& event);
        void OnButtonMergeDirectoriesClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(directory_mergerFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(directory_mergerFrame)
        wxButton* ButtonFirstDirectory;
        wxButton* ButtonMergeDirectories;
        wxButton* ButtonOutputDirectory;
        wxButton* ButtonSecondDirectory;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextFirstDirectory;
        wxTextCtrl* TextOutputDirectory;
        wxTextCtrl* TextSecondDirectory;
        //*)

        DECLARE_EVENT_TABLE()

		std::string firstDirectoryPath;
		std::string secondDirectoryPath;
		std::string outputDirectoryPath;
		std::vector<std::string>contentOnFirstDirectory;
		std::vector<std::string>contentOnSecondDirectory;
};

#endif // DIRECTORY_MERGERMAIN_H
