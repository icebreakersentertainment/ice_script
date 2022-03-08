#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <boost/exception/exception.hpp>
#include <boost/exception/diagnostic_information.hpp>

//#include "exceptions/Throw.hpp"

namespace ice_script
{

struct BaseException : virtual boost::exception, virtual std::exception
{
};

struct Exception : virtual BaseException
{
public:
	explicit Exception(const std::string& error = std::string());
    explicit Exception(const std::exception& e);

	const char* what() const noexcept override { return message_.c_str(); }

protected:
	std::string message_;
};

}

#endif /* EXCEPTION_H_ */
