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
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class directory_mergerFrame: public wxFrame
{
    public:

        directory_mergerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~directory_mergerFrame();

    private:

        //(*Handlers(directory_mergerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(directory_mergerFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(directory_mergerFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DIRECTORY_MERGERMAIN_H
