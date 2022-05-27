/***************************************************************
 * Name:      tugas_besarMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Devandri Suherman (devandri.suherman.tele419@polban.ac.id)
 * Created:   2021-07-18
 * Copyright: Devandri Suherman (devandri-suherman.engineer)
 * License:
 **************************************************************/

#include "tugas_besarMain.h"
#include <wx/msgdlg.h>
#include "data_pasien.h" //menambahkan layar data_pasien

//(*InternalHeaders(tugas_besarFrame)
#include <wx/bitmap.h>
#include <wx/image.h>
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

//(*IdInit(tugas_besarFrame)
const long tugas_besarFrame::ID_STATICBOX2 = wxNewId();
const long tugas_besarFrame::ID_STATICBOX1 = wxNewId();
const long tugas_besarFrame::ID_TEXTCTRL1 = wxNewId();
const long tugas_besarFrame::ID_TEXTCTRL2 = wxNewId();
const long tugas_besarFrame::ID_BUTTON1 = wxNewId();
const long tugas_besarFrame::ID_BUTTON2 = wxNewId();
const long tugas_besarFrame::ID_STATICBITMAP1 = wxNewId();
const long tugas_besarFrame::ID_BUTTON3 = wxNewId();
const long tugas_besarFrame::idMenuQuit = wxNewId();
const long tugas_besarFrame::idMenuAbout = wxNewId();
const long tugas_besarFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(tugas_besarFrame,wxFrame)
    //(*EventTable(tugas_besarFrame)
    //*)
END_EVENT_TABLE()

tugas_besarFrame::tugas_besarFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(tugas_besarFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Login"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(450,400));
    Move(wxPoint(0,0));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, wxEmptyString, wxPoint(112,288), wxSize(232,48), 0, _T("ID_STATICBOX2"));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, wxEmptyString, wxPoint(112,160), wxSize(231,120), 0, _T("ID_STATICBOX1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(128,176), wxSize(199,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(128,208), wxSize(199,22), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Login\n"), wxPoint(136,240), wxSize(56,27), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Help"), wxPoint(272,240), wxSize(51,27), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("E:\\Devandri Suherman\\D4 Teknik Elektronika\\Semester 4\\16TEK4043 Pemrograman Piranti Keras dan GUI\\tugas_besar (1)\\tugas_besar\\images.bmp")).Rescale(wxSize(65,91).GetWidth(),wxSize(65,91).GetHeight())), wxPoint(192,42), wxSize(65,91), 0, _T("ID_STATICBITMAP1"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Exit"), wxPoint(200,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tugas_besarFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tugas_besarFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tugas_besarFrame::OnButton3Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&tugas_besarFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&tugas_besarFrame::OnAbout);
    //*)
}

tugas_besarFrame::~tugas_besarFrame()
{
    //(*Destroy(tugas_besarFrame)
    //*)
}

void tugas_besarFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void tugas_besarFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void tugas_besarFrame::OnButton3Click(wxCommandEvent& event) //tombol exit
{
    Destroy();
}

void tugas_besarFrame::OnButton1Click(wxCommandEvent& event) //tombol login
{
    wxString User = ("Astronaut");
    wxString Pass = ("1234");
    wxString Input_User = TextCtrl1->GetValue(); //membaca input username
    wxString Input_Pass = TextCtrl2->GetValue(); //membaca input password

    if (User == Input_User && Pass == Input_Pass){
        this->Hide();
        data_pasien * KK = new  data_pasien(this);
        KK->Show();
    } else {
        wxMessageBox("Username atau Password salah","Info");
    }
}

void tugas_besarFrame::OnButton2Click(wxCommandEvent& event) //tombol help
{
    wxMessageBox("Selamat datang di aplikasi Data Kesehatan\n\nCara Menggunakan :\n"
                 "Username : Astronaut \n"
                 "Password : 1234 \n"
                 "Dibuat oleh : Kelompok 2 \n"
                 ,"Info");
}
