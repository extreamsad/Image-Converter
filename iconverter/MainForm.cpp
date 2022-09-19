#include "MainForm.h"



void MainForm::m_mm_openOnMenuSelection(wxCommandEvent & event)
{
	wxFileDialog OpenDialog(this, _("Choose a image file"), wxEmptyString, wxEmptyString,
		m_str_open_formats, wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition);
	if (OpenDialog.ShowModal() == wxID_OK) {		
		m_if_path = OpenDialog.GetPath();
		m_if_clear_name = m_if_name = OpenDialog.GetFilename();
		size_t pos = m_if_name.rfind('.');
		if(pos != wxString::npos) m_if_clear_name.Truncate(pos);
		m_img.clear();
		
		m_img.loadU(m_if_path);
		if (!m_img.isValid())
		{
			wxMessageBox(_("Wrong format!"), wxT("Error"), wxICON_ERROR);
			return;
		}
		/*int numc = _img.getColorsUsed();
		FREE_IMAGE_COLOR_TYPE ct = _img.getColorType();		
		const BITMAPINFO *bi = _img.getInfo();*/
		
		const BITMAPINFOHEADER *bih = m_img.getInfoHeader();
		m_image_width->SetValue(bih->biWidth);
		m_image_height->SetValue(bih->biHeight);
		m_image_bit->SetValue(bih->biBitCount);
		m_image_file->SetValue(m_if_path);
		int fif_index = 0;
		for (const ImageFormatInfo &ifi : m_ifi_stor) {			
			if(ifi.fif == m_img.getFIF())  { 
				m_image_format->SetValue(ifi.strAlias); 				
				m_cur_fif = m_ifi_stor.at(fif_index).fif;
				m_fif_index = fif_index;
				break; 
			}
			fif_index++;
		}
		//m_image_format->SetValue();
		m_main_status_bar->SetStatusText(m_if_path);
		m_btn_convert->Enable();
		m_mm_convert->Enable();
		m_mm_slice->Enable();
		m_btn_slice->Enable();
	}
}

void MainForm::m_mm_convertOnMenuSelection(wxCommandEvent & event)
{
	if (m_if_path.IsEmpty()) return;
	boost::scoped_ptr<wxFileDialog> OpenDialog(new wxFileDialog(this, _("Save a image file"), wxEmptyString, wxEmptyString,
		m_str_save_formats, wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition));
	if (OpenDialog->ShowModal() == wxID_CANCEL) return;
	wxString path = OpenDialog->GetPath();
	wxString filename = OpenDialog->GetFilename();
	try
	{
		FREE_IMAGE_FORMAT fif = m_ifi_stor.at(OpenDialog->GetFilterIndex()).fif;		
		int tmpH = m_image_height->GetValue().GetInteger();
		int tmpW = m_image_width->GetValue().GetInteger();
		int tmpBit = m_image_bit->GetValue().GetInteger();		
		if(tmpH != m_img.getHeight() || tmpW != m_img.getWidth() /*|| tmpBit != _img.getBitsPerPixel()*/)
		{			
			m_img.rescale(tmpW, tmpH, FREE_IMAGE_FILTER::FILTER_BOX);			
		}
		int curBit = m_img.getBitsPerPixel();
		FREE_IMAGE_TYPE fit = m_img.getImageType();

		if (tmpBit != curBit && m_img.getImageType() == FIT_BITMAP)
		{
			switch (tmpBit)
			{
			case 1:
			case 4:
				m_img.convertTo4Bits();
				break;
			case 8:
				m_img.convertTo8Bits();
				break;
			case 16:
				m_img.convertTo16Bits555();
				break;
			case 24:
				m_img.convertTo24Bits();
				break;
			case 32:
				m_img.convertTo32Bits();
				break;
			default:
				break;
			}
		}		
		bool bTransparent = m_img.isTransparent();
		UINT tcount = m_img.getTransparencyCount();
		BYTE *ttable = m_img.getTransparencyTable();
		bool bBkColor = m_img.hasFileBkColor();
		/*if (_img.getFIF() == FIF_PNG) {
			RGBQUAD bkColor{ 0,0,0,0 };
			_img.setFileBkColor(&bkColor);			

		}*/
		
		m_img.save(fif, path) ? m_main_status_bar->SetStatusText("Converting successful!") : m_main_status_bar->SetStatusText("Converting failed!");
		/*if (_img.getFIF() == FIF_XPM) {
			RGBQUAD bkColor{ 255,255,255,0 };
			_img.setFileBkColor(&bkColor);
			BYTE tt[] = { 0xff };
			_img.setTransparencyTable(tt, 1);
			_img.save(path);
		}*/
	}
	catch (const std::exception& e)
	{
		wxMessageBox(wxString::Format("Error: %s", e.what()), wxT("Exception"), wxICON_ERROR);
		return;
	}	
	//_img.save(FIF_XPM, )
}

void MainForm::m_mm_closeOnMenuSelection(wxCommandEvent & event)
{
	Close();
}

void MainForm::m_btn_convertOnButtonClick(wxCommandEvent & event)
{
	m_mm_convertOnMenuSelection(event);
}

void MainForm::m_OnSliceButtonClick(wxCommandEvent & event)
{
	boost::scoped_ptr<SliceParamDlg> slice_param_dlg(new SliceParamDlg(this));
	if (slice_param_dlg->ShowModal() == wxID_OK) {
		auto param = slice_param_dlg->GetParams();
		fipImages images;
		switch (param->type)
		{
		case SLICE_BYPERCENT:
			break;
		case SLICE_BYPARTS:
			slice_image(m_img, images, param->h, param->w);
			if (images.size()) {
				wxDirDialog DirForSaveImages(this, "Choose folder for save images", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
				if (DirForSaveImages.ShowModal() == wxID_OK) 
				{
					try{
						auto ext = m_ifi_stor.at(m_fif_index).strExt;
						int img_count = 1;
						for (fipImage * pimg : images) {
							auto p = wxString::Format("%s/%s_%d%s", DirForSaveImages.GetPath(), m_if_clear_name, img_count, ext).wchar_str();
							pimg->saveU(m_cur_fif, p);
							img_count++;
						}
						clear_std_container(images);
						wxMessageBox("Slice successful!", "Information", wxICON_INFORMATION);
					}
					catch (const std::exception &e) {
						wxMessageBox(e.what(), "Error", wxICON_ERROR);
					}
				}
			}else wxMessageBox("Bad parameters!", "Error", wxICON_ERROR);
			break;		
		}		
	}
}

void MainForm::OnToolOpenImageClicked(wxCommandEvent & event)
{
	m_mm_openOnMenuSelection(event);
}

void MainForm::OnMenuSliceSelection(wxCommandEvent & event)
{
	m_OnSliceButtonClick(event);
}

MainForm::MainForm(wxWindow* parent, prop_tree::ptree& settings, src::severity_logger< severity_level >& log) :
	MainFormBase(parent),
	_log(log),
	_settings(settings)
{
	SetIcon(main_form_icon);
	BOOST_LOG_SEV(_log, severity_level::info) << "Main window created!";
	m_ifi_stor.push_back({ FIF_BMP, "*.bmp", "Bitmaps", ".bmp"});
	m_ifi_stor.push_back({ FIF_ICO, "*.ico", "Icons", ".ico" });
	//m_ifi_stor.push_back({ FIF_JPEG, "*.jpeg", "JPEG", ".jpeg" });
	m_ifi_stor.push_back({ FIF_JPEG, "*.jpg", "JPG", ".jpg" });
	m_ifi_stor.push_back({ FIF_PNG, "*.png", "PNG", ".png" });
	m_ifi_stor.push_back({ FIF_TIFF, "*.tiff", "TIFF", ".tiff" });
	m_ifi_stor.push_back({ FIF_XPM, "*.xpm", "XPM", ".xpm" });
	m_ifi_stor.push_back({ FIF_WEBP, "*.webp", "WEBP", ".webp" });
	
	m_str_open_formats = "All formats ";
	wxString tmpStr1 = "(", tmpStr2 = ") |";
	for (const ImageFormatInfo &ifi : m_ifi_stor) {
		//wxString str_tmp = wxString::Format("");
		tmpStr1.Append(wxString::Format("%s,", ifi.strFilter));
		tmpStr2.Append(wxString::Format("%s;", ifi.strFilter));
	}
	tmpStr1.Truncate(tmpStr1.size() - 1);
	tmpStr2.Truncate(tmpStr2.size() - 1);
	m_str_open_formats.Append(tmpStr1);
	m_str_open_formats.Append(tmpStr2);
	m_str_open_formats.Append("|");
	for (const ImageFormatInfo &ifi : m_ifi_stor) {
		wxString str_tmp = wxString::Format("%s (%s)|%s|", ifi.strAlias, ifi.strFilter, ifi.strFilter);		
		m_str_save_formats.Append(str_tmp);
	}	
	
	m_str_save_formats.Truncate(m_str_save_formats.size()-1);
	m_str_open_formats.Append(m_str_save_formats);
	//wxString str = wxString::Format("");
}

MainForm::~MainForm()
{
}
