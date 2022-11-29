#ifndef ICE_SCRIPT_EXCEPTIONS_DUPLICATEVALUEEXCEPTION_HPP
#define ICE_SCRIPT_EXCEPTIONS_DUPLICATEVALUEEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct DuplicateValueException : virtual Exception
{
    using Exception::Exception;
};

}

#endif /* ICE_SCRIPT_EXCEPTIONS_DUPLICATEVALUEEXCEPTION_HPP */
