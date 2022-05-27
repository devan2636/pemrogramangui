#ifndef DATA_PASIEN_H
#define DATA_PASIEN_H

//(*Headers(data_pasien)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class data_pasien: public wxFrame
{
	public:

		data_pasien(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~data_pasien();

		//(*Declarations(data_pasien)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxGrid* Grid1;
		wxStaticBox* StaticBox1;
		wxStaticBox* StaticBox2;
		wxStaticBox* StaticBox3;
		wxStaticBox* StaticBox4;
		wxStaticBox* StaticBox5;
		wxStaticBox* StaticBox6;
		wxStaticBox* StaticBox7;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		wxTextCtrl* TextCtrl6;
		wxTextCtrl* TextCtrl7;
		wxTextCtrl* TextCtrl8;
		wxTextCtrl* TextCtrl9;
		//*)

	protected:

		//(*Identifiers(data_pasien)
		static const long ID_STATICBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICBOX2;
		static const long ID_STATICBOX3;
		static const long ID_STATICBOX4;
		static const long ID_STATICBOX5;
		static const long ID_STATICBOX6;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICBOX7;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT12;
		static const long ID_TEXTCTRL6;
		static const long ID_TEXTCTRL7;
		static const long ID_TEXTCTRL8;
		static const long ID_TEXTCTRL9;
		static const long ID_GRID1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		//*)

	private:

		//(*Handlers(data_pasien)
		void OnClose(wxCloseEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnGrid1CellLeftClick(wxGridEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
