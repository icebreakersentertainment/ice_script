#ifndef ICE_SCRIPT_DUPLICATEFUNCTIONEXCEPTION_HPP
#define ICE_SCRIPT_DUPLICATEFUNCTIONEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct DuplicateFunctionException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_DUPLICATEFUNCTIONEXCEPTION_HPP
