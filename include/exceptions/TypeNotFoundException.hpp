#ifndef ICE_SCRIPT_TYPENOTFOUNDEXCEPTION_HPP
#define ICE_SCRIPT_TYPENOTFOUNDEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct TypeNotFoundException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_TYPENOTFOUNDEXCEPTION_HPP
