#ifndef ICE_SCRIPT_SYMBOLNOTFOUNDEXCEPTION_HPP
#define ICE_SCRIPT_SYMBOLNOTFOUNDEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct SymbolNotFoundException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_SYMBOLNOTFOUNDEXCEPTION_HPP
