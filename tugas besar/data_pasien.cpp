#include "data_pasien.h"
#include <wx/msgdlg.h>
#include <wx/wxsqlite3.h>
#include <iostream>
#include "tugas_besarMain.h"

//(*InternalHeaders(data_pasien)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(data_pasien)
const long data_pasien::ID_STATICBOX1 = wxNewId();
const long data_pasien::ID_STATICTEXT1 = wxNewId();
const long data_pasien::ID_STATICTEXT2 = wxNewId();
const long data_pasien::ID_STATICBOX2 = wxNewId();
const long data_pasien::ID_STATICBOX3 = wxNewId();
const long data_pasien::ID_STATICBOX4 = wxNewId();
const long data_pasien::ID_STATICBOX5 = wxNewId();
const long data_pasien::ID_STATICBOX6 = wxNewId();
const long data_pasien::ID_STATICTEXT3 = wxNewId();
const long data_pasien::ID_STATICTEXT4 = wxNewId();
const long data_pasien::ID_STATICTEXT5 = wxNewId();
const long data_pasien::ID_STATICTEXT6 = wxNewId();
const long data_pasien::ID_STATICTEXT7 = wxNewId();
const long data_pasien::ID_TEXTCTRL1 = wxNewId();
const long data_pasien::ID_TEXTCTRL2 = wxNewId();
const long data_pasien::ID_TEXTCTRL3 = wxNewId();
const long data_pasien::ID_TEXTCTRL4 = wxNewId();
const long data_pasien::ID_TEXTCTRL5 = wxNewId();
const long data_pasien::ID_STATICBOX7 = wxNewId();
const long data_pasien::ID_STATICTEXT8 = wxNewId();
const long data_pasien::ID_STATICTEXT9 = wxNewId();
const long data_pasien::ID_STATICTEXT10 = wxNewId();
const long data_pasien::ID_STATICTEXT11 = wxNewId();
const long data_pasien::ID_STATICTEXT12 = wxNewId();
const long data_pasien::ID_TEXTCTRL6 = wxNewId();
const long data_pasien::ID_TEXTCTRL7 = wxNewId();
const long data_pasien::ID_TEXTCTRL8 = wxNewId();
const long data_pasien::ID_TEXTCTRL9 = wxNewId();
const long data_pasien::ID_GRID1 = wxNewId();
const long data_pasien::ID_BUTTON1 = wxNewId();
const long data_pasien::ID_BUTTON2 = wxNewId();
const long data_pasien::ID_BUTTON3 = wxNewId();
const long data_pasien::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(data_pasien,wxFrame)
	//(*EventTable(data_pasien)
	//*)
END_EVENT_TABLE()

data_pasien::data_pasien(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(data_pasien)
	Create(parent, wxID_ANY, _("Aplikasi Data Kesehatan"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1000,550));
	Move(wxPoint(0,0));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, wxEmptyString, wxPoint(22,106), wxSize(250,347), 0, _T("ID_STATICBOX1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Data Pasien Pra - Vaksinasi"), wxPoint(400,32), wxSize(208,29), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Data Pribadi"), wxPoint(104,128), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, wxEmptyString, wxPoint(48,160), wxSize(208,48), 0, _T("ID_STATICBOX2"));
	StaticBox3 = new wxStaticBox(this, ID_STATICBOX3, wxEmptyString, wxPoint(48,216), wxSize(208,48), 0, _T("ID_STATICBOX3"));
	StaticBox4 = new wxStaticBox(this, ID_STATICBOX4, wxEmptyString, wxPoint(48,272), wxSize(208,48), 0, _T("ID_STATICBOX4"));
	StaticBox5 = new wxStaticBox(this, ID_STATICBOX5, wxEmptyString, wxPoint(48,328), wxSize(208,48), 0, _T("ID_STATICBOX5"));
	StaticBox6 = new wxStaticBox(this, ID_STATICBOX6, wxEmptyString, wxPoint(48,384), wxSize(208,48), 0, _T("ID_STATICBOX6"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Nama"), wxPoint(56,176), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("NIK"), wxPoint(56,232), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Gender"), wxPoint(56,288), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Usia"), wxPoint(56,344), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Alamat"), wxPoint(56,400), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(136,176), wxSize(110,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(136,232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxPoint(136,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("Text"), wxPoint(136,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _("Text"), wxPoint(136,400), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	StaticBox7 = new wxStaticBox(this, ID_STATICBOX7, wxEmptyString, wxPoint(304,106), wxSize(642,181), 0, _T("ID_STATICBOX7"));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Data Kesehatan"), wxPoint(592,128), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	wxFont StaticText8Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial Narrow"),wxFONTENCODING_DEFAULT);
	StaticText8->SetFont(StaticText8Font);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Tensi"), wxPoint(352,168), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Denyut Nadi"), wxPoint(352,216), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Suhu"), wxPoint(736,168), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Vaksin"), wxPoint(736,208), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, _("Text"), wxPoint(456,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, _("Text"), wxPoint(456,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	TextCtrl8 = new wxTextCtrl(this, ID_TEXTCTRL8, _("Text"), wxPoint(816,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	TextCtrl9 = new wxTextCtrl(this, ID_TEXTCTRL9, _("Text"), wxPoint(816,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	Grid1 = new wxGrid(this, ID_GRID1, wxPoint(312,336), wxSize(632,184), 0, _T("ID_GRID1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Create"), wxPoint(360,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Load Data"), wxPoint(544,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(this, ID_BUTTON3, _("Insert"), wxPoint(672,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button4 = new wxButton(this, ID_BUTTON4, _("Exit"), wxPoint(824,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));

	Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&data_pasien::OnGrid1CellLeftClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&data_pasien::OnButton1Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&data_pasien::OnButton4Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&data_pasien::OnClose);
	//*)

	//db = new wxSQLite3Database();
}

data_pasien::~data_pasien()
{
	//(*Destroy(data_pasien)
	//*)
}


void data_pasien::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void data_pasien::OnButton4Click(wxCommandEvent& event)
{
    Close();
}

void data_pasien::OnGrid1CellLeftClick(wxGridEvent& event)
{
}

void data_pasien::OnButton1Click(wxCommandEvent& event)
{
    wxString dbName = wxGetCwd() + wxT("/Data/datapasien.db");
}
