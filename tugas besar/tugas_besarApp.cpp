/***************************************************************
 * Name:      tugas_besarApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Devandri Suherman (devandri.suherman.tele419@polban.ac.id)
 * Created:   2021-07-18
 * Copyright: Devandri Suherman (devandri-suherman.engineer)
 * License:
 **************************************************************/

#include "tugas_besarApp.h"

//(*AppHeaders
#include "tugas_besarMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(tugas_besarApp);

bool tugas_besarApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	tugas_besarFrame* Frame = new tugas_besarFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
