#ifndef ICE_SCRIPT_DUPLICATETYPEEXCEPTION_HPP
#define ICE_SCRIPT_DUPLICATETYPEEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct DuplicateTypeException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_DUPLICATETYPEEXCEPTION_HPP
