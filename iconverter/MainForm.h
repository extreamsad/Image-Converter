#pragma once

#include "wxMainFormBase.h"
#include "SliceParamDlg.h"
#include "helper.h"
#include "env32.xpm"

using namespace logging::trivial;

class MainForm :
	public MainFormBase
{
	src::severity_logger< severity_level > &_log;
	prop_tree::ptree &_settings;
	wxString m_if_path, m_if_name, m_if_clear_name, m_str_save_formats, m_str_open_formats;
	StorageIFI m_ifi_stor;
	fipImage m_img;
	int m_fif_index = -1;
	FREE_IMAGE_FORMAT m_cur_fif = FIF_UNKNOWN;
protected:
	void m_mm_openOnMenuSelection(wxCommandEvent& event) override;
	void m_mm_convertOnMenuSelection(wxCommandEvent& event) override;
	void m_mm_closeOnMenuSelection(wxCommandEvent& event) override;
	void m_btn_convertOnButtonClick(wxCommandEvent& event) override;
	void m_OnSliceButtonClick(wxCommandEvent& event) override;
	void OnToolOpenImageClicked(wxCommandEvent& event) override;
	void OnMenuSliceSelection(wxCommandEvent& event) override;
public:
	MainForm(wxWindow* parent, prop_tree::ptree& settings, src::severity_logger< severity_level > &log);
	~MainForm();
};

