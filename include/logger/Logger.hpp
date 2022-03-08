#ifndef ICE_SCRIPT_LOGGER_HPP_
#define ICE_SCRIPT_LOGGER_HPP_

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include "logger/ILogger.hpp"

namespace logger = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

using namespace logger::trivial;

namespace ice_script { namespace logger {

class Logger : public ILogger
{	
public:
	Logger(const std::string& fileName = std::string("ice_script.log"));
	Logger(const Logger& other);
	Logger& operator=(const Logger& other);
	virtual ~Logger();
	
	virtual void info(const std::string& message) override;
	virtual void debug(const std::string& message) override;
	virtual void trace(const std::string& message) override;
	virtual void warn(const std::string& message) override;
	virtual void error(const std::string& message) override;
	virtual void fatal(const std::string& message) override;

private:
	src::severity_logger< severity_level > log_;
};

}}

#endif /* ICE_SCRIPT_LOGGER_HPP_ */
