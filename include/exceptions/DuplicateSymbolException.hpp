#ifndef ICE_SCRIPT_DUPLICATESYMBOLEXCEPTION_HPP
#define ICE_SCRIPT_DUPLICATESYMBOLEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct DuplicateSymbolException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_DUPLICATESYMBOLEXCEPTION_HPP
