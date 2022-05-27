/***************************************************************
 * Name:      tugas_besarMain.h
 * Purpose:   Defines Application Frame
 * Author:    Devandri Suherman (devandri.suherman.tele419@polban.ac.id)
 * Created:   2021-07-18
 * Copyright: Devandri Suherman (devandri-suherman.engineer)
 * License:
 **************************************************************/

#ifndef TUGAS_BESARMAIN_H
#define TUGAS_BESARMAIN_H
#include <wx/wxsqlite3.h>

//(*Headers(tugas_besarFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class tugas_besarFrame: public wxFrame
{
    public:

        tugas_besarFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~tugas_besarFrame();

    private:

        //(*Handlers(tugas_besarFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(tugas_besarFrame)
        static const long ID_STATICBOX2;
        static const long ID_STATICBOX1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICBITMAP1;
        static const long ID_BUTTON3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(tugas_besarFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBox* StaticBox1;
        wxStaticBox* StaticBox2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        //*)

        wxSQLite3Database* db;
        DECLARE_EVENT_TABLE()
};

#endif // TUGAS_BESARMAIN_H
