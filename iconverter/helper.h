#pragma once
#include "Common.h"


template<typename T>
void clear_std_container(T &cont) {
	for (auto p : cont) delete p;
	cont.~T();
}

typedef std::vector<UINT> vCoord;
typedef std::vector<fipImage *> fipImages;

void slice_image(const fipImage &image, fipImages &images, const vCoord &vX, const vCoord &vY);
void slice_image(const fipImage &image, fipImages &images, UINT h_parts, UINT v_parts, RECT rect = { 0, 0, 0, 0 });

struct ImageFormatInfo
{
	FREE_IMAGE_FORMAT fif;
	wxString strFilter;
	wxString strAlias;
	wxString strExt;
};

enum SliceType { SLICE_UNKNOWN = -1, SLICE_BYPERCENT, SLICE_BYPARTS};

struct SliceParams {
	SliceType type;
	UINT h;
	UINT w;
	std::vector<int> vec_h, vec_w;
};

typedef std::vector<ImageFormatInfo> StorageIFI;
void LogInit(std::string &name);
