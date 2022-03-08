#ifndef ICE_SCRIPT_DUPLICATEALLOCAINSTEXCEPTION_HPP
#define ICE_SCRIPT_DUPLICATEALLOCAINSTEXCEPTION_HPP

#include "exceptions/Exception.hpp"

namespace ice_script
{

struct DuplicateAllocaInstException : virtual Exception
{
    using Exception::Exception;
};

}

#endif //ICE_SCRIPT_DUPLICATEALLOCAINSTEXCEPTION_HPP
