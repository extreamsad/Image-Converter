#include "wxMyApp.h"
#include "MainForm.h"


wxMyApp::wxMyApp()
{
}


wxMyApp::~wxMyApp()
{
}

bool wxMyApp::OnInit()
{

	LogInit(std::string(_log_name));
	
	logging::add_common_attributes();	
	try
	{
		prop_tree::ini_parser::read_ini(_ini_file, _settings);
		/*
		** Read value from ini-file example

		std::string value1 = ptRead.get<std::string>("Section1.Value1");
		for (auto& section : _settings) {						
			for (auto& key : section.second) {
				
			}
		}*/
	}
	catch (std::exception const&  ex) 
	{
		BOOST_LOG_SEV(_log, severity_level::error) << ex.what();		
		/*
		** Write to ini-file example
		
		_settings.put<string>("Section1.Value1", "1");
		_settings.put<int>("Section1.Value2", 2);		
		_settings.put<float>("Section2.Value1", 3.1f);
		_settings.put<double>("Section2.Value2", 4.145f);
		prop_tree::ini_parser::write_ini(_ini_file, _settings);	*/	
	}
		


	wxInitAllImageHandlers();
	MainForm *mainForm = new MainForm(NULL, _settings, _log);
	mainForm->Show(true);
	return true;
}

IMPLEMENT_APP(wxMyApp)
