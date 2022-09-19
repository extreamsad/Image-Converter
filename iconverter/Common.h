#pragma once
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/scoped_ptr.hpp>

#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/accel.h>
#include <wx/clipbrd.h>
#include <wx/dirdlg.h>

#include <FreeImagePlus.h>

#include <map>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace options = boost::program_options;
namespace prop_tree = boost::property_tree;
