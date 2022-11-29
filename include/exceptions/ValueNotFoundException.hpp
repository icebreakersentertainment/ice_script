#ifndef ICE_SCRIPT_EXCEPTIONS_VALUENOTFOUNDEXCEPTION_HPP
#define ICE_SCRIPT_EXCEPTIONS_VALUENOTFOUNDEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct ValueNotFoundException : virtual Exception
{
    using Exception::Exception;
};

}


#endif /* ICE_SCRIPT_EXCEPTIONS_VALUENOTFOUNDEXCEPTION_HPP */
