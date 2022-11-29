#ifndef ICE_SCRIPT_FUNCTIONNOTFOUNDEXCEPTION_HPP
#define ICE_SCRIPT_FUNCTIONNOTFOUNDEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct FunctionNotFoundException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_FUNCTIONNOTFOUNDEXCEPTION_HPP
