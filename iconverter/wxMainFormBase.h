///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/frame.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>
#include <wx/valtext.h>
#include <wx/panel.h>
#include <wx/simplebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFormBase
///////////////////////////////////////////////////////////////////////////////
class MainFormBase : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_main_menu;
		wxMenu* m_mm_file;
		wxMenu* m_menu_tools;
		wxMenuItem* m_mm_convert;
		wxMenuItem* m_mm_slice;
		wxPropertyGrid* m_property;
		wxPGProperty* m_image_file;
		wxPGProperty* m_image_format;
		wxPGProperty* m_image_width;
		wxPGProperty* m_image_height;
		wxPGProperty* m_image_bit;
		wxButton* m_btn_convert;
		wxButton* m_btn_slice;
		wxStatusBar* m_main_status_bar;
		wxToolBar* m_toolbar_main;
		wxToolBarToolBase* m_tbtn_open;

		// Virtual event handlers, overide them in your derived class
		virtual void m_mm_openOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_mm_closeOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_mm_convertOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSliceSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_btn_convertOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_OnSliceButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolOpenImageClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFormBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 582,403 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFormBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class FormPreview
///////////////////////////////////////////////////////////////////////////////
class FormPreview : public wxFrame
{
	private:

	protected:

	public:

		FormPreview( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~FormPreview();

};

///////////////////////////////////////////////////////////////////////////////
/// Class SliceParamBaseDlg
///////////////////////////////////////////////////////////////////////////////
class SliceParamBaseDlg : public wxDialog
{
	private:

	protected:
		wxBoxSizer* m_sizer_sliceparam;
		wxRadioBox* m_rbox_sliceparam;
		wxSimplebook* m_book_panels;
		wxPanel* m_panel_param_1;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_edt_hperc;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_edt_vperc;
		wxPanel* m_panel_param_2;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_edt_hparts;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_edt_vparts;
		wxButton* m_btn_slice;
		wxButton* m_btn_close;

		// Virtual event handlers, overide them in your derived class
		virtual void OnRadioBoxSliceParam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSliceClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCloseClick( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxBoxSizer* m_sizer_panels;

		SliceParamBaseDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~SliceParamBaseDlg();

};

