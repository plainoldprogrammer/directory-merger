/***************************************************************
 * Name:      directory_mergerApp.cpp
 * Purpose:   Code for Application Class
 * Author:     (PlainOldProgrammer)
 * Created:   2019-10-05
 * Copyright:  ()
 * License:
 **************************************************************/

#include "directory_mergerApp.h"

//(*AppHeaders
#include "directory_mergerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(directory_mergerApp);

bool directory_mergerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    directory_mergerFrame* Frame = new directory_mergerFrame(0);
    Frame->Show();
    SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
