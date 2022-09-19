///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxMainFormBase.h"

///////////////////////////////////////////////////////////////////////////

MainFormBase::MainFormBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_main_menu = new wxMenuBar( 0 );
	m_mm_file = new wxMenu();
	wxMenuItem* m_mm_open;
	m_mm_open = new wxMenuItem( m_mm_file, wxID_ANY, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_mm_file->Append( m_mm_open );

	m_mm_file->AppendSeparator();

	wxMenuItem* m_mm_close;
	m_mm_close = new wxMenuItem( m_mm_file, wxID_ANY, wxString( wxT("Close") ) , wxEmptyString, wxITEM_NORMAL );
	m_mm_file->Append( m_mm_close );

	m_main_menu->Append( m_mm_file, wxT("File") );

	m_menu_tools = new wxMenu();
	m_mm_convert = new wxMenuItem( m_menu_tools, wxID_ANY, wxString( wxT("Convert") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_tools->Append( m_mm_convert );
	m_mm_convert->Enable( false );

	m_mm_slice = new wxMenuItem( m_menu_tools, wxID_ANY, wxString( wxT("Slice") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_tools->Append( m_mm_slice );
	m_mm_slice->Enable( false );

	m_main_menu->Append( m_menu_tools, wxT("Tools") );

	this->SetMenuBar( m_main_menu );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_property = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE|wxPG_SPLITTER_AUTO_CENTER|wxTAB_TRAVERSAL);
	m_image_file = m_property->Append( new wxStringProperty( wxT("File"), wxT("File") ) );
	m_image_format = m_property->Append( new wxStringProperty( wxT("Format"), wxT("Format") ) );
	m_image_width = m_property->Append( new wxUIntProperty( wxT("Width"), wxT("Width") ) );
	m_image_height = m_property->Append( new wxUIntProperty( wxT("Height"), wxT("Height") ) );
	m_image_bit = m_property->Append( new wxUIntProperty( wxT("Bit / pixel"), wxT("Bit / pixel") ) );
	bSizer1->Add( m_property, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_convert = new wxButton( this, wxID_ANY, wxT("Convert"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btn_convert->Enable( false );

	bSizer2->Add( m_btn_convert, 0, wxALL, 5 );

	m_btn_slice = new wxButton( this, wxID_ANY, wxT("Slice"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btn_slice->Enable( false );

	bSizer2->Add( m_btn_slice, 0, wxALL, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_main_status_bar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_toolbar_main = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_tbtn_open = m_toolbar_main->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("IDB_OPEN_IMAGE"), wxBITMAP_TYPE_RESOURCE ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolbar_main->Realize();


	this->Centre( wxBOTH );

	// Connect Events
	m_mm_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFormBase::m_mm_openOnMenuSelection ), this, m_mm_open->GetId());
	m_mm_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFormBase::m_mm_closeOnMenuSelection ), this, m_mm_close->GetId());
	m_menu_tools->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFormBase::m_mm_convertOnMenuSelection ), this, m_mm_convert->GetId());
	m_menu_tools->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFormBase::OnMenuSliceSelection ), this, m_mm_slice->GetId());
	m_btn_convert->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFormBase::m_btn_convertOnButtonClick ), NULL, this );
	m_btn_slice->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFormBase::m_OnSliceButtonClick ), NULL, this );
	this->Connect( m_tbtn_open->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFormBase::OnToolOpenImageClicked ) );
}

MainFormBase::~MainFormBase()
{
	// Disconnect Events
	m_btn_convert->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFormBase::m_btn_convertOnButtonClick ), NULL, this );
	m_btn_slice->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFormBase::m_OnSliceButtonClick ), NULL, this );
	this->Disconnect( m_tbtn_open->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFormBase::OnToolOpenImageClicked ) );

}

FormPreview::FormPreview( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );
}

FormPreview::~FormPreview()
{
}

SliceParamBaseDlg::SliceParamBaseDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_sizer_sliceparam = new wxBoxSizer( wxVERTICAL );

	m_sizer_panels = new wxBoxSizer( wxHORIZONTAL );

	wxString m_rbox_sliceparamChoices[] = { wxT("Slice by percents"), wxT("Slice by parts") };
	int m_rbox_sliceparamNChoices = sizeof( m_rbox_sliceparamChoices ) / sizeof( wxString );
	m_rbox_sliceparam = new wxRadioBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_rbox_sliceparamNChoices, m_rbox_sliceparamChoices, 1, wxRA_SPECIFY_COLS );
	m_rbox_sliceparam->SetSelection( 1 );
	m_sizer_panels->Add( m_rbox_sliceparam, 0, wxALL, 5 );

	m_book_panels = new wxSimplebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel_param_1 = new wxPanel( m_book_panels, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_param_1->Hide();

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText21 = new wxStaticText( m_panel_param_1, wxID_ANY, wxT("Height (%):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	gSizer2->Add( m_staticText21, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_edt_hperc = new wxTextCtrl( m_panel_param_1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_edt_hperc, 0, wxALL, 5 );

	m_staticText31 = new wxStaticText( m_panel_param_1, wxID_ANY, wxT("Width (%):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	gSizer2->Add( m_staticText31, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_edt_vperc = new wxTextCtrl( m_panel_param_1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_edt_vperc, 0, wxALL, 5 );


	m_panel_param_1->SetSizer( gSizer2 );
	m_panel_param_1->Layout();
	gSizer2->Fit( m_panel_param_1 );
	m_book_panels->AddPage( m_panel_param_1, wxT("a page"), false );
	m_panel_param_2 = new wxPanel( m_book_panels, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel_param_2->Hide();

	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText2 = new wxStaticText( m_panel_param_2, wxID_ANY, wxT("Height (parts):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	gSizer4->Add( m_staticText2, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_edt_hparts = new wxTextCtrl( m_panel_param_2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( m_edt_hparts, 0, wxALL, 5 );

	m_staticText3 = new wxStaticText( m_panel_param_2, wxID_ANY, wxT("Width (parts):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer4->Add( m_staticText3, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_edt_vparts = new wxTextCtrl( m_panel_param_2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( m_edt_vparts, 0, wxALL, 5 );


	m_panel_param_2->SetSizer( gSizer4 );
	m_panel_param_2->Layout();
	gSizer4->Fit( m_panel_param_2 );
	m_book_panels->AddPage( m_panel_param_2, wxT("a page"), false );

	m_sizer_panels->Add( m_book_panels, 1, wxALL|wxEXPAND, 5 );


	m_sizer_sliceparam->Add( m_sizer_panels, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_slice = new wxButton( this, wxID_ANY, wxT("Slice"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btn_slice, 0, wxALL, 5 );

	m_btn_close = new wxButton( this, wxID_ANY, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_btn_close, 0, wxALL, 5 );


	m_sizer_sliceparam->Add( bSizer8, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( m_sizer_sliceparam );
	this->Layout();
	m_sizer_sliceparam->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_rbox_sliceparam->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SliceParamBaseDlg::OnRadioBoxSliceParam ), NULL, this );
	m_btn_slice->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SliceParamBaseDlg::OnButtonSliceClick ), NULL, this );
	m_btn_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SliceParamBaseDlg::OnButtonCloseClick ), NULL, this );
}

SliceParamBaseDlg::~SliceParamBaseDlg()
{
	// Disconnect Events
	m_rbox_sliceparam->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SliceParamBaseDlg::OnRadioBoxSliceParam ), NULL, this );
	m_btn_slice->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SliceParamBaseDlg::OnButtonSliceClick ), NULL, this );
	m_btn_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SliceParamBaseDlg::OnButtonCloseClick ), NULL, this );

}
