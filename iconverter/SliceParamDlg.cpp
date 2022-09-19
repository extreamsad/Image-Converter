#include "SliceParamDlg.h"

SliceParamDlg::SliceParamDlg( wxWindow* parent ):
	SliceParamBaseDlg( parent )	
{	
	m_slice_param.reset(new SliceParams());
	m_book_panels->ChangeSelection(m_rbox_sliceparam->GetSelection());
	//m_book_panels->GetPage();
	//SetClientSize(m_book_panels->GetBestSize());
}

boost::shared_ptr<SliceParams> SliceParamDlg::GetParams() const
{
	return m_slice_param;
}

int SliceParamDlg::GetH() const
{
	return m_h;
}

int SliceParamDlg::GetW() const
{
	return m_w;
}

std::vector<int> SliceParamDlg::GetVectorH() const
{
	return std::vector<int>();
}

std::vector<int> SliceParamDlg::GetVectorW() const
{
	return std::vector<int>();
}

SliceType SliceParamDlg::GetTypeOfSlice() const
{	
	return (SliceType)m_rbox_sliceparam->GetSelection();
}

void SliceParamDlg::OnButtonCloseClick( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}

void SliceParamDlg::OnRadioBoxSliceParam(wxCommandEvent & event)
{	
	m_book_panels->ChangeSelection(m_rbox_sliceparam->GetSelection());	
	//SetClientSize(m_book_panels->GetBestSize());
}

void SliceParamDlg::OnButtonSliceClick(wxCommandEvent & event)
{
	SliceType type = (SliceType)m_rbox_sliceparam->GetSelection();
	switch (type)
	{
	case SLICE_BYPERCENT:
		m_edt_hperc->GetLabel();
		m_edt_vperc->GetLabel();
		break;
	case SLICE_BYPARTS:
		m_slice_param->h = wxAtoi(m_edt_hparts->GetValue());
		m_slice_param->w = wxAtoi(m_edt_vparts->GetValue());
		m_slice_param->type = type;
		break;
	default:
		EndModal(wxID_CANCEL);
		return;
	}
	//m_slice_param
	EndModal(wxID_OK);
}

