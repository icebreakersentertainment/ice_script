#ifndef ICE_SCRIPT_ALLOCAINSTNOTFOUNDEXCEPTION_HPP
#define ICE_SCRIPT_ALLOCAINSTNOTFOUNDEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct AllocaInstNotFoundException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_ALLOCAINSTNOTFOUNDEXCEPTION_HPP
