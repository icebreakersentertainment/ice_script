#ifndef ICE_SCRIPT_DUPLICATEARGUMENTEXCEPTION_HPP
#define ICE_SCRIPT_DUPLICATEARGUMENTEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct DuplicateArgumentException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_DUPLICATEARGUMENTEXCEPTION_HPP
