#ifndef __SliceParamDlg__
#define __SliceParamDlg__

/**
@file
Subclass of SliceParamDlg, which is generated by wxFormBuilder.
*/

#include "wxMainFormBase.h"
#include "helper.h"

//// end generated include

/** Implementing SliceParamDlg */
class SliceParamDlg : public SliceParamBaseDlg
{
private:
	int m_h = 0, m_w = 0;
	//SliceType m_type;
	boost::shared_ptr<SliceParams> m_slice_param;
protected:
		// Handlers for SliceParamDlg events.
	void OnButtonCloseClick( wxCommandEvent& event ) override;
	void OnRadioBoxSliceParam(wxCommandEvent& event) override;
	void OnButtonSliceClick(wxCommandEvent& event) override;
private:
	
public:
		/** Constructor */
	SliceParamDlg( wxWindow* parent );
//// end generated class members
	boost::shared_ptr<SliceParams> GetParams() const;
	int GetH() const;
	int GetW() const;
	std::vector<int> GetVectorH() const;
	std::vector<int> GetVectorW() const;
	SliceType GetTypeOfSlice() const;
};

#endif // __SliceParamDlg__
