#pragma once
#include "wx/wxprec.h"
#include "helper.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#ifndef __WXMSW__
#error Sorry, this sample is only appropriate under Windows.
#endif

#include <map>
#include <string>

using namespace logging::trivial;
using namespace std;
//typedef std::multimap<std::string, std::pair<std::string, std::string>> settings;

class wxMyApp : public wxApp
{
	src::severity_logger< severity_level > _log;
	prop_tree::ptree _settings;
	string _ini_file = "config.ini";
	string _log_name = "execute";
public:
	wxMyApp();
	~wxMyApp();
	virtual bool OnInit() override;
};

